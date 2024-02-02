#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1010
vector< vector<int> > grafo(MAXN);
int visitados[MAXN];

void dfs(int node){
    visitados[node] = 1;
    for (int i=0; i<grafo[node].size(); i++) {
         if (visitados[grafo[node][i]] == 0){
            dfs(grafo[node][i]);
        }
    }
}

int mdc(int a, int b){
    if (b>a) return mdc(b,a);
    else if (b==0) return a;
    else return (mdc(b, a%b));
}

int main(){

    cout << mdc(7, 6);

    int n;
    cin >> n;
    int arestas;
    cin >> arestas;

    for (int i=0; i<arestas; i++){
        int a, b;
        cin >> a >> b;

        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    dfs(0);

    bool conexo = true;
    for (int i=1; i<=n; i++){
        if (visitados[i] == 0) conexo = false;
    }

    cout << conexo << endl;

}