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
#define MODN 998244353
#define int long long // -> solução divina
    
using namespace std;
    
int k;
    
int memo[2510][2510];
    
int dp(int n, int l) {
    if (n == 0) return 1;
    
    if (memo[n][l] != -1) return memo[n][l];
    
    int resp = 0;
    for (int i = 0; i <= k-l-1; i++) {
        if (n - (l+1)*(i+1) < 0) {
            return memo[n][l] = resp;
        } else {
            resp = (resp + dp(n - (l+1)*(i+1), i)) %MODN;
        }
    }
    
    return memo[n][l] = resp;
}
    
void solve() {
    int n;
    cin >> n >> k;
    for(int i = 0; i <= n; i++) for (int j = 0; j <=k; j++) memo[i][j] = -1;
    
    
    int resp = 0;
    for(int i = 0; i <=k; i++) resp= (resp + dp(n, i))%MODN;
    cout << resp <<endl;
}
    
signed main(){_
    int t;
    cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}