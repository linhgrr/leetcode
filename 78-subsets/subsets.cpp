class Solution {
public:
    vector<int> tmp;
    int visited[12];
    vector<int> curr;
    vector<vector<int>> kq;


    bool check(int i, int k){
        if (k == 0) return true;
        if (tmp[i] <= curr[k-1]) return false;

        return !visited[i];
    }

    void Try(int k){
        for (int i = 0; i < tmp.size(); i++){
            if (check(i, k)){
                curr.push_back(tmp[i]);
                kq.push_back(curr);
                visited[i] = 1;

                if (k < tmp.size()){
                    Try(k+1);
                }

                curr.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        set<int> a;
        for (auto i: nums) a.insert(i);

        tmp.assign(a.begin(), a.end());
        kq.push_back(vector<int>()); 

        Try(0);

        return kq;
    }
};