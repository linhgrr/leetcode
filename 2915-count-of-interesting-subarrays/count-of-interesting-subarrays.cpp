class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long n = nums.size();
        unordered_map<long long, long long> prefixCount;
        prefixCount[0] = 1;
        long long currentPrefix = 0;
        long long result = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] % modulo == k) {
                currentPrefix++;
            }
            long long targetPrefix = (currentPrefix - k + modulo) % modulo;
            if (prefixCount.find(targetPrefix) != prefixCount.end()) {
                result += prefixCount[targetPrefix];
            }
            prefixCount[currentPrefix % modulo]++;
        }

        return result;
    }
};