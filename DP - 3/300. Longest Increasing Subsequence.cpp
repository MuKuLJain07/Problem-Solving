// Recursive
class Solution {
private:
    int solve(vector<int> &nums, int curr_idx, int prev_idx){
        if(curr_idx >= nums.size()) return 0;

        int take = -1e9;
        if(prev_idx == -1 || nums[prev_idx] < nums[curr_idx]){
            take = 1 + solve(nums,curr_idx+1, curr_idx);
        }

        int notTake = 0 + solve(nums, curr_idx+1, prev_idx);

        return max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return solve(nums,0,-1);    // array, curr_idx, prev_idx
    }
};

// Memoization
class Solution {
private:
    int solve(vector<int> &nums, int curr_idx, int prev_idx,vector<vector<int>> dp){
        if(curr_idx >= nums.size()) return 0;

        if(dp[curr_idx][prev_idx+1] != -1) return dp[curr_idx][prev_idx+1];

        int take = -1e9;
        if(prev_idx == -1 || nums[prev_idx] < nums[curr_idx]){
            take = 1 + solve(nums,curr_idx+1, curr_idx,dp);
        }

        int notTake = 0 + solve(nums, curr_idx+1, prev_idx,dp);
        
        dp[curr_idx][prev_idx+1] = max(take,notTake);
        return dp[curr_idx][prev_idx+1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return solve(nums,0,-1,dp);    // array, curr_idx, prev_idx
    }
};


// Binary Search
class Solution {
private:
    int findLowerBound(vector<int> temp, int num){
        int low = 0;
        int high = temp.size()-1;
        int index;
        while(high>=low){
            int mid = (low+high)/2;

            if(temp[mid] == num) return mid;
            if(temp[mid] > num){
                index = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return index;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > temp[temp.size()-1]){
                temp.push_back(nums[i]);
            }
            else{
                int index = findLowerBound(temp, nums[i]);
                temp[index] = nums[i];
            }
        }

        return temp.size();
    }
};