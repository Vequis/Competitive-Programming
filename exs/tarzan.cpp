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

ii v[1123];
vi adj[1123];
int vis[1123];

double dist(int x1, int y1, int x2, int y2){
    return (double)sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int dfs(int node){
    int cont = 1;
    for(int x : adj[node]){
        if(!vis[x]){
            vis[x] = 1;
            cont+=dfs(x);
        }
    }

    return cont;
}

signed main(){_

    int n, d;
    cin >> n >> d;

    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        v[i] = {a,b};
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(dist(v[i].fs, v[i].sc, v[j].fs, v[j].sc) <= d){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    vis[0] = 1;
    if(dfs(0) != n){
        cout << "N" << endl;
    } else {
        cout << "S" << endl;
    }

    return 0;
}
