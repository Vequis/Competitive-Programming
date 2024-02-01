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
#define maxn 212345

using namespace std;

int alvo;
int dist[maxn];
int pai[maxn];
bool vis[maxn];
vi adj[maxn];

set<int> ciclo;
bool jaciclo = 0;

void dfs(int node) {
    vis[node] = 1;

    if (jaciclo) return;

    for (int v : adj[node]) {
        if (jaciclo) return;
        if (!vis[v]) {
            pai[v] = node;
            vis[v] = 1;
            dist[v] = dist[node] + 1;
            dfs(v);
        } else if(pai[node] != v) {
            // cout << "Entrou" << endl;
            int itr = node;
            while (itr != v) {
                ciclo.insert(itr);
                if (itr != 0) cout << v << ' ' << itr << endl;
                itr = pai[itr];
            }

            ciclo.insert(v);
            // cout << "Entrou" << endl;
            jaciclo = 1;
            return;
        }
    }
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a, b;
        cin >> a >> b;

        for(int i = 1; i <= n; i++) {
            int aa, bb;
            cin >> aa >> bb;

            adj[aa].eb(bb);
            adj[bb].eb(aa);
        }

        jaciclo = 0;

        for(int i = 1; i <= n; i++) {
            vis[i] = 0;
            dist[i] = -1;
            pai[i] = -1;
        }

        dist[1] = 0;
        dfs(1);

        stack<int> pilha;
        pilha.push(a);

        int dista = -1;
        int fsa = -1;

        for(int i = 1; i <= n; i++) dist[i] = -1;
        dist[a] = 0;
        while(!pilha.empty()) {
            int topo = pilha.top();
            pilha.pop();

            if (ciclo.find(topo) != ciclo.end()) {
                dista = dist[topo];
                fsa = topo;
                while(!pilha.empty()) pilha.pop();
                break;
            }
            
            for(int v : adj[topo]) {
                if (dist[v] == -1) {
                    dist[v] = dist[topo] + 1;

                    pilha.push(v);
                }
            }
        }



        pilha.push(b);

        int distb = -1;
        int fsb = -1;

        // cout << fsa << ' ' << endl;

        for(int i = 1; i <= n; i++) dist[i] = -1;
        dist[b] = 0;
        while(!pilha.empty()) {
            int topo = pilha.top();
            pilha.pop();

            if (topo == fsa) {
                distb = dist[topo];
                // cout << topo << ' ' << "entrou" << endl;
                // fsb = topo;
                while(!pilha.empty()) pilha.pop();
                break;
            }
            
            for(int v : adj[topo]) {
                if (dist[v] == -1) {
                    dist[v] = dist[topo] + 1;

                    pilha.push(v);
                }
            }
        }

        cout << dista << ' ' << distb << endl;

        if (dista < distb) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
