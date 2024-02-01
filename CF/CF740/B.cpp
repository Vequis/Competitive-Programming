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

int m;
int n;

int memo[4000000 + 10];

int dp(int n){
    cout << n << endl;
    if(n==1) return 1;

    if(memo[n] != -1) return memo[n];

    int resp = 0;

    for(int i=1; i<=n; i++){
        if(i!=n) resp = (resp + dp(i))%m;
        if(i!=1) resp = (resp + dp(n/i))%m;
    }

    return memo[n] = resp;

}

signed main(){_

    cin >> n >> m;
    memset(memo, -1, sizeof(memo));

    cout << dp(n) << endl;

    return 0;
}
