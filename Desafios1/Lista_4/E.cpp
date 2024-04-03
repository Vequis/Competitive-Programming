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

int n;

char grid[1123][1123];
int dp[1123][1123];

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> grid[i][j];
    }

    for (int i = 0; i <=n; i++) {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    if (grid[1][1] != '*') dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 and j == 1) continue;
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%MODN;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n][n] << endl;
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