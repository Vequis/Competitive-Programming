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

int n, m;
int l[11234], r[11234];
int dp[2][1123];

signed main(){_

    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> l[i] >> r[i];
    }

    dp[0][0] = 1;
    int minant = 0;

    for(int i=n; i>=1; i--){
        minant+=l[i];
        for(int j=minant; j<=m; j++){
            dp[1][j] = (dp[1][j-1] + dp[0][j-l[i]]);
            if(j-minant>l[i]) dp[1][j] -= dp[0][j-r[i]-1];
        }

        for(int i=0; i<=m; i++){
            dp[0][i] = dp[1][i];
            dp[1][i] = 0;
        }
    }

    int resp = 0;
    for(int i=1; i<=m; i++) resp+=dp[0][i];

    cout << resp << endl;

    return 0;
}
