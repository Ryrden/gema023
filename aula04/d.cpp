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

int binary_search(int plates, int pieceA, int pieceB){
    int start = 1;
    int pieceSum = pieceA + pieceB;
    int end = pieceSum;
    int ans = 1;
    while(start + 1 < end){
        int mid = (start+ 1 + end) / 2;
        int cakeToPlates = (pieceA/mid + pieceB/mid);
        if (pieceA >= mid && pieceB >= mid && cakeToPlates >= plates){
            ans = mid;
            start = mid;
        }else {
            end = mid;
        }
    }
    return ans;
}

void solve(){
    int n,a,b;
    cin>>n>>a>>b;

    cout << binary_search(n,a,b) << endl;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();

    return 0;
}