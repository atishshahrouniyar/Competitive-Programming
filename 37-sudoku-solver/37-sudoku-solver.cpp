class Solution {
public:
    
    bool isValid(vector<vector<char>>& input, int x, int y, char c) {
    int blkrow = (x / 3) * 3, blkcol = (y / 3) * 3;
    for (int i = 0; i < 9; ++i) {
        
        if (input[i][y] == c || input[x][i]==c || input[blkrow + i / 3][blkcol + i % 3] ==c)
            return false;
    }
    return true;

}

bool solve(vector<vector<char>>& input, int x, int y) {
    for (int i = x; i < 9; ++i, y=0) {
        for (int j = y; j < 9; ++j) {
            if (input[i][j] != '.')
                continue;
            for (char num = '1'; num <= '9'; ++num) {
                if (isValid(input, i, j, num)) {
                    input[i][j] = num;
                    if (solve(input, i, j + 1))
                        return true;
                    input[i][j] = '.';
                }
            }
            return false;
        }
    }
    return true;
}
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};