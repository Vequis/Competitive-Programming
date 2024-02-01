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
#define MAXX 300005
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;
int n, q;
int memo[MAXX][3];
int h[MAXX], custo[MAXX];

signed main(){_
    cin >> q;

    memset(memo, -1, sizeof(memo));
    while(q--){
        cin >> n;

        for(int i = 1; i<=n; i++) cin >> h[i] >> custo[i];

        memo[0][0] = memo[0][1] = memo[0][2] = 0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=2; j++){
                int resp = LLONG_MAX;
                for(int k=0; k<=2; k++){
                    if(h[i] + j != h[i-1]+k)
                        resp = min(resp, memo[i-1][k] + j*custo[i]);
                }

                memo[i][j] = resp;
            }
        }


        cout << min(min(memo[n][0], memo[n][1]), memo[n][2]) << endl;
    }
    return 0;
}
