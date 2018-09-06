   // In number theory, the totient φ of a positive integer n is defined to be the number of positive integers less than or equal to
   // n that are coprime to n.

   // Given an integer n (1 <= n <= 10^6). Compute the value of the totient φ.
    #include <bits/stdc++.h>
    #include <cstring>
    #define fo(i,a,b) for(int i=a;i<b;i++)
    #define mem(a,b) memset((a),(b),sizeof(a))
    using namespace std;
     
    int main(){
      int t;
      cin>>t;
      while(t--){
    	  int x,res;
    	  cin>>x;
    	  res=x;
    	  for(int i=2;i*i<=x;i++){
    	  	if(x%i==0){
    	  		while(x%i==0){
    	  			x/=i;
    	  		}
    	  		res-=res/i;
    	  	}
    	  }
    	  if(x>1) res-=res/x;
    	  cout<<res<<"\n";
    	}
     } 
