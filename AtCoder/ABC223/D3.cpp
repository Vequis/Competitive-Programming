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

vi adj[212345];
int grau[212345];
priority_queue<int, vi, greater<int>> pq;

signed main(){_

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        grau[b]+=1;
    }

    for(int i = 1; i <=n; i++) {
        if (grau[i] == 0) pq.push(i);
    }

    vi resp;

    while(!pq.empty()) {


        int topo = pq.top();
        // cout << topo << endl;
        pq.pop();

        for(int v : adj[topo]) {
            grau[v]--;
            if(grau[v] == 0) pq.push(v);
        }

        resp.pb(topo);
    }

    if(sz(resp) < n) {
        cout << -1 << endl;
    } else {
        for(int x : resp) cout << x << ' ';
        cout << endl;
    }

    return 0;
}
