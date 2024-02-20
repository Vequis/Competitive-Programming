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
set<int> sett;
vii v;
priority_queue<ii> pq;

void solve() {

    int n;
    cin >> n;
    f.clear();
    // sett.clear();
    v.clear();
    while(!pq.empty()) pq.pop();

    for(int i = 1; i <=n; i++) {
        int a;
        cin >> a;

        f[a+i]++;

        pq.push({a+i, a+1});
        // v.eb(a+i, a+1);
    }

    // sort(v.rbegin(), v.rend());


    int greatused = INF;
    int nextlivre = INF;
    while(!pq.empty()) {
        ii t = pq.top();
        pq.pop();
        if (t.fs >= greatused) {
            // aux = greatused-1;
            nextlivre = min(nextlivre - 1, greatused - 1);
            if (t.sc <= nextlivre) pq.push({nextlivre, t.sc});
        } else {
            cout << t.fs << ' ';
            greatused = t.fs;
        }
    }
    // for(int i = 0; i < n; i++) {
    //     // cout << v[i].sc << ' ' << v[i].fs << endl;
    //     if (v[i].sc <= greatused - 1) {
    //         cout << min(greatused - 1, v[i].fs) << ' ';
    //         greatused = min(greatused - 1, v[i].fs);
    //     }
    // }
    cout << endl;
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
