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
   string s,t;
   in n;
   s(n);
   in o=0;
   in z=0;
   s(s);s(t);
   fr(i,0,n){
    if(s[i]=='0') z++;
    else o++;
   }
   in z1=0;
   in o1=0;
   fr(i,0,n){
    if(t[i]=='0') z1++;
    else o1++;
   }
   if(z==n){
    if(o1==n){
        pn(1);
        return;
    }
   }
   if(o==n){
    if(z1==n){
        pn(1);
        return;
    }
   }
   if(s==t){
    pn(0);
    return;
   }
   if(o1==n){
    pn(1);
    return;
   }
   if(z1==n){
    pn(1);
    return;
   }
   if(o==n){
    pn(1);
    return;
   }
   if(z==n){
    pn(1);
    return;
   }
   pn(0);
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