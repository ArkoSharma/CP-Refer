#include <bits/stdc++.h>
using namespace std;
#define N 13
#define set_solved(a,b) a=((a)|(1<<(b)))
#define solved_already(a,b) ((a)&(1<<b))
#define set_unsolved(a,b) a=((a) & (~(1<<(b))))
#define fo(i,a,b) for(int i=a;i<b;i++)
int times[4][309];
int dp[15][300][1<<13];

//time 1 to 280
//probs 1 to n 
//ppl 1,2,3
int max_probs(int tim_consumed,int last_tosol,int solvd_probs,int numProbs){
    
    
    if(tim_consumed>=280){
     return 0;
    }
    //memoized results
    if( last_tosol>=1 &&  dp[last_tosol][tim_consumed][solvd_probs]!=-1) return dp[last_tosol][tim_consumed][solvd_probs] ;
    
    //else compute dp 
    dp[last_tosol][tim_consumed][solvd_probs]=-1;
    int ma=0;
    fo(i,1,4){
        if(i!=last_tosol){
            fo(j,1,numProbs+1){
                if(!(solved_already(solvd_probs,j))){
                        //solve j with person i,and dig deeper
                        if(times[i][j]+tim_consumed<=280){
                            set_solved(solvd_probs,j);
                            ma=max(ma,1+max_probs(tim_consumed+times[i][j],i,solvd_probs,numProbs));
                            //for next person i
                            set_unsolved(solvd_probs,j);      
                        }
			
                }
                
            }
        }
    }
    
    //its possible that m is still zero
    return last_tosol>=1? (dp[last_tosol][tim_consumed][solvd_probs]=ma) : ma;
    
}
int main() {
	int t,n;
//	cin.tie(NULL);
        scanf("%d",&t);
        
	while(t--){
	    scanf("%d",&n);
	    fo(j,1,4){
		      fo(i,1,n+1){
	            scanf("%d",&times[j][i]);

	        }
	    }
	    memset(dp,-1,sizeof dp);
	    printf("%d\n",max_probs(0,0,0,n));
	}
	return 0;
}

