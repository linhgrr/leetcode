class Solution {
public:
    int sum = 0;
    int n, k;
    vector<int> curr;
    vector<int> a;
    vector<vector<int>> kq;

    bool check(int num){
        if (sum + num > k) return false;
        return true;
    }

    void try_num(int u){
        for (int i = 0; i < n; i++){
            if (check(a[i])){
                curr.push_back(a[i]);
                sum += a[i];
                if (sum == k){
                    vector<int> tmp;
                    for (auto i: curr) {
                        if (i != 0) tmp.push_back(i);
                    }
                    kq.push_back(tmp);
                } else if (sum < k) try_num(u+1);

                curr.pop_back();
                sum -= a[i];
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    n = candidates.size();
    k = target;
    a.resize(n);

    int min_num = INT_MAX;
    for (int i = 0; i < n; i++) {
        a[i] = candidates[i];
        if (a[i] > 0) { // Chỉ xét các giá trị dương
            min_num = min(min_num, a[i]);
        }
    }

    if (min_num == INT_MAX || min_num == 0) { 
        // Không có phần tử nào hợp lệ hoặc tất cả phần tử đều bằng 0
        return {}; 
    }

    sort(a.begin(), a.end());
    int u = k / min_num + 1;
    curr.resize(u);
    try_num(0);

    for (auto &a: kq) {
        sort(a.begin(), a.end());
    }

    set<vector<int>> last_kq;
    for (auto a: kq) {
        last_kq.insert(a);
    }

    vector<vector<int>> last_last;
    for (auto a: last_kq) last_last.push_back(a);

    return last_last; 
}

};