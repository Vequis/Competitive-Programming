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

vector<int> nobre[112345];
int pai[112345];
int filhos[112345];
bool morto[112345];

void transferir(int filho) {
    vi aux;

    int cor = 0;

    for (int i = 0; i < sz(nobre[pai[filho]]); i++) {
        if (nobre[pai[filho]][i] != filho) {
            aux.pb(nobre[pai[filho]][i]);
        } else {
            for (int j = 0; j < sz(nobre[filho]); j++) {
                aux.pb(nobre[filho][j]);
                pai[nobre[filho][j]] = pai[filho];
            }
        }
    }

    nobre[pai[filho]] = aux;
}

void atualiza(int node, int valor) {
    filhos[node] += valor;
    if(node == 0) return;
    atualiza(pai[node], valor);
}

int herdeiro(int node) {

    for (int i = 0; i < sz(nobre[node]); i++) {
        if ( !morto[nobre[node][i]] ) return nobre[node][i];
        if (filhos[ nobre[node][i] ] != 0) {
            return herdeiro(nobre[node][i]);
        }
    }
    return -1;
}

int cont = 1;

signed main(){_

    nobre[0].pb(1);
    pai[1] = 0;
    filhos[0] = 1;
    filhos[1] = 1;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int op, num;
        cin >> op >> num;

        if (op == 1) {
            cont++;
            pai[cont] = num;
            nobre[num].pb(cont);
            atualiza(num, 1);
            filhos[cont] = 1;
        } else {
            atualiza(num, -1);
            morto[num] = 1;
            cout << herdeiro(0) << endl;
        }

        // cout << '*' << filhos[1] << endl;
    }

    // for(int i = 0; i <5; i++) cout << filhos[i] << endl;

    return 0;
}
