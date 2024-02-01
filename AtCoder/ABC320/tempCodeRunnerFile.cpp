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

signed main(){_

    int n;
    cin >> n;

    string a, b, c;
    cin >> a >> b >> c;

    int resp = INF;
    int pos = false;

    for(int i = 0; i <= 9; i++) {
        int fa, fb, fc;
        fa = fb = fc = INF;

        int frb, frc;
        frb = frc = INF;

        for(int j = 0; j < sz(a); j++) if (a[j] == (i + '0')) fa = min(fa, j);
        for(int j = 0; j < sz(a); j++) if (b[j] == (i + '0') and j != fa) fb = min(fb, j);
        if(fb == INF) {
            for(int j = 0; j < sz(a); j++) if (b[j] == (i + '0')) {
                fb = j + n;
                break;
            }
        }

        for(int j = 0; j < sz(a); j++) if (c[j] == (i + '0') and j != fb and j != fa) fc = min(fc, j);
        if(fc == INF) {
            for(int j = 0; j < sz(a); j++) if (c[j] == (i + '0')) {
                fc = j + n;
                break;
            }
        }

        int cur = max(max(fa, fb), fc);

        resp = min(resp, cur);
    }

    if(resp == INF) {
        cout << -1 << endl;
    } else {
        cout << resp << endl;
    }

    return 0;
}
