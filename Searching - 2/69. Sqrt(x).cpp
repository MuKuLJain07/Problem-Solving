// O(root n) time complexity solution

// class Solution {
// public:
//     int mySqrt(int x) {
//         int i;
//         for(i = 0; i < x; i++){
//             if(i*i > x){
//                 break;
//             }
//         }

//         return i-1;
//     }
// };



// O(logn) Time complexity

class Solution {
public:
    long long int Sqrt(int x){
        int s = 0;
        int e = x;
        long long int mid = s + (e-s)/2;
        long long int ans;
        while(e>=s){
            if(mid*mid == x){
                ans = mid;
                break;
            }
            else if(mid*mid > x){
                e = mid - 1;
            }
            else{
                s = mid+1;
                ans = mid;
            }
            mid = s + (e-s)/2;
        }

        return ans;
    }
    int mySqrt(int x) {
        return Sqrt(x);
    }
};