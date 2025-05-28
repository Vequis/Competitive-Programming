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
    priority_queue<int, vi, greater<int>> pq;
    vii v;
    vi pointed_index;

    int n;
    cin >> n;
    int k;
    cin >> k;
    vi resp(n+1);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        v.eb(a, 0);
        pointed_index.pb(a);
    }

    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;

        v[i] = {v[i].fs, b};
    }

    sort(all(v));

    int sum = 0;
    for (int i = 0; i < n; i++) {
        //cout << v[i].fs << ' ' << v[i].sc << ' ' << sum;
        resp[v[i].fs] = sum;
        sum += v[i].sc;
        pq.push(v[i].sc);
        if ((int)(pq.size()) > k) {
            int primeiro = pq.top(); pq.pop();
            sum -= primeiro;
        } 
    }

    for (int i = 0; i < n; i++) {
        cout << resp[pointed_index[i]] << ' ';
    }
    cout << endl;
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