#include <bits/stdc++.h>
using namespace std;

int maxProfit(int n, vector<int> &wines, int i, int j, int year){     // returns the max profit by selling wines from index i to j
    if(i > j) return 0;
    if(i == j){
        return wines[i] * year;
    } 

    int SoldBeg = wines[i] * year + maxProfit(n, wines, i+1, j, year+1);
    int SoldEnd = wines[j] * year + maxProfit(n, wines, i, j-1, year+1); 
    
    if(SoldBeg > SoldEnd){
        return SoldBeg;
    } 
    return SoldEnd;
}

int main(){
    int n;
    cin >> n;
    vector<int> wines(n);
    for(int i = 0; i < n; i++){
        cin >> wines[i];
    }

    cout<<"Maximum profit : "<< maxProfit(n, wines , 0 , n-1, 1)<<endl;
    return 0;
}