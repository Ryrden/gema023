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

void solve() {
    int n,k;cin>>n>>k;
    vector<int> dmg(n);
    for(int i = 0; i < n; i++){
        cin>>dmg[i];
    } 
    ll ans = 0;
    
    priority_queue<int> pq[27];
    string s;cin>>s;
    int i = 0;
    int j = 0;
    while(i < n){
        while(j < n && s[i] == s[j]) {
            pq[s[i] - 'a'].push(dmg[j]);
            j++;
        }
        int cnt = 0;
        for(int idx = i; idx < j; idx++){
            if(cnt == k) break;
            else if(cnt < k){
                ans += pq[s[idx] - 'a'].top();   
            }
            pq[s[idx] - 'a'].pop();
            cnt++;
        }
        while(!pq[s[i] - 'a'].empty()) pq[s[i] - 'a'].pop();
        i = j;
    }
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}