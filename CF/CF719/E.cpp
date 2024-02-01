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

int n,t;

string s;

ll d[1123456];
int cont;
ll resp;
ll dp[1123456];
ll dpp[1123456];
char c;

int main(){_

    //dp[x] = 0;
    //dp[i] = dp[i+1] + (x-i)*(d[i+1] - d[i] - 1)
    //dpp[1] = 0;
    //dpp[i] = dpp[i-1] + (i-1)*(d[i] - d[i-1] - 1)

    cin >> t;

    while(t--){
        cin >> n;

        cont=0;
        for (int i=0; i<n; i++){
            cin >> c;
            if(c=='*'){
                cont++;
                d[cont] = i+1;
            }
        }

        if (cont==0 or cont==1){
            cout << 0 << endl;
            continue;
        }

        dp[cont] = 0;
        for (int i=cont-1; i>=1; i--){
            dp[i] = dp[i+1] + (cont-i)*(d[i+1] - d[i] - 1);
            // cout << (cont-i) << ' ' << (d[i+1] - d[i] - 1) << endl;
        }

        resp = dp[1];

        dpp[cont] = 0;
        for (int i=2; i<=cont; i++){
            dpp[i] = dpp[i-1] + (i-1)*(d[i] - d[i-1] - 1);
            // cout << i << ' ' << dp[i] << ' ' << dpp[i] << endl;
            // if (dp[i] + dpp[i] < INT_MAX) {
                resp = min(resp, dp[i] + dpp[i]);
            // }
        }   

        cout << resp << endl;

        memset(dp, 0, n);
    }

    return 0;
}