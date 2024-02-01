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
#define vvi vector<vi>
#define vvii vector<vii>
#define endl '\n'
#define ll long long int
#define MAX (1<<10) //2^10 = 1024

using namespace std;

int n, m, s;
int u,v,w;
vvii adj;

vi dist; //guarda o menor caminho de s até u
vi proc; // guarda se u já foi processado

void dijkstra(int s){
    dist = vi(n+1,INT_MAX);
    proc = vi(n+1,0);

    dist[s] = 0;
    int menor = s;

    for (int j=1; j<=n; j++){

        menor = 0;

        //Vendo qual é a menor distancia não processada
        for(int i=1; i<=n; i++){
            if (!proc[i] && dist[i] <= dist[menor]){
                menor = i;
            }
        }

        //Falando que ja foi processado
        proc[menor] = 1;

        //Olhando todos os vizinhos de menor
        for(auto [v,w] : adj[menor]){
            if (w != INT_MAX and dist[menor] + w < dist[v]){
                dist[v] = dist[menor] + w;
            }
        }
    }
}

int main(){_

    cin >> n >> m;

    adj = vvii(n+1);

    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            adj[i][j] = INT_MAX;
        }
    }

    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        adj[u].eb(v,w);
        adj[v].eb(u,w);
    }
    
    cin >> s;

    dijkstra(s);

    for (int i=1; i<=n; i++){
        cout << i << ' ' << dist[i] << endl; 
    }

    return 0;
}