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

vi ingr_adj[312345];
int count_rec[312345];

void solve() {
    int n, m;
    cin >> n >> m;


    for (int j = 1; j<=m; j++) {
        int k;
        cin >> k;

        for (int i = 1; i<=k; i++) {
            int x;
            cin >> x;

            ingr_adj[x].pb(j);

        }

        count_rec[j] = k;
    }


    int fittable = 0;

    for (int i = 1; i<=m; i++) if (count_rec[i] == 0) fittable++;

    while(n--) {
        int x;
        cin >> x;

        for (int v : ingr_adj[x]) {
            count_rec[v]--;
            if (count_rec[v] == 0) fittable++;
        }

        cout << fittable << endl;
    }


}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        // solve();
    }

    return 0;
}