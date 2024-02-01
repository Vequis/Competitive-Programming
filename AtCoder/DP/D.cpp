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

int memo[111][112345];
int w[111];
int v[111];

int dp(int n, int capacidade) {
    if (capacidade < 0) return -INF;
    if (n == 0) return 0;

    if (memo[n][capacidade] != -1) return memo[n][capacidade];

    // int resp = max(dp(n-1, capacidade), dp(n-1, capacidade - w[n]) + v[n]);
    // cout << n << ' ' << capacidade << ' ' << resp << endl;

    return memo[n][capacidade] = max(dp(n-1, capacidade), dp(n-1, capacidade - w[n]) + v[n]);
}

signed main(){_

    int n, we;
    cin >> n >> we;

    memset(memo, -1, sizeof(memo));

    for(int i = 1; i <=n; i++) cin >> w[i] >> v[i];

    cout << dp(n, we) << endl;

    return 0;
}
