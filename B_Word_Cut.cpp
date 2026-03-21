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
   s(s);s(t);
   in k;
   s(k);
   in n=s.size();
   vii dp1(k+1,vi(2,0));
   if(s==t){
    dp1[0][0]=1;
    dp1[0][1]=0;
   }
   else{
    dp1[0][0]=0;
    dp1[0][1]=1;
   }
   in g=0;
   for(int i=0;i<n;i++){
    string p=s.substr(i)+s.substr(0,i);
    // cout<<p<<endl;
    if(p==t){
        g++;
    }
   }
   fr(i,1,k+1){
    dp1[i][0]=(dp1[i-1][0]*(g-1)+dp1[i-1][1]*(g))%MOD;
    dp1[i][1]=(dp1[i-1][1]*(n-g-1)+dp1[i-1][0]*(n-g))%MOD;
   }
   cout<<dp1[k][0];
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