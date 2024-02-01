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

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
string moves[] = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};
int dist[9][9];
ii ini, fim;
string a, b;
queue<ii> fila;

signed main(){_

    cin >> a >> b;

    ii ini, fim;
    ini.fs = a[1] - '0'; 
    ini.sc = a[0] - 'a' + 1; 
    fim.fs = b[1] - '0';
    fim.sc = b[0] - 'a' + 1; 

    for(int i=1; i<=8; i++){
        for(int j=1; j<=8; j++){
            dist[i][j] = -1;
        }
    }

    fila.push(fim);
    dist[fim.fs][fim.sc] = 0;

    while(!fila.empty()){
        ii p = fila.front();
        fila.pop();

        int linha = p.fs, coluna = p.sc;

        for(int k = 0; k < 8; k++){
            int xx = linha + dx[k], yy = coluna + dy[k];
            if(xx < 1 or xx > 8 or yy < 1 or yy > 8) continue;

            if(dist[xx][yy] == -1){
                dist[xx][yy] = dist[linha][coluna]+1;
                fila.push({xx, yy});
            }
        }
    }

    cout << dist[ini.fs][ini.sc] << endl;

    int a = fim.fs;
    int b = fim.sc;



    int linha = ini.fs, coluna = ini.sc, xm, ym, menor, kk;
    while(1){
        if(linha == fim.fs && coluna == fim.sc) break;
        menor = 1000;
        for(int k = 0; k < 8; k++){
            int xx = linha + dx[k], yy = coluna + dy[k];

            if(xx < 1 or xx > 8 or yy < 1 or yy > 8) continue;

            if(dist[xx][yy] < menor){
                xm = xx;
                ym= yy;
                menor = dist[xx][yy];
                kk = k;
            }
        }
        linha = xm;
        coluna = ym;
        cout << moves[kk] << endl;
    }

    return 0;
}
