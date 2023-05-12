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
#define printStack(s) while(!s.empty()){cout << s.top() << ' '; s.pop();} cout << endl;
#define printQueue(q) while(!q.empty()){cout << q.front() << ' '; q.pop();} cout << endl;
#define printMap(m) for(auto x : m) cout << x.first << ' ' << x.second << endl;
#define _ << ' ' <<
#define endl '\n'

using namespace std;

void solve() {
    ll n;cin>>n;
    vector<ll> price(n);
    vector<int> fcolor(n);
    vector<int> bcolor(n);
    ll buyers;
    
    for(int i = 0; i < n;i++){
        cin >> price[i];
    }
    for(int i = 0; i < n;i++){
        cin >> fcolor[i];
    }
    for(int i = 0; i < n;i++){
        cin >> bcolor[i];
    }
    //ALL PRICES ARES DISTINCT -> JUST USE AS KEY 
    set<ll> stockColor[4];
    for(int i = 0; i < n; i++){
        stockColor[fcolor[i]].insert(price[i]);
        stockColor[bcolor[i]].insert(price[i]);
    }
    cin >> buyers;
    int favColor;
    for(int i = 0; i < buyers;i++){
        cin >> favColor;
        if (stockColor[favColor].empty()){
            cout << -1 << ' ';
        }else{
            ll price = *stockColor[favColor].begin();
            cout << price << ' ';
            for(int j = 0; j <= 3; j++){
                stockColor[j].erase(price);
            }
        }
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