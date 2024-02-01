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

int n, w, b, x, maior;

int dp[1111][11234];
int c[1111], custo[1111];

signed main(){_

    cin >> n >> w >> b >> x;

    for(int i=1; i<=n; i++) cin >> c[i];
    for(int i=1; i<=n; i++) cin >> custo[i];

    memset(dp, 0, sizeof(dp));

    dp[0][0] = w;

    for(int i=1; i<=10005; i++) dp[0][i] = -1; //Inválida

    //dp iterativa
    //dp[posicao][passaros invocados no total]
    //dp = maior valor de mana depois de finalizar a rodada com tal qtnd de passaros
    for(int i=1; i<=n; i++){ //Passando por todas as posições
        maior=0;//Guarda a resposta
        for(int q=0; q<=10005; q++){
            for(int j=0; j<=min(q,c[i]); j++){
                if(dp[i-1][q-j] - custo[i]*j >= 0){ //Se puder invocar o pássaro
                    dp[i][q] = max(dp[i][q], min(dp[i-1][q-j] - custo[i]*j + x, w+b*q));
                    maior = max(maior, q);
                } else {
                    if(dp[i-1][q] == -1 && (dp[i][q] <= 0)) dp[i][q] = -1;
                }
            }   
        }
        // for(int j=0; j<=11; j++) cout << dp[i][j] << ' ';
        // cout << endl;
    }

    cout << maior << endl;

    return 0;
}
