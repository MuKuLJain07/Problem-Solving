class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        if(nums[0] > nums[1]){
            return 0;
        }

        int size = nums.size();
        if(nums[size-1] > nums[size-2]){
            return size-1;
        }


        int low = 0;
        int high = nums.size()-1;
        
        while(high>=low){
            int mid = (low + high)/2;
            if(mid-1 >= 0 && ((mid+1) < size) && nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(mid-1 >= 0 && mid+1 < size && nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                low = mid+1;
            }
            else if(mid-1 >= 0 && mid+1 < size && nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1]){
                high = mid-1;
            }
            else if((mid-1) < 0){
                low = mid+1;
            }
            else if((mid+1) > (size-1)){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
};