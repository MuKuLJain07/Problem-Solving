class Solution {
public:
    int jump(vector<int>& nums) {
        // DP
        int n = nums.size();
        vector<int> steps(n, INT_MAX);

        steps[n-1] = 0;
        
        for(int i = n-2; i >= 0; i--){
            int val = INT_MAX;
            for(int j = 1; j <= nums[i]; j++){
                if(i+j < n){
                    val = min(val, steps[i+j]);
                }
                else{
                    break;
                }
            }
            if (val != INT_MAX) {
                steps[i] = val + 1;
            }
        }

        return steps[0];
    }
};