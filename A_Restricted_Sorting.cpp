#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve(){
    ll n;
    cin>>n;
    vector <ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    vector <ll> s(a);
    sort(a.begin(),a.end());
    ll large =-1;
    for(ll i =0;i<n;i++){
        ll cdiff=s[i]-a[i];

        large=max(large,abs(cdiff));
    }
    if(large==0){
        cout<<"-1"<<endl;
        return;
    }
    cout<<large<<endl;

    

}
int main(){

    int tc;
    cin>>tc;
    while(tc--){
        solve();
    }



}