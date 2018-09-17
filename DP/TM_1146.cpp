#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset((a),(b),sizeof(a))
const int md=1e9+7;
using namespace std;
int sum[1002][1002],n;
vector<vector<int> >a;
int get(int i,int j){
  int ss[n];
  fo(ii,0,n){
    if(i==0) ss[ii]=sum[j][ii];
    else ss[ii]=sum[j][ii]-sum[i-1][ii];
  }
  int minsum=0,maxsum,flag=1,su=0;
  fo(ii,0,n){
    su+=ss[ii];
    if(su-minsum>maxsum || flag==1){
      maxsum=su-minsum,flag=0;
    }

    if(su<minsum){
      minsum=su;
    }
  }
  return maxsum;

}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin>>n;
  a.assign(n,vector<int>(n));
  fo(i,0,n){
    fo(j,0,n){
      cin>>a[i][j];
    }
  }
  fo(i,0,n){
    fo(j,0,n){
      if(i==0) sum[i][j]=a[i][j];
      else sum[i][j]=sum[i-1][j]+a[i][j];
      
    }
  }
  int res=-1270008;
  fo(i,0,n){
    fo(j,i,n){
      res=max(res,get(i,j));

    }
  }

  //cout<<res<<1.0*clock()/CLOCKS_PER_SEC;
}
