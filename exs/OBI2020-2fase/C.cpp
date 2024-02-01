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
#define MAX (1<<10)
#define INF 0x3f3f3f3f
#define MODN 1000000007

using namespace std;

int n,m, x;

int ans, sz1, sz2;
int mat[3][MAX];

void mover(int linha, int coluna, int final){
    int in = mat[linha][coluna];
    mat[linha][final] = in;
    mat[linha][coluna] = 0;

    int l = 1 + (linha)%2;

    ans = ans + in*(mat[l][final] - mat[l][coluna]);
} 

int main(){_

    cin >> n;
    for (int i=1; i<=2; i++){
        cin >> m;
        if (i==1) sz1=m;
        else sz2= m;
        for (int j=1; j<=m; j++){
            cin >> x;
            ans+=mat[1][j]*x;
            mat[i][j] = x;
        }
    }

    for (int k=sz2; k>=0; k--){
        for (int j=sz1; j>=0; j--){
            for (int i=j; i<=n; i++){
                while(mat[1][i+1] == 0){
                    mover(1, i, i+1);
                }
            }
        }
    }
    return 0;
}