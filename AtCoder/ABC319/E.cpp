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

int p[112345];
int T[112345];

int mdc(int a, int b) {
    if(a < b) swap(a, b);
    if(b==0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b) {
    return a*b/mdc(a,b);
}

int dp[112345];

signed main(){_

    int n, x, y;

    cin >> n >> x >> y;

    for(int i = 1; i <=n-1; i++) cin >> p[i] >> T[i];

    int q;
    cin >> q;
    int somaconst = x + y;

    for(int i = 1; i <=n - 1; i++) somaconst+=T[i];

    int maximo = 1;
    for(int i = 1; i<=n-1; i++) maximo = mmc(maximo, p[i]);

    // cout << maximo << endl;

    for(int i = 0; i <= maximo; i++) {
        
        int resp = i + x;


        // cout << resp << endl;
        for(int j = 1; j <= n-1; j++) {
            resp = resp + (p[j] - (resp)%p[j])%p[j] + T[j];
            // cout << resp << endl;
        }

        // cout << i << ' ' << resp + y << endl;

        dp[i] = resp + y;
    }

    while(q--) {
        int qi;
        cin >> qi;

        // cout << qi << ' ' << qi%maximo << endl;
        // cout << "teste" << dp[0] << endl;
        int resp = qi - qi%maximo + dp[qi%maximo];
        cout << resp << endl;
        // cout << endl;
    }

    return 0;
}
