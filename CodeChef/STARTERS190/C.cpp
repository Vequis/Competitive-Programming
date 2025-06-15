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

int dp[212345]; // minima hab que da pra chegar em i
int a[212345];
int b[212345];
bool resp[212345];
int maxhab[212345]; // max_hab que da pra finalizar i

void solve() {
    
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <=n; i++) cin >> a[i];
    for (int i = 1; i<=n; i++) cin >> b[i];

    dp[0] = x;
    for (int i = 1; i <=n; i++) {
        int last = dp[i-1];
        last = max(last, a[i]);

        dp[i] = last - (last >= b[i]);
        // cout <<'*' << dp[i] << endl;
    }

    int m = dp[n];
    // cout << m << endl;

    for (int i =n-1; i>=1; i--) {
        if (dp[i] < dp[i+1]) dp[i] = dp[i+1];
    }

    maxhab[n] = dp[n];
    for (int i = n-1; i>=1; i--) {
        maxhab[i] = (maxhab[i+1]);
        int proposta = maxhab[i+1] + 1;
        if (proposta >= b[i+1]) maxhab[i] = min(maxhab[i] + 1, x);

        // cout << '*' << maxhab[i] << endl;
    }

    int maxima_habilidade = x-m;

    for (int i = n; i>=1; i--) {
        // cout << i << ' ' << dp[i] << ' ' << maxhab[i] << endl;
        if (dp[i] != dp[i-1] or dp[i-1] < maxhab[i-1]) resp[i] = 1;
        else resp[i] = 0;
    }

    for (int i = 1; i <= n; i++) cout << resp[i];
    cout << endl;
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