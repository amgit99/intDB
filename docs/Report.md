# **DS Project Phase 2 Report | Team 10** 

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


## Assumptions
* `flex` and `bison` needs to be installed if not already present.
* `,` is omitted as a separator for _column names_ and _ordering criteria_ in whichever commands they are applicable since the _space_ character is sufficient for delimiting them. 
* The terms _block_ and _page_ are used interchangeably. Similary the terms _table_ and _relation_ are also used interchangeably.

## TASK 1
### Inplace sorting of a table
- **Syntax**: 
    ```sql
    SORT <table_name>
    BY <column_name1 column_name2 ... column_namek> 
    IN <ASC|DESC ASC|DESC ... ASC|DESC>
    ```
   <details><summary>Example</summary>

    ![](https://hackmd.io/_uploads/SJflturgp.png)
    ![](https://hackmd.io/_uploads/HJzZFuSlT.png)

    </details>
- **Approach**
    - **Merge sort** (two way) is used to sort the table.
    - An **iterative** merge approach is used instead of the standard recursive one. This is done by maintaining appropriate information about the _current **level** in the merge tree_ and the _**block id** and **count** of blocks being merged_.
    - The rows within a block itself are sorted using the `std:: sort` function with a **custom comparator** function. 
    - The **custom comparator** function takes the list of constraists as a `std::pair` of `columnIndex` and `order` i.e. (`ASC` or `DESC`)  which is represented by a `bool`.  The order of the rows are defined by the priority of the constraints  i.e. leftmost constraint gets highest priority. Therefore, only if a constraint fails the next constraint is checked.
- **Algorithm**:
    ![](https://hackmd.io/_uploads/SJY1btBW6.png)


<!-- ---
</br> -->



## TASK 2
### Part A - `JOIN`
- **Syntax**: (binops:  `==`, `>`, `>=`, `<`, `<=`)
    ```sql
    <new_relation_name> <- JOIN <tablename1> <tablename2> 
                           ON <column1> <bin_op> <column2>
    ```
        
    <details><summary>Example</summary>

    ![](https://hackmd.io/_uploads/SJrsuuHlT.png)
    ![](https://hackmd.io/_uploads/ryknOdSlp.png)

    </details>
- **Approach**:
    - [**Block Nested Loop Join**](https://dev.mysql.com/doc/refman/8.0/en/nested-loop-joins.html#block-nested-loop-join-algorithm) is used to perform `JOIN` on the two relations.
    - Going forward, we use the terms $ltable$ and  $rtable$, $lblock$ and $rblock$ which correspond the left and right table in the join and the current block of those tables respectively 
    - Based on the `binop`, exclusive optimizations can be made, as before performing the join, both relations are sorted on their respective columns (based on which `JOIN` is being done). For each operator the corresponding optimization is mentioned as follows:
        - `==`
    
            As we iterate through the rows in  $lblock$ we don't need to start comparing with the first row of the first block of $rtable$.  
            Eg:
            |     |  L  |  R  |
            | --- | --- | --- |
            |  1  |  5  |  1  |
            |  2  |  6  |  2  |
            |  3  |  7  |  4  |
            |  4  |  7  |  5  |
            |  5  |  8  |  6  |
            |  6  |  9  |  7  |
            |  .  |  .  |  .  |

            Let us consider $L$ to be $ltable$'s col and $R$ to be $rtable$'s col that are being compared and let's assume $3$ rows are stored in a block. 
            If we are currently comparing the $2^{nd}$ row where $L = 6$ it is not necessary to start from the first block of $rtable$ as for the $1^{st}$ row where $L = 5$ we already traversed to row 4 where $R = 5$ and since we are aware that $rtable$ is also sorted, we can ensure that there will be no row before row $5$ where $R = 6$, so in this case as $3$ rows are in a block we save a whole block access.
        - `<=`, `<`
        
           Similar to the logic for `==` we just need to compare starting from the row in $rblock$ that last didnt satisfy the condition for the row previous to the current row from $ltable$ (given that the value in the previous and current row of $ltable$ are different). Any row before that in $rblock$ would by default satisfy the condition, as the previous row for $lblock$ would have a value `<=` to the value in the current row; so they can be added directly without explicitly comparing the values.
        - `>=`, `>`


            Relations can be swapped and `<=` and `<` can be used.
<!--         - `<=`
           Similar to the logic for `==` we just need to compare starting from the row in $rblock$ that last didnt satisfy the condition for the row previous to the current row from $ltable$ (given that the value in the previous and current row of $ltable$ are different) then find the last row in $rblock$ that satisfies the condition and include all rows in that $rblock$ before the last matched row for the result of the `JOIN`.
        - `<`
            Similar to logic for `<=` but we find the last row that has a value less than the one in the current row of $lbock$.
        - `>=`, `>`
            Relations can be swapped and `<=` and `<` can be used. -->
    

    
<!--     > **NOTE**: 
    The Result table must contain all the columns from both the tables. For the sake of this assignment, you can assume that both tables will never contain columns with matching names. The order of the columns must be columns from the first table followed by columns from the second table. 
 -->
 




### Part B - `ORDER BY`
- **Syntax**:
    ```sql
    <new_table> <- ORDER BY
                   <attribute> ASC|DESC
                   ON <table_name>
    ```  
    <details><summary>Example</summary>

    ![](https://hackmd.io/_uploads/Sy8OBkhxa.png)


    </details>
- **Approach**:
    - The function implemented for `SORT` command is run with an argument intimating it to store the result in a relation called `new_table` instead of replacing the original table with the sorted version based on the constraint in `ORDER`.
    


### Part C - `GROUP BY`
- **Syntax**: (Aggregate fns: `MIN`, `MAX`, `SUM`, `COUNT`, `AVG`)
    ```sql
    <new_table> <- GROUP BY <grouping_attribute> 
                   FROM <table_name> 
                   HAVING <aggregate_func(attribute)> <bin_op> <attribute_value> 
                   RETURN <aggregate_func(attribute)>

    ```   

    <details><summary>Example</summary>

    ![](https://hackmd.io/_uploads/H1-Su_Hx6.png)

    </details>
- **Approach**:
    - Table is sorted on the `grouping_attribute`
    - A `stats` object is maintained per group for the `aggregrate_func`s used in `HAVING` and `RETURN`
    - Sorting the table based on the `grouping_attribute` ensures that a group is processed in a **batch**. Otherwise, we would have to persist the `stat` objects for every group until the last value in that group is reached (whose arrival is unknown if the table is not sorted) so it would have to be maintained until all the rows are traversed.
<!--     - If `MIN` and `MAX` `aggregate_func`s are being using in `HAVING` or `RETURN` this could further be optimized.
        - If `MIN`/`MAX` is being used only in either of `HAVING` and `RETURN` we sort the table on 2 constraints i.e.  `grouping_attribute ASC` and `HAVING/RETURN attribute ASC/DESC` with the `ASC/DESC` depending on `MIN` or `MAX`
        - If `MIN`/`MAX` is being used on both `HAVING` and `RETURN` then we might need to maintain 2 sorted copies based on the following constraints
            - `grouping_attribute ASC` and `HAVING attribute ASC/DESC`
            - `grouping_attribute ASC` and `RETURN attribute ASC/DESC` -->

<!--     > **NOTE**: The output column name will be the aggregate operator concatenated with column name it's operating on -->


## Miscellaneous
### Parsing using `lex` and `bison`

The hand-written parser was replaced with regex for tokens and CFG based rules for grammar written in a `lexer.l` and `parser.y` file. The semantic and execution phase was implemented as actions for the corresponding rules defined in the grammar file.  

So the flow for parsing now is as below:

![](https://hackmd.io/_uploads/HkdaezuWT.png)



