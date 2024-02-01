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

int n,m, a, b;

int ans, sz1, sz2, at;
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
        for (int j=1; j<=m; j++){
            int x;
            cin >> x;
            ans += x*mat[1][j];
            mat[i][j] = x;
        }
    }

    for (int x=1; x<=n; x++){
        for (int y=1; y<=n; y++){
            at = 0;
            if (x==y and x!=1) continue;

            for (int i=1; i<=n; i++){
                if (i==y or i==x) continue;

                if (i>x) a = mat[1][i-1];
                else a = mat[1][i];

                if (i>y) b = mat[2][i-1];
                else b = mat[2][i];

                at+=a*b;
            }
            ans = max(ans, at);
        }
    }

    cout << ans << endl;

    return 0;
}