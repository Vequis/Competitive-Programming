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

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vi prox_a(n+2);
    prox_a[n+1] = n+1;
    for (int i = n; i>=1; i--) {
        if (s[i-1] == 'A') prox_a[i] = i;
        else prox_a[i] = prox_a[i+1];
    }

    vi ultimo_c(n+2);
    ultimo_c[0] = 0;
    for (int i = 1; i<=n; i++) {
        if (s[i-1] == 'C') ultimo_c[i] = i;
        else ultimo_c[i] = ultimo_c[i-1];
    }

    vi psa(n + 1);
    psa[0] = 0;
    for (int i = 1; i <= n; i++) {
        psa[i] = psa[i-1];
        if (s[i-1] == 'B') psa[i]++;
    }


    int resp = 0;
    for (int i = 1; i <= n; i++) {
        // cout << i << ' ' << prox_a[i] << ' ' << ultimo_c[i] << ' ' << psa[i] << endl;
        if (s[i-1] == 'B') {


            int num_a = (i - ultimo_c[i] - 1) - (psa[i-1] - psa[ultimo_c[i]]);
            int num_c = (prox_a[i] - i - 1) - (psa[prox_a[i] - 1] - psa[i]);
        
            resp += max(num_a, num_c);
        }
    }

    cout << resp << endl;
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}