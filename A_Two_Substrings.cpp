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
   cin>>s;
   in n=s.size();
   in f=0;
   in idx=-1;
   in f1=0;
   in f2=0;
   fr(i,0,n){
    if(s[i]=='A'){
        if(i+1<n&&s[i+1]=='B'){
            idx=i+2;
            f2=1;
            break;
        }
        f1=1;
    }
    else{
        f2=1;
    }
   }
   if(f1==0&&f2==0){
    cout<<"NO"<<endl;
    return;
   }
//    if(idx==-1){
//     N;
//     return;
//    }
   if(idx!=-1){
   fr(i,idx,n){
    if(s[i]=='B'){
        if(i+1<n&&s[i+1]=='A'){
            f=1;
            break;
        }
    }
   }
}
   if(f){
    cout<<"YES"<<endl;
    return;
   }
   idx=-1;
   fr(i,0,n){
    if(s[i]=='B'){
        if(i+1<n&&s[i+1]=='A'){
            idx=i+2;
            break;
        }
    }
   }
//    cout<<idx<<endl;
   if(idx!=-1){
    fr(i,idx,n){
        if(s[i]=='A'){
            if(i+1<n&&s[i+1]=='B'){
                f=1;
                break;
            }
        }
    }
   }
   if(f){
    Y;
    return;
   }
   N;
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