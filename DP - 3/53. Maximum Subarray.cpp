// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int sum = 0;
//         int maxi = nums[0];

//         for(int i = 0; i < nums.size(); i++){
//             sum+=nums[i];
//             maxi = max(maxi, sum);

//             if(sum<0){
//                 sum = 0;
//             }
//         }

//         return maxi;
//     }
// };

// kadane's algo


// dp solution
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if(nums.size() == 0) return 0;
//         vector<int> dp(nums.size(), 0);
//         dp[0] = nums[0];

//         for(int i = 1;  i < nums.size(); i++){
//             dp[i] = max(nums[i], nums[i] + dp[i-1]);
//         }

//         return *max_element(dp.begin(), dp.end());
//     }
// };


// dp solution --> optimized
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        int prev = nums[0];
        int ans = nums[0];
        for(int i = 1;  i < nums.size(); i++){
            int curr = max(prev+nums[i], nums[i]);
            ans = max(ans, curr);
            prev = curr;
        }

        return ans;
    }
};