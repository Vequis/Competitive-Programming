#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1010
vector<vector<int>> grafo(MAXN);
int visitados[MAXN];

void dfs(int node){
    if (visitados[node]) return;
    else visitados[node] = 1;

    vector<int> vizinhos = grafo[node];

    for (int i=0; i<vizinhos.size(); i++) dfs(vizinhos[i]);
}

int main(){

    int n;
    cin >> n;

    int arestas;
    cin >> arestas;

    for (int i=1; i<=arestas; i++) {
        int a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    int start_node = 1;
    dfs(start_node);

    bool completo = true;
    for (int i=1; i<=n; i++){
        if (visitados[i] == 0){
            completo = false;
            break;
        }
    }

    if (completo) cout << "O grafo está inteiramente conectado" << endl;
    else cout << "Algum ponto do grafo está fora dele" << endl;

    return 0;
}

// for(auto it=vizinhos.begin(); it!=vizinhos.end(); ++it){
//     // int i = (*it);
//     // dfs[i];
// }
//Deu errado, depois eu vejo como isso funciona