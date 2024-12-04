class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
    int m = text2.size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0)); // Khởi tạo mảng 2D

    // Tính toán LCS
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) { // So sánh ký tự tại chỉ số i-1 và j-1
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    return f[n][m];
    }
};