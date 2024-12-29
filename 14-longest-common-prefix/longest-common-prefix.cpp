class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";

        if (strs.size() == 1) return strs[0];

        for (int i = 0; i < strs[0].size(); i++){
            char tmp = strs[0][i];
            bool isOke = true;
            for (int j = 1; j < strs.size(); j++){
                if (strs[j][i] != tmp){
                    isOke = false;
                    break;
                }
            }

            if (isOke) s += tmp;
            else break;
        }

        return s;
    }
};