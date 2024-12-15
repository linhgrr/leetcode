class Solution {
public:
    int n;
    int dp[105];

    int rob(vector<int>& nums) {
        n = nums.size();
        if (n == 1) return nums[0];
        else if (n == 0) return 0;
        else if (n == 2) return max(nums[1], nums[0]);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < n; i++){
            dp[i] = dp[i-1];
            int k = 0;
            for (int j = 0; j < i - 1; j++){
                k = max(k, dp[j]);
            }

            dp[i] = max(dp[i], k + nums[i]);
        }

        return dp[nums.size()-1];
    }
};