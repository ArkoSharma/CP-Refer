/*inefficient solution depicting MCM idea*/

#include <bits/stdc++.h>
using namespace std;
char s[6109];
int dp[6109][6109];
#define fo(i,a,b) for(int i=a;i<b;i++)
int main() {
    int t;
    cin>>t;
    while(t--){
        scanf(" %[^\n]s",s+1); //store from 1 to len
        // idea is as follows:
        // dp[i][j] = dp[i+1][j-1] if s[i]==s[j]
        // else
        //          = min(1+dp[i+1][j],dp[i][j-1]+1) ..adding either at last or at first
        
        int len=strlen(s+1);
        fo(i,1,len+1){
            dp[i][i]=0;
            if(i+1<= len)
                dp[i][i+1] =s[i]==s[i+1]?0:1; //base cases
        }
        fo(l,3,len+1){  // l stores length of chain
			  // here length 2 chains already inc in base so start from l=3 (if not start from l=2)


            fo(i,1,len-l+1 +1){ // i is the starting point of the sub-chain

			        	

                int j=i+l-1;// j is the ending point of the sub-chain

			   
                          //   length l but i included so add l-1


                for(int k=i;k<=j;k++){       // k is the partition point  (should go from i to j-1 )     
                    if(s[i]==s[k]){
                       dp[i][k]=dp[i+1][k-1];
                    }
                    else{
                       dp[i][k]=min(1+dp[i+1][k],dp[i][k-1]+1); // fft === min dp (f + dp[ft], t+dp[ff])
                    }
                }
            }
        }
//      cout<<len<<endl;
        cout<<dp[1][len]<<endl;
    }
	return 0;
}

/*More efficient solution  using LCS*/
#include <bits/stdc++.h>
using namespace std;
char s[6109];
int lcs[6109][6109];
#define fo(i,a,b) for(int i=a;i<b;i++)
int main() {
    int t;
    cin>>t;
    while(t--){ 
        scanf(" %[^\n]s",s+1);
        int len=strlen(s+1);
        fo(i,0,len+1){
            lcs[i][0]=0;
		    }
        
        fo(i,0,len+1){
            lcs[0][i]=0;
        }
    
        fo(i,1,len+1){
            fo(j,1,len+1){
                    if(s[i]==s[len-j+1]){
                       lcs[i][j]=1+lcs[i-1][j-1];
                    }
                    else{
                       lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                        
                    }
                }
            }
        cout<<len-lcs[len][len]<<endl;
    }
	return 0;
}

