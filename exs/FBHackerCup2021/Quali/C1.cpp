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

int t, n, cnt, k;
int c[550];
vi adj[550];
int vis[550];
vi respos;
int cntviz;
int resp;

int dfs(int node){
    vis[node] = 1;
    int resp = c[node];
    for(int x : adj[node]){
        if(!vis[x]){
            // cout << "**" << node << ' ' << x << endl;
            resp = max(resp, c[node] + dfs(x));
        }
    }

    return resp;
}

bool cmp(int a, int b){
    return a>b;
}

signed main(){_

    cnt = 0;
    cin >> t;
    while(t--){
        cnt++;

        cin >> n >> k;

        for(int i=1; i<=n; i++) cin >> c[i];

        for(int i=1; i<=n-1; i++){
            int a, b;
            cin >> a >> b;

            adj[a].pb(b);
            adj[b].pb(a);
        }

        vis[1] = 1;
        cntviz = 0;
        for(int x : adj[1]){
            respos.pb(dfs(x));
            // cout << '*' << dfs(x) << endl;
            cntviz++;
        }

        sort(all(respos), cmp);

        cout << "Case #" << cnt << ": ";

        int ptr = 0;

        resp = c[1];
        while(ptr<min(2*k, cntviz)){
            resp+=respos[ptr];
            ptr++;
        }

        cout << resp << endl;

        for(int i=1; i<=50; i++) {
            adj[i].clear();
            vis[i] = 0;
        }
        respos.clear();
    }

    return 0;
}
