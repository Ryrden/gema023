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

const int MAXN = 1e5+5;

vector<int> adj[MAXN];
int visited[MAXN];
set<int> team[3];

void dfs(int curr, int paint){
    if (visited[curr]) return;
    visited[curr] = true;
    //team[paint].insert(curr);
    for(int vtx : adj[curr]){
        if (team[paint].find(vtx) != team[paint].end()){
            cout << -1 << endl;
            return;
        }else{
            team[paint].insert(vtx);
        }
        paint = paint == 1 ? 2 : 1;
        dfs(vtx,paint);
    }
}

void solve() {
    int n,m;cin>>n>>m;
    for(int i=0,u,v;i<m;i++){
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i = 1; i < n; i++){
        dfs(i,1);
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