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

void solve() {
    int n;
    cin >> n;

    int zeros = 0;
    int neg = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        zeros = zeros or (x == 0);
        neg = neg xor (x < 0);
    }   

    if (zeros or neg) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
        cout << 1 << ' ' << 0 << endl;
    }

}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}