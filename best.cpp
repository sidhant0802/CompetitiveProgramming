#include<bits/stdc++.h>
using namespace std;


void sieve() {
    for (int i = 1; i <= N; i++)
        spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}


in lower(const vi &v, in x) {
    return lower_bound(all(v), x) - v.begin();
}
in upper(const vi &v, in x) {
    return upper_bound(all(v), x) - v.begin();
}
in f(in a,in b){
    in x=1;
    while(b){
        if(b%2) x=((x%MOD)*(a%MOD))%MOD;
        a=((a%MOD)*(a%MOD))%MOD;
        b/=2;
    }
    return x;
}

in inv(in a){
    return f(a,MOD-2);
}
in mod_mul(in a,in b){
    return (a%MOD)*(b%MOD)%MOD;
}
cout<<fixed<<setprecision(6)<<x<< endl;

vi fact;
void factorial(in n){
    fact.resize(n);
    fact[0]=1;
    fr(i,1,n){
        fact[i]=mod_mul(fact[i-1],i);
    }
}

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); // path compression
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;

        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

int main() {
    ordered_set os;

    os.insert(5);
    os.insert(1);
    os.insert(10);

    cout << *os.find_by_order(0) << endl; // 1
    cout << os.order_of_key(6) << endl;   // 2
// k-th smallest
*os.find_by_order(k)

// number of elements < x
os.order_of_key(x)

// erase element
os.erase(x);

    return 0;
}

class Solution {
public:
       #define ll long long

static ll mod_mul(ll a, ll b, ll m) {
    return (a % m) * (b % m) % m;
}

static ll mod_sub(ll a, ll b, ll m) {
    return ((a - b) % m + m) % m;
}

static ll mminvprime(ll a, ll m) {
    ll res = 1, b = m - 2;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

struct Hashing {
    string s;
    int n;
    const ll base = 31;
    vector<ll> mod = {998244353};

    vector<vector<ll>> hashValues, power, invPower;

    Hashing(string str) {
        s = str;
        n = s.size();
        int k = mod.size();

        hashValues.assign(k, vector<ll>(n));
        power.assign(k, vector<ll>(n + 1));
        invPower.assign(k, vector<ll>(n + 1));

        for (int i = 0; i < k; i++) {
            power[i][0] = 1;
            for (int j = 1; j <= n; j++)
                power[i][j] = mod_mul(power[i][j - 1], base, mod[i]);

            invPower[i][n] = mminvprime(power[i][n], mod[i]);
            for (int j = n - 1; j >= 0; j--)
                invPower[i][j] = mod_mul(invPower[i][j + 1], base, mod[i]);

            for (int j = 0; j < n; j++) {
                hashValues[i][j] = ((s[j] - 'a' + 1) * power[i][j]) % mod[i];
                if (j > 0)
                    hashValues[i][j] = (hashValues[i][j] + hashValues[i][j - 1]) % mod[i];
            }
        }
    }

    vector<ll> getHash(int l, int r) {
        vector<ll> res(mod.size());
        for (int i = 0; i < mod.size(); i++) {
            ll val = hashValues[i][r];
            if (l > 0) val = mod_sub(val, hashValues[i][l - 1], mod[i]);
            res[i] = mod_mul(val, invPower[i][l], mod[i]);
        }
        return res;
    }
};
    string longestPrefix(string s) {
        int n=s.size();
        Hashing h(s);
        int maxi=-1;
        for(int i=0;i<n-1;i++){
            vector<ll>v1=h.getHash(0,i);
            vector<ll>v2=h.getHash(n-i-1,n-1);
            if(v1==v2){
                maxi=i;
            }
        }
        if(maxi==-1) return "";
        return s.substr(0,maxi+1);
    }
};

struct node{
    in sm=0;
    in pre=0;
};
 
vector<node>tree;
 
node merge(const node &a,const node &b){
    node n;
    n.sm=a.sm+b.sm;
    n.pre=max(a.pre,a.sm+b.pre);
    return n;
}
 
void build(in idx,in l,in r,vi &arr){
    if(l==r){
        node n;
        n.sm=arr[l];
        n.pre=arr[l];
        tree[idx]=n;
        return;
    }
    in m=(l+r)>>1;
    build(2*idx+1,l,m,arr);
    build(2*idx+2,m+1,r,arr);
    tree[idx]=merge(tree[2*idx+1],tree[2*idx+2]);
}
 
void update(in idx,in l,in r,in pos,in val,vi &arr){
    if(l==r){
        node n;
        arr[pos]=val;
        n.sm=arr[l];
        n.pre=arr[l];
        tree[idx]=n;
        return;
    }
    in m=(l+r)>>1;
    if(pos<=m) update(2*idx+1,l,m,pos,val,arr);
    else update(2*idx+2,m+1,r,pos,val,arr);
    tree[idx]=merge(tree[2*idx+1],tree[2*idx+2]);
}
 
node query(in idx,in l,in r,in ql,in qr){
    if(qr<l||r<ql){
        node n;
        return n;
    }
    if(ql<=l&&r<=qr){
        return tree[idx];
    }
    in m=(l+r)>>1;
    node left=query(2*idx+1,l,m,ql,qr);
    node right=query(2*idx+2,m+1,r,ql,qr);
    return merge(left,right);



    #include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // add val to index idx
    void update(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    // sum from 1 to idx
    long long query(int idx) {
        long long s = 0;
        for (; idx > 0; idx -= idx & -idx)
            s += bit[idx];
        return s;
    }

    // sum from l to r
    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }

    // value at index idx
    long long getValue(int idx) {
        return query(idx) - query(idx - 1);
    }

    // set index idx to newVal
    void setValue(int idx, long long newVal) {
        long long cur = getValue(idx);
        update(idx, newVal - cur);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // build array
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        ft.update(i, x);
    }

        int type;
        cin >> type;
        if (type == 1) {
            // set a[i] = x
            int i;
            long long x;
            cin >> i >> x;
            ft.setValue(i, x);
        } 
        else if (type == 2) {
            // range sum [l, r]
            int l, r;
            cin >> l >> r;
            cout << ft.rangeQuery(l, r) << '\n';
        }
    }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> tail;        // values
    vector<int> idx;               // indices of tail values
    vector<int> parent(n, -1);     // to rebuild path

    for (int i = 0; i < n; i++) {
        int pos = lower_bound(tail.begin(), tail.end(), a[i]) - tail.begin();

        if (pos == (int)tail.size()) {
            tail.push_back(a[i]);
            idx.push_back(i);
        } else {
            tail[pos] = a[i];
            idx[pos] = i;
        }

        if (pos > 0) parent[i] = idx[pos - 1];
    }

    // Reconstruct LIS
    vector<long long> lis;
    int cur = idx.back();
    while (cur != -1) {
        lis.push_back(a[cur]);
        cur = parent[cur];
    }
    reverse(lis.begin(), lis.end());

    cout << "Length of LIS: " << lis.size() << "\n";
    cout << "LIS sequence: ";
    for (auto x : lis) cout << x << " ";
    cout << "\n";

    return 0;
}
    long long int dp[20][2][2][500][20];
    long long int f(int n,string s,int tight,int st,int od,int aa){
        if(n==0){
            if((aa>=2)&&st&&(od==0)) return 1;
            return 0;
        }
        if(dp[n][tight][st][od+200][aa]!=-1) return dp[n][tight][st][od+200][aa];
        int limit=9;
        if(tight){
            limit=s[s.size()-n]-'0';
        }
        int y=s.size()-n;
        long long int curr=0;
        for(int i=0;i<=limit;i++){
            int x=0;
            if(tight&&i==limit) x=1;
            int z=1;
            if(i==0&&st==0) z=0;
            if(z){
                int a=aa+1;
                int p=od;
                if(a%2==0){
                    p-=i;
                }
                else{
                    p+=i;
                }
                curr+=f(n-1,s,x,1,p,a);
            }
            else{
                curr+=f(n-1,s,x,0,od,aa);
            }  
        }
        return dp[n][tight][st][od+200][aa]=curr;
    }
    long long countBalanced(long long low, long long high) {
        string s=to_string(high);
        memset(dp,-1,sizeof(dp));
        long long int p=f(s.size(),s,1,0,0,0);
        
        low--;
        s=to_string(low);
        memset(dp,-1,sizeof(dp));
        long long int q=f(s.size(),s,1,0,0,0);
        long long int ans=p-q;
        return ans;
    }

 
in dp[20][2][4];
in f(string s,in n,in tight,in cc){
    if(cc<0) return 0;
    if(n==0) return 1;
    if(dp[n][tight][cc]!=-1) return dp[n][tight][cc];
    in limit=9;
    if(tight){
        limit=s[s.size()-n]-'0';
    }
    in curr=0;
    fr(i,0,limit+1){
        in x=0;
        if(tight&&i==limit){
            x=1;
        }
        in ncc=cc;
        if(i) ncc--;
        curr+=f(s,n-1,x,ncc);
    }
    return dp[n][tight][cc]=curr;
}
 
in sol(in n){
    string s=to_string(n);
    n=s.size();
    memset(dp,-1,sizeof(dp));
    return f(s,n,1,3);
}
 
void solve(){
   in l,r;
   s(l);s(r);
   l--;
   in ans=sol(r)-sol(l);
   pn(ans);
   return;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a / __gcd(a, b)) * b
 
vi tree;
void build(in idx,in l,in r,vi &arr){
    if(l==r){
        tree[idx]=arr[l];
        return;
    }
    in m=(l+r)>>1;
    build(2*idx+1,l,m,arr);
    build(2*idx+2,m+1,r,arr);
    tree[idx]=max(tree[2*idx+1],tree[2*idx+2]);
}
 
void update(in idx,in l,in r,in pos,in val){
    if(l==r){
        tree[idx]-=val;
        return;
    }
    in m=(l+r)>>1;
    if(pos<=m) update(2*idx+1,l,m,pos,val);
    else update(2*idx+2,m+1,r,pos,val);
    tree[idx]=max(tree[2*idx+1],tree[2*idx+2]);
}
 
in query(in idx,in l,in r,in val){
    if(l==r){
        if(val>tree[idx]){
            return -1;
        }
        return l;
    }
    if(tree[idx]<val) return -1;
    in m=(l+r)>>1;
    if(tree[2*idx+1]>=val){
        return query(2*idx+1,l,m,val);
    }
    else{
        return query(2*idx+2,m+1,r,val);
    }
}
 
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) cout << i << " ";
    }


#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
    fast;


 vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // IMPORTANT: start from the smallest permutation
    sort(a.begin(), a.end());

    do {
        for (int x : a)
            cout << x << ' ';
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

bool nextPermutation(vector<int>& a) {
    int n = a.size();

    int i = n - 2;
    while (i >= 0 && a[i] >= a[i + 1])
        i--;

    // step 2: if no such index, this is the last permutation
    if (i < 0) {
        reverse(a.begin(), a.end());
        return false;
    }

    // step 3: find index j such that a[j] > a[i]
    int j = n - 1;
    while (a[j] <= a[i])
        j--;

    // step 4: swap
    swap(a[i], a[j]);

    // step 5: reverse suffix
    reverse(a.begin() + i + 1, a.end());

    return true;
}

