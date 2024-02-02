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
#define int long long

using namespace std;

bool dp[1123456];

vi v;
int n;
int soma;

void build_knapsack() {
    for (int i = 0; i < soma; i++) dp[i] = 0;

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int w = soma; w - v[i] >= 0; w--) {
            dp[w] = dp[w] | dp[w - v[i]];
        }
    }



}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int wt, fr;
        cin >> wt >> fr;

        cin >> n;

        soma = 0;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.pb(a);
            soma += a;
        }

        build_knapsack();

        int resp = INF;
        for (int i = 0; i <= soma; i++) {
            // cout << i << ' ' << dp[i] << endl;
            if (dp[i]) {
                resp = min(resp, max( (i + wt - 1)/wt, (soma - i + fr - 1)/fr ));
            }
        }

        cout << resp << endl;

        v.clear();
    }

    return 0;
}
