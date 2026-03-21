#include <bits/stdc++.h>
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
#define Y cout << "YES" << endl
#define N cout << "NO" << endl
#define fr(i, a, b) for (in i = a; i < (int)b; ++i)
#define all(v) v.begin(), v.end()
#define sz(v) (in)(v.size())
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a / __gcd(a, b)) * b

vi tree;

void update(in l,in r,in pos,in idx){
    if(l==r){
        tree[idx]=1;
        return;
    }
    in m=(r+l)>>1;
    if(pos<=m){
        update(l,m,pos,2*idx+1);
    }
    else{
        update(m+1,r,pos,2*idx+2);
    }
    tree[idx]=tree[2*idx+1]+tree[2*idx+2];
}

in query(in l,in r,in ql,in qr,in pos){
    if(l>qr||ql>r){
        return 0;
    }
    if(l>=ql&&qr>=r){
        return tree[pos];
    }
    in m=(r+l)>>1;
    in left=query(l,m,ql,qr,2*pos+1);
    in right=query(m+1,r,ql,qr,2*pos+2);
    return left+right;
}

void solve() {
    in n;
    s(n);
    vi arr(n);
    fr(i,0,n)  s(arr[i]);    
    tree.resize(n*4);
    vi ans(n);
    fr(i,0,n){
        ans[i]=query(0,n-1,arr[i],n-1,0);
        update(0,n-1,arr[i]-1,0);
    }
    fr(i,0,n) cout<<ans[i]<<" "
;    return;
}

int main() {
    fast;
    in t;
t=1;
    while (t--) {
        solve();
    }
}
