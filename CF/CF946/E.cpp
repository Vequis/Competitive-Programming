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

int c[52];
int h[52];
int memo[52][112345];
int m, x;
int comp = 0;

int dp(int n, int hap) { // Minimo custo para chegar no dia n com felicidade hap

    if (hap==0) return 0;
    if (n <= 0)return comp;
    if (hap < 0) return comp;
    if (memo[n][hap] != comp ) return memo[n][hap];

    int resp = min(dp(n-1, hap), dp(n-1, hap - h[n]) + c[n]);
    // cout << hap << ' ' << n << ' ' <<  resp << endl;
    if (resp <=  (n-1)*x) return resp;
    else return comp;
}

void solve() {
    cin >> m >> x;
    int limiar = 0;

    memset(memo, INF, sizeof(memo));
    for (int i = 1; i <=m; i++) cin >> c[i] >> h[i];
    for (int i = 1; i <=m; i++) limiar += h[i];

    comp = memo[m][112344]; 
    // cout << dp(m, 112344) << endl;
    // cout << INF << endl;

    // int ini = 0, fim = limiar;
    // int mid;
    // while(ini < mid) {
    //     mid = ini + (fim - ini)/2;
    //     if (dp(m, mid) != comp)
    // }

    for (int i = limiar; i >= 0; i--) if (dp(m, i) != comp) {
        cout << i << endl;
        return;
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