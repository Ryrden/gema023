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

vector<int> graph[MAXN];
bool visited[MAXN];
vector<int> dist(MAXN);
//vector<int> path(MAXN);

int bfs(int v){
    queue<int> q;
    q.push(v);
    visited[v] = true;
    //path[v] = -1;
    
    while(not q.empty()){
        int vtx = q.front();
        q.pop();    

        for(int u : graph[vtx]){
            if (not visited[u]){
                visited[u] = true;
                dist[u] = dist[vtx] + 1;
                q.push(u);
                //path[u] = vtx;
            }
        }
    }
}



void solve() {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    for(int i=0,u,v;i < m;i++){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    bfs(a);

    if (visited[b]){
        cout << dist[b] << endl;
    }else{
        cout << -1 << endl;
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