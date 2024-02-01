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

int grau[112345];
int adj[112345];
int c[112345];
bool sold[112345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        queue<int> fila;

        int vendidos = 0;

        for(int i = 1; i<=n; i++) sold[i] = 0;
        for(int i = 1; i<=n; i++) grau[i] = 0;


        for(int i = 1; i <= n; i++) {
            int a;
            cin >> a;

            grau[a]++;
            adj[i] = a;
        }

        for(int i = 1; i <= n; i++) {
            cin >> c[i];
        }

        for(int i = 1; i <= n; i++) {
            if(grau[i] == 0) fila.push(i);
        }

        while(!fila.empty()) {
            int u = fila.front();
            sold[u] = 1;
            fila.pop();
            grau[adj[u]]--;
            if(grau[adj[u]] == 0) fila.push(adj[u]);
            vendidos++;

            cout << u << ' ';
        }

        //Vao restar apenas ciclos

        for(int i = 1; i <=n; i++) {
            if (!sold[i]) {
                int itr = adj[i];

                int menor = c[i];
                int indMenor = i;

                while(itr!=i) {
                    if (c[itr] < menor) {
                        menor = c[itr];
                        indMenor = itr;
                    }

                    itr = adj[itr];
                }

                itr = adj[indMenor];

                while(itr != indMenor) {
                    sold[itr] = 1;
                    cout << itr << ' ';
                    itr = adj[itr];
                }

                sold[indMenor] = 1;
                cout << indMenor << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}
