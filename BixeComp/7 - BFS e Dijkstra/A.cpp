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

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1,-1, 1,-1, 0, 1, -1, 0};

int n, m;
char mat[60][60];
int dist[60][60];
queue<ii> fila;
int cont, maior;

signed main(){_

    while((cin >> n >> m) && (n!=0 && m!=0)){
        cont++;
        maior = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                dist[i][j] = -1;
                char c;
                cin >> c;
                mat[i][j] = c;
                if(c=='A') {
                    fila.push({i, j});
                    dist[i][j] = 1;
                    maior = 1;
                }
            }
        }   

        while(!fila.empty()){
            ii p = fila.front(); 
            fila.pop();
            int ia = p.fs, ja = p.sc;

            for(int i=0; i<8; i++){
                if((char)('A' + dist[ia][ja]) == mat[ia+dx[i]][ja+dy[i]] && dist[ia+dx[i]][ja+dy[i]]==-1){
                    fila.push({ia+dx[i], ja+dy[i]});
                    dist[ia+dx[i]][ja+dy[i]] = dist[ia][ja] + 1;
                    maior = max(dist[ia+dx[i]][ja+dy[i]], maior);
                }
            }
        }

        cout << "Case " << cont << ": " << maior << endl;
    } 


    return 0;
}
