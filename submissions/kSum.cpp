/* Response to 3Sum follow up question: 
While this solution works, what will happen if, in a follow-up question, you are asked to solve sum4?

You have the loop that provides the first possible number, let's call it "a"
You would like to get to a state where a + b + c = n
or:
b + c = n - a

the leetcode question twoSum(array, n) is considered easy

Can you think of a way in which you can solve the sum-k problem using a sub-problem of sum-k-1 ? in such a way that eventually you will get to use twoSum?
*/

void setNextStartIdx(vector<int>& nums, size_t& startIdx, size_t endIdx) {
    ++startIdx;

    while ((startIdx < endIdx) && (nums[startIdx - 1] == nums[startIdx]))
        ++startIdx;
}

vector<vector<int>> twoSumWithSortedNums(vector<int>& nums, int target, size_t startIdx, size_t endIdx) {
    vector<vector<int>> result;
    while (startIdx < endIdx) {
        int resSum = nums[startIdx] + nums[endIdx];
        if (resSum == target) {
            result.push_back({nums[startIdx], nums[endIdx] });
            setNextStartIdx(nums, startIdx, endIdx);
        }
        else if (resSum < target)
            ++startIdx;
        else
            --endIdx;
    }
        
    return result;
};

vector<vector<int>> kSumWithSortedNums(vector<int>& nums, int target, size_t startIdx, size_t endIdx, int k) {
    vector<vector<int>> result;
    if (k == 2) {
        return twoSumWithSortedNums(nums, target, startIdx, endIdx);
    }
    for (size_t i = startIdx; i < endIdx; ++i) {
        if ((i == startIdx) || (nums[i - 1] != nums[i])) {
            vector<vector<int>> subResult = kSumWithSortedNums(nums, target - nums[i], i + 1, endIdx, k - 1);
            for (vector<int> vec : subResult) {
                vec.push_back(nums[i]);
                result.push_back(vec);
            }
        }
    }

    return result;
}

vector<vector<int>> kSum(vector<int> nums, int target, int k) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result = kSumWithSortedNums(nums, target, 0, nums.size() - 1, k);
    return result;
}