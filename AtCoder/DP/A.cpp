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

int memo[112345][3];
int h[112345][3];

signed main(){_

    int n;
    cin >> n;

    memset(memo, -1, sizeof(memo));

    for(int i = 1; i <=n; i++) {
        cin >> h[i][0];
        cin >> h[i][1];
        cin >> h[i][2];
    }

    memo[1][0] = h[1][0];
    memo[1][1] = h[1][1];
    memo[1][2] = h[1][2];

    for(int i = 2; i <=n; i++) {
        for(int j = 0; j <= 2; j++) {
            memo[i][j] = max( memo[i-1][(j+1)%3], memo[i-1][(j+2)%3]) + h[i][j];
        }
    }


    cout << max(max(memo[n][0], memo[n][1]), memo[n][2]) << endl;

    return 0;
}
