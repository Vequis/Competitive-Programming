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

int s, t, p;
vi adj[300];
int h[300];
int resp[300];

int dfs(int node){

    if(resp[node] != 0) return resp[node];

    for(int x : adj[node]) {
        resp[node] = max(dfs(x) + 1, resp[node]);
    }

    return resp[node];
}

signed main(){_

    cin >> s >> t >> p;

    for(int i=1; i<=s; i++){
        cin >> h[i];
    }

    for(int i=1; i<=t; i++){
        int a, b;
        cin >> a >> b;

        if(a>b)swap(a,b);

        if(h[a] == h[b]){
            continue;
        } else if(h[a] > h[b]){
            adj[a].pb(b);
        } else {
            adj[b].pb(a);
        }
    }

    cout << dfs(p) << endl;

    return 0;
}
