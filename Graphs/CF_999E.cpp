//http://codeforces.com/contest/999/problem/E
#include <bits/stdc++.h>
#include <cstring>
#define fo(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
vector< vector<int> >g, gr,adj;
vector<char> used,seen,parent;
vector<int> order, component;
void dfs1 (int v) {
    used[v] = true;
    for (int i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (int i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}


void dfs3 (int v) {
    seen[v] = true;
    for (int i=0; i<adj[v].size(); ++i)
        if (!seen[adj[v][i]])
            dfs3 (adj[v][i]);
}

int main() {
    int n,m,c;
    cin>>n>>m>>c;
    c--;
    int inc[n];
    mem(inc,0);
    g.resize(n);
    gr.resize(n);
    fo(i,0,m) {
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    used.assign (n, false);
    vector<int> compu(n);
    int cc=0;
    fo(i,0,n) if(!used[i]) dfs1(i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            fo(j,0,component.size()) compu[component[j]]=cc;
            cc++;
            component.clear();
      }
    }
    int k=0;
    adj.resize(n);
    fo(i,0,n){
      fo(j,0,g[i].size()){
        if(compu[i]==compu[g[i][j]]) continue;
        else adj[compu[i]].push_back(compu[g[i][j]]);
        inc[compu[g[i][j]]]++;
      }
    }
    seen.assign (cc, false);
    dfs3(compu[c]);
    fo(i,0,cc){
      if(!seen[i] && inc[i]==0){
        dfs3(i);
        k++;

      }
    }
    cout<<k;
  }
