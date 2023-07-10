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

const int MAXN = 205;

int height[MAXN];
vector<int> adj[MAXN];
int memo[MAXN];

void _solve(int u){
    if (memo[u] != -1) return memo[u];

    memo[u] = 1;
    for(int v : adj[u]){
        memo[u] = max(memo[u], 1 + solve(v));
    }
}

void solve() {
    int n,m,s; cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) cin >> height[i];
    for(int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        if (height[u] > height[v]) adj[u].pb(v);
        else if (height[v] > height[u]) adj[v].pb(u);
    }
    memset(memo, -1, sizeof(memo));

    cout << solve(s) - 1 << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}