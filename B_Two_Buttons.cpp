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
   in n,m;
   s(n);s(m);
   queue<in>q;
   q.push(n);
   if(n>=m){
    pn(n-m);
    return;
   }
   vector<in>v(1e6,0);
   v[n]=1;
   in c=0;
   while(q.size()){
    in x=q.size();
    fr(i,0,x){
        in y=q.front();
        q.pop();
        if(y==m){
            pn(c);
            return;
        }
        in a=y-1;
        in b=2*y;
        if(b<1e6&&v[b]==0){
            v[b]=1;
            q.push(b);
        }
        if(a>=0&&v[a]==0){
            v[a]=1;
            q.push(a);
        }
        if(a==m||b==m){
            pn(c+1);
            return;
        }
    }
    c++;
   }
   return;
}


int main() {
    fast;
in t=1;
    while (t--) {
        solve();
    }
}