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
vector< vi> p(112345, vi(3));
int memo[112345][3];

int dp(int n, int x){
    if(n==1){
        return p[1][x];
    }

    if (memo[n][x] != -1) return memo[n][x];

    int resp= 0;
    for(int i=0; i<3; i++){
        if(i==x) continue;
        resp = max(resp, dp(n-1, i) + p[n][x]);
    }

    return memo[n][x] = resp;
}

signed main(){_

    cin >> n;

    memset(memo, -1, sizeof(memo));

    for(int i=1; i<=n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        p[i][0] = a;
        p[i][1] = b;
        p[i][2] = c;
    }

    int resp = 0;
    for(int i=0; i<3; i++) resp = max(resp, dp(n, i));

    cout << resp << endl;

    return 0;
}