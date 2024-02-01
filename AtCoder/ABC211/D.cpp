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
#define MAX 212345
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int dist[MAX], cnt[MAX];
int n, m;
vector< vi > adj;
queue<int> fila;

signed main(){_

    cin >> n >> m;

    adj = vector<vi>(n+1, vi());
    memset(dist, -1, sizeof(dist));

    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;

        adj[a].pb(b);
        adj[b].pb(a);
    }

    fila.push(1);
    dist[1] = 0;
    cnt[1] = 1;
    while(!fila.empty()){
        int topo = fila.front();
        for(int x : adj[topo]){
            if(dist[x] == -1){
                dist[x] = dist[topo] + 1;
                fila.push(x);
            }

            if(dist[x] == dist[topo] + 1){
                cnt[x] = (cnt[x] + cnt[topo])%MODN;
            }
        }
        fila.pop();
    }

    cout << cnt[n] << endl;

    return 0;
}
