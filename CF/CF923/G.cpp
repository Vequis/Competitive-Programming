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

//dp[i][{0, 1, 2}] => dp para cobrir até i 
// 0 - não utilizando a tinta em ai
// min(dp[j][1]) tal que i - j < a[j]
// 1 - utilizando para direita
// dp[i-1] + 1 =1 + min{dp[i-1][{0, 1, 2}]}
// 2 - utilizando para esquerda
// dp[i - a[i]] + 1

int a[11234];
int memo[123][3];

int dp(int n);

int dp(int n, int x) {
    if (n<=0) return 0;

    if (memo[n][x] != -1) return memo[n][x];

    if (x == 0) {
        int resp = INF;
        for(int j =1; j< n; j++) {
            if (n - j < a[j]) resp = min(resp, dp(j, 1));
        }
        return memo[n][x] = resp;
    } else if (x == 1) {
        return memo[n][x] = dp(n - 1) + 1;
    } else {
        memo[n][x] = dp(n - a[n]) + 1;
        for (int i = 1; i < n; i++){
            memo[i][0] = min(memo[i][0], memo[n][x]);
            memo[i][1] = min(memo[i][1], dp(i - 1) + 1);
            memo[i][2] = min(memo[i][2], dp(i - a[i]) + 1);
        }
        return memo[n][x];
    }
}

int dp(int n) {
    int a = dp(n, 1);
    int b = dp(n, 2);
    return min(dp(n, 0), min(a, b));
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {

        memset(memo, -1, sizeof(memo));
        int n;
        cin >> n;

        memo[0][1] = INF;

        for(int i = 1; i <=n; i++) cin >> a[i];

        cout << dp(n) << endl;

        for(int i = 1; i <=n; i++) {
            cout << dp(i, 0) << ' ' << dp(i, 1) << ' ' << dp(i, 2) << endl;
        }
    }

    return 0;
}
