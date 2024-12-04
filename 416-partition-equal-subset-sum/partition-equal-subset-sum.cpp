class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) sum += i;

        // Nếu tổng không chia hết cho 2, không thể chia được
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<int> dp(target + 1, 0); // Khởi tạo dp với kích thước target + 1
        dp[0] = 1; // Có thể tạo tổng 0 bằng cách không chọn số nào

        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                // Kiểm tra nếu có thể tạo tổng `j` bằng cách thêm `num`
                if (dp[j - num]) dp[j] = 1;
            }
        }

        return dp[target];
    }
};
