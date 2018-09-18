#include <bits/stdc++.h>
#include <cstring>
#define fo(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset((a),(b),sizeof(a))
using namespace std;
int q;
std::vector<int> ans;
std::vector<std::vector<int> > adj;
std::vector<int> par;
std::vector<int> ranks;
std::vector<int> ancestor;
std::vector<int> vis;
void init(int n){
  adj.resize(n);
  par.resize(n);
  ancestor.resize(n);
  vis.resize(n);
  ranks.resize(n);
}
int find_set(int v){
  return par[v]=(par[v]==v)? v:find_set(par[v]);
}
int unionn(int a,int b){
  a=find_set(a);
  b=find_set(b);
  if(a!=b){
    if(ranks[a]<ranks[b]){
      int t=0;
      t=b;
      b=a;
      a=t;
    }
    par[b]=a;
    if(ranks[a]==ranks[b]) ranks[a]++;
  }
}
int make_set(int u){
  par[u]=u;
  ranks[u]=0;
}
typedef struct que{
  int i,l,r;
}qu;
vector<qu> qs;
void Tolca(int u){
  vis[u]=1;
  ancestor[u]=u;
  for(auto j:adj[u]){
    if(!vis[j]){
      Tolca(j);
      unionn(u,j);
      ancestor[find_set(u)]=u;
    }
  }
  fo(i,0,q){
    if(qs[i].l==u){
      int a=qs[i].r;
      if(vis[a]) ans[qs[i].i]=ancestor[find_set(a)]+1;
    }
     if(qs[i].r==u){
       int a=qs[i].l;
       if(vis[a]) ans[qs[i].i]=ancestor[find_set(a)]+1;
     }
   }
  
}

int main(){
  int t,tt=0;
  cin>>t;
  while(t--){
      tt++;
      int n;
      cin>>n;
      init(n);
      std::vector<int> isroot(n,1);
      fo(i,0,n){
        make_set(i);
        int m;
        cin>>m;
        fo(j,0,m){
          int u;
          cin>>u;
          u--;
          adj[i].push_back(u);
          isroot[u]=0;

        }
      }
      int root;
      fo(i,0,n){
        if(isroot[i]) root=i;break;
      }
      cin>>q;
      qs.resize(q);
      ans.assign(q,0);

      fo(i,0,q){
        int l,r;
        cin>>l>>r;
        l--,r--;
        qs[i].i=i;
        qs[i].l=l;
        qs[i].r=r;
      }
      vis.assign(n,0);
      Tolca(root);
      cout<<"Case "<<tt<<":\n";
      fo(i,0,q){
        cout<<ans[i]<<"\n";
      }
  }
}
