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

const int MAXN = 1e+5;

set<int> graph[MAXN];
bool visited[MAXN];
vector<pi> friendship;

bool dfs(int curr, int target){
    visited[curr] = true;
    if (curr == target)
        return true;
    for(int v : graph[curr]){
        if(not visited[v]){
            if (dfs(v,target)) return true;
        }
    }
    return false;
}

void solve() {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    for(int i=0,u,v;i<m;i++){ 
        cin>>u>>v;
        graph[u].insert(v);
        graph[v].insert(u);

        friendship.pb({u,v});
    }
    bool canReachMariazinha = dfs(a,b);
    if (not canReachMariazinha)
        cout << "NAO" << endl;
    else {
        for(int i = 0; i < m; i++){ // O(m)
            int friend1 = friendship[i].first;
            int friend2 = friendship[i].second;

            fill(visited,visited+MAXN,false); // O(n)

            graph[friend1].erase(friend2); // O(log m)
            graph[friend2].erase(friend1); // O(log m)

            canReachMariazinha = dfs(a,b); // O(n+m)
            
            if (not canReachMariazinha){
                cout << "NAO" << endl;
                return;
            }

            graph[friend1].insert(friend2); // O(log m)
            graph[friend2].insert(friend1); // O(log m)
        }
        cout << "SIM" << endl;
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