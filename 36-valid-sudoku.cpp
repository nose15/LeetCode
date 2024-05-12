class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<pair<uint8_t, uint8_t>> rows, cols, boxes;

        for (uint8_t i = 0; i < 9; i++) {
            for (uint8_t j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                uint8_t current = board[i][j];
                uint8_t boxIndex = (j / 3) + (i / 3) * 3;
                
                if (rows.contains({i, current}) || cols.contains({j, current}) || boxes.contains({boxIndex, current}))
                    return false;

                rows.insert({i, current});
                cols.insert({j, current});
                boxes.insert({boxIndex, current});
            }
        }
        return true;
    }
};
