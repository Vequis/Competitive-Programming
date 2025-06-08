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

int a[212345];

vector<vi> v;

vi resp_olhando_pela_direita;
vi resp_olhando_pela_esquerda;
int idx_menor, idx_maior; //idx_menor eh o ultimo idx que contem valor+1 antes do indice que eu to agr
int k;

int melhor_resp(int indx, int valor) {
    if (valor==k) return 0;
    auto it = lower_bound(all(v[valor+1]), indx);
    int x = it - v[valor+1].begin();

    if (x == sz(v[valor+1])) {
        idx_menor = v[valor+1][x-1];
        return resp_olhando_pela_direita[idx_menor] + indx;
    } else if (x == 0) {
        idx_maior = v[valor+1][0];
        return resp_olhando_pela_esquerda[idx_maior] - indx;
    } else {
        idx_maior = v[valor+1][x];
        idx_menor = v[valor+1][x-1];

        return min(resp_olhando_pela_direita[idx_menor] + indx, resp_olhando_pela_esquerda[idx_maior] - indx);
    }
}

int INFLL = INF;
int anterior = INFLL;

void solve() {
    int n;
    cin >> n >> k;
    
    v = vector<vi>(n+1); // v[i] guarda um vector com todos os indicies j
            // tal que a[j] = i

    for (int i = 1; i <=n; i++) {
        cin >> a[i];
        v[a[i]].pb(i);
    }

    //v[i] ja esta sorteado
    resp_olhando_pela_direita = vi(n+1);
    resp_olhando_pela_esquerda = vi(n+1);

    for (int valor = k; valor>=1; valor--) {
        anterior = INFLL;
        // for (int i = 0; i < sz(v[valor]); i++) {
        for (int idx : v[valor]) {
            resp_olhando_pela_direita[idx] = min(melhor_resp(idx, valor) - idx, anterior);
            anterior = resp_olhando_pela_direita[idx];
        }
        
        anterior = INFLL;
        for (int i = sz(v[valor])-1; i>=0; i--) {
            int idx = v[valor][i];
            resp_olhando_pela_esquerda[idx] = min(melhor_resp(idx, valor) + idx, anterior);
            anterior = resp_olhando_pela_esquerda[idx];
        }
    }

    for (int i = 1; i <=n; i++) {
        cout << melhor_resp(i, 0) << ' ';
    }
    cout <<endl;

}

signed main(){_
    INFLL*=INF;
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}