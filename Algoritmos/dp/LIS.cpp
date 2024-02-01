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

int memo[1000][200];
int n;
vi v;

int dp(int x, int m){ //Quantidade de elementos processadoS(atual) / Maior considerado
    if(x>n) return 0;
    
    if(memo[x][m] != -1) return memo[x][m];

    if(v[x] > m) return memo[x][m] = max(dp(x+1, v[x]) + 1, dp(x+1, m));
    return memo[x][m] = dp(x+1, m);
}

signed main(){_

    cin >> n;
    v = vi(n+1);

    memset(memo, -1, sizeof(memo));

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    cout << dp(1,0) << endl;

    return 0;
}
