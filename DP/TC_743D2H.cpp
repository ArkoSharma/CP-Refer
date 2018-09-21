/*
Problem Statement
    
John and Brus have found a nice horizontal plane and they built a rectangular city somewhere on the plane. The city has n rows and m columns of houses, with n*m ≤ 20. More precisely, John and Brus built a house at each lattice point (x, y) such that 0 ≤ x < n and 0 ≤ y < m.  Today is a holiday. John decided to go to the city and visit all the houses. However, some of the houses are locked since the owners left the city for the holiday. You are given a vector <string> city. For each x and y, the character city[x][y] represents the house at (x, y): '.' is an open house and '#' is a locked one.  John's trip has to satisfy the following constraints:
He has to visit each open house exactly once.
He cannot visit the locked houses and he cannot leave and re-enter the city during the trip.
His trip has to start somewhere on the border of the city. In other words, the first house he visits must have x = 0 or x = n-1 or y = 0 or y = m-1.
His trip also has to end somewhere on the border of the city.
From any house John may only move to an adjacent house. Two houses are adjacent if they are next to each other in the same row or column. Formally, (x1, y1) and (x2, y2) are adjacent if |x1 - x2| + |y1 - y2| = 1.
Brus now wants to compute the number of ways in which John can visit all the open houses in the city. Compute and return that number.
Constraints

-
n will be between 1 and 20, inclusive.
-
m will be between 1 and 20, inclusive.
-
n*m will be between 1 and 20, inclusive.
-
city will contain exactly n elements.
-
Each element of city will consist of exactly m characters, each being either '.' or '#'.
-
At least one character in city will be '.'.
Examples
0)

    
{
"....", 
".##.", 
"...."
}
Returns: 20
All houses on the city border have to be visited. John can start from any of them and choose the direction: either clockwise or counterclockwise. Thus the total number of ways to visit all open houses is 10 * 2 = 20;
1)

    
{
"....", 
".###", 
"...."
}
Returns: 2
Now John has to start from one of the rightmost houses and then he has to travel around the city to the other rightmost house.
2)

    
{
"....", 
"####", 
"...."
}
Returns: 0
Here it's impossible to visit all opened houses.
3)

    
{
"....", 
"....", 
"...."
}
Returns: 80

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.
*/

#define fo(i,a,b) for(int i=a;i<b;i++)
#include <bits/stdc++.h>

using namespace std;


class TheRectangularCityDiv2 {
public:
	int m,n,a[21][21];
    int dp[(1<<20)+1][21];
	long long find(vector <string> aa) {
	memset(dp,0,sizeof(dp));
    m=aa.size();
    n=aa[0].size();
    fo(i,0,m){
        fo(j,0,n){
            a[i][j]= (aa[i][j]=='.')?1:0;
        }
    }
    int k=0,ansmask=0;
    fo(i,0,m){
        fo(j,0,n){

            ansmask|=(a[i][j]==1)?(1<<k):0;
            if(i==0 || i==m-1 || j==0 || j==n-1){
                dp[(1<<k)][k]=(a[i][j]==1)? 1:0;
            }
            k++;
       }
    }
    fo(mask,1,(1<<(m*n))){
        k=0;
        fo(i,0,m){
            fo(j,0,n){
             if((mask & (1<<k))>0){
              if(a[i][j]==0 ) dp[mask][k]=0;
              else{
                if(i>0) if(a[i-1][j]==1 && (mask & (1<<(k-n)))>0) dp[mask][k]+=dp[mask & (~(1<<k))][k-n];
                if(i<m-1) if(a[i+1][j]==1 && (mask & (1<<(k+n)))>0)  dp[mask][k]+=dp[mask & (~(1<<k))][k+n];
                if(j>0) if(a[i][j-1]==1 && (mask & (1<<(k-1)))>0) dp[mask][k]+=dp[mask & (~(1<<k))][k-1];
                if(j<n-1) if(a[i][j+1]==1 && (mask & (1<<(k+1)))>0) dp[mask][k]+=dp[mask & (~(1<<k))][k+1];
              }
            }
            k++;
          }
        }
    }
    int ansk=0,ans=0;
    fo(i,0,m){
        fo(j,0,n){
            if(i==0 || i==m-1 || j==0 || j==n-1){
                ans+=(a[i][j]==1)? dp[ansmask][ansk]:0;
            }
            ansk++;
        }
    }
    //cout<<ans<<" "<<1.0*clock()/CLOCKS_PER_SEC;
    return ans;
		
	}
};
