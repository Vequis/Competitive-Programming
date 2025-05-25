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

int dp[123]; // dp[i][j] = max valor no tempo j usando os i primeiros
int psa[5123][123];

signed main(){_

    int n, t;
    cin >> n >> t;

    for (int i = 1; i <=n; i++) psa[i][0] = 0LL;

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j<=t; j++) {
            int x;
            cin >> x;
            psa[i][j] = psa[i][j-1] + x;
        }
    }

    int l, u;
    cin >> l >> u;

    for (int j = 1; j<=t; j++) dp[j] = -1LL;
    dp[0] = 0LL;

    for (int j = 1; j<=t; j++) {
        for (int delta = l; delta <= u; delta++) {
            if ((j - delta) < 0LL or dp[j-delta] == -1LL) continue;

            int maior = -1LL;
            for (int i = 1; i<=n; i++) {
                maior = max(maior, psa[i][j] - psa[i][j-delta]);
            }

            dp[j] = max(dp[j], dp[j-delta] + maior);
        }
    }

    cout << dp[t] << endl;

    return 0;
}