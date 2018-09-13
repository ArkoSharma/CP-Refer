// UP IM'P'

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define fo(i,a,b) for(int i=a;i<b;i++)

using namespace std;


class IncreasingSequencesEasy {
public:
    const int md=998244353;
    int dp[300][10003];
    vector<int> l,r;
    long long int get(int i,int j){
        if(i>=0 && j>=0 && dp[i][j]!=-1) return dp[i][j];
    	if(i<0) return 0;
    	else if(i==0) {
    		if(j>=l[i] && j<=r[i]){
    			return dp[i][j]=1;
    		}
    		else if(j>=0) return dp[i][j]=0;
    	}
    	else{
    	   
    		if(j<l[i] ) return dp[i][j]=0;
    		else if(j==l[i] ){
    			int sum=0;
    			fo(k,1,j){
    				sum=(sum+get(i-1,k))%md;
    			}
    			return dp[i][j]=sum;
    		}
    		else if(j<=r[i]){
    			return dp[i][j]=(get(i,j-1)%md+get(i-1,j-1)%md)%md;
    		}
    		else return dp[i][j]=0;
    	}
    }
	int count(vector <int> L, vector <int> R) {
	  int ans=0;
	  memset(dp,-1,sizeof(dp));
	  l=L,r=R;
	  dp[0][L[0]]=1;
	  fo(i,L[L.size()-1],R[L.size()-1]+1)
	    ans=(ans+get(L.size()-1,i))%md;
	  return ans%md;
		
	}
};

