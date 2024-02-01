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
// #define int long long // -> solução divina

using namespace std;

vector<vi> adj;
int memo[10000005][2];

int dp(int n, int vert){
    if(n==0){
        if(vert==0) return 1;
        else return 0;
    }

    if(vert!=0) vert=1;

    if(memo[n][vert] != -1) return memo[n][vert];

    ll resp = 0;
    for(int x : adj[vert]) resp = (resp + (ll)dp(n-1, x))%MODN;

    // cout << n << ' ' << vert << ':' << resp;

    return memo[n][vert] = resp;
}

int n;

int main(){_

    adj=  vector<vi>(4);

    memset(memo, -1, sizeof(memo));

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(i==j) continue;
            adj[i].pb(j);
        }
    }

    cin >> n;

    // for(int i=1; i<=n; i++) cout << dp(i, 0) << endl;

    cout << dp(n, 0) << endl;

    return 0;
}
