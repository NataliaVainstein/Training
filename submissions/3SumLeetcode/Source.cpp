#include <vector>
#include <algorithm>
#include<iostream>

using namespace std;

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


void printRes(vector<vector<int>>& res) {
	cout << "NUM RES VEC: " << res.size() << "\n";
	for (vector<int> vec : res) {
		for (int i : vec)
			cout << i << " ";
		cout << "\n";
	}
}
int main() {
	vector<int> v1 = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> res1 = threeSum(v1);
	printRes(res1);

	vector<int> v2 = { 0, 1, 1 };
	vector<vector<int>> res2 = threeSum(v2);
	printRes(res2);

	vector<int> v3 = { 0, 0, 0 };
	vector<vector<int>> res3 = threeSum(v3);
	printRes(res3);

	vector<int> v4 = { -1, -1, -1, -1, 2 };
	vector<vector<int>> res4 = threeSum(v4);
	printRes(res4);

	vector<int> v5 = { -2, 2, 2, 2, 0 };
	vector<vector<int>> res5 = threeSum(v5);
	printRes(res5);

	return 0;
}