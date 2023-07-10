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

vector<pi> adj[MAXN];
int dist[MAXN];
vector<int> finalAdj;
int path[14];

void dijkstra(int a, int b){
    memset(dist, INF, sizeof(dist));
    dist[a] = 0;
    path[a] = -1;
    priority_queue<pi, vector<pi>, greater<pi>> pq; // {weight, vtx}
    pq.push({0,a});

    while(not pq.empty()){
        int u = pq.top().second;
        int uDist = pq.top().first;
        pq.pop();

        if (uDist > dist[u]) continue;

        for(auto [v,w] : adj[u]){
            if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                path[v] = u;
            }
        }
    }
}

void solve() {
    int n,m,a,b;cin>>n>>m>>a>>b;
    vector<pi> check;
    for(int i=0,u,v,w; i < m;i++){
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
        check.pb({u,v});
    }
    dijkstra(a,b);
    
    set<int> newPath; 
    for(auto [vtx, w] : adj[b]){
        cout << vtx << endl;
    }
    printArray(newPath);
    printArray(finalAdj);
    for(int i = 1; i <= n; i++){
        if (newPath.count(adj[i][0].first))
            cout << "sim" << endl;
        else
            cout << "nao" << endl;
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