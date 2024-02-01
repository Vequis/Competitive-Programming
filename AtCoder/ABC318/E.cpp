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

vi pos[312345];
int dp[312345];

signed main(){_

    int n;
    cin >> n;

    int resp = 0;

    for(int i = 1; i <=n; i++) dp[i] = 0;

    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        // for (int j = 0; j < pos[a].size(); j++) {
        //     resp += i - pos[a][j] - 1 - j;
        // }

        int x = pos[a].size();
        if (x >= 1) {
            // dp[a] = (i - pos[a][x-1] - 1 + dp[a])*x;
            dp[a] = (i - pos[a][x-1] - 1)*x + dp[a];
            resp += dp[a];
            // cout << resp << endl;
        }

        // cout << resp << endl;

        pos[a].pb(i);
    }

    cout << resp << endl;

    return 0;
}
