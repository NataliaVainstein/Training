// https://leetcode.com/problems/3sum/description/

class Solution {
public:

    void setNextStartIdx(vector<int>& nums, size_t& startIdx, size_t n) {
        ++startIdx;

        while ((startIdx < n) && (nums[startIdx - 1] == nums[startIdx]))
            ++startIdx;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        size_t n = nums.size();
        for (size_t runningIdx = 0; runningIdx < n - 2; ++runningIdx) {
            if ((runningIdx == 0) || (nums[runningIdx - 1] != nums[runningIdx])) {
                size_t startIdx = runningIdx + 1;
                size_t endIdx = n - 1;
                while (startIdx < endIdx) {
                    int resSum = nums[runningIdx] + nums[startIdx] + nums[endIdx];
                    if (resSum == 0) {
                        result.push_back({ nums[runningIdx], nums[startIdx], nums[endIdx] });
                        setNextStartIdx(nums, startIdx, n);
                    }
                    else if (resSum < 0)
                        ++startIdx;
                    else
                        --endIdx;
                }
            }
        }

        return result;
    }
};