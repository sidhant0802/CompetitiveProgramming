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

void dfs(in node,in par,vi &brr,vi &ans,vii &adj){
    in curr=0;
    if(par!=-1) curr=brr[par];
    if(brr[node]==-1){
        if(adj[node].size()==0){

            return;
        }
        in x=1e10;
        fr(i,0,adj[node].size()){
            x=min(x,brr[adj[node][i]]);
        }
        ans[node]=x-curr;
        brr[node]=x;
    }
    else{
        ans[node]=brr[node]-curr;
    }
    fr(i,0,adj[node].size()){
        dfs(adj[node][i],node,brr,ans,adj);
    }
}

void solve(){
   in n;
   s(n);
   vi arr(n-1);
   vi brr(n);
   fr(i,0,n-1) s(arr[i]);
   fr(i,0,n) s(brr[i]);
   vii adj(n);
   fr(i,1,n){
    adj[arr[i-1]-1].pb(i);
   }
   vi ans(n,0);
   dfs(0,-1,brr,ans,adj);
   in s=0;
   fr(i,0,n){
    if(ans[i]<0){
        pn(-1);
        return;
    }
    s+=ans[i];
   }
   pn(s);
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