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

int memo[123][11234];
int a[123];
int b[123];

int dp(int suf, int s) { // Da para fazer a soma s usando os suf primeiros indices dos vetores?
    if (suf == 0 and s == 0) return 1;
    if (suf <= 0 or s <= 0) return 0;

    if (memo[suf][s] != -1) return memo[suf][s];

    return memo[suf][s] = dp(suf - 1, s - a[suf]) || dp(suf - 1, s - b[suf]);
} 

signed main(){_

    int t;

    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        memset(memo, -1, sizeof(memo));

        for(int i = 1; i<=n; i++) cin >> a[i];
        for(int i = 1; i<=n; i++) cin >> b[i];

        int somaTotal = 0;
        int somaq = 0;

        for(int i = 1; i <=n; i++) {
            somaTotal+=a[i] + b[i];
            somaq+=a[i]*a[i] + b[i]*b[i];
        }

        int maxi = INF;
        for(int i = 0; i <=somaTotal; i++) {
            if (dp(n, i)) maxi = min(maxi, i*i + (somaTotal - i)*(somaTotal - i));
        }

        cout << maxi + (n-2)*(somaq) << endl;
    }

    return 0;
}
