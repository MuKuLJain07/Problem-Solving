class Solution {
private:
    bool isPossible(vector<int> bloomDay, int m, int k, int mid){
        for(int i = 0 ; i < bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                bloomDay[i] = -1;
            }
        }
        for(int i = 0 ; i < bloomDay.size(); i++){
            if(bloomDay[i] == -1 ){
                int temp = 1;
                for(int j =i+1;j<k-1;j++){
                    if(bloomDay[j] == -1)
                    temp++;
                }
                if(temp == k){
                    m--;
                    i+=(k-1);
                }
            }
        }
        if(m==0){
            return 1;
        }
        return 0;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(high >= low){
            int mid = (low+high)/2;
            if(isPossible(bloomDay,m,k,mid)){
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