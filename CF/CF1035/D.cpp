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
#define INFLL 0x3f3f3f3f3f3f3f3
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int n, m;

int last[5123]; // last[k] = dp[x+1][k]
int cur[5123]; // cur[k] = dp[x][k]

int soma(int a, int b) {
    return (a+b)%m;
}

int mult(int a, int b) {
    return (a*b)%m;
}

void solve() {
    cin >> n >> m;

    last[0] = 1;
    for (int i = 1; i <= n+1; i++) last[i] = 0;

    for (int i = n; i>=1; i--) {

        for (int k = 1; i+k <= n+1; k++) {
            // cout << last[k] << ' ' << i << ' ' << n+2-i-k << last[k-1] << endl;
            cur[k] = soma(last[k], mult(i, mult(n+2 - i - k, last[k-1])));
        }

        for (int k = 1; i+k <= n+1; k++) {
            last[k] = cur[k];
        }
    }

    int resp = 0;
    for (int i = 0; i <= n; i++) {
        resp = (resp + last[i])%m;
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