class Solution {
public:
    int n;
    int visited[29];
    vector<int> curr;
    vector<int> cur_n;
    vector<vector<int>> kq;

    bool check(int i, int k){
        if (k == 0) return true;
        if (i <= curr[k-1]) return false;

        return !visited[i];
    }    

    void Try(int k, vector<int>& nums){
        for (int i = 0; i < n; i++){
            if (check(i, k)){
                curr.push_back(i);
                cur_n.push_back(nums[i]);
                visited[i] = 1;
                kq.push_back(cur_n);

                if (k < n) Try(k+1, nums);
                visited[i] = 0;
                curr.pop_back();
                cur_n.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        
        kq.push_back(vector<int>());
        Try(0, nums);
        
        set<vector<int>> uniqueSubsets(kq.begin(), kq.end());
        kq.assign(uniqueSubsets.begin(), uniqueSubsets.end()); 
        return kq;
    }
};