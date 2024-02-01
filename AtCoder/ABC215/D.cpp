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

vi v, resp;
vi primos;
int visitados[112345];
int passado[112345];

void crivo(int n){
    primos.pb(2);
    for(int i=3; i<=n; i+=2){
        if(!visitados[i]){
            visitados[i] = 1;
            primos.pb(i);
            for(int j=i*i; j<=n; j+=i) visitados[j] = 1;
        }
    }
}

signed main(){_

    int n, m;
    cin >> n >> m;

    crivo(m);

    int atual;

    int contresp = m;
    bool fecha;

    for(int i = 1; i<=n; i++){
        cin >> atual;
        fecha = false;
        for(int primo : primos){
            if(atual == 1) break;

            if(primo*primo > atual) {
                primo = atual;
                fecha = true;
            }


            if(atual%primo == 0 && passado[primo] == 0){
                for(int j=primo; j<=m; j+=primo){
                    passado[j] = 1;
                }
            }

            if(fecha) break;

            while(atual%primo == 0){
                atual/=primo;
            }
        }
    }

    for(int i=1; i<=m; i++){
        if(!passado[i]){
            resp.pb(i);
        }
    }

    cout << sz(resp) << endl;

    for(int x : resp){
        cout << x << endl;
    }

    return 0;
}
