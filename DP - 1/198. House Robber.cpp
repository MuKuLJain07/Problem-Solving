// Recursion : 
class Solution {
private:
    int robHelper(vector<int> &nums, int i){
        if(i==0) return nums[0];
        if(i<0) return 0;

        int pick = nums[i] + robHelper(nums,i-2);
        int notPick = 0 + robHelper(nums,i-1);
        
        return max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return robHelper(nums,n-1);
    }
};


// Memoization :
class Solution {
private:
    int robHelper(vector<int> &nums, int i, vector<int> &dp){
        if(i<0) return 0;
        if(i==0) return dp[0] = nums[0];

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + robHelper(nums,i-2,dp);
        int notPick = 0 + robHelper(nums,i-1,dp);
        
        return dp[i] = max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return robHelper(nums,n-1,dp);
    }
};


// Dynamic Programming : 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);

        dp[0] = nums[0];

        for(int i = 1; i < n; i++){
            if(i-2 < 0){
                dp[i] = max(dp[i-1], nums[i]);
            }
            else{
                dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
            }
        }
        return dp[n-1];
    }
};



// Space Optimized DP : 
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = INT_MIN;
        int prev2 = nums[0];

        for(int i = 1; i < n; i++){
            int temp;
            if(i-2 < 0){
                temp = max(prev2 ,nums[i]);
            }
            else{
                temp = max(prev2,prev1 + nums[i]);
            }
            prev1 = prev2;
            prev2 = temp;
        }
        return prev2;
    }
};