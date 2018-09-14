#define fo(i,a,b) for(int i=a;i<b;i++)
#define mem(a,b) memset((a),(b),sizeof(a))
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

class MagicNumberThree {
public:
	const int md=1000000007;
	int dp[451][53];
	string a;
	int get(int k,int i){
		if(k<0) return 0;
		if(i==a.size()) return 0;
		if(dp[k][i]!=-1) return dp[k][i];
		int sum=0;
		if(a[i]-'0'==k) sum++;
		fo(j,i+1,a.size()){
			sum=(sum+get(k-(a[i]-'0'),j))%md;
		} 
		return dp[k][i]=sum;
	}
	
	int countSubsequences(string s) {
		a=s;
		mem(dp,-1);
		int p=0;
		int ssum=0;
		fo(j,0,s.size()){
			ssum+=s[j]-'0';
		}
		for(int i=0;i<=ssum;i+=3){
		  fo(j,0,s.size())
		  	p=(p+get(i,j))%md;
		}
		return p%md;

	}
};
