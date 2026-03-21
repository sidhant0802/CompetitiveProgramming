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
    fr(i,0,n)  s(arr[i]);    
    set<in>s;
    fr(i,0,n){
        s.insert(i);
    }
    fr(i,0,n){
        in x=arr[i]+i;
        x%=n;
        x+=n;
        x%=n;
        if(s.find(x)!=s.end()){
            s.erase(x);
        }
    }
    if(s.size()){
        N;
    }
    else{
        Y;
    }
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
