class Solution {
public:
    int climbStairs(int n) {
        vector<int> a(n+2);
        a[0]=0;
        a[1]=1;
        a[2]=2;
        for (int i = 3; i <= n; i++){
            a[i] = a[i-2] + a[i-1];
        }

        return a[n];
    }
};