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
int folhas[212345];

int dfs(int node) {
    folhas[node] = 0;
    for(int v : adj[node]) {
        if (folhas[v] == -1) {
            folhas[node] += dfs(v); 
        }
    }
    if(folhas[node] == 0) folhas[node]++;
    return folhas[node];
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
        }

        memset(folhas, -1, sizeof(folhas));

        dfs(1);

        // for(int i = 1; i <=n; i++) {
        //     cout << i << ' ' << folhas[i] << endl;
        // }

        int q;
        cin >> q;

        for(int i = 0; i < q; i++) {
            int a, b;
            cin >> a >> b;

            cout << folhas[a]*folhas[b] << endl;
        }

        for(int i = 1; i <=n; i++) adj[i].clear();
    }

    return 0;
}
