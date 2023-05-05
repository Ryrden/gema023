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
#define endl '\n'

using namespace std;

void solve() {
    int n,m; cin>>n>>m;
    if (n <= 1){
        cout << 0 << endl;
        return;
    }
    queue<int> elevator;
    for(int i=0;i<n;i++){
        int floor;cin>>floor;
        elevator.push(floor);
    }
    int dist = 0;
    int last_floor = elevator.front();
    elevator.pop();
    while(!elevator.empty()){
        int current_floor = elevator.front();
        dist += 4*abs(last_floor-current_floor);
        last_floor = current_floor;
        elevator.pop();
    }
    cout << dist << endl;
}   
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}