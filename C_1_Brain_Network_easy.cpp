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

   vii adj(n+1);
   fr(i,0,m){
    in u,v;
    s(u);s(v);
    adj[u].pb(v);
    adj[v].pb(u);
   }
   if(m!=n-1){
    cout<<"no"<<endl;
    return;
   }
   vector<int>visit(n+1,0);
   in cc=0;
   fr(i,1,n+1){
    if(!visit[i]){
        cc++;
        queue<in>q;
        q.push(i);
        while(q.size()){
            int x=q.front();
            q.pop();
            for(in child:adj[x]){
                if(visit[child]==0){
                    visit[child]=1;
                    q.push(child);
                }
            }
        }
    }
    if(cc>=2){
        cout<<"no"<<endl;
        return;
    }
   }
   cout<<"yes"<<endl;
   return;
}

/*
int main() {
    fast;
    in t;
t=1;
    while (t--) {
        solve();
    }
}
    */