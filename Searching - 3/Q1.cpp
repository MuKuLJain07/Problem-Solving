// You have given an array A having N elements and an integer S. You have to find a maximum number X such that the sum of all its subarrays of size X is less than or equal to S.
// Example Input:  
//     A = [1, 3, 4, 2]  
//     S = 7  
// Example Output:  
//     2  
// Explanation:  
//     All subarrays of size 2 have the sum less than 7.  
//     Subarays are :  
//     1. [1, 3]  
//     2. [3, 4]  
//     3. [4, 2]  


#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector <int> A, int N, int S, int potentialAns){
    int temp = 0;
    for(int i = 0; i < potentialAns;i++){
        temp+=A[i];
    }
    if(temp>S){
        return 0;
    }


    for(int i = potentialAns; i < N;i++){
        temp+=A[i];
        temp-=A[i-potentialAns];
        if(temp>S){
            return 0;
        }
    }
    return 1;
}

int maxSizeSubArray(vector <int> A, int N, int S){

    int low = 1;
    int high = N;
    int ans = -1;

    while(high >= low){
        int mid = (low+high)/2;

        if(isPossible(A,N,S,mid)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return ans;
}

int main(){
    int S;
    int N;
    vector<int> A;

    cin >> N >> S;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        A.push_back(temp);
    }

    cout<<maxSizeSubArray(A,N,S);

    return 0;
}