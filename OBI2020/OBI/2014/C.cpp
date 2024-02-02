#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 1010
vector< vector<int> > chefe(MAXN); //Anota os chefes da pessoa
vector< vector<int> > funcionario(MAXN); //Anota os funcionarios da pessoa
int visitado[MAXN];
vector<int> representa;
vector<int> idade;

int bfs(int n){

    queue<int> fila;
    fila.push(n);
    int idades = 110;
    while(!fila.empty()){
        int var = fila.front();
        fila.pop();
        for (int i=0; i<chefe[var].size(); i++){
            int chefeA = chefe[var][i];
            if (!visitado[chefeA]){
                fila.push(chefeA);
                visitado[chefeA] = 1;
                idades = min(idades, idade[chefeA]);
            }
        }
    }
    return idades;
}

void troca(int a, int b){
    int temp;
    temp = representa[a];
    representa[a] = representa[b];
    representa[b] = temp;

    temp = idade[representa[a]];
    idade[representa[a]] = idade[representa[b]];
    idade[representa[b]] = temp;
}

int main(){
    int n, m, t;
    cin >> n >> m >> t;

    representa.push_back(0);
    idade.push_back(0);

    for (int i=1; i<=n; i++) {
        int num;
        cin >> num;
        idade.push_back(num);
        representa.push_back(i);
    }

    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b; // a gerencia b

        funcionario[a].push_back(b);
        chefe[b].push_back(a);
    }

    for (int i=1; i<=t; i++){
        char op;
        cin >> op;
        if (op=='T'){
            int a, b;
            cin >> a >> b;
            troca(a,b);
        } else if (op == 'P'){
            int n;
            cin >> n;

            if (chefe[representa[n]].empty()) {
                cout << '*' << endl; 
            } else {
                int fdp = bfs(representa[n]);
                cout << fdp << endl;;
                for (int i=1; i<=n; i++) visitado[i] = 0;
            }
        }
    }

    return 0;
}