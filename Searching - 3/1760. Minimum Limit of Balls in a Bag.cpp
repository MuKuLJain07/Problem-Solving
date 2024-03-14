class Solution {
private:
    bool isPossible(vector<int>& nums, int maxOperations, int mid){
        int noOfOperations = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > mid){
                noOfOperations+=((nums[i]-1)/mid);
            }
        }
        if(noOfOperations<=maxOperations){
            return true;
        }
        return false;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = *max_element(nums.begin(), nums.end());
         
        while(high>=low){
            int mid = (low + high)/2;
            if(isPossible(nums,maxOperations,mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};