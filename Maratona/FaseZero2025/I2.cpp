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

int dp[5123][123]; // dp[i][j] = max valor no tempo j usando usando o que esta em i
int psa[5123][123];

signed main(){_

    int n, t;
    cin >> n >> t;

    for (int i = 1; i <=n; i++) psa[i][0] = 0;

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j<=t; j++) {
            int x;
            cin >> x;
            psa[i][j] = psa[i][j-1] + x;
        }
    }

    int l, u;
    cin >> l >> u;

    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=t; j++) dp[i][j] = -1;
    }

    for (int i = 1; i<=n; i++) {
        dp[i][0] = 0;
    }    

    for (int j = 1; j<=t; j++) {
        for (int i = 1; i<=n; i++){
            for (int delta = l; delta <= u; delta++) {
                if (j - delta < 0) {
                    break;
                }

                if (j-delta == 0) dp[i][j] = max(dp[i][j], psa[i][j]);

                for (int k = 1; k <=n; k++) {
                    if (k == i) continue;

                    if (dp[k][j-delta] != -1) {
                        dp[i][j] = max(dp[i][j], dp[k][j-delta] + psa[i][j] - psa[i][j-delta]);
                    }
                }

            }

        }
    }

    int resp = -1;
    for (int i = 1; i<=n; i++) {
        resp = max(resp, dp[i][t]);
    }
    cout <<resp << endl;

    return 0;
}