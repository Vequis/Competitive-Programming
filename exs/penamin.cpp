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
#define MAXX 1111
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int memo2[MAXX][MAXX], memo5[MAXX][MAXX];
int qtd2[MAXX][MAXX], qtd5[MAXX][MAXX]; 
int atual1, atual2;
ii melhor;
int n;

void dp(int i, int j){
    if(i<=0 || i>n || j<=0 || j>n) return;

    if(i-1<=0 || i-1>n || j<=0 || j>n || (memo2[i-1][j] == -1)){
        atual1 = INT_MAX;
    } else {
        dp(i-1, j);
        atual1 = min(memo2[i-1][j], memo5[i-1][j]);
    }

    if(i<=0 || i>n || j-1<=0 || j-1>n || (memo2[i][j-1] == -1)){
        atual2 = INT_MAX;
    } else {
        dp(i, j-1);
        atual2 = min(memo2[i][j-1], memo5[i][j-1]);
    }

    if(atual1 < atual2) melhor = {-1, 0};
    else if (atual1 > atual2) melhor = {0, -1};
    else {
        
    }

    memo2[i][j] = memo2[i+melhor.fs][j+melhor.sc] + qtd2[i][j];
    memo5[i][j] = memo5[i+melhor.fs][j+melhor.sc] + qtd5[i][j];
}

signed main(){_

    cin >> n;
    int cont = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int num;
            cin >> num;

            if(num==0) {
                memo2[i][j] = -1;
                continue;
            }

            cont=0;
            while(num%2 == 0){
                num/=2;
                cont++;
            }
            qtd2[i][j] = cont;

            cont = 0;
            while(num%5 == 0){
                num/=5;
                cont++;
            }
            qtd5[i][j] = cont;
        }
    }

    dp(n, n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << memo2[i][j] << ' ' << memo5[i][j] << ' ' << ' ';
        }
        cout << endl;
    }
    cout << min(memo2[n][n], memo5[n][n]) << endl;

    return 0;
}
