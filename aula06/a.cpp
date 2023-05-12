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
    int n;cin>>n;
    map<string,string> m;
    while(n--){
        string name, day;
        cin>>name>>day;
        if (m.count(name) == 0)
            m.insert({name,day});
    }
    int wed = 0;
    int fri = 0;
    for(auto [key,value] : m){
        value == "quarta" ? wed++ : fri++;
    }
    if (wed > fri)
        cout << "quarta" << endl;
    else if (wed < fri)
        cout << "sexta" << endl;
    else
        cout << "empate" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}