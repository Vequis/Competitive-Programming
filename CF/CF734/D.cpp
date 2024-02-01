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

int n, m, ni, mi, x, y;
int k;
int t, atual;
int mat[110][110];

signed main(){_

    cin >> t;
    while(t--){
        cin >> n >> m >> k;

        int quadrados = (m/2)*2;
        quadrados *= (n/2)*2;

        quadrados/=4;

        if(n%2 == 1){
            k-=m/2;
        }

        ni = (n/2)*2;
        mi = (m/2)*2;

        if(k<0 or k%2==1 or k/2 > quadrados) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;

            atual = 1;
            x = y = 1;
            for(int i=0; i<k/2; i++){
                if(mat[x-1][y] == atual or mat[x][y-1] == atual){
                    atual++;
                }
                mat[x][y] = atual;
                mat[x][y+1] = atual;
            
                if(atual==26) atual=1;
                else atual++;
            
                mat[x+1][y] = atual;
                mat[x+1][y+1] = atual;

                if(x+2<=ni) x+=2;
                else {
                    x=1;
                    y+=2;
                }
            }

            if(n%2==1){
                for(int i=1; i<=m; i+=2){
                    if(mat[x-1][y] == atual or mat[x][y-1] == atual){
                        atual++;
                    }
                    mat[n][i] = atual;
                    mat[n][i+1] = atual;

                    if(atual==26)atual=1;
                    else atual++;
                }
            }

            for(int i=1; i<=n; i++){
                for(int j=1; j<=m; j++){
                    cout << (char)('a' -1 + mat[i][j]);
                }
                cout << endl;
            }
        }
    }

    return 0;
}
