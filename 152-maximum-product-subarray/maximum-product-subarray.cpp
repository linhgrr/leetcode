class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // dpMax[i] = tích lớn nhất kết thúc tại i
        // dpMin[i] = tích nhỏ nhất kết thúc tại i
        vector<long long> dpMax(n), dpMin(n);

        // Khởi tạo
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];
        long long ans = nums[0];

        for (int i = 1; i < n; i++) {
            // Nếu nums[i] >= 0:
            if (nums[i] >= 0) {
                dpMax[i] = max((long long)nums[i], dpMax[i-1] * nums[i]);
                dpMin[i] = min((long long)nums[i], dpMin[i-1] * nums[i]);
            } else { 
                // nums[i] < 0
                dpMax[i] = max((long long)nums[i], dpMin[i-1] * nums[i]);
                dpMin[i] = min((long long)nums[i], dpMax[i-1] * nums[i]);
            }
            // Cập nhật kết quả
            ans = max(ans, dpMax[i]);
        }
        return (int)ans;
    }
};
