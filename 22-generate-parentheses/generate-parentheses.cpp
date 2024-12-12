class Solution {
public:
    int n, n_dong = 0, n_mo = 0;
    char a[3] = {'(', ')'};
    string curr = "";
    vector<string> c;

    bool check(int i) {
        if (i == 1) {
            if (n_mo == n) return false;
        }
        if (i == 2) {
            if (n_dong >= n_mo) return false;
            if (n_dong == n) return false;
        }
        return true;
    }

    void Try(int k) {
        for (int i = 1; i <= 2; i++) {
            if (check(i)) {
                curr.push_back(a[i-1]);
                if (i == 1) n_mo++;
                else n_dong++;

                if (k == 2*n) 
                    c.push_back(curr); // Sửa lại ở đây: thay c.push_back(k) thành c.push_back(curr)
                else 
                    Try(k+1);

                curr.pop_back();
                if (i == 1) n_mo--;
                else n_dong--;
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        this->n = n; // Gán giá trị n trước khi chạy Try
        Try(1);
        return c;
    }
};
