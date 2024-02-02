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

signed main(){_

    priority_queue<int, vi, greater<int>> pq;

    int t; 
    cin >> t;

    while (t--) {
        int n, m, d;
        cin >> n >> m >> d;
        vector<int> a;

        int soma = 0;
        int soma_rejeitados = 0;

        a.pb(0);
        for (int i = 1; i <= n; i++) {
            soma_rejeitados -= d;
            int num;
            cin >> num;
            a.pb(num);
            int cond = a[i];
            cond += soma_rejeitados;
            if (sz(pq) == m) cond -= pq.top();
            if (cond > 0) {
                soma += cond;

                soma_rejeitados = 0;

                if (sz(pq) == m) {
                    pq.pop();
                }
                pq.push(a[i]);
            } else if(a[i] > 0) {
            // } else {
                if (sz(pq) < m or a[i] > pq.top()) {
                    if (sz(pq) == m) {
                        soma_rejeitados -= pq.top();
                        pq.pop();
                    }
                    pq.push(a[i]);
                    soma_rejeitados += a[i];
                }
            }

            // cout << soma << ' ' << cond << endl;
        }

        cout << soma << endl;

        while (!pq.empty()) pq.pop();
        a.clear();
    }

    return 0;
}
