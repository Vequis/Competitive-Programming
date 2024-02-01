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
vector< vii > adj;

void dijkstra(){
    priority_queue<ii> pq;
    vi dist(n+2, -1);
    dist[1] = 0;
    pq.push({1 ,dist[1]});

    while(!pq.empty()){
        ii p = pq.top();
        pq.pop();
        int u = p.fs, atual = p.sc;

        cout << u << ' ' << atual << endl;

        if (atual > dist[u]) continue;

        for (ii q : adj[u]){
            int v = q.fs, w = q.sc;
            if (dist[v] == -1 or dist[v] > atual + w){
                dist[v] = atual + w;
                pq.push({w, atual + w});
            }
        }
    }

    for(int i = 1; i <= n; i++) cout << dist[i] << " ";
}

signed main(){_
	cin >> n >> m;

    adj = vector< vii >(n+2);

	for(int i = 1; i <= m; i++){
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c)); //Criação da lista de adjacencia
	}

	dijkstra();
    return 0;
}
