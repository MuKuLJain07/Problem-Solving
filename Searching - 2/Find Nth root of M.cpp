class solution{ 
    private:
    int powerOf(int a, int b){
    
    }
    
    long long int fast_exponential(int a, int b){
       long long int res = 1;

        while(b>0){
            // odd
            if(b&1){
                res = res*a;
            }
            a = a*a;
            b = b>>1;
        }

        return res;
    }
    
    
	public:  
	int NthRoot(int n, int m){
	   // base condition
	    if(m==1){
	        return 1;
	    }
	    if(n==1){
	        return m;
	    }
	    
	    int ans = -1;
	    
	    for(int i = 1; i <= m/n; i++){
	       int temp = fast_exponential(i,n);
	        if(temp>m){
	            break;
	        }
	        else if(temp==m){
	            ans = i;
	        }
	    }
	    
	   // int low = 1; 
	   // int high = (m/n)+1;
	   // while(high>=low){
	   //     int mid = (low+high)/2;
	   //     long long int temp = fast_exponential(mid,n);
	   //     if(temp==m){
	   //         ans = mid;
	   //         break;
	   //     }
	   //     else if(temp>m){
	   //         high = mid-1;
	   //     }
	   //     else{
	   //         low = mid+1;
	   //     }
	   // }
	    return ans;
	}  
};