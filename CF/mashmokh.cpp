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

int soma(int a, int b) {
    return (a+b)%MODN;
}

int f[2123];
int dp[2123][2123];

signed main(){_

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <=n; i++)  {
        int it = i;
        while(it <= n) {
            f[it]++;
            it+=i;
        }
    }

    for (int ni = 0; ni<= k; ni++) dp[ni][1] = 1;
    dp[0][1] = 0;

    for (int ki = 2; ki <= n; ki++) {
        dp[0][ki] = dp[0][ki - 1];
        dp[1][ki] = 1;
        cout << '1' << ' ';
        for (int ni = 2; ni <= k; ni++) {
            dp[ni][ki] = (dp[ni-1][ki] + dp[ni][ki-1])%MODN;
            cout << dp[ni][ki] << ' ';
        }
        cout << endl;
    }

    int resp = 0;

    for (int i = 1; i <= n; i++) {
        resp = (resp + dp[k][f[i]])%MODN;
    }

    cout << resp << endl;


    return 0;
}
