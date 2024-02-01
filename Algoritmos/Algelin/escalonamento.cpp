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

using namespace std;

double matriz[1000][1000], pos[1000], maux[1000], sol[1000];
int m,n, pivos, linha;

int pivo(int col){
    for (int i=pivos+1; i<=n; i++){
        if (matriz[i][col]){
            return i;
        }
    }
    return 0;
}

void tipo3(int a, int b, int col){
    double fator = matriz[b][col]/matriz[a][col];
    int co = col;
    matriz[b][col] = 0;
    for (int i=co+1; i<=m+1; i++){
        matriz[b][i] -= matriz[a][i]*fator;
    }
}

void tipo3inv(int a, int b){ //coluna e linha
    double fator = matriz[a][b]/matriz[b][b];
    matriz[b][a] = 0;
    matriz[b][m+1] -= matriz[a][m+1]*fator;
}

int main(){_

    cin >> n >> m; //Linhas e colunas;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m+1; j++){
            cin >> matriz[i][j];
        }
    }

    cout << endl;

    for (int i=1; i<=m; i++){
        linha = pivo(i);
        // cout << i << ' ' << linha << endl;
        if (linha){
            pivos++;
            pos[i] = linha;
            swap(matriz[pivos], matriz[linha]);
        
            for (int j=linha+1; j<=n; j++){
                if (matriz[j][i]){
                    tipo3(linha, j, i);
                }
            }
        }
    }
    
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << matriz[i][j] << ' ';
        }
        cout << '=' << ' ' << matriz[i][m+1];
        cout << endl;
    }

    for (int i=1; i<=m; i++){
        if (pos[i] == 0){
            cout << "Esse nao e um SPD! Tente novamente, panaca!" << endl;
            return 0;
        }
    }


    cout << "RETRO" << endl;

    for (int i=m; i>=1; i--){
        for (int j=i-1; j>=1; j--){
            if (matriz[j][i] and matriz[i][i] != 0){
                matriz[j][m+1] -= matriz[i][m+1]*(matriz[j][i]/matriz[i][i]);
                matriz[j][i] = 0;
            }
        }
    }

    double det = 1;
    for (int i=1; i<=n; i++){
        if (m!=n) break;
        det*=matriz[i][i];

        if (i==n) cout << "DETERMINANTE: " << det << endl;
    }

    for (int i=m+1; i<=n; i++){
        if (matriz[i][m+1] !=0){
            cout << "Esse sistema e impossivel!" << endl;
            return 0;
        }
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << matriz[i][j] << ' ';
        }
        cout << '=' << ' ' << matriz[i][m+1];
        cout << endl;
    }

    cout << "Esse e um SPD cujas solucoes sao: " << endl;

    for (int i=1; i<=m; i++){
        double resp = matriz[i][m+1]/matriz[i][i];
        cout <<resp << endl;
    }
    return 0;
}