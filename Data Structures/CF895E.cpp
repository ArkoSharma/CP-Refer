//http://codeforces.com/contest/895/problem/E 
#include<bits/stdc++.h>
#include<string.h>
#define fo(i,a,b)  for (int i = int(a); i < int(b); i++)
using namespace std;
#define N 131072
int n;
double seg[N << 1],alazy[N << 1],mlazy[N << 1];
double a[N];

int size(int n){
  int siz=1;
  for(;siz<n;siz<<=1);
    return siz<<1;
}
void build(int id,int l,double r){
  mlazy[id]=1;
  if(l==r-1){ // *
    seg[id]=a[l];
    return ;
  }
  int mid=(l+r)/2;
  build(2*id,l,mid);
  build(2*id+1,mid,r);
  seg[id]=seg[2*id]+seg[2*id+1];
  

}
void lazy_updatea(int id,int l,int r,double x){
  
  seg[id]+=(r-l)*x;
  alazy[id]+=x;
}
void lazy_updatem(int id,int l,int r,double x){
  
  seg[id]=(seg[id])*x;
  mlazy[id]*=x;
  alazy[id]*=x;
}

void shift(int id,int l,int r){
  int mid=(l+r)/2;
  lazy_updatem(2*id,l,mid,mlazy[id]);
  lazy_updatem(2*id+1,mid,r,mlazy[id]);
  mlazy[id]=1.0;
  //int mid=(l+r)/2;
  lazy_updatea(2*id,l,mid,alazy[id]);
  lazy_updatea(2*id+1,mid,r,alazy[id]);
  alazy[id]=0;
}

void range_update_mult(int x,int y,double val,int id=1,int l=1,int r=n+1){
  if(y-1<l || r-1 < x) return;
  if(l>=x && r-1<=y-1){
    lazy_updatem(id,l,r,val);
    return;
  }
  shift(id,l,r);
  int mid=(l+r)/2;
  range_update_mult(x,y,val,2*id,l,mid);
  range_update_mult(x,y,val,2*id+1,mid,r);
  //now for the sum feature
  seg[id]=seg[2*id]+seg[2*id+1];

}
void range_update_ad(int x,int y,double val,int id=1,int l=1,int r=n+1){
  //outofrange
  if(y-1<l || r-1 < x) return;
  //total overlap
  if(l>=x && r-1<=y-1){
    lazy_updatea(id,l,r,val);
    return;
  }
  shift(id,l,r);
  int mid=(l+r)/2;
  range_update_ad(x,y,val,2*id,l,mid);
  range_update_ad(x,y,val,2*id+1,mid,r);
  //now for the sum feature
  seg[id]=seg[2*id]+seg[2*id+1];

}
double sum_lazy(int x,int y,int id=1,int l=1,int r=n+1){
  // xy covers lr
  if(l>=x && r-1<=y-1) return seg[id];
  //lr out of range
  // remember the range which is asked is x..y-1 and the current segment is l..r-1 bcos of *
  if(l> y-1 || r-1 <x) return 0;
  shift(id,l,r);
  int mid=(l+r)/2;
  return sum_lazy(x,y,2*id,l,mid)+sum_lazy(x,y,2*id+1,mid,r);
}
int main() {
  int q;
  cin>>n>>q;
  fo(i,1,n+1){
    cin>>a[i];
  }
  int size_ofstree=size(n);// size(no of elements of arr)
  
  memset(alazy,0,sizeof alazy);
 
  build(1,1,n+1); 
  int t,l,r,ll,rr,lll,rrr;
  while(q--){
      cin>>t;
      if(t==1){
        cin>>l>>r>>ll>>rr;
        //exp value of replacement (FOR ll,rr)=am of values in l,r
        double currexpsum1=sum_lazy(l,r+1)/(r-l+1);
        double currexpsum2=sum_lazy(ll,rr+1)/(rr-ll+1);
        range_update_mult(l,r+1,(double)(r-l)/(double)(r-l+1));
        range_update_mult(ll,rr+1,(double)(rr-ll)/(double)(rr-ll+1));
        range_update_ad(l,r+1,currexpsum2/(double)(r-l+1));
        range_update_ad(ll,rr+1,currexpsum1/(double)(rr-ll+1));
            
      }
      else
      {     cin>>lll>>rrr;
            printf("%.9lf\n",sum_lazy(lll,rrr+1));        // gives sum of 2 to 4 since *
      }
  }
  return 0;
}
