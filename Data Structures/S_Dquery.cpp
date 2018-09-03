// https://www.spoj.com/problems/DQUERY/

#include<bits/stdc++.h>
#include <climits>
#define fo(i,a,b) for (int i=(a);i<(b);i++)
using namespace std;
#define Q 1000000007
#define TIMESTAMP(x) printf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
typedef long long int ll;
 
const int  N= 1000009;
int a[N];  
//final answer
int ans[N];
int n,cnt[N],distinct;
int Blksize=550;
typedef struct qu{
	int l,r,i;
	bool operator <(const struct qu&a ){
		//sort by the quotients
		if(l/Blksize != a.l/Blksize)
    		return l/Blksize < a.l/Blksize;
	    
	    //break ties using endpoints
	    return r<a.r;
	}	
}qu;
qu qq[N];
 
//for mos algo we need 3 conds
// offline queries
// no updates(*)
// calculating f(l+-1,r+-1) from f(l,r) in const or log time
 
// here the f is max freq function
// returns the max freq of elements in l,r
 
 
 
 
 
//let , cnt keep the frequencies of encountered array elements
// and freq keep the frequencies of the frequencies of the encountered elems 
void add(int index){
  if(index>0 && index<n+1){
    int elem=a[index];    
    if(cnt[elem]==0){		
		distinct++;
	}
	cnt[elem]++;
 }
}
void remove(int index){
	if(index >0 && index<n+1){
	 int elem=a[index];
	 if(cnt[elem]==1){	
	    distinct--;
     }
     cnt[elem]--;
   } 
}
int main() {
      int q;
  	  scanf("%d",&n);
	  if(n!=0){
		Blksize=(int)sqrt(n);
		fo(i,1,n+1){
			scanf("%d",&a[i]);
			
		
		}
		scanf("%d",&q);
		
		fo(i,1,q+1){
			scanf("%d %d",&qq[i].l,&qq[i].r);
			qq[i].i=i;
			
		}
		//sort the queries
		sort(qq+1,qq+q+1);
		
		distinct=0;
		int mo_left=0,mo_right=0;
		fo(i,1,q+1){
			
			while(mo_left<qq[i].l)  remove(mo_left++);//inc moleft
			while(mo_left>qq[i].l) add(--mo_left);//excl moleft
			while(mo_right>qq[i].r) remove(mo_right--);//inc
			while(mo_right<qq[i].r) add(++mo_right);
			ans[qq[i].i]=distinct;    
		}
		
		fo(i,1,q+1){
			printf("%d\n",ans[i]);
		}
	  }
  else {/*TIMESTAMP(end);*/ return 0;}
 
}
 
