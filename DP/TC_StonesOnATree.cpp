// tree,
// each v has weights,
// game-in each turn , remove or add a stone to a node of the tree
// for a node to have a stone, all its children need to have a stone
// cost of a state of the tree = sum of weights of all v's with stones
// find minimum value of the maximum-cost that the tree can have for winning the game(placing a stone on root).

// solution- dp[i] stores the min value of the max cost the tree rooted at i can have. 
#include <bits/stdc++.h>
#include <cstring>
#define fo(i,a,b) for(int i=a;i<b;i++)
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
#include <ctime>

using namespace std;


class StonesOnATree {
public:

  int dp[2000];
	vector<vector<int> >adj;
	vector<int> w;
	int dfs(int i){
		if(dp[i]!=-1) return dp[i];
		int ret;
		if(adj[i].size()==0) ret=w[i];
		else if(adj[i].size()==1) ret=max(w[i]+w[adj[i][0]],dfs(adj[i][0]));
		else ret=max(dfs(adj[i][1]),dfs(adj[i][0])),ret=max(ret,min(w[adj[i][0]]+dfs(adj[i][1]),w[adj[i][1]]+dfs(adj[i][0]))),ret=max(ret,w[i]+w[adj[i][0]]+w[adj[i][1]]);
		return dp[i]=ret;

	}

	int minStones(vector <int> p, vector <int> W) {
	  w=W;
		memset(dp,-1,sizeof(dp));
		adj.resize(w.size());
		fo(i,0,p.size()){
			adj[p[i]].push_back(i+1);
		}
		return dfs(0);
	}
};
