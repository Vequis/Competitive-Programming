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

int dp[20];
int n;

signed main(){_

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    for(int i=0; i<=n-1; i++){
        cout << dp[i] << ' ';
    }

    return 0;
}
