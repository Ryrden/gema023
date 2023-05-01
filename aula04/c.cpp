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

using namespace std;

//Solution Without Binary Search
void solve2() {
    int candiesCount = 0;
    cin >> candiesCount;
    int candies[candiesCount];
    int candieWeight = 0;
    for(int i=0; i<candiesCount; i++){
        int w;cin>>w;
        candies[i] = w;
    }
    //printArray(candies);
    int aliceCount = 0;
    int bobCount = 0;

    int ans = 0;

    int cnt = 0;
    int start = 0;
    int end = candiesCount - 1;
    while (start <= end){
        if (aliceCount > bobCount){
            bobCount += candies[end--];
            cnt++;
        } else if (aliceCount < bobCount){
            aliceCount += candies[start++];
            cnt++;
        }
        if (aliceCount == bobCount){
            ans = cnt;
            aliceCount += candies[start++];
            cnt++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;cin>>t;
    while(t--){
        //solve2();
        solve();
    }

    return 0;
}