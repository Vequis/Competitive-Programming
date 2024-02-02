#include <iostream>
#include <vector>

using namespace std;

char matriz[55][55];
int visitados[55][55]{0};
int n, m;

check(int x, int y, int n, int m){
    bool resp = true;
    if (x<1 or x>m) resp = false;
    if (y<1 or y>n) resp = false;

    return resp;
}

int cont = 0;
int poss = true;

void dfs(int x, int y){

    if (visitados[y][x] == 1) return;

    visitados[y][x] = 1;

    char ch = matriz[y][x];

    // if (char == '#') return;
    if (ch == 'G') cont++;
    else if (ch=='B') poss = false;

    if (check(x+1, y, n, m) and !visitados[y][x+1]) dfs(x+1, y);
    if (check(x-1, y, n, m) and !visitados[y][x-1]) dfs(x-1, y);
    if (check(x, y+1, n, m) and !visitados[y+1][x]) dfs(x, y+1);
    if (check(x, y-1, n, m) and !visitados[y-1][x]) dfs(x, y-1);
}

int main(){
    int t;
    cin >> t;
    for (int j=0; j<t; j++){
        cin >> n >>m;

        int contG = 0;
        char c;

        for (int i=1; i<=n; i++){
            string s;
            cin >> s;
            for (int k=1; k<=m; k++){
                c = s[k-1];
                matriz[i][k] = c;
                if (c == '#') {
                    visitados[i][k] = 1;
                } else {
                    visitados[i][k] = 0;
                }
                
                if (c == 'G'){
                    contG++;
                }
            }
        }

        for (int y=1; y<=n; y++){
            for (int x=1; x<=m; x++){
                char c = matriz[y][x];
                if (c == 'B'){
                   if (check(x, y+1, n, m) and matriz[y+1][x]!='G' and matriz[y+1][x]!='B') visitados[y+1][x] = 1;
                   if (check(x, y-1, n, m) and matriz[y-1][x]!='G' and matriz[y-1][x]!='B') visitados[y-1][x] = 1;
                   if (check(x+1, y, n, m) and matriz[y][x+1]!='G' and matriz[y][x+1]!='B') visitados[y][x+1] = 1;
                   if (check(x-1, y, n, m) and matriz[y][x-1]!='G' and matriz[y][x-1]!='B') visitados[y][x-1] = 1;
                }
            }
        }

        cont = 0;
        dfs(m,n);

        if ((cont!=contG) or !poss) cout << "No" << endl;
        else cout << "Yes" << endl;

        poss = true;
    }

    return 0;
}
