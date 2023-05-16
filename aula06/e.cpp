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
    vector<pair<int,int>> v(n);
    int idx = 0;
    for(int i = 0; i < n; i++){
        cin>>v[i].first;
        v[i].second = i;
    }
    sort(v.rbegin(),v.rend());

    queue<int> bestStudents;
    for(int i = 0; i < n; i++){
        bestStudents.push(v[i].second);
    }
    set<int> studentsPos;
    for(int i = 0; i < n; i++){
        studentsPos.insert(i);
    }
    string ans(n,'0');
    char coach = '1';
    while(!studentsPos.empty()){
        //while the best student is not in the set of choosen students
        while(!studentsPos.count(bestStudents.front())){
            bestStudents.pop();
        }
        int pos = bestStudents.front();
        bestStudents.pop();

        vector<int> studentsToRemove;

        //expand the team to the left
        auto leftTeamStart = studentsPos.find(pos);
        for(int i = 0; i <= k; i++){
            studentsToRemove.pb(*leftTeamStart);
            if(leftTeamStart == studentsPos.begin()) break;
            leftTeamStart--;
        }

        //expand the team to the right
        auto rightTeamEnd = next(studentsPos.find(pos));
        for(int i = 0; i < k; i++){
            if(rightTeamEnd == studentsPos.end()) break;
            studentsToRemove.pb(*rightTeamEnd);
            rightTeamEnd++;
        }
        for(auto x : studentsToRemove){
            studentsPos.erase(x);
            ans[x] = coach;
        }
        coach = (coach == '1') ? '2' : '1';
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