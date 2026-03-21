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

in powr[9];
in f(in idx,in a,in b,in n,in m,vi &v,in n1,in m1){
    if(n1>=n) return 0;
    if(m1>=m) return 0;
    if(idx>=(a+b)) return 1;
    in x=0;
    if(idx>=b) x=1;
    in curr=0;
    fr(i,0,7){
        if(!v[i]){
            v[i]=1;
            if(x){
                curr+=f(idx+1,a,b,n,m,v,n1+1ll*powr[idx-b]*i,m1);
            }
            else{
                // cout<<i<<" "<<idx<<" "<<powr[idx-b]*i<<endl;
                curr+=f(idx+1,a,b,n,m,v,n1,m1+1ll*powr[idx]*i);
            }
            v[i]=0;
        }
    }
    return curr;
}
void solve(){
   in n,m;
   s(n);
   s(m);
   powr[0]=1;
   fr(i,1,9){
    powr[i]=powr[i-1];
    powr[i]*=7;
   }
   in a=0;
   in x=1;
   while(x<n){
    a++;
    x*=7;
   }
   if(n==1) a=1;

//    pn(a);
   in b=0;
   x=1;
   while(x<m){
    b++;
    x*=7;
   }
   if(m==1) b=1;
   if(a+b>7){
    pn(0);
    return;
   }
   vi v(10,0);
   in ans=f(0,a,b,n,m,v,0,0);
   pn(ans);
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