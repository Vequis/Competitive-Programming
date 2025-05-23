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
int dp[11123456];
int h[1123456];

signed main(){_

    cin >> n;

    for(int i=1; i<=n; i++) cin>>h[i];


    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = min(dp[i-1] + 1, h[i]);
    }

    dp[n+1] = 0;
    int resp = 0;
    for(int i=n; i>=1; i--){
        dp[i] = min(dp[i+1] + 1, dp[i]);
        resp = max(resp, dp[i]);
    }

    cout << resp << endl;

    return 0;
}
