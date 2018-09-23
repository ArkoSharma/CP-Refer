
//changes from standard : 
// 1. (re)rooting
// BUT HAD to skip union by rank to always keep parent as ancestor
// 1.06 s 

#include <bits/stdc++.h>
#include <climits>
#define fo(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset((a),(b),sizeof(a))
int q,cnt=0;
using namespace std;
typedef struct par{
  int p,mi,ma;
}parent;
std::vector<int> ans;
std::vector<std::vector<pair<int,int> > >adj,adjj;
std::vector<std::vector<pair<int,int> > > quers;
vector<vector<int> >underme;
std::vector<parent> par;
std::vector<int> ranks;
std::vector<int> ancestor,mians,maans,levels,subtree_size;


std::vector<int> vis;
void set_levels(int i,int j){
  levels[i]=j;
  vis[i]=1;
  for(auto k: adjj[i])  if(!vis[k.first]) set_levels(k.first,j+1); 
}
void set_adj(){
  fo(i,0,adjj.size()){
    for(auto j:adjj[i]){
      if(levels[i]<levels[j.first])  adj[i].push_back({j.first,j.second});
    }
  }
}
void init(int n){
  adj.resize(n);
  adjj.resize(n);
  par.resize(n);
  ancestor.resize(n);
  vis.resize(n);
  ranks.resize(n);
  underme.resize(n);
  subtree_size.resize(n);
  quers.resize(n);
}

parent find_set(int v){
  if(par[v].p!=v){
    int mi=par[v].mi;
    int ma=par[v].ma;
    par[v]=find_set(par[v].p);
    par[v].mi=min(par[v].mi,mi);
    par[v].ma=max(par[v].ma,ma);
    return par[v];
  }
  return par[v];
}
int unionn(int aa,int bb,int weight){
  auto a=find_set(aa);
  auto b=find_set(bb);
  if(a.p!=b.p){
    // if(ranks[a.p]<ranks[b.p]){
    //   int t;
    //   t=b.p;
    //   b.p=a.p;
    //   a.p=t;
    // }
    par[b.p].p=a.p;
    //if(ranks[a.p]==ranks[b.p]) ranks[a.p]++;
  }
}
int make_set(int u){
  par[u].p=u;
  par[u].mi=INT_MAX;
  par[u].ma=-INT_MAX;
  ranks[u]=0;
}
typedef struct que{
  int i,l,r;
}qu;
vector<qu> qs;
void Tolca(int u){
  vis[u]=1;
  ancestor[u]=u;
  // sort(adj[u].rbegin(),adj[u].rend(),[](auto a,auto b){
  //   return subtree_size[a.first]<subtree_size[b.first];
  // });
  for(auto j:adj[u]){
    if(!vis[j.first]){
      Tolca(j.first);
      unionn(u,j.first,j.second);
      par[j.first].mi=j.second;
      par[j.first].ma=j.second;
      ancestor[find_set(u).p]=u;
    }
  }
  for(auto j : quers[u]){
    if(vis[j.first]){
      int lca=ancestor[find_set(j.first).p];
      underme[lca].push_back(j.second);
    }
  }
  // fo(i,0,q){
  //   if(qs[i].l==u){
  //     int a=qs[i].r;
  //     if(vis[a]){ 
  //       int lca =ancestor[find_set(a).p];
  //       underme[lca].push_back(i);

  //     }
  //   }
  //    if(qs[i].r==u){
  //      int a=qs[i].l;
  //      if(vis[a]){
  //       int lca =ancestor[find_set(a).p];
  //       underme[lca].push_back(i);
  //     }
  //    }
  // }
  for(auto j:underme[u]){
    mians[qs[j].i]=min(find_set(qs[j].l).mi,find_set(qs[j].r).mi);
    maans[qs[j].i]=max(find_set(qs[j].l).ma,find_set(qs[j].r).ma);

  }
} 
/*not req
void find_subtree_sizes(int id){
  vis[id]=1;
  int stcnt=cnt;
  cnt++;
  fo(i,0,adj[id].size()){
    if(!vis[adj[id][i].first]){
      find_subtree_sizes(adj[id][i].first);
    }
  }
  subtree_size[id]=cnt-stcnt;
}*/
int main(){
      int n;
      cin>>n;
      init(n);
      fo(i,0,n){
        make_set(i);
      }
      fo(i,0,n-1){
        int m,mm,c;
        cin>>m>>mm>>c;
        m--;
        mm--;
        c;
        adjj[m].push_back({mm,c});
        adjj[mm].push_back({m,c});
      }
      levels.resize(n);
      vis.assign(n,0);
      set_levels(0,0);
      set_adj();
      //vis.assign(n,0);
      //find_subtree_sizes(0);
      cin>>q;
      qs.resize(q);
      mians.assign(q,0);
      maans.assign(q,0);
      fo(i,0,q){
        int l,r;
        cin>>l>>r;
        l--,r--;
        qs[i].i=i;
        qs[i].l=l;
        qs[i].r=r;
        quers[l].push_back({r,i});
        quers[r].push_back({l,i});

      }
      vis.assign(n,0);
      Tolca(0);
      fo(i,0,q){
        cout<<mians[i]<<" "<<maans[i]<<"\n";
      }
  }
