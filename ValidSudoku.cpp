// ===== CADE EXPLANATION — VALID SUDOKU =====
//
// C — Clarify
// - The task is to validate a partially filled 9×9 Sudoku board.
// - We do NOT need to solve the Sudoku.
// - Empty cells are represented by '.' and should be ignored.
// - Each digit (1–9) must appear at most once in:
//   • each row
//   • each column
//   • each 3×3 sub-box
//
// A — Approach
// - We need to track whether a number has already appeared
//   in a given row, column, or 3×3 box.
// - Use three 2D arrays (or hash sets):
//   • row[9][9]  → row[i][num]
//   • col[9][9]  → col[j][num]
//   • box[9][9]  → box[k][num]
// - For each non-empty cell:
//   • Compute num = board[i][j] - '1'
//   • Compute box index:
//       k = (i / 3) * 3 + (j / 3)
// - If the number already exists in row, column, or box,
//   the board is invalid.
// - Otherwise, mark it as seen.
//
// Time Complexity:
// - O(81) → constant time since the board size is fixed.
//
// Space Complexity:
// - O(1) → fixed-size arrays (9×9).
//
// D — Dry Run
// - Suppose board[i][j] = '5'.
// - Check:
//   • row[i][4]
//   • col[j][4]
//   • box[k][4]
// - If any of them is already marked, return false.
// - Otherwise, mark all three and continue scanning.
//
// E — Execute
// - Traverse the board cell by cell.
// - Skip '.' cells.
// - Perform validation using row, column, and box tracking.
// - If no conflicts are found, return true.
//
// Interviewer Expectation:
// - Clear separation of row, column, and box constraints.
// - Correct computation of the 3×3 box index.
// - Constant-time validation using structured tracking.


class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
        
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }
        
        return true;
    }
};