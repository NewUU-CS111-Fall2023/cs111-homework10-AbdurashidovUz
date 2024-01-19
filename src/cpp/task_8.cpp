#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty() || nums.size() < 2) {
            return false;
        }

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int targetSum = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(targetSum + 1, -1));

        return equalSumPartition(nums, targetSum, 0, dp) > 0;
    }

private:
    int equalSumPartition(const vector<int>& nums, int sum, int index, vector<vector<int>>& dp) {
        if (index > nums.size() - 1) {
            return 0;
        }

        if (sum == 0) {
            return 1;
        }

        if (dp[index][sum] != -1) {
            return dp[index][sum];
        }

        if (nums[index] <= sum) {
            return dp[index][sum] = equalSumPartition(nums, sum - nums[index], index + 1, dp)
                | equalSumPartition(nums, sum, index + 1, dp);
        } else {
            return dp[index][sum] = equalSumPartition(nums, sum, index + 1, dp);
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 5, 11, 5};

    bool result = solution.canPartition(nums);

    if (result) {
        cout << "Array can be partitioned into two subsets with equal sum.\n";
    } else {
        cout << "Array cannot be partitioned into two subsets with equal sum.\n";
    }

    return 0;
}
