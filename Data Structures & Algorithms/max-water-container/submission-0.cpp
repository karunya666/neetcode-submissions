class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        int i = 0;
        int j = n - 1;
        while (i < j) {
            int temp = 0;
            temp = (j - i) * min(heights[i], heights[j]);
            ans = max(ans, temp);
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};
