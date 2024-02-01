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

#define MAXL 50
#define MAXN 212345

int n;
int a[MAXN];
int pai[MAXN];
int nivel[MAXN];
int maior = 0;

// declarar a tabela
int ancestral[MAXN][MAXL]; // MAXL representa lg N (com uma margem a mais, claro)

void ancestrais() {
    // primeiro, inicializamos tudo para -1
    for(int i = 0;i < MAXN;i++)
    for(int j = 0;j < MAXL;j++)
        ancestral[i][j] = -1;

    // definimos os pais de carda vértice
    for(int i = 0;i <= maior;i++) ancestral[i][0] = pai[i];

    // montamos o restante da tabela com programação dinâmica
    for(int j = 0;j <  MAXL;j++)
    for(int i = 0;i <=maior;i++)
        if(ancestral[i][j-1] != -1)
            ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
}

int LCA(int u, int v){
    
    if(nivel[u] < nivel[v]) swap(u, v); // isto é para definir u como estando mais abaixo
    
    // vamos agora fazer nivel[u] ser
    // igual nivel[v], subindo pelos
    // ancestrais de u
    
    for(int i = MAXL-1;i >= 0;i--)
        if(nivel[u] - (1<<i) >= nivel[v])
            u = ancestral[u][i];
            
    cout << nivel[u] << ' ' << nivel[v] <<  endl;
    // agora, u e v estão no mesmo nível
    if(u == v) return u;
    
    // subimos o máximo possível de forma
    // que os dois NÃO passem a ser iguais
    
    for(int i = MAXL-1;i >= 0;i--)
        if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
            u = ancestral[u][i];
            v = ancestral[v][i];
        }
    
    // como subimos o máximo possível
    // sabemos que u != v e que pai[u] == pai[v]
    // logo, LCA(u, v) == pai[u] == pai[v]
    
    return ancestral[u][0];
}

signed main(){_

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maior = max(maior, a[i]);
    }

    pai[0] = -1;
    nivel[0] = 0;
    int atual = 1;
    for (int i = 1; i <= maior; i++) {
        pai[i] = atual - i;
        nivel[i] = nivel[pai[i]] + 1;

        if (atual == i) atual*=2;
    }

    ancestrais();

    int resp = 0;
    ii p;

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cout << i << ' ' << j << ' ' << LCA(a[i], a[j]) << endl;
            int atual = nivel[a[i]] + nivel[a[j]] - 2*nivel[LCA(a[i], a[j])];

            if (atual > resp) {
                resp = atual;
                p = {i, j};
            }
        }
    }

    cout << p.fs << ' ' << p.sc << ' ' << resp << endl;

    return 0;
}
