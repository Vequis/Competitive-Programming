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
vector<vi> h(112345, vi(2));
int memo[112345][2];

int dp(int x, int r){ //Ultimo considerado/ Fila atual
    if (x>n) return 0;

    if(memo[x][r] != -1) return memo[x][r];

    return memo[x][r] = max(dp(x+1, r), dp(x+1, 1-r) + h[x][r]);
}

signed main(){_

    cin >> n;

    memset(memo, -1, sizeof(memo));

    for(int i=1; i<=n; i++) cin >> h[i][0];
    for(int i=1; i<=n; i++) cin >> h[i][1];

    // for(int i=1; i<=n; i++){
    //     for(int j=0; j<=1; j++){
    //         cout << dp(i, j) << ' ';
    //     }
    //     cout << endl;
    // }
    cout << max(dp(0, 1), dp(0, 0)) << endl;


    return 0;
}
