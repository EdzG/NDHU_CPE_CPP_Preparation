#include <vector>
#include <unordered_map>

//Todo, use array instead, unordered map is overkill
//From leetcode -> (r /3) * 3 + (c / 3) for subgrid mapping
class Solution {
   public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) { return isValidRowCol(board); }
    bool isValidRowCol(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            std::unordered_map<char, int> seenR;
            std::unordered_map<char, int> seenC;

            for (int j = 0; j < 9; j++) {
                // check subgrid
                if (i % 3 == 0 && j % 3 == 0) {
                    std::unordered_map<char, int> seenS;
                    for (int y = 0; y < 3; y++) {
                        for (int z = 0; z < 3; z++) {
                            char chr = board[i + y][j + z];
                            if (chr == '.') continue;
                            if (seenS[board[i + y][j + z]] >= 1)
                                return false;
                            else
                                seenS[board[i + y][j + z]]++;
                        }
                    }
                }

                // check row
                if (seenR[board[i][j]] >= 1 && board[i][j] != '.')
                    return false;
                else
                    seenR[board[i][j]]++;
                // check col
                if (seenC[board[j][i]] >= 1 && board[j][i] != '.')
                    return false;
                else
                    seenC[board[j][i]]++;
            }
        }
        return true;
    }
};
