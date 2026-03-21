#include<bits/stdc++.h>

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
#define Y cout<<"YES"<<endl
#define N cout<<"NO"<<endl
#define fr(i, a, b) for (in i = a; i < (int)b; ++i)
#define all(v) v.begin(), v.end()
#define sz(v) (in)(v.size())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a / __gcd(a, b)) * b

void solve(){
   in n,m;
   s(n);
   s(m);
   in ans=10000000;
   fr(i,0,1e6){
    in x=n-i*m;
    in q=x;
    in cc=0;
    if(x<0) continue;
    while(x){
        if(x%2)
        cc++;
        x>>=1;
    }
    // pn(cc);
    if(cc<=i&&i<=q){
    ans=min(ans,i);
    }
   }
   if(ans==10000000) ans=-1;
   pn(ans);
   return;
}


int main() {
    fast;
    in t;
t=1;
    while (t--) {
        solve();
    }
}