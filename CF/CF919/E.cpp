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
#define MODN 998244353
#define int long long // -> solução divina

using namespace std;

int k;

int memo[2510][2510];

void solve() {
    int n;
    cin >> n >> k;
    // memset(memo, 0, sizeof(memo));


    int resp = 0;
    // for(int i = 0; i <=k; i++) resp= (resp + dp(n, i))%MODN;
    
    for(int i = 0; i<= k; i++) memo[0][i] = 1;

    for (int sum = 1; sum <=n; sum++) {
        for (int r = 0; r <=k; r++) {
            // memo[sum][r] = 1;
            memo[sum][r] = 0;
            for(int l = 0; l+1+r <= k and (sum - (l+1)*(r+1) >= 0); l++) {
                memo[sum][r] = (memo[sum][r] + memo[sum - (l+1)*(r+1)][l])%MODN;
            }

            // cout << sum << ' ' << r << ' ' << memo[sum][r] << endl;
        }
    }

    for(int i = 0; i <=k; i++) resp = (resp + memo[n][i])%MODN;

    cout << resp <<endl;


}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
