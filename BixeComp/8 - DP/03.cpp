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

int memo[4444];

int n;
vi v;

int dp(int x){
    if(x<0) return -2;
    if(x==0) return 0;

    if(memo[x] != -1) return memo[x];

    int resp = -2;
    for(int i=0; i<3; i++){
        int num = dp(x-v[i]);
        if(num!=-2) resp = max(resp, num + 1);
    }

    return memo[x] = resp;
}

signed main(){_

    v = vi(3);
    cin >> n;

    memset(memo, -1, sizeof(memo));

    for(int i=0; i<3; i++) {
        cin >> v[i];
    }

    // for(int i=1; i<=100; i++){
    //     cout << i << ' ' << dp(i) << endl;
    // }

    cout << dp(n) << endl;

    return 0;
}
