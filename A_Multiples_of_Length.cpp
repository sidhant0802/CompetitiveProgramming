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
    cout<<"1 1"<<endl;
    cout<<-arr[0]<<endl;
    cout<<"1 "<<n<<endl;
    cout<<"0 ";
    fr(i,1,n){
        cout<<-arr[i]*n<<" ";
    }
    cout<<endl;
    if(n==1){
        cout<<"1 1"<<endl;
        cout<<"0"<<endl;
        return;
    }
    cout<<"2 "<<n<<endl;
    fr(i,1,n){
        cout<<arr[i]*(n-1)<<" ";
    }
    cout<<endl;
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
