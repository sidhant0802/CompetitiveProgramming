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

vii dp(1e6,vi(12,0));

void solve(){
   in n,k;
   s(n);
   s(k);
   string s=to_string(n);
   in ans=0;
   fr(i,0,s.size()){
    in x=dp[k][s[i]-'0'];
    ans=(ans+x)%MOD;
   }
   pn(ans);
   return;
}


int main() {
    fast;
    in t;
    s(t);
    fr(i,0,10){
        dp[0][i]=1;
    }
    fr(i,1,dp.size()){
        fr(j,0,10){
            if(j==9){
                dp[i][j]=(dp[i-1][0]+dp[i-1][1])%MOD;
            }
            else{
                dp[i][j]=dp[i-1][j+1];
            }
        }
    }
    while (t--) {
        solve();
    }
}