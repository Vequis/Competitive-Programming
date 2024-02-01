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

int n, m, cont;
int mat[100][100];

bool sqr(int i, int j){
    if (mat[i+1][j]>0 && mat[i][j+1]>0 && mat[i+1][j+1]>0) return 1;
    return 0;
}

bool pos = true;

int main(){_

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mat[i][j];
        }
    }

    for (int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if ((mat[i][j] == 1 or mat[i][j] == 2) && sqr(i,j)){
                // cout << "op" << ' ' << i << ' ' << j << endl;
                mat[i][j] = 2;
                mat[i+1][j] = 2;
                mat[i][j+1] = 2;
                mat[i+1][j+1] = 2;
                cont++;
            } else if (mat[i][j]==1 && !sqr(i,j)){
                // cout << i << ' ' << j << endl;
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << cont << endl;

    for (int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if ((mat[i][j] == 2) and sqr(i,j)){
                cout << i << ' ' << j << endl;
            }
        }
    }

    return 0;
}