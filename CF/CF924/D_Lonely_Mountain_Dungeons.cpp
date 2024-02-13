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

int c[212345];
int cur[212345];
int legado[212345];

void solve() {
    int n, b, x;
    cin >> n >> b >> x;


    int maiorc = 0;
    for(int i = 1; i<= n; i++) {
        cin >> c[i];
        maiorc = max(maiorc, c[i]);
    }
    for(int i = 1; i<=maiorc; i++) cur[i] = 0;
    for(int i = 1; i<=maiorc; i++) legado[i] = 0;

    for(int i = 1; i <=n; i++) {
        for (int k = 1; k <= c[i]; k++) {
            int q = c[i]/k;
            int r = c[i]%k;
            cur[k] += (c[i]*c[i] - r*(q+1)*(q+1) - (k - r)*q*q)/2;

        }
        legado[c[i]] += (c[i]*c[i] - (c[i]))/2;
    }

    int agregado = 0;
    int resp = 0;
    for(int k = 1; k <=maiorc; k++) {
        int curr = (cur[k] + agregado) * b - (k-1)*x;
        agregado += legado[k];
        resp = max(resp, curr);
        // cout << curr << ' ' << k << endl;
    }

    cout << resp << endl;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
