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
// #define int long long -> solução divina?

using namespace std;

ll atual[51][51], ant[51][51], resp[51][51], aux[51][51], n, m;

void multmatriz(ll a[51][51], ll b[51][51], ll aux[51][51]){
    //aux é a matriz onde deixaremos a resposta;

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            ll var = 0;
            for(int k=0; k<m; k++){
                var = (var + (a[i][k]*b[k][j])%MODN)%MODN;
            }
            aux[i][j] = var;
        }
    }
}

void expo(ll n){

    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            resp[i][j] = 0;
            if(i==j) resp[i][j] = 1;
        }
    }

    while(n>0){
        if(n%2) {
            multmatriz(resp, atual, aux);
            for(int i=0; i<m; i++){
                for(int j=0; j<m; j++){
                    resp[i][j] = aux[i][j];
                }
            }
        }
        n/=2;
        multmatriz(atual, atual, aux);
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                atual[i][j] = aux[i][j];
            }
        }
    }
}

int main(){_

    int t;
    cin >> t;

    while(t--){
        cin >> m >> n;

        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                cin >> atual[i][j];
            }
        }

        expo(n);

        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
                cout << resp[i][j] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}