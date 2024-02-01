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

using namespace std;

int n,m;
vector<vi> adj;
int cor[25][4];
int vis[25];

int dfs(int node){
    if (vis[node]) return 1;
    vis[node] = 1;
    ll soma=0;
    ll prod = 1;
    for (auto prox : adj[node]){
        prod*=dfs(prox);
        for (int i=0; i<4; i++){
            cor[node][i] = (cor[node][i] or cor[prox][i]); 
        }
    }

    for (int i=1; i<=3; i++){
        if(!cor[node][i]){
            cor[node][i] = 1;    
            soma++;   
        } 
    }

    cout << node << ' ' << soma << ' ' << prod << endl;

    return soma*prod;
}

int main(){_

    cin >> n >> m;
    adj = vector<vi>(m+1);

    for (int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    cout << dfs(1) << endl;

    return 0;
}