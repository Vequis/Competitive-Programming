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

int nec_for_add_bit(int a) {
    int b = ~a;
    // cout << bitset<4>(b) << endl;
    // cout << bitset<4>(-b) << endl;
    b = b & -b; // set all one bit of x to 0, except the last one bit  
    return b;
}

void solve() {

    int n, k;
    cin >> n >> k;

    priority_queue<ii, vii, greater<ii> > pq;
    int resp = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push({nec_for_add_bit(x), x});

        resp += __builtin_popcountll(x);
    }


    while(pq.top().fs <= k) {
        ii topo = pq.top(); pq.pop();
        k-=topo.fs;

        int x = topo.sc;
        x += topo.fs;
        pq.push({nec_for_add_bit(x), x});
        resp++;
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