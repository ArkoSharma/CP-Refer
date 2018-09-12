//http://codeforces.com/contest/369/problem/C

/*marking all endpoints of bad edges , dp[i] = no of white vertices in the subtree of i
	So, dp[i] = 1 or 0 + summatn ( dp (children of i ))

  claim=== we need only consider the WHITE vertices whose dp[i]=1 ie they have no white vertices in their subtree 
  		   other than themselves.

  proof== log
 */

#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<b;i++)
#define fi first
#define se second
const int N=100009;
vector<int> adj[N],ans;
int white[N];
int dp[N];

void dfs(int a,int pa){
	if(white[a]==1){
		dp[a]=1;
	}
	else
		dp[a]=0;
	for(int v: adj[a]){
		if(v!=pa && v!=-1){
			dfs(v,a);
			dp[a]+=dp[v];
		}
	}
	if(dp[a]==1 && white[a]==1){
		ans.push_back(a);
	}

}

int main(){
	int n,x,y,z;
	scanf("%d",&n);
	fo(i,0,n+1){
		adj[i].push_back(-1);
	}
	fo(i,1,n){
		scanf("%d %d %d",&x,&y,&z);
		adj[x].push_back(y);
		adj[y].push_back(x);
		if(z==2){
			white[x]=white[y]=1;
		}
	}
	//for tree dp types
	dfs(1,0);
	int c=0;
	cout<<(int)ans.size()<<endl;
	for(auto it: ans){
		cout<<it<<' ';
	}


	return 0;
}
