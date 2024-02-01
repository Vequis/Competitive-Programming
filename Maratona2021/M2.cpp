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
bool morto[112345];

int inicio;

int prox[112345];

int cont = 1;

void inserir(int node) {
    int alvo = 0;
    int p = pai[node];
    alvo = p;
    for (int i = 0; i < sz(nobre[p]); i++) {
        if (!morto[nobre[p][i]]) {
            alvo = nobre[p][i];
        }
    }

    nobre[p].pb(node);

    prox[node] = prox[alvo];
    prox[alvo] = node;
}

signed main(){_

    nobre[0].pb(1);
    pai[1] = 0;
    inicio = 1;
    morto[1] = false;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int op, num;
        cin >> op >> num;

        if (op == 1) {
            cont++;
            pai[cont] = num;
            morto[cont] = false;
            inserir(cont);
        } else {
            morto[num] = true;
            while(morto[inicio]) {
                inicio = prox[inicio];
            }
            cout << inicio << endl;
        }
    }

    return 0;
}
