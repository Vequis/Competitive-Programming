#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

// O(N log N)
vector<int> compress(const vector<int>& a) {
    vi sorted = a;
    sort(all(sorted));
    sorted.erase(unique(all(sorted)), sorted.end());

    vi compressed;
    for (int val : a) {
        int idx = lower_bound(all(sorted), val) - sorted.begin();
        compressed.pb(idx);
    }

    return compressed;
}

void solve() {
    
}

signed main(){_
    // vi original = {100, 500, 100, 2000, 500};
    // vi compressed = compress(original);
    
    // for (int x : compressed) {
    //     cout << x << ' ';
    // }
    // cout << endl;
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}