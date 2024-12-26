class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int dp[200];
        if (s[0] == '0'){
            return 0;
        } else {
            dp[0] = 1;
        }
        for (int i = 1; i < n; i++){
            if (s[i] == '0'){
                string tmp = string(1, s[i-1]) + "0";
                int tmp_num = stoi(tmp);
                if (10 <= tmp_num && tmp_num <= 26) {
                    if (i >= 2) dp[i] = dp[i-2];
                    else dp[i] = 1;
                } else return 0;
            } else {
                dp[i] = dp[i-1];
                string tmp = string(1, s[i-1]) + string(1, s[i]);
                int tmp_num = stoi(tmp);
                if (10 <= tmp_num && tmp_num <= 26) {
                    if (i >= 2) dp[i] += dp[i-2];
                    else dp[i] ++;
                }
            }
        } 

        return dp[n-1];  
    }
};