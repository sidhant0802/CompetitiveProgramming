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
   in k;
   s(k);
   in s;
   s(s);
   vi arr(n);
   fr(i,0,n) s(arr[i]);
   vii adj(n+1);
   vii v(k+1);
   fr(i,0,n){
    v[arr[i]].pb(i+1);
   }
   fr(i,0,m){
    in u,v;
    s(u);
    s(v);
    adj[u].pb(v);
    adj[v].pb(u);
   }
   vii c(n+1);
   fr(i,1,k+1){
    vi visit(n+1,0);
    vi dis(n+1,0);
    queue<in>q;
    fr(j,0,v[i].size()){
        q.push(v[i][j]);
        dis[v[i][j]]=0;
        visit[v[i][j]]=1;
    }
    in c1=0;
    while(q.size()){
        c1++;
        in cc=q.size();
        fr(i,0,cc){
            in x=q.front();
            q.pop();
            fr(j,0,adj[x].size()){
                in p=adj[x][j];
                if(visit[p]) continue;
                dis[p]=c1;
                visit[p]=1;
                q.push(p);
            }
        }
    }
    fr(i,1,n+1){
        c[i].pb(dis[i]);
    }
   }
   fr(i,1,n+1){
    sort(all(c[i]));
   }
   vi ans(n+1);
   fr(i,1,n+1){
    in cc=0;
    fr(j,0,s){
        cc+=c[i][j];
    }
    ans[i]=cc;
   }
   fr(i,1,n+1){
    cout<<ans[i]<<" ";
   }
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