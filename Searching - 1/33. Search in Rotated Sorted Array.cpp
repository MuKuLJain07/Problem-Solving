class Solution {
public:
    int BinarySearch(vector<int>& nums, int start, int end,int target){
        int s = start;
        int e = end;
        int mid = s + (e-s)/2;

        while(e>=s){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid] > target){
                e = mid -1;
            }
            else{
                s = mid+1;
            }
            mid = s + (e-s)/2;
        }

        return -1;
        
    }
    int search(vector<int>& nums, int target) {
        // Find Pivot Element
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e-s)/2;
        while(s<e){
            if(nums[mid]>=nums[0]){
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }

        int ans = -1;
        if(target >= nums[s] && target <= nums[nums.size()-1]){
            ans = BinarySearch(nums,s,nums.size()-1,target);
        }
        else{
            ans = BinarySearch(nums,0,s,target);
        }
        return ans;
    }
};