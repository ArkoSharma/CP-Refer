//https://www.codechef.com/problems/LRQUER
#include<bits/stdc++.h>
#include <bits/stdc++.h>
#define fi first
#define se second
#define mem(a,b) memset(a,b,sizeof(a))
#define fo(i,a,b) for(int i=a;i<b;i++)
using namespace std;
using ll = long long;
const int mod = 1e9+7; 
const int maxn = 1e5;
ll a[maxn],n,m;
ll inf = 2e9 + 2;
multiset<ll> s[4*maxn];

void build(int id, int l, int r){
    if(l+1 == r){
        s[id].insert(a[l]);
        return;
    }
    int mid = (l + r)/2;

    build(2*id, l, mid);
    build(2*id + 1, mid, r);

    s[id].insert(s[2*id].begin(),s[2*id].end());
    s[id].insert(s[2*id+1].begin(),s[2*id+1].end());

}

void p_upd(int x, int y, int id = 1, int l = 0, int r = n){
    
    s[id].erase(s[id].find(a[x]));
    s[id].insert(y);

    if(l+1 == r){
        a[l] = y;
        return;
    }

    int mid = (l+r)/2;
    if(x < mid)
        p_upd(x, y, 2*id, l, mid);
    else
       p_upd(x, y, 2*id+1, mid, r);

}

ll query(int x, int y ,int id = 1 ,int l = 0, int r = n){
    

    if( (y-1 < l) || (x > r -1 ) ) return inf;

    if( x <= l && r <= y){
        auto lb = s[id].lower_bound((1LL*(a[x]+a[y-1]))/2);
        if( lb == s[id].begin()) return *lb;
        else{
            ll t = *(lb--);
            ll q = *lb;
            if(abs(t - ((a[x]+a[y-1]))/2)  < abs(q - ((a[x]+a[y-1]))/2)){
                return t;

            }else return q; 
        }
    }



    int mid = (l+r)/2;
    ll t = query(x,y, 2*id, l, mid);
    ll q = query(x,y, 2*id + 1, mid, r);
    if(abs(t - (a[x]+a[y-1])/2) < abs(q - (a[x]+a[y-1])/2)){
        return t;

    }else return q; 
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        fo(i,0,4*maxn){
            s[i].clear();
        }
        fo(i,0,n){
            cin>>a[i];
            a[i] *= 2;

        }
        build(1,0,n);
        fo(i,0,m){
            int cc,l;
            ll r;
            cin>>cc>>l>>r;
            if(cc == 1){
                l--,r--;
                ll p = query(l,r+1);
                cout<< ((a[l] - p)*(p - a[r]))/4 <<"\n";
            }
            else{
                l--;
                p_upd(l,r*2);
            }
        }
    }

}
