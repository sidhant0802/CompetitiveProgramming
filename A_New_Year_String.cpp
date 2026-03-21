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
   string s;
   in n;
   s(n);
   s(s);
   in f=0;
   fr(i,0,n-3){
    if(s[i]=='2'&&s[i+1]=='0'&&s[i+2]=='2'&&s[i+3]=='6'){
        f=1;
        break;
    }
   }
   if(f){
    pn(0);
    return;
   }
   f=0;
   fr(i,0,n-3){
    if(s[i]=='2'&&s[i+1]=='0'&&s[i+2]=='2'&&s[i+3]=='5'){
        f=1;
        break;
    }
   }
   if(f){
    cout<<1<<endl;
   }
   else{
    cout<<0<<endl;
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