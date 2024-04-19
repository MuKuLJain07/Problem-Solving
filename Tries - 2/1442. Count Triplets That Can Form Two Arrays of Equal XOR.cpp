class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans=0;
        for(int i = 0; i < arr.size()-1; i++){
            int x = 0;
            for(int k=i;k<arr.size();k++){
                x^=arr[k];
                if(x==0){
                    ans+=(k-i);
                }
            }
        }
        return ans;
    }
};