#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

#define in long long int
#define vi vector<in>
#define vii vector<vector<in>>
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define p(n) cout << n
#define pn(n) cout << n << endl
#define s(n) cin >> n
#define f first
#define sd second
#define Y cout << "YES" << endl
#define N cout << "NO" << endl
#define fr(i, a, b) for (in i = a; i < (int)b; ++i)
#define all(v) v.begin(), v.end()
#define sz(v) (in)(v.size())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a / __gcd(a, b)) * b

void solve() {
    in n;
    s(n);
    vi arr(n);
    in l,r;
    s(l);
    s(r);
    fr(i,0,n)  s(arr[i]);    
    // in ans=0;
    in l1=min(l,r);
    in r1=max(l,r);
    in cc1=0;
    in cc2=0;
    fr(i,0,n){
        if(arr[i]<=l1) cc1++;
        if(arr[i]<=r1) cc2++;
    }
    cc2-=cc1;
     in x=min(cc1,cc2);
    // cout<<cc1<<" "<<cc2<<endl;
    if(cc2>=cc1){
        pn(cc1);
        return;
    }
    in ans=max(cc2,0ll);
    in y=min(cc1,cc2);
    ans=y+(cc1-x)/2;
    pn(ans);
    // in ans=min(cc1/2,cc2/2);
    // if(cc1>=2*cc2){
    //     ans=max(ans,cc2);
    // }
    // // pn(ans);
    // fr(i,0,n){
    //     if(arr[i]<=)
    // }



    return;
}

int main() {
    fast;
    in t;
    s(t);
    while (t--) {
        solve();
    }
}
