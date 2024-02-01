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

int t, n, m, cur=1;
int a[1010][1010];
int aux[10010];

void trocar(int b, int c, int x, int y){
    int var = a[b][c];
    a[b][c] = a[x][y];
    a[x][y] = var;
}

int main(){_

    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                cin >> a[i][j];
                aux[m*(i-1)+j] = a[i][j];
            }
        }

        sort(aux+1, aux+1+n*m);

        int maior = aux[m];

        cur=1;

        for (int i=1; i<=n; i++){
            sort(a[i]+1, a[i]+m+1);
            for (int j=1; j<=m; j++){
                if (a[i][j] <=maior and cur<=m){
                    trocar(i,j,i,cur);
                    cur++;
                }
            }
        }

        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}