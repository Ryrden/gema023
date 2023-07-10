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
    int a,l;
    int n;
    cin>>a>>l;
    cin>>n;
    int maxArea = INT_MIN;
    int ans = 0;
    int cnt = 1;
    while(n--){
        int x,y;
        cin>>x>>y;
        if ((a <= x and l <= y) or (l <= x and a <= y)){
            maxArea = max(maxArea, x*y);
            ans = cnt;
        }
        cnt++;
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}