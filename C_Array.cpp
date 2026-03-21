#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define in long long int
#define vi vector<in>
#define vii vector<vector<in>>
// #define MOD 998244353
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

in MOD=1e9+7;

in lower(const vi &v, in x) {
    return lower_bound(all(v), x) - v.begin();
}
in upper(const vi &v, in x) {
    return upper_bound(all(v), x) - v.begin();
}

in f(in a,in b){
    in x=1;
    while(b){
        if(b%2) x=((x%MOD)*(a%MOD))%MOD;
        a=((a%MOD)*(a%MOD))%MOD;
        b/=2;
    }
    return x;
}

in inv(in a){
    return f(a,MOD-2);
}
in mod_mul(in a,in b){
    return (a%MOD)*(b%MOD)%MOD;
}

// cout<<fixed<<setprecision(6)<<x<< endl;

vi fact;
void factorial(in n){
    fact.resize(n);
    fact[0]=1;
    fr(i,1,n){
        fact[i]=mod_mul(fact[i-1],i);
    }
}

void solve(){
   in n;
   s(n);
   in x=2*n-1;
   in ans=2;
   ans=mod_mul(ans,fact[x]);
   ans=mod_mul(ans,inv(fact[n]));
   ans=mod_mul(ans,inv(fact[n-1]));
   ans=(ans-n+MOD)%MOD;
   pn(ans);
   return;
}


int main() {
    fast;
    in t;
t=1;
    factorial(1e6+1);
    while (t--) {
        solve();
    }
}