class Solution {
public:
    int n;
    vector<int> visited;
    vector<int> b;
    vector<vector<int>> kq;

    bool check(int i) {
        return !visited[i];
    }

    void Try(int k, vector<int>& nums) {
        for (int i = 0; i < n; i++) { 
            if (check(i)) {
                visited[i] = true;
                b.push_back(nums[i]);

                if (k == n) {
                    kq.push_back(b);
                } else {
                    Try(k + 1, nums);
                }

                visited[i] = false; 
                b.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        visited.resize(n, 0);
        Try(1, nums);
        return kq;
    }
};
