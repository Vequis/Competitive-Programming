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

int prox[312345];

int a[312345];
int topo, fim;

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            prox[i] = i+1;
        }

        prox[n] = -1;
        topo = 1;
        fim = n;

        int m, it, cont;
        cin >> m;

        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;

            cont = 0;
            it = topo;

            while(cont < num - 1) {
                it = prox[it];
                cont++;
            }

            prox[fim] = topo;
            fim = it;
            topo = prox[it];
            prox[it] = -1;
        }

        cout << a[topo] << endl;
    }



    return 0;
}
