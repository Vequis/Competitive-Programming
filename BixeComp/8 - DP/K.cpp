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

int n, k, d;
int memo[111][2];

int dp(int m, int ok){
    if(m==0 and ok == false) return 0;
    if(m==0) return 1;

    if(memo[m][ok] != -1) return memo[m][ok];

    int resp = 0;
    for(int i=1; i<=k; i++){
        if(m-i < 0) break;

        if(i<d){
            resp = (resp+dp(m-i, ok))%MODN;
        } else {
            resp = (resp + dp(m-i, 1))%MODN;
        }
    }

    return memo[m][ok] = resp;
}

signed main(){_

    cin >> n >> k >> d;

    memset(memo, -1, sizeof(memo));

    // for(int i=1; i<=n; i++)cout << dp(i, 0) << endl;

    cout << dp(n,0) << endl;

    return 0;
}
