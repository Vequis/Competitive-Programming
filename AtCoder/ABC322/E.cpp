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
#define INF 11234567891234
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int memo[101][6][6][6][6][6];
int a[101][7];
int c[101];

int knapsack(int n, int w1, int w2, int w3, int w4, int w5) {
    if (w1 < 0) w1=0;
    if (w2 < 0) w2=0;
    if (w3 < 0) w3=0;
    if (w4 < 0) w4=0;
    if (w5 < 0) w5=0;

    if (w1 == 0 and w2 == 0 and w3 == 0 and w4 ==0 and w5 == 0) return 0;
    if (n==0) return INF;

    if (memo[n][w1][w2][w3][w4][w5] != -1) return memo[n][w1][w2][w3][w4][w5];

    return memo[n][w1][w2][w3][w4][w5] = min(c[n] + knapsack(n-1, w1 - a[n][1], w2 - a[n][2], w3 - a[n][3], w4 - a[n][4], w5 - a[n][5]), knapsack(n-1, w1, w2, w3, w4, w5));

}

signed main(){_

    int n, k, p;

    cin >> n >> k >> p;

    memset(memo, -1, sizeof(memo));

    for(int i = 1; i <=n; i++) {
        cin >> c[i];
        for(int j = 1; j <= k; j++) {
            cin >> a[i][j];
        }

        for(int j = k+1; j<=n; j++) {
            a[i][j] = 0;
        }
    }

    int w[7];

    for(int i = 1; i <=k; i++) w[i] = p; 
    for(int i = k+1; i<6; i++) w[i] = 0;
 
    // for (int i = 1; i <= 5; i++) {
    //     cout << i << ' ' << w[i] << endl;
    // }

    int resp = knapsack(n, w[1], w[2], w[3], w[4], w[5]);
    if (resp > INF - 1000) cout << -1 << endl;
    else {
        cout << resp << endl;
    }
    // cout << knapsack(n, w[1], w[2], w[3], w[4], w[5]) << endl;

    return 0;
}
