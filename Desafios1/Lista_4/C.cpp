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

int memo[512][512];

int dp(int a, int b) {
    if (a < b) swap(a, b);
    if (a==b) return 0;

    int resp = INF;

    if (memo[a][b] != -1) return memo[a][b];

    for (int i= 1; i<= a/2; i++) {
        int cur = dp(i, b) + dp(a-i, b) + 1;
        resp = min(cur, resp);
    }

    for (int i= 1; i<= b/2; i++) {
        int cur = dp(a, i) + dp(a, b-i) + 1;
        resp = min(cur, resp);
    }

    return memo[a][b] = resp;
}

void solve() {
    int a, b;
    cin >> a >> b;   

    memset(memo, -1, sizeof(memo));

    cout << dp(a, b) << endl;
}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}