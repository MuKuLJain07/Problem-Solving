// Recursion
class Solution {
private:
    int lengthOfLongestSubsequenceHelper(vector<int>& nums, int target, int i){
        if(i >= nums.size() || target < 0) return INT_MIN;
        if(target == 0) return 0;

        int take = 1 + lengthOfLongestSubsequenceHelper(nums,target - nums[i], i+1);
        int notTake = 0 + lengthOfLongestSubsequenceHelper(nums, target, i+1);

        return max(take, notTake);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int ans =  lengthOfLongestSubsequenceHelper(nums, target, 0);
        if(ans <= 0) return -1;
        return ans;
    }
};


// Memoization
class Solution {
private:
    int lengthOfLongestSubsequenceHelper(vector<int>& nums, int target, int i, vector<vector<int>> &dp) {
        if (i >= nums.size()) return INT_MIN;
        if (target == 0) return 0;
        if (target < 0) return INT_MIN; 

        if(i == nums.size()-1 && nums[i] == target) return 1;

        if (dp[i][target] != -1) return dp[i][target];

        int take = INT_MIN;
        if (nums[i] <= target) {
            take = 1 + lengthOfLongestSubsequenceHelper(nums, target - nums[i], i + 1, dp);
        }
        int notTake = lengthOfLongestSubsequenceHelper(nums, target, i + 1, dp);

        return dp[i][target] = max(take, notTake);
    }
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        int ans = lengthOfLongestSubsequenceHelper(nums, target, 0, dp);

        if (ans <= 0) return -1;
        return ans;
    }
};
