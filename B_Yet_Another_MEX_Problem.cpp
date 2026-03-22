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

void solve() {
    in n,k;
    s(n);
    s(k);
    vi arr(n);
    fr(i,0,n)  s(arr[i]);    
    // map<in,in>mp;
    vi v(n+5,0);
    fr(i,0,n) v[arr[i]]++;
    in x=n-k+1;
    in cc=0;
    in f=0;
    fr(i,0,n+5){
        if(i==cc&&v[i]>0){
            cc++;
        }
        else{
            break;
        }
    }
    // if(x<0){
    //     pn(cc);
    //     return;
    // }
    // vi v(n)
    // for(in i=v.size()-1;i>=cc;i--){
    //     x-=v[i];
    // // }
    // if(x<=0){
    //     pn(cc);
    //     return;
    // }
    // // pn(cc);
    // for(in i=cc-1;i>=0;i--){
    //     if(v[i]==0) continue;
    //     x-=v[i];
    //     if(x==0){
    //         pn(i);
    //         return;
    //     }
    //     if(x<0){
    //         pn(i+1);
    //         return;
    //     }
    //     // if(x-cc==0){
    //     //     pn(i);
    //     //     return;
    //     // }

    // }
    // pn(cc);
    fr(i,0,v.size()){
        if(v[i]>1){
            x-=(v[i]-1);
            v[i]=1;
        }
    }
    if(x<=0){
        pn(cc);
        return;
    }
     for(in i=v.size()-1;i>=cc;i--){
        x-=v[i];
    }
    if(x<=0){
        pn(cc);
        return;
    }
       for(in i=cc-1;i>=0;i--){
        if(v[i]==0) continue;
        x-=v[i];
        if(x==0){
            pn(i);
            return;
        }
        if(x<0){
            pn(i+1);
            return;
        }
        // if(x-cc==0){
        //     pn(i);
        //     return;
        // }

    }
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
