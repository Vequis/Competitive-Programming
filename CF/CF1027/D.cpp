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



    vi cols(n);
    vi rows(n);
    vii pos(n);
    for (int i = 0; i <n; i++) {
        int a, b;
        cin >> a >> b;
        pos[i] = {a, b};
        rows[i] = a;
        cols[i] = b;
    }    

    if (n==1) {
        cout << 1 << endl;
        return;
    }

    sort(all(cols));
    sort(all(rows));

    int colmin, colmax, rowmin, rowmax;

    int resp = -1;
    for (int i = 0; i < n; i++) {
        colmin = cols[0];
        if (pos[i].sc == colmin) colmin = cols[1];

        colmax = cols[n-1];
        if (pos[i].sc == colmax) colmax = cols[n-2];

        rowmin = rows[0];
        if (pos[i].fs == rowmin) rowmin = rows[1];

        rowmax = rows[n-1];
        if (pos[i].fs == rowmax) rowmax = rows[n-2];

        // cout << rowmin << ' ' << rowmax << ' ' << colmin << ' ' << colmax << endl;

        int w = colmax - colmin + 1;
        int h = rowmax - rowmin + 1;

        int cur = w*h;
        if (cur == n-1) {
            cur += min(h, w);
        }

        if (resp == -1) resp = cur;
        else resp = min(resp, cur);
        // cout << i << ' ' << cur << endl;
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