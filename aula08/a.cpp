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

vector<pi> adj[MAXN]; // {vertex, weight}
int dist[MAXN];

void dijkstra(int s){
    memset(dist, INF, sizeof(dist));
    dist[s] = 0;
    priority_queue<pi, vector<pi>, greater<pi>> pq; // {dist, vertex}
    pq.push({0, s});
    while(!pq.empty()){
        int v = pq.top().second; 
        int vDist = pq.top().first;
        pq.pop();
        
        if(vDist > dist[v]) continue;

        for(auto [u,w] : adj[v]){
            if(dist[v] + w < dist[u]){
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }
}


void solve() {
    int n,m,a;cin>>n>>m>>a;
    for(int i=0,u,v,w; i<m; i++){
        cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dijkstra(a);
    for(int i=1; i<=n; i++){
        cout << (dist[i] != INF ? dist[i] : -1) << endl;
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