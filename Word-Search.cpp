#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, const string& word, int pos) {
        int n = board.size(), m = board[0].size();

        if (pos == word.size()) return true;
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != word[pos]) return false;

        char temp = board[i][j];
        board[i][j] = '#'; 

        bool found = dfs(board, i - 1, j, word, pos + 1) ||
                     dfs(board, i + 1, j, word, pos + 1) ||
                     dfs(board, i, j - 1, word, pos + 1) ||
                     dfs(board, i, j + 1, word, pos + 1);

        board[i][j] = temp;         
        return found;
    }

    bool exist(vector<vector<char>>& board, const string& word) {
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
     

    return 0;
}
