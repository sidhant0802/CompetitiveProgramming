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
    vi arr(n+1);
    fr(i,1,n+1)  s(arr[i]);    
    vi dp(n+1,1e9);
    dp[0]=0;
    fr(i,1,n+1){
        dp[i]=dp[i-1]+20;
        in idx=upper_bound(all(arr),arr[i]-90)-arr.begin();
        if(idx==0){
            dp[i]=min(dp[i],50ll);
        }
        else{
            idx--;
            dp[i]=min(dp[i],50+dp[idx]);
        }
        idx=upper_bound(all(arr),arr[i]-1440)-arr.begin();
        if(idx==0){
            dp[i]=min(dp[i],120ll);
        }
        else{
            idx--;
            dp[i]=min(dp[i],120+dp[idx]);
        }
    }
    fr(i,0,n){
        cout<<dp[i+1]-dp[i]<<endl;
    }
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
