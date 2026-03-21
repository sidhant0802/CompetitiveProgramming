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
vi lazy;
void build(in idx,in l ,in r,vi &arr){
    if(l==r){
        tree[idx]=arr[l];
        return;
    }
    in m=(l+r)>>1;
    build(2*idx+1,l,m,arr);
    build(2*idx+2,m+1,r,arr);
    tree[idx]=tree[2*idx+1]+tree[2*idx+2];
}

void push(in idx,in l,in r){
    if(lazy[idx]!=0){
        tree[idx]+=(r-l+1)*lazy[idx];
        if(l!=r){
            lazy[2*idx+1]+=lazy[idx];
            lazy[2*idx+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
}

void update(in idx,in l,in r,in ql,in qr,in val){
    push(idx,l,r);
    if(qr<l||r<ql) return ;
    if(ql<=l&&r<=qr){
        lazy[idx]+=val;
        tree[idx]=val;
        push(idx,l,r);
        return;
    }
    in m=(l+r)>>1;
    update(2*idx+1,l,m,ql,qr,val);
    update(2*idx+2,m+1,r,ql,qr,val);
    tree[idx]=tree[2*idx+1]+tree[2*idx+2];
}

in query(in idx,in l,in r,in ql,in qr){
    push(idx,l,r);
    if(qr<l||r<ql){
        return 0;
    }
    if(ql<=l&&r<=qr){
        return tree[idx];
    }
    in m=(l+r)>>1;
    return query(2*idx+1,l,m,ql,qr)+query(2*idx+2,m+1,r,ql,qr);
}

void solve() {
    in n,k;
    s(n);
    tree.assign(4*n,0);
    lazy.resize(4*n);
    s(k);
    vi arr(n);
    fr(i,0,n)  s(arr[i]);    
    build(0,0,n-1,arr);
    fr(i,0,k){
        in a;
        s(a);
        if(a==1){
            in l,r,val;
            s(l);
            s(r);
            s(val);
            update(0,0,n-1,l,r-1,val);
        }
        else{
            in l;
            in r;
            s(l);s(r);
            cout<<query(0,0,n-1,l,r-1)<<endl;
        }
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
