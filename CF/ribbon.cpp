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

int a, b, c;
int memo[21234];

int dp(int n) {
    if (n == 0) {
        return 0;
    } else if (n < 0) return -2;

    // cout << n << endl;
    if (memo[n] != -1) return memo[n];

    int x = dp(n-a);
    int y = dp(n-b);
    int z = dp(n-c);

    if (x==-2 and y==-2 and z==-2) return memo[n] = -2;

    return memo[n] = 1 + max(max(dp(n-a), dp(n-b)), dp(n-c));
}

signed main(){_

    int n;
    cin >>  n >> a >> b >> c;

    memset(memo, -1, sizeof(memo));

    cout << dp(n) << endl;

    // for(int i = 1; i <=n; i++) cout << i << ' ' << dp(i) << endl;

    // for(int i = 0; i < 21233; i++) cout << memo[i] << endl;


    return 0;
}
