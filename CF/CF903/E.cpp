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

int a[212345];
int resp[212345];
int dp[212345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> a[i+1];
        }

        int last = n+1;

        vi posb;
        posb.eb(1000LL*INF);
        posb.eb(n+1);

        resp[n+1] = 0;

        dp[n+1] = 0;

        for(int i = n; i >= 1; i--) {
            // int ini = 0; int fim = sz(posb);
            // while(ini < fim) {
            //     int mid = ini + (fim - ini) / 2;
            //     // cout << ini << ' ' << mid << ' ' << fim << ' ' << posb[mid] << endl;
            //     if (posb[mid] <= i + a[i]) fim = mid;
            //     else ini = mid + 1;
            // }
            //ini;
            // cout << i << ' ' << ini - 1 << ' ' << posb[ini-1] << ' ' << endl;

            if (a[i] + i + 1 > n + 1) {
                dp[i] = 1 + dp[i+1];
            } else {
                dp[i] = min(1+ dp[i+1], dp[i + a[i] + 1]);
            }

        
            // cout << i << ' ' << dp[i] << endl;

        }

        cout << dp[1] << endl;
    }

    return 0;
}
