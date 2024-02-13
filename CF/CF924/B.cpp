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
vector<int> v;
map<int, int> f;

priority_queue<ii, vii, greater<ii>> pq;

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        v.clear();

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.pb(a);
        }

        sort(all(v));

        int cur = 0;
        int resp = 0;

        for(int i = 0; i <n; i++) {
            if (i == 0 or v[i] != v[i-1]) {
                pq.push({v[i] + 1, +1});
                pq.push({v[i] + n + 1, -1});
            }
        }

        while(!pq.empty()) {

            ii topo = pq.top();
            pq.pop();
            cur += topo.sc;
            // cout << topo.fs << ' ' << topo.sc << endl;

            while(!pq.empty() and pq.top().fs == topo.fs) {
                cur += pq.top().sc;
                // cout << pq.top().fs << ' ' << pq.top().sc << endl;
                pq.pop();
            }

            resp = max(cur, resp);
        }

        cout << resp << endl;

        f.clear();
    }

    return 0;
}
