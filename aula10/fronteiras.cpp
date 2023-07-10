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

const int INF = 0x3f3f3f3f;

const int MAXN = 1e5+5;

void solve() {
    int t; cin>>t;
    int n; cin>>n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int minDist = INT_MAX;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int front, back;
        if (i == 0) back = 0;
        else back = v[i] + v[i-1];

        if (i == i-1) front = 2*t;
        else front = v[i+1] + v[i];

        ans = min(ans, front - back);
    }

    cout << fixed << setprecision(2);
    cout << ans/2.0 << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}