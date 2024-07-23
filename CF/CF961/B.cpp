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
    int n, k;
    cin >> n >> k;

    vi v(n);

    map<int, int> f;
    f.clear();

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] = a;
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        f[v[i]] = a;
    }

    int resp = 0;
    int cur = 0;
    //cout << f.size() << endl;
    for (int x : v) {

        int ideal = k/x;



        if ( (f[x] + f[x + 1] >= ideal)) {
            int resto = k%x - f[x+1];
            resto = max(resto, 0LL);
            resp = max(resp, k - resto);
        } else {
            int m = max(k%x, f[x+1]);
            if ( f[x] * x + m*(x+1) >= ideal * x ) {
                int resto = k%x - m%x;
                resto = max(resto, 0LL);
                resp = max(resp, k - resto);
            } else {
                cur = f[x] * x;
                cur += f[x+1] * (x+1);
                resp = max(resp, cur);

                if (cur > k) {
                    cout << "ERRO:" << endl;
                    cout << x << ' ' << f[x] << endl;
                    cout << x+1 << ' ' << f[x+1] << endl;
                }
            }

        }

        // for (int i = 1; i<=f[x]; i++) {
        //     cur = i*x + min(f[x+1], (k - i*x)/(x+1)) * (x+1);
        //     if (cur <= k and i*x <= k) resp = max(resp, cur);
        // }
    }

    cout << resp << endl;

    return;
}

signed main(){
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}