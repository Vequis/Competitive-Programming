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

int memo[111][112345];

signed main(){_

    int n, we;
    cin >> n >> we;

    int v[111];
    int w[111];

    memset(memo, INF, sizeof(memo));

    for(int i = 1; i <=n; i++) cin >> w[i] >> v[i];

    int soma = 0;
    for(int i = 1; i <=n; i++) soma+=v[i];

    memo[1][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int val = 0; val <= soma; val++) {
            memo[i+1][val] =         min(memo[i+1][val],        memo[i][val]);
            memo[i+1][val + v[i]] =  min(memo[i+1][val + v[i]], memo[i][val] + w[i] );
            // cout << i << ' ' << val << ' ' << memo[i+1][val] << endl;
        }
    }


    //Pensar melhor sober esse detalhe do n+1
    for(int i = soma; i>=0; i--) {
        if (memo[n+1][i] <= we) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
