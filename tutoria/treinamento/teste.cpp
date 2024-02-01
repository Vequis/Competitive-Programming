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

map<int, int> f;
vi v;
vi val;
vii ids;

signed main(){_

    int n, m;
    int t;
    cin >> t;
    while (t--) {

        cin >> m >> n;

        v = vi(n+1, -1);
        val = vi(n+1, 0);

        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            ids.eb(a%m, i);
            val[i] = a;
        }

        sort(all(ids));

        int ite = 0;
        for (int i = 0; i < m; i++) {
            cout << i << " -> ";
            for (int j = ite; ids[j].fs == i; j++) {
                ii p = ids[j];
                ite++;
                cout << val[p.sc] << " -> ";
            }
            cout << "\\" << endl;
        }
        cout << endl;

        f.clear();
        val.clear();
        v.clear();
        ids.clear();
    }

    return 0;
}
