class Solution {
public:
    int n, k;
    int cur_sum = 0;
    vector<int> curr;
    vector<int> curr_i;
    vector<vector<int>> kq;
    
    bool check(int i, int u, vector<int>& a){
        if (cur_sum + a[i] > k) return false;
        if (u == 0) return true;
        if (i <= curr_i[u-1]) return false;

        return true;
    }

    void Try(int u, vector<int>& a){
        if (u == n) return;
        for (int i = 0; i < n; i++){
            if (u >= 1) if (i > 0 && a[i] == a[i - 1] && curr_i[u-1] != i - 1) continue;

            if (check(i, u, a)){
                curr.push_back(a[i]);
                cur_sum += a[i];
                curr_i.push_back(i);

                if (cur_sum == k){
                    kq.push_back(curr);
                } else if (cur_sum < k) Try(u+1, a);

                curr.pop_back();
                cur_sum -= a[i];
                curr_i.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        k = target;

        int sum = 0;
        for (auto i: candidates) sum += i;
        if (sum < target) return vector<vector<int>>();

        Try(0, candidates);
        set<vector<int>> uniqueSubsets(kq.begin(), kq.end());
        kq.assign(uniqueSubsets.begin(), uniqueSubsets.end()); 

        return kq;
    }
};