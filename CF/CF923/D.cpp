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

vi inicios;
int find(int x) {
    return upper_bound(all(inicios), x) - inicios.begin() - 1;
}

signed main(){_

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        int last;
        cin >> last;
        inicios.eb(1);
        for(int i = 2; i <=n; i++) {
            int a;
            cin >> a;
            if (a != last) {
                last = a;
                inicios.eb(i);
            }
        }

        // for(int x : inicios) cout << x << ' ';
        // cout << endl;

        int q;
        cin >> q;
        while(q--) {
            int l, r;
            cin >> l >> r;

            int f = find(l);
            f++;
            // cout << f << ' ' << inicios[f] << endl;
            if (f >= sz(inicios) or inicios[f] > r) {
                cout << -1 << ' ' << -1 << endl;
            } else {
                cout << l << ' ' << inicios[f] << endl;
            }
        }
        cout << endl;
        inicios.clear();
    }

    return 0;
}
