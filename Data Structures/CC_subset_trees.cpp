#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
using ll = long long;
int n;
vector<int> adj[100004];
int p[100004],par[100004],sz[100004];
void root(int a,int b){
	p[a]=b;
	for(auto c : adj[a]){
		if(c!=b)
  		   root(c,a);
	}
}
int get(int x){
	return x == par[x] ? x : par[x] = get(par[x]);
}
int unionn(int x,int y){
	x = get(x);
	y = get(y);
	if(x == y ) return sz[x];
	else {
		if(sz[x] < sz[y]){
			swap(x,y);
		}
	 	sz[x]+=sz[y];
		par[y]=x;
		return sz[x];

	}
}
void init(){
	fo(i,1,n+1){
		adj[i].clear();
	}
	fo(i,0,n-1){
		int a,b;
		cin>>a>>b;
		adj[0]=std::vector<int> ();
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fo(i,1,n+1){
		par[i]=i;
		sz[i]=1;
	}
}
void solve(){
	long long res = 0;
  root(1,1);
	fo(i,1,n+1){
		int mx = 1;
		for(int j=i; j<= n; j=(i|(j+1))){
			int pp = p[j];
			if((pp & i)==i) mx = max(mx,unionn(j,pp));

		}
		res = max(res,1LL * mx *i);
		for(int j=i; j<=n; j=(i|(j+1))){
			par[j]=j;
			sz[j]=1;
		}
	}
	cout<<res<<"\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
	    cin>>n;
	    init();
	    solve();
    }
}
