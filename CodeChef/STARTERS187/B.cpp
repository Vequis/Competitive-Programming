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

string s;
int dp[212345];

bool inverting_last_4(int i) {
    if (i < 3) return false;
    return (s[i] == s[i-2] and s[i-1] == s[i-3] and s[i] != s[i-1]);
}

void solve() {
    int n;
    
    cin >> n;

    cin >> s;

    dp[0] = dp[1] = dp[2] = 1;
    for (int i = 3; i<n; i++) {
        dp[i] = dp[i-1];
        if (inverting_last_4(i)) dp[i] = (dp[i] + dp[i-3])%MODN;
    }

    cout << dp[n-1] << endl;

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