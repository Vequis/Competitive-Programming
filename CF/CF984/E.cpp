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
    int n, k, q;
    cin >> n >> k >> q;

    int grid[n+1][k+1];

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j<=k; j++) {
            cin >> grid[i][j];
        }
    }   

    vector< tuple<char, int, int> > reqs[k + 1];
    int resp[q+1];
    for (int i = 1; i <=q; i++) resp[i] =-1;
    for (int qr = 1; qr <= q; qr++) {
        int m;
        cin >> m;
        
        while(m--) {
            char op;
            int r;
            int x;
            cin >> r >> op >> x;

            reqs[r].pb({op, x, qr});
        }
    }

    for (int i = 1; i<= n; i++) {

        bool flags[q + 1];
        for (int j = 1; j <= q; j++) flags[j] = 1;
        
        for (int j = 1; j<=k; j++) {
            if (i != 1) grid[i][j] = grid[i-1][j] | grid[i][j];


            for (tuple<char, int, int> p : reqs[j]) {
                char op = get<0>(p);
                int x = get<1>(p);
                int qr = get<2>(p);
                if (op == '>') {
                    flags[qr] = flags[qr] and (grid[i][j] > x);
                } else {
                    flags[qr] = flags[qr] and (grid[i][j] < x);
                }
            }
        }

        for (int qr = 1; qr<=q; qr++) {
            if (flags[qr] and resp[qr] == -1) resp[qr] = i;
        }
    }   

    for (int qr = 1; qr <=q; qr++) cout << resp[qr] << endl;
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