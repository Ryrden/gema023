#include <bits/stdc++.h>

#define ll long long int
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define hashMap unordered_map
#define minHeap priority_queue<int, vector<int>, greater<int>>
#define maxHeap priority_queue<int>
#define print(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< ' '; cout << endl
#define printArray(arr) for(auto x : arr) cout << x << ' '; cout << endl;
#define _ << ' ' <<

using namespace std;

void solve() {
    ll n,m;cin>>n>>m;
    vector<ll> v;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        v.pb(x);
    }
    while(m--){
        ll x;cin>>x;
        ll s=0,e=n-1;
        ll minDiff = INT_MAX;
        ll ans = INT_MAX;
        while(s<=e){
            ll mid = (s+e)/2;
            if (abs(v[mid]-x) == 0){
                ans = v[mid];
                break;
            } else if (v[mid] > x){
                e = mid-1;
            }else{
                s = mid+1;
            }
            if (abs(v[mid]-x) < minDiff){
                ans = v[mid];
                minDiff = abs(v[mid]-x);
            } else if (abs(v[mid]-x) == minDiff && v[mid] < ans){
                ans = v[mid];
            }
        }
        cout << ans << endl;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}