class Solution{
    public:  
	int NthRoot(int n, int m){
	    if(m==1){
	        return 1;
	    }
	    if(n==1){
	        return m;
	    }
	    int ans = -1;
	    for(int i = 1; i <= m/n; i++){
	        int temp = 1;
	        for(int j = 0; j < n; j++){
	            temp*=i;
	        }
	        if(temp>m){
	            break;
	        }
	        else if(temp==m){
	            ans = i;
	        }
	    }
	    return ans;
	}  
};