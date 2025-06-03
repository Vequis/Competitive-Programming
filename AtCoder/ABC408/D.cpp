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

int psa[212345];
int dp[212345];

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    s = '%' + s;

    psa[0] = 0;
    for (int i = 1; i <=n; i++) {
        psa[i] = psa[i-1] + (s[i] == '1');
    }

    dp[n+1] = 0;
    for (int i = n; i>=1; i--) {
        dp[i] = min(dp[i+1], psa[n] - psa[i]) + (s[i] == '0');
    }

    int resp = psa[n];
    for (int i = 1; i <=n; i++) {
        // cout << i << ' ' << dp[i] << ' ' << psa[i-1] << endl;
        resp = min(resp, dp[i] + psa[i-1]);
    }
    cout << resp << endl;

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