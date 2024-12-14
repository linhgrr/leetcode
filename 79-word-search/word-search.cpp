class Solution {
public:
    int n, m;
    vector<vector<char>> c;
    string s;
    pair<int, int> b[20];
    bool isOke = false;
    bool visited[10][10] = {false};

    bool check(int i, int j, int k){
        if (visited[i][j]) return false;
        if (c[i][j] == s[k] && k == 0) return true;
        if (c[i][j] != s[k]) return false;
        // kiem tra xem i, j co nam canh i = b[k-1].first j = b[k-1].second khong
        int x = b[k-1].first;
        int y = b[k-1].second;

        if (
            x == i - 1 && y == j     ||
            x == i     && y == j - 1 ||
            x == i + 1 && y == j     ||
            x == i     && y == j + 1 
            // x == i - 1 && y == j - 1 ||
            // x == i - 1 && y == j + 1 ||
            // x == i + 1 && y == j - 1 ||
            // x == i + 1 && y == j + 1 
        ) return true;

        return false;
    }
    
    void Try(int k){
        if (isOke) return;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (check(i, j, k)){
                    b[k] = {i, j};
                    visited[i][j] = true;

                    if (k == s.size() - 1){
                        isOke = true;
                    } else Try(k+1);

                    visited[i][j] = false;
                }
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        c = board;
        s = word;

        Try(0);

        return isOke;
    }
};