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

using namespace std;

int n,m,k, s = 0;
int cont;
vector< string > maze(505, "");
vector< vi > visitados (505, vector<int>(505, 0));

pair<int,int> dir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1}};

bool check(int a, int b){
    return !(a>n or a<1 or b>m or b<1);
}

void dfs(int a, int b){
    if (visitados[a][b] == 1) return;
    
    if (cont == s-k) return;

    cont++;
    visitados[a][b] = 1;

    for (int i=0; i<4; i++){
        if (check(a+dir[i].fs, b+dir[i].sc) and maze[a+dir[i].fs][b+dir[i].sc] == '.') dfs(a+dir[i].fs, b+dir[i].sc);
    }
}

int main(){_

    cin >> n >> m >> k;

    // maze = vector< vector<char>(m)> (n);
    // visitados = vector< vector<int>(m)> (n);

    ii inicial = {0,0};

    for (int i=1; i<=n; i++){
        string st;
        cin >> st;
        maze[i] = '#';
        for (int j=1; j<=m; j++){
            maze[i] += st[j-1];
            if (st[j-1] == '.'){
                if (inicial.fs == 0 and inicial.sc==0){
                    inicial = {i,j};
                }
                s++;
            } else {
                visitados[i][j] = 1;
            }
        }
    }

    cont = 0;
    dfs(inicial.fs, inicial.sc);

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (visitados[i][j] == 0){
                cout << 'X';
            } else {
                cout << maze[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}