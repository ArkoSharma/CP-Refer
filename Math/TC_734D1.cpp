/*
1.Calculating no of coprime nos wrt X in a given range using INCLUSION EXCLUSION over prime divisors of X.
 	Sieve (minp) for factorization. -- see hackerearth pic ,O()
 	Inclusion Exclusion for no of coprimes less than a no.
 	Bound on the no of prime factors-- O (log)
 	Sieve complexity O(nloglogN) -- see hackerearh pic

For each x<r, we factorise it and use the factors to generate the nos coprime to x less than y.
This requires iterating over all subsets of factors. 

*/

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
#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<b;i++)
using namespace std;
  const int MAXN=1000100;

class TheRoundCityDiv1 {
public:

int minp[MAXN];

long long get(int x,int y) // no of coprimes with x from  1 to y
{
  vector<int> xfactors;
  while(x>1){
    int mi=minp[x];
    xfactors.push_back(mi);
    while(x%mi==0){
      x/=mi;
    }
  }
  long long ans=0,num=xfactors.size();
  fo(mask,0,1<<(num)){
    int mul=1,div=1;
    fo(j,0,num){
      if(mask&(1<<j)){
        mul=-mul;
        div*=xfactors[j];
      }

    }
    ans+=(long long)mul*(y/div);
  }
  return ans;

} 

 long long find(int r) {
    memset(minp,-1,sizeof(minp));
    fo(i,2,MAXN){
      if(minp[i]==-1){
        for(int j=i;j<MAXN;j+=i) if(minp[j]==-1) minp[j]=i;
      }
    }
    long long ans=4;
    long long maxy=r;
    fo(i,1,r+1){
      while(maxy*maxy > r*(long long)r-i*(long long)i)
        maxy--;
      ans+=4*get(i,maxy);
    }
    return ans;

 }
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
