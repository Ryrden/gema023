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
#define _ >> ' ' >>

using namespace std;

//Interaction

void solve() {
    int answer = 1;
    int s = 1;
    int e = 10;
    while(answer != 2){
        int mid = (s+e)/2;
        cout << mid << endl;
        fflush(stdout);
        cin >> answer;

        if (answer){
            s = mid+1;
        }else {
            e = mid-1;
        }

    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t = 1; //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}