// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        size_t numsLength = nums.size();

        if (numsLength == 0)
            return 0;
        if (numsLength == 1)
            return nums[0];

        int sum = 0;
        int maxSum = nums[0];

        for (int num : nums) {
            if (sum <= 0)
                sum = num;
            else
                sum += num;
            if (sum > maxSum)
                maxSum = sum;
        }

        return maxSum;
    }
};