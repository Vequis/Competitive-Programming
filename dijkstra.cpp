//https://cses.fi/problemset/task/1671/
#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
vector< pair<int, int> > adj[100010];

void dijkstra(){
	vector<int> dist(n + 2, -1);
	set< pair<int, int> > s;
	s.insert(make_pair(0, 1));
	dist[1] = 0;

	//definir variáveis

	// Inicia a fila
	while(s.size() != 0){
		auto it = *s.begin(); s.erase(it);

		int distancia_atual = it.first, u = it.second;
		if(dist[u] < distancia_atual) continue; //Condição de contorno
		
		for(auto it1 : adj[u]){  //Ve todos os adjacentes
			int v = it1.first, peso = it1.second;
			if(dist[v] == -1 or dist[v] > distancia_atual + peso){ // Ve se é elegivel
				dist[v] = distancia_atual + peso; //Nova distancia
				s.insert(make_pair(dist[v], v)); //Coloca na pq
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << dist[i] << " ";
}

void solve(){
	cin >> n >> m;

	for(int i = 1; i <= m; i++){
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c)); //Criação da lista de adjacencia
	}
	dijkstra();
}

signed main(){
	solve();
}