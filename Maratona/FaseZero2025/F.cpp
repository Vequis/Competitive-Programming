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

int dp[3][1001][6002];

signed main(){_
    int n;
    cin >> n;

    vi v(n+1);

    for (int i = 1; i <=n; i++) {
        cin >> v[i];
        v[i] = v[i] + 1000;
    }


    for (int i = 1; i<=n; i++) {
        for (int j = 0; j<= 6000; j++) {
            dp[0][i][j] = dp[0][i-1][j];
            dp[1][i][j] = dp[1][i-1][j];
            dp[2][i][j] = dp[2][i-1][j];

            if (j - v[i] >= 0) {
                dp[1][i][j] += dp[0][i-1][j - v[i]];
                dp[2][i][j] += dp[1][i-1][j - v[i]];
            }
        }

        dp[0][i][v[i]]++;
    }

    int q;
    cin >> q;

    while(q--) {
        int num;
        cin >> num;

        num = num + 4000;

        int resp = 0;
        for (int i = 1; i<=n; i++) {
            if (num - v[i] <= 6000 and num - v[i] >= 0) {
                resp += dp[2][i-1][num - v[i]];
            }
        }

        cout << resp << endl;
    }


    return 0;
}