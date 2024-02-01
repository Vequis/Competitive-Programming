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

int n, m;
int componente[1123];
vi adj[1123];

void dfs(int node){

    for(int x : adj[node]){
        if(componente[x] == -1){
            componente[x] = componente[node];
            dfs(x);
        }
    }
}

signed main(){_

    int n, m;
    cin >> n >> m;

    memset(componente, -1, sizeof(componente));

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int cont = 0;    

    for(int i=1; i<=n; i++){
        if(componente[i] == -1){
            cont++;
            componente[i] = cont;
            dfs(i);
        }
    }

    cout << cont << endl;

    return 0;
}
