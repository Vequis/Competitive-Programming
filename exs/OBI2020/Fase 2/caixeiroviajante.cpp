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

int n;
int dp[2][1500][1500];
int dist[1600][1600];

signed main(){_

    cin >> n;

    // memset(memo, -1, sizeof(memo));

    for(int i=1; i<=(n*(n-1))/2; i++){
        int a, b;
        cin >> a >> b;
        int custo;
        cin >> custo;

        dist[a][b] = custo;
        dist[b][a] = custo;
    }

    dp[0][1][1] = 0;

    for(int i=2; i<=n; i++){
        dp[1][i-1][i] = dp[0][i-1][1] + dist[1][i];
        for(int j=1; j<i-1; j++){
            
            dp[1][j][i] = dp[0][j][i-1] + dist[i-1][i];
            
            dp[1][i-1][i] = min(dp[0][i-1][j] + dist[j][i], dp[1][i-1][i]); 
        }

        for(int j=1; j<=i-1; j++){
            dp[0][j][i] = dp[1][j][i];
            dp[0][i][j] = dp[0][j][i];
        }

    }

    int resp = INT_MAX;
    for(int i=1; i<=n-1; i++){
        resp = min(resp, dp[1][i][n]);
    }

    cout << resp << endl;

    return 0;
}
