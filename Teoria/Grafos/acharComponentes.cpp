#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1010
vector< vector<int> > grafo(MAXN);
int visitados[MAXN];
int cont = 0;
int rotulos[MAXN];
int n;

void dfs(int nodo){
    if (visitados[nodo]) return;
    else visitados[nodo] = 1;
    rotulos[nodo] = cont;
    for (int i=0; i<grafo[nodo].size(); i++) dfs(grafo[nodo][i]);
}

void acharComponentes() {
    for (int i=0; i<n; i++){
        if (!visitados[i]){
            cont++;
            dfs(i);
        }
    }
}

int main(){
    
    cin >> n;
    int arestas;
    cin >> arestas;

    for (int i=0; i<arestas; i++) {
        int a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    acharComponentes();

    for (int i=0; i<n;i++) cout << rotulos[i] << " ";
    cout << endl;

    cout << "Existem " << cont << " componentes conexas";
}