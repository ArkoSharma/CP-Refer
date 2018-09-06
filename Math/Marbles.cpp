//marbles
/*

I have some (say, n) marbles (small glass balls) and I am going to buy some boxes to store them. The
boxes are of two types:
T ype 1: each box costs c1 Taka and can hold exactly n1 marbles
T ype 2: each box costs c2 Taka and can hold exactly n2 marbles
I want each of the used boxes to be filled to its capacity and also to minimize the total cost of
buying them. Since I find it difficult for me to figure out how to distribute my marbles among the
boxes, I seek your help. 




I want your program to be efficient also. <-- minimise cost.


long long 
floor ceil

*/
#include <bits/stdc++.h>
#define fo(i,a,b) for(i=a;i<b;i++)
#define p(n) printf("%d",(n))
#define s(n) scanf("%d",&(n))
using namespace std;

long long int x,y,d;
void extendedEuclid(int a,int b){
    if(b==0){
        x=1;
        y=0;
        d=a;
        return;
    }
    extendedEuclid(b,a%b);
    long long int x1=y;
    long long int y1=x-(a/b)*y;
    x=x1;
    y=y1;
    return;
}
int main() {
	long long int n,c1,c2,n1,n2,i;
    double k;
    //freopen("a.txt","r",stdin);
    while(1){

            scanf("%lld",&n);
            if(n==0){
                return 0;
            }
            scanf("%lld %lld %lld %lld",&c1,&n1,&c2,&n2);
            extendedEuclid(n1,n2);
            if(n%d!=0){
                printf("failed\n");
                continue;
            }
            else{
                x*=(n/d);
                y*=(n/d);
                k=(-1* (d *((1.0 * x)/n2)));
                long long int lb=(long long int)ceil(k);
                k=/*less_than_eq*/d*((1.0*y)/n1);
                long long int ub=(long long int)floor(k);
                if(lb>ub){
                    printf("failed\n");
                    continue;
                }
                if(c1*(n2/d)-c2*(n1/d) >=0 ){
                    i=lb;
                }
                else{
                    i=ub;
                }
                printf("%lld %lld\n", (x+(i*(n2/d))),(y-(i*(n1/d))));
            }
    }
}
