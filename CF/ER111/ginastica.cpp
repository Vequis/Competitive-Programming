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

int memo[60][112345];

int m, n;

int dp(int t, int nivel){
    if(nivel>n || nivel<m) return 0;
    if(t==1) return 1;

    if(memo[t][nivel] != -1) return memo[t][nivel];

    return memo[t][nivel] = (dp(t-1, nivel-1) + dp(t-1, nivel+1))%MODN;
}

int t;

signed main(){_

    memset(memo, -1, sizeof(memo));

    cin >> t >> m >> n;

    int resp = 0;
    for(int i=m; i<=n; i++) resp = (resp + dp(t, i))%MODN;

    cout << resp << endl;

    return 0;
}
