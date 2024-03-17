class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums[0] != nums[1]){
            return nums[0];
        }
        if(nums[nums.size()-1] != nums[nums.size()-2]){
            return nums[nums.size()-1];
        }

        int i = 0;
        int j = nums.size()-1;

        while(j>=i){
            int mid = (i+j)/2;

            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }

            // first occurence
            else if(nums[mid] != nums[mid-1] && (mid%2==0)){
                i = mid+1;
            }
            else if(nums[mid] != nums[mid-1] && (mid%2!=0)){
                j = mid-1;
            }

            // second occurence
            else if(nums[mid] == nums[mid-1] && ((mid-1)%2==0)){
                i = mid+1;
            }
            else if(nums[mid] == nums[mid-1] && ((mid-1)%2!=0)){
                j = mid-1;
            }
        }
        return -1;
    }
};