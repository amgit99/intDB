#include "logger.h"

/**
 * @brief The Page object is the main memory representation of a physical page
 * (equivalent to a block). The page class and the page.h header file are at the
 * bottom of the dependency tree when compiling files. 
 *<p>
 * Do NOT modify the Page class. If you find that modifications
 * are necessary, you may do so by posting the change you want to make on Moodle
 * or Teams with justification and gaining approval from the TAs. 
 *</p>
 */

class Page{
    string tableName;
    string pageIndex;

public:
    int columnCount;
    int rowCount;
    vector<vector<int>> rows;
    string pageName = "";

    Page();
    Page(string tableName, int pageIndex);
    Page(string tableName, int pageIndex, vector<vector<int>> rows, int rowCount);
    Page(Matrix &matrix, int pageIndex);
    Page(string matrixName, int rowCount, int colCount, vector<vector<int>> &data, int pageIndex);
    vector<int> getRow(int rowIndex);
    void writePage();
    void writePage(Matrix &matrix, int rowCount, int colCount, vector<vector<int>> &data, int pageIndex);
};