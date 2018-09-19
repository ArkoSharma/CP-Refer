#include <bits/stdc++.h>
#define fi first
#define se second
#define mem(a,b) memset(a,b,sizeof(a))
#define fo(i,a,b) for(int i=a;i<b;i++)
using namespace std;
using ll = long long;
const int mod = 1e9+7; 
const int mx = 1e5  + 3;
int aiz[mx],azi[mx],aio[mx],aoi[mx],ati[mx],ait[mx];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--){

    string m,n;
    cin>>m>>n;
    fo(i,1,n.size()+1){
      aiz[i] = (n[i-1]-'0') == 0;

    }
    fo(i,1,m.size()+1){
      azi[i] = (m[i-1]-'0') == 0;
    }
 
    aoi[1] = ((aiz[1] == 1) || (azi[1] == 1));
    aio[1] = aoi[1];
    fo(i,2,n.size()+1){
      if(aiz[i] == 1) aio[i] = 1;
      else{
        if(aio[i-1] == 0) aio[i] = 1;
        else aio[i] = 0;
      }
    }
    fo(i,2,m.size() + 1){
      if(azi[i] == 1) aoi[i] = 1;
      else{
        if(aoi[i-1] == 0) aoi[i] = 1;
        else aoi[i] = 0;
      }
    }
 
    ati[2] = ait[2] = ((aio[2] == 0) || (aoi[2] == 0));
    fo(i,3,n.size()+1){
      ait[i] = ((ait[i-1] == 0)||(aio[i] == 0));
    }
    fo(i,3,m.size()+1){
      ati[i] = (ati[i-1] == 0)||(aoi[i] == 0);
    }

    int q;
    cin>>q;
    fo(i,0,q){
      int j,k;
      cin>>j>>k;
      if(j == 1){
        cout<<aoi[k]; 
      }
      else if (k == 1){
        cout<<aio[j];
      }
      else{
        if(j>k){
          cout<<ait[j-k+2];
        }
        else{
          cout<<ati[k-j+2];
        }
      }
    }
    cout<<"\n";
  }
}
