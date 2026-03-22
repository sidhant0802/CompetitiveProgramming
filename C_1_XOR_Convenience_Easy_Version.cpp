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
   in n;
   s(n);
   vi ans(n-1);
   set<in>s;
   fr(i,1,n+1){
    s.insert(i);
   }
   in curr1=3;
   in curr2=2;
   fr(i,1,n-1){
    if(i%2){
        ans[i]=curr1;
        s.erase(curr1);
        curr1+=2;
    }
    else{
        ans[i]=curr2;
        s.erase(curr2);
        curr2+=2;
    }
   }
   s.erase(1);
   ans[0]=*(s.begin());
   fr(i,0,n-1){
    cout<<ans[i]<<" ";
   }
   cout<<"1"<<endl;


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