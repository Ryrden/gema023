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

struct Point {
    int x;
    int y;
};

void solve() {
    int n,m;cin>>n>>m;
    vector<vector<char>> matrix(n, vector<char>(m));
    vector<Point> start;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m;j++){
            char pos;cin >> pos;
            matrix[i][j] = pos;
            if (pos == '.'){
                start.pb({i,j});
            }
        }
    }

    auto check = [&](Point p) -> int {
        auto isThereWall = [&](int x, int y) -> bool {
            if (matrix[x][y] == '#')
                return true;
            return false;
        };
        //Check Up
        for(int i = p.x; i >= 0; i--){
            if (matrix[i][p.y] == 'D')
                return 0;
            if (isThereWall(i,p.y))
                break;
        }
        //Check Right
        for(int i = p.y; i < m; i++){
            if (matrix[p.x][i] == 'L')
                return 0;
            if (isThereWall(p.x,i))
                break;
        }
        //Check Down
        for(int i = p.x; i < n; i++){
            if (matrix[i][p.y] == 'U')
                return 0;
            if (isThereWall(i,p.y))
                break;
        }  
        //Check Left
        for(int i = p.y; i >= 0; i--){
            if (matrix[p.x][i] == 'R')
                return 0;
            if (isThereWall(p.x,i))
                break;
        }
        return 1;
    };

    int ans = 0;
    for(auto p : start){
        ans += check(p);
        if (ans > 1){
            cout << "MULTIPLE SOLUTIONS" << endl;
            return;
        }
    }
    cout << (ans ? "ONLY ONE SOLUTION" : "NO SOLUTION") << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}