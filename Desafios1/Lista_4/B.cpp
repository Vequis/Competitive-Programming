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

int n, m, b, modulo;
int a[512];
int memo[512][512];
int ant[512][512];
// x : amigo
// d : Linha atual

/*
int dp(int x, int d, int erros) {
    if (x > n) return 0;
    if (d > m) return 1;

    if (memo[x][d][erros] != -1) return memo[x][d][erros];

    if (a[x] + erros > b) {
        return memo[x][d][erros] = dp(x+1, d, erros);
    } else {
        return memo[x][d][erros] = (dp(x+1, d, erros) + dp(x, d+1, erros + a[x]))%modulo;
    }
}
*/

void solve() {
    cin >> n >> m >> b >> modulo;

    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(memo, -1, sizeof(memo));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

        }
    }

    //cout << dp(1, 1, 0) << endl;
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