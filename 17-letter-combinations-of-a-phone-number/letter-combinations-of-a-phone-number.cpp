class Solution {
public:
    vector<vector<char>> a = vector<vector<char>>(10); // Khởi tạo 10 vector con
    string input;
    string output = "";
    vector<string> kq;

    void try_num(int k, string digits) {
        int currNum = digits[k] - '0';
        for (int i = 0; i < a[currNum].size(); i++) {
            output += a[currNum][i];
            if (k == digits.length() - 1) {
                kq.push_back(output);
            } else {
                try_num(k + 1, digits);
            }
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return kq; // Nếu không có đầu vào, trả về danh sách rỗng
        }

        // Khởi tạo các vector con cho từng chỉ số từ 2 đến 9
        a[2] = {'a', 'b', 'c'};
        a[3] = {'d', 'e', 'f'};
        a[4] = {'g', 'h', 'i'};
        a[5] = {'j', 'k', 'l'};
        a[6] = {'m', 'n', 'o'};
        a[7] = {'p', 'q', 'r', 's'};
        a[8] = {'t', 'u', 'v'};
        a[9] = {'w', 'x', 'y', 'z'};

        try_num(0, digits);
        return kq;
    }
};
