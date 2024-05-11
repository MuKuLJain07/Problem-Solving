class Solution {
private:
    int robHelper(vector<int>& nums) {
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
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        
        vector<int> temp1,temp2;

        for(int i = 1; i < n; i++){
            temp1.push_back(nums[i]);
        }
        for(int i = 0; i < n-1; i++){
            temp2.push_back(nums[i]);
        }

        return max(robHelper(temp1), robHelper(temp2));
    }
};