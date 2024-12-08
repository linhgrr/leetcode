class Solution {
public:
vector<int> a; // Dùng để lưu tổ hợp hiện tại
vector<vector<int>> b; // Lưu tất cả các tổ hợp

bool check(int i, int u) {
    if (u == 1) return true; // Nếu là phần tử đầu tiên, luôn hợp lệ
    if (i > a[u - 1]) return true; // Đảm bảo phần tử hiện tại lớn hơn phần tử trước
    return false;
}

void try_num(int u, int n, int k) {
    for (int i = 1; i <= n; i++) {
        if (check(i, u)) {
            a[u] = i; // Gán giá trị cho vị trí u
            if (u == k) {
                b.push_back(vector<int>(a.begin() + 1, a.begin() + k + 1)); // Lưu tổ hợp
            } else {
                try_num(u + 1, n, k); // Tiếp tục thử cho vị trí tiếp theo
            }
        }
    }
}
    vector<vector<int>> combine(int n, int k) {
        a.resize(k + 1); // Cấp phát kích thước cho vector a
    try_num(1, n, k);
    return b;
    }
};