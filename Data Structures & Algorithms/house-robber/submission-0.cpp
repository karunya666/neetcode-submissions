class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n + 1, 0);
        t[0] = 0;
        t[1] = nums[0];
        for (int i = 2; i < n + 1; i++) {
            t[i] = max(t[i - 2] + nums[i - 1], t[i - 1]);
        }
        return t[n];
    }
};
