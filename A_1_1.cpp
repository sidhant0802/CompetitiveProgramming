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
   string s;
   s(s);
   in ans1=0;
   fr(i,0,n){
    if(s[i]=='1'){
        ans1++;
    }
    else{
        if(i>0&&i<n-1&&s[i-1]=='1'&&s[i+1]=='1'){
            ans1++;
            s[i]='1';
        }
    }
   }
   in ans2=0;
//    cout<<s<<endl;
   fr(i,0,n){
    if(s[i]=='1'){
        if(i>0&&i+1<n&&s[i-1]=='1'&&s[i+1]=='1'){
            i++;
            ans2++;
        }
        else{
            ans2++;
        }
    }
   }

   cout<<ans2<<" "<<ans1<<" ";
   cout<<endl;
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