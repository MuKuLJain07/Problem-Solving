class Solution {
public:
    int searchFirstOccurence(vector<int>& arr, int target){
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        int ans = -1;

        while(e>=s){
            if(arr[mid]==target){
                ans = mid;
                e = mid-1;
            }
            else if(arr[mid]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }

            mid = s + (e-s)/2;
        }

        return ans;
    }

    int searchLastOccurence(vector<int>& arr, int target){
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        int ans = -1;

        while(e>=s){
            if(arr[mid]==target){
                ans = mid;
                s = mid+1;
            }
            else if(arr[mid]>target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }

            mid = s + (e-s)/2;
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int> res;
        int left = searchFirstOccurence(nums,target);
        int right = searchLastOccurence(nums,target);
        res.push_back(left);
        res.push_back(right);

        return res;
    }
};