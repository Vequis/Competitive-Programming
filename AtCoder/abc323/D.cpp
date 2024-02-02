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
#define int long long

using namespace std;

map<int, int> f;

signed main(){_

    int n;
    cin >> n;

    vi slimes;

    priority_queue<int, vi, greater<int> > pq;
    for(int i = 0; i < n; i++) {
        int s, c;
        cin >> s >> c;

        slimes.eb(s);
        pq.push(s);
        f[s] = c;
    }

    sort(all(slimes));

    int resp = 0;
    int last = -1;
    while(!pq.empty()) {
        int topo = pq.top();
        pq.pop();
        if (topo == last) continue;
        last = topo;
    
        resp+=f[topo]%2;

        f[2*topo] += f[topo]/2;

        if(f[topo] >= 2) pq.push(2*topo);

        // cout << topo << ' ' << resp << endl;
    }

    resp -= f[last]%2;
    resp += f[last];

    cout << resp << endl;

    return 0;
}
