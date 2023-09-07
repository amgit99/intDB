# **DS PROJECT PHASE 1 REPORT | TEAM 10** 

## Team Members

<!-- Roll no.   Name         Email 
2022201006 Jaffrey Joy  jaffrey.joy@students.iiit.ac.in
2022201013 Amit Marathe amit.marathe@students.iiit.ac.in
2022201056 Neeraj Asdev neeraj.asdev@students.iiit.ac.in -->


| Roll No        | Name             | Email                                |
| -------------- | ---------------- | ------------------------------------ |
| 2022201006     | Jaffrey Joy      | jaffrey.joy@students.iiit.ac.in      |
| 2022201013     | Amit Marathe     | amit.marathe@students.iiit.ac.in     |
| 2022201056     | Neeraj Asdev     | neeraj.asdev@students.iiit.ac.in     |



**NOTE**: Some $\LaTeX$ symbols are failing to render on GitHub Markdown preview. Use [HackMD](https://hackmd.io/?nav=overview) to view this Markdown file.


## INTRODUCTION
Here we are extending the features of the existing *__SimpleRA__* RDBMS by implementing and adding the commands dealing with **MATRICES**.

---
## ASSUMPTIONS
* Every csv file that is to be read as a matrix should end with a new line character i. e. `\n` (the carriage return in UNIX based operating systems). Spaces between commas are allowed.
<!-- * Grammar for a line present in the CSV file should be:
$$
\begin{align}
          S &\rightarrow RN \\ 
          N &\rightarrow \text{\n} \\
          R &\rightarrow RCR \mid Z_w \\
        Z_w &\rightarrow WZW \\
          C &\rightarrow \text{,} \\
          W &\rightarrow WW \mid \ \text{' '}  \mid \epsilon \\   
          Z &\rightarrow PD \mid 0\\ 
          P &\rightarrow - \mid \epsilon \\
          D &\rightarrow DD \mid D0 \mid 1 \mid  2 \mid  3 \mid  4 \mid  5 \mid  6 \mid 7 \mid 8 \mid 9
\end{align}
$$
The number of $Z$ symbols on each line in the csv file must be equal. -->


## PAGE DESIGN
- No changes to attributes
- Page creation occurs through new overloading constructors written for a page storing matrix data

---
## COMMANDS
### `LOAD MATRIX`
* This function loads data from a csv file into the matrix.The file is read line by line, calculating offsets for each line (NOTE: The int elements are being read as characters) and storing them in a vector.
* Basically, we are slicing the file into blocks (slices) using the `blockify()` function which loads the appropriate data to create blocks within the matrix and initializes data structures to manage offsets, block sizes, and block contents.
* We first create a read offsets array (locally) which is the size of the number of rows in the whole matrix. This stores the byte position of the first line of each line in the file. This is then used to seek to that byte position and read the data for that corresponding row.
    ```
    offsets |  matrix
    --------|----------------------------
    [0]     |  1, 2, 3, ... || 6, 7 ...
    [0+x]   |  1, 2, 3, ... || 6, 7 ...
    [0+x+y] |  1, 2, 3, ... || 6, 7 ...
    .       |  .
    .       |  .
    .       |  .
    ---     |  ---
    .       |  .
    .       |  .
    .       |  .
    ```
    The values in `[]` are the read offsets and using this we would read `slice.colCount` number of values denoted above by `||` and then move on to the next offset to read the same till `slice.rowCount` number of rows are read denoted by `---`. This is then used to create a page and write it. These offsets are updated in every row of the slice for the next slice to be read.  **This is how our `BLOCK_READ` count for the `LOAD` operation is equal to the actual no. of blocks needed to store the matrix; as we are reading one whole block/page i.e. slice of the matrix from the file by seeking to the appropriate byte position in the input file and creating the block in "one go", rather than creating it in parts by going line by line in the input file** 
* For each block, we calculate the number of rows and columns. It updates offset information (updates various data structures to keep track of offsets and block sizes for a matrix) and then closes the file.
* When matrix is finally loaded, we insert the matrix in the matrix catalogue (similar to the table catalogue used in case of tables)
* NOTE: We are storing square slices of the matrix in every page and mainting the per slice row and col count in case of fragmented slices (slices that end up having non-square matrix) for operations on those slices


### `PRINT MATRIX`
* This is used to print the `PRINT_COUNT` no. of rows and columns to `stdout`
* Here we export a portion of the matrix data to a temp file, display it in the console, and then clean up by deleting the temp file.
* The `exportMatrix()` function exports a portion of the matrix to a temp file. It takes as input the number of rows and columns to export
* Matrix is iterated in slices, data from each slice is retrieved, and written to the temp file. Logic here is similar to `LOAD MATRIX` with the difference that a write offset is used instead of a read offset


### `EXPORT MATRIX`
* This command is used to export a matrix to a CSV file
* We store exported matrices in the`exports` directory
* The exported filename is as such`<MATRIX_NAME>.csv`
* The logic as mentioned above in `PRINT MATRIX` is to read a whole block and write its contents be seeking to the appropriate byte position using a `writeOffsets` array that stores at which position a line in the file would begin.
* We used this functionalityto implement the `PRINT MATRIX` command by giving it the corresponding row and column limiting arguments.


### `RENAME MATRIX`
* For every matrix that is loaded, we are creating a directory in which all the pages belonging to that matrix are stored.
* For rename function, we are just renaming the directory of that matrix with a new name that is passed as an argument which just updates the corresponding data structures in the memory.


### `TRANSPOSE MATRIX`
* As mentioned earlier, we are slicing the matrix in pages. So, basically we need to exchange the row and column elements within these pages. We stored the pages count both vertically and horizontally when we loaded the matrix.
* We have 2 sections implementing the transpose operation :-
    * **Outer Section**: (2 nested loops) 
    Considering the page index is <$s_i$, $s_j$> w. r. t.  the matrix then:
        * __CASE I__: if $s_i > s_j$ $\rightarrow$ exchange elements between pages <$s_i$, $s_j$> and <$s_j$, $s_i$>
        * __CASE II__: if $s_i = s_j$ $\rightarrow$ swap elements within the page itself (pages appearing at the diagonal of the sliced matrix) 
        * __CASE III__: else if $s_i < s_j$ $\rightarrow$ do nothing
    * **Inner Section**: (2 nested loops)
        * For __CASE I__ we perform an _INTER-transpose_. An _INTER-transpose_ is a transpose operation among 2 slices of the matrix
        Eg:
            ```
            ------------------------- . . .
            |           |           |
            | <s_0,s_0> | <s_0,s_1> | 
            |           |           |
            |------------------------ . . .
            |           |           |
            | <s_1,s_0> | <s_1,s_1> | 
            |           |           |
            ------------------------- . . .
            .           .           .
            .           .           .
            .           .           .
            ```
            Based on the above diagram, the slices among which and _INTER-TRANSPOSE_ would happen is  <$s_1$, $s_0$> and <$s_1$, $s_0$>, i. e. bsically for all <$s_i$, $s_j$>,<$s_j$, $s_i$ pairs where $i \neq j$. Let us consider $A$ denotes slice <$s_1$, $s_0$> and $B$ denotes slice <$s_1$, $s_0$> then an _INTER-TRANSPOSE_ would defined be as follows (Below $i$ and $j$ are not slice indices, but indices of the matrix within the slice, and this operation would be performed for all valid $i$ and $j$ in the matrix $A$ and $B$):
            $$
            \begin{align}
                   temp &= A[i][j] \\
                A[i][j] &= B[j][i] \\
                B[j][i] &= temp
            \end{align}
            $$
            
            <center>or</center>
            
            $$
            swap(A[i][j], B[j][i])
            $$
            
        * For __CASE II__ we perform an _INTRA-transpose_. An _INTRA-transpose_ is a transpose operation that happens within a slice.
        Based on the above diagram, the slices among which and _INTER-TRANSPOSE_ would happen is  <$s_0$, $s_0$>, <$s_1$, $s_1$>, ... basically for all <$s_i$, $s_j$> where $i = j$. Let us consider $A$ denotes slice <$s_0$, $s_0$> then an _INTRA-TRANSPOSE_ would be as follows ($i$ and $j$'s definition is mentioned above;  and this operation would be performed for either all $i<j$ or $i>j$ in the matrix $A$):
            $$
            \begin{align}
                   temp &= A[i][j] \\
                A[i][j] &= A[j][i] \\
                A[j][i] &= temp
            \end{align}
            $$
            
            <center>or</center>
            
            $$
            swap(A[i][j], A[j][i])
            $$
* We use the `BufferManager` to get the pages associated with the current slice indexes.
* After the transpose operation is complete, the updated data is written back to the pages using the `BufferManager`. The outer section ensures that all slices of the matrix are transposed, and the inner section ensures the actual swapping happens between the elements in the right slices of the matrix.

### `CHECKSYMMETRY`
* The sections and base implementation are same as the transpose operation but note that here we don't need to actually implement transpose, just use the transpose conditions to check the symmetry of the matrix.
* It also uses the `BufferManager` to get the pages associated with the current slice indexes. It then iterates through the rows and columns of one page and compares the values with the corresponding positions in other page. 
* If any pair of values doesn't match, it immediately returns `false`, indicating that the matrix is _asymmetric_.
* If all the corresponding slice pairs are matched completely, then the function returns `true`, indicating that the matrix is _symmetric_.


### `COMPUTE`
* In this operation, we subtract the matrix element with its corresponding transpose element. This is the most computationally extensive operation in this phase coz it includes several other operations like (export, subtracting the corresponding elements, etc.).
                                                    
    * `EXPORT` is required because the `TRANSPOSE MATRIX` command replaces the original matrix with its transpose (inplace).
    * We DON'T need to implement the transpose separately, we just need to apply subtraction on elements of the one sided triangular matrix with the elements of the other sided triangular matrix and vice versa. The diagonal elements would be 0 in this case.
* Similar to the above `TRANSPOSE` and `CHECKSYMMETRY` operations the code does the following for each pair of pages with slice indices <$s_i$, $s_j$> and <$s_j$, $s_i$> inside the outer section:
    * It uses the `BufferManager` to get the pages (say) A and B associated with the current slice indexes.
    * It then iterates through the rows and columns of A and B, performing the following computation for each element:
        $$
            \begin{align}
               temp &= A[i][j] \\
            A[i][j] &= A[i][j] - B[j][i] \\
            B[j][i] &= B[j][i] - temp
            \end{align}
        $$
            
    * After the computation is complete for the current pair of pages, it writes the updated data back to the pages using the `BufferManager`
* The flow for `COMPUTE` is as follows considering $A$ is the name of the matrix for whom `COMPUTE` is being calculated:
$$
\text{Export Matrix $A$}\\
\downarrow \\
\text{Compute $A$ - $A^T$ (in place)}\\
\downarrow \\
\text{Rename the computed $A$ - $A^T$ to $A\_RESULT$}\\
\downarrow \\
\text{Load the exported matrix $A$ back}\\
\downarrow \\
\text{Rename the loaded matrix $A$ to it's original name }\\
\downarrow \\
\text{Change the} \ \texttt{sourceFileName} \  \text{to its original one from the exported one}\\
\downarrow \\
\text{Delete the exported file}\\
$$


---


## LEARNINGs

<img src="https://miro.medium.com/v2/resize:fit:1400/1*uGY5dJ9wl2siXkE3YbH6MQ.jpeg" alt="“Premature optimization is the root of all evil”" width="700">


## CONTRIBUTION



| Roll No        | Name             | Work                                 |
| -------------- | ---------------- | ------------------------------------ |
| 2022201006     | Jaffrey Joy      | `COMPUTE`, `RENAME`, `Page` and `BufferManager` modifications     |
| 2022201013     | Amit Marathe     | `LOAD`, `EXPORT`, `PRINT`, `Page` and `BufferManager` modifications   |
| 2022201056     | Neeraj Asdev     | `TRANSPOSE`, `CHECKSYMMETRY` and Command parsing    |


