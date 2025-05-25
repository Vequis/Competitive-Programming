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
    int n, w;
    cin >> n >> w;

    vector<pair<ii, int>> waves;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == '?') {
            int x;
            cin >> x;

            int resp = 0;
            for (pair<ii, int> wave : waves) {
                ii coords = wave.first;
                int amplitude = wave.sc;
                if (coords.first <= x and x <= coords.second) {
                    int delta = (x - coords.first) % 4;
                    if (delta == 0) resp += amplitude;
                    else if (delta == 2) resp -=amplitude;
                }
            }

            cout << resp << endl;

        } else if (c == '!') {
            int p, l, a;
            cin >> p >> l >> a;
            
            waves.eb(make_pair(p, p + l -1), a);
        }
    }   

}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}