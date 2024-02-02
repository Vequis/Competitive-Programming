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
#define int long long

using namespace std;

int adj[112345];
int first_vis[112345];
int first_adj[112345];
int in[112345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int k;
        cin >> k;

        int final = 0;

        for(int i = 1; i <=n; i++) in[i] = 0;

        for(int i = 1; i <=n; i++) {
            cin >> adj[i];
            in[adj[i]]++;
        }

        for(int i = 1; i <=n; i++) {
            if (adj[i] == i and k != 1) {
                cout << "NO" << endl;
                final = 1;
                break;
            } else if (adj[i] == i) {
                adj[i] = -1;
                first_vis[i] = 0;
                in[i]--;
            }
        }

        if(final) continue;

        for(int i = 1; i <=n; i++) first_adj[i] = adj[i];

        int cont = 0;

        for (int i = 1; i <= n; i++) {
            // cout << i << ' ' << adj[i] << endl;
            if (first_adj[i] != -1) {
                cont++;
                int itr = i;

                while(first_adj[itr] != -1) {
                    // cout << itr << endl;k
                    int aux = itr;
                    itr = first_adj[itr];
                    first_adj[aux] = -1;
                    first_vis[aux] = cont;
                }

                if (first_vis[itr] == cont) {
                    int ciclo = 1;
                    int init = itr;

                    itr = adj[itr];
                    adj[init] = -1;
                    while(itr != init) {
                        int aux = itr;
                        itr = adj[itr];
                        adj[aux] = -1;
                        ciclo++;
                        if(itr != -1) in[itr]--;
                    }

                    // cout << "Cicloo" << ciclo << endl;

                    if (ciclo!=k) {
                        final = 1;
                        cout << "NO" << endl;
                        break;
                    }
                }
            }
        }
        if (final) continue;

        for (int i = 1; i <= n; i++) {
            if (adj[i] != -1 and in[i] == 0) {
                int itr = i;

                int ciclo = 0;

                while(itr != -1) {
                    // cout << '*' << itr << endl;
                    ciclo++;
                    int aux = itr;
                    itr = adj[itr];
                    adj[aux] = -1;
                    if(itr!=-1) in[itr]--;

                }

                if (ciclo != k) {
                    final = 1;
                    cout << "NO" << endl;
                    break;
                }
            }
        }

        if(!final) cout << "YES" << endl;

    }

    return 0;
}
