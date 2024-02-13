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

int prox[212345];
int mark[212345];

void solve() {
    int n, k;
    cin >> n >> k;

    for(int i = 1; i<=n; i++) prox[i] = -1;
    for(int i = 1; i<=n; i++) mark[i] = 0;

    int head = -1;
    int primeiro = 1;
    int deuruim = 0;
    int ultimo = 1;
    while(k--) {
        int prim;
        cin >> prim;
        int ant = prim;
        int itl = head;

        for(int i = 1; i <=n; i++) cout << prox[i] << ' ';
        cout << endl;

        for(int i = 2; i <=n; i++) {
            int itv;
            cin >> itv;

            if (primeiro) {
                head = itv;
                primeiro = 0;
            }

            if (ant != prim and prox[ant] == -1) {
                prox[ant] = itv;
                mark[ant] = 1;
            }

            if (!deuruim and itl == prim) itl = prox[itl];
            if (itl == INF and i!=n) {
                deuruim = 1;
                // continue;
            }

            if (!mark[itv]) {
                if (ant != prim) {
                    prox[ant] = itv;
                }
                mark[itv] = 1;
            } else if (!deuruim and mark[itv]) {
                if (itl != itv) {
                    deuruim = 1;
                    cout << k << ' ' <<  itl << ' ' << itv << endl;
                }
                if(itl!=INF) itl = prox[itl];
            }
            ant = itv;      
        }

        // if (ultimo) {
        //     ultimo = 0;
        //     prox[ant] = INF;
        // }
    }

    if (deuruim) {
        cout << "NO" << endl;
        return;
    }

    if (k==1) {
        cout << "YES" << endl;
        return;
    }

    cout << "YES" << endl;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
