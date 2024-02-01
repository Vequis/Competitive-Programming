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

int nivel[212345];
bool marked[212345];
vi adj[212345];
int last = 0;

void dfs_down(int node) {
    if(last == -1 or (nivel[node] > nivel[last] and marked[node])) last = node;

    for (int v : adj[node]) {
        if (nivel[v] == -1) {
            nivel[v] = nivel[node] + 1;
            dfs_down(v);

        }
    }

    // cout << node << ' ' << down[node] << endl;

    return;
}

signed main(){_

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i = 1; i <=n; i++) marked[i] = 0;

        for(int i = 0; i < k; i++) {
            int a;
            cin >> a;
            marked[a] = 1;

        }

        for(int i = 0; i < n-1; i++) {
            int a, b;
            cin >> a >> b;
            adj[a].eb(b);
            adj[b].eb(a);
        }

        for(int i = 1; i <=n; i++) nivel[i] = -1;
        nivel[1] = 0;
        last = -1;
        dfs_down(1);

        // cout << nivel[last] << ' ' << last << endl;


        int ult = last;
        // if (k==1) {
        //     for(int i = 1; i <=n; i++) marked[i] = 1;
        // }

        // cout << last << endl;
        for(int i = 1; i <=n; i++) nivel[i] = -1;
        nivel[ult] = 0;
        dfs_down(ult);

        // cout << nivel[last] << ' ' << last << endl;
        cout << (nivel[last] + 1)/2 << endl;

        for(int i = 1; i <=n; i++) adj[i].clear();

    }

    return 0;
}
