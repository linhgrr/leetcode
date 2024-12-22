class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int dp[20005];

        dp[0] = 1;
        for (int i = 1; i < n; i++){
            int max_n = 0;
            for (int j = 0; j < i; j++){
                if (nums[j] < nums[i]){
                    max_n = max(max_n, dp[j]);
                }
            }
            dp[i] = max_n + 1;
        }

        int max_n = -1;
        for (int i = 0; i < n; i++) max_n = max(max_n, dp[i]);

        return max_n;
    }
};