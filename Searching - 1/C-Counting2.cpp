#include <iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &heights, int key){
    int lb = 0;
    int ub = heights.size()-1;
    while(ub>=lb){
        int mid = lb + (ub-lb)/2;
        if(heights[mid] == key){
            return mid;
        }
        else if(heights[mid] > key){
            ub = mid-1;
        }
        else{
            lb = mid+1;
        }
    }
    return -1;
}
void cCounting(int N, int Q, vector<int> &heights, vector<int> &testCases){
    for(int i = 0; i < Q; i++){
        int firstOccurence = binarySearch(heights, testCases[i]);
        if(firstOccurence == -1){
            cout<<0<<endl;
        }
        else{
            cout<<heights.size() - firstOccurence<<endl;
        }
    }
}

int main(){
    int N;
    int Q;
    vector<int> heights;
    vector<int> testCases;
    cin >> N >> Q;
    
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        heights.push_back(temp);
    }
    for(int i = 0; i < Q; i++){
        int temp;
        cin >> temp;
        testCases.push_back(temp);
    }
    cout<<endl;
    cCounting(N, Q, heights, testCases);
    return 0;
}