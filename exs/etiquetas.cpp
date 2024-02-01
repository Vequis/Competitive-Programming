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

using namespace std;

// int dp[10010][10010];
vector< vi> dp(10010, vi(10010, -1));
int n, k, c, soma;
vi v, psa;

int f(int m, int e){
    if (dp[m][e] != -1) return dp[m][e];

    if (m==0 and e>0) return -1;
    else if (m==0 and e==0) return 0;
    if (e==0) {
        cout << m << ' ' << e << ' ' << psa[n] - psa[n-m] << endl;
        return psa[n] - psa[n-m];
    }
    // - Ou eu literalmente vou para frente
    // - Ou colo uma etiqueta
 
    //dp[n][e] = dp[n-c][e-1] ou dp[n-1][e] + v[i] ( se isso for diferente de -1);

    if (f(m-c, e-1) == -1 and f(m-1, e) + v[n-m+1]==-1) return -1;
    
    int ans = 0;
    if(f(m-c, e-1) != -1) ans = f(m-c, e-1);
    
    if (m-1 >= e*c and f(m-1, e) + v[n-m+1]!=-1) ans = max(ans, f(m-1, e) + v[n-m+1]);

    cout << m << ' ' << e << ' ' << ans << endl;

    return dp[m][e] = ans; 
}


int main(){_

    cin >> n >> k >> c;

    v.pb(0);
    psa = vi(n+1);
    psa[0] = 0;
    for (int i=1; i<=n; i++){
        int x;
        cin >>x;
        v.pb(x);
        psa[i] = psa[i-i] + x;
        soma+=x;
    }

    cout << f(n, k) << endl;
    cout << dp[n][k] << endl;

    return 0;
}