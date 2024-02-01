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

int memo[30][10005];
int v[11234];
int n, t;
int ok, soma;

int dp(int delta, int x){
    if(abs(delta) > 5) return 0;
    if(x==n+1) return 1;

    if(memo[5+delta][x] != -1) return memo[5+delta][x];

    return memo[5+delta][x] = (dp(delta+v[x], x+1) || dp(delta-v[x], x+1));
}

signed main(){_

    cin >> t;
    while(t--){
        cin >> n;

        soma=0;
        for(int i=1; i<=n; i++){
            cin >> v[i];
            soma+=v[i];
        }

        memset(memo, -1, sizeof(memo));

        // for(int i=1; i<=n; i++){
        //     for(int j=0; j<=10; j++){
        //         cout << dp(j-5, i) << ' ';
        //     }
        //     cout << endl;
        // }

        if(dp(0,1)){
            cout << "Feliz Natal!" << endl;
        } else {
            cout << "Ho Ho Ho! " << endl;
        }

    }

    return 0;
}
