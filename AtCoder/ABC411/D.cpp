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
#define INFLL 0x3f3f3f3f3f3f3f3
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

stack<int> final_s;

string buffer[212345];
stack<pair<int, ii> > pcs[212345]; // pc[0] is the server
int type[212345];

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <=n; i++) buffer[i] = "";

    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;

        type[i] = op;
        if (op == 1) {
            int p;
            cin >> p;

            pcs[p].push({i, {p, 0}});
        } else if (op == 2) {
            int p;
            cin >> p;
            string s;
            cin >> s;
            pcs[p].push({i, {p, p}});
            buffer[i] = s;
        } else {
            int p;
            cin >> p;
            pcs[0].push({i, {0, p}});
        }
    }

    int cur_op = q;
    int pos = 0;

    while(1) {
        while(!pcs[pos].empty() and pcs[pos].top().fs > cur_op) pcs[pos].pop();
        if (pcs[pos].empty()) break;

        int id = pcs[pos].top().fs;
        ii move = pcs[pos].top().sc;

        if (type[id] == 2) final_s.push(id);

        pos = move.sc;
        cur_op = id-1;
    }

    while(!final_s.empty()) {
        cout << buffer[final_s.top()];
        final_s.pop();
    }
    cout << endl;

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