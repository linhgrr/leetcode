class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int dp[200];
        int dp2[1004];

        dp[0] = nums[0];
        dp2[0] = 0;

        if (n > 1) {
            dp[1] = nums[1];
            dp2[1] = nums[1];
        }

        for (int i = 2; i < n-1; i++){
            int max_n = 0;
            int max_n2 = 0;
            for (int j = 0; j < i-1; j++){
                max_n = max(max_n, dp[j]);
                max_n2 = max(max_n2, dp2[j]);
            }
            dp[i] = nums[i] + max_n;
            dp2[i] = nums[i] + max_n2;
        }
        // den day la okela cho tat ca ngoi nha khac nha cc
        int max_n = 0;
        
        for (int i = 0; i < n-2; i++){
            max_n = max(max_n, dp2[i]);
        }
        dp2[n-1] = max_n + nums[n-1];
        dp[n-1] = dp2[n-1];

        max_n = INT_MIN;
        for (int i = 0; i < n; i++) max_n = max(max_n, dp[i]);

        return max_n;
    }
};