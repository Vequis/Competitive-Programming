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
#define maxn 11234

using namespace std;

int dp[maxn];

signed main(){_

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;

    int n;
    cin >> n;

    for(int i=4; i<=n; i++){
        dp[i] = ((dp[i-1] + 4*dp[i-2])%MODN + 2*dp[i-3])%MODN;
    }

    cout << dp[n] << endl;

    return 0;
}
