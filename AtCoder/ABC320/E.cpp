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

int cont[212345];

signed main(){_

    int n, m;
    cin >> n >> m;

    memset(cont, 0, sizeof(cont));
    priority_queue<int, vi, greater<int>> pq;
    priority_queue<ii, vii, greater<ii>> eventos; //{tempo, id}
    vii reg_eventos;

    for(int i = 0; i < m; i++) {
        int t, w, s;
        cin >> t >> w >> s;

        reg_eventos.eb(w, s);

        eventos.push({t, sz(reg_eventos) - 1 + 5123456});
    }

    for(int i = 1; i <= n; i++) pq.push(i);

    while(!eventos.empty()) {
        ii fr = eventos.top();
        eventos.pop();

        int t = fr.first;
        int id = fr.sc;

        if (id >= 5123456) id-=5123456;
        // cout << id << endl;

        if (reg_eventos[id].sc != -1 and !pq.empty()) {
            // id-=212345;
            int primeiro = pq.top();
            pq.pop();

            cont[primeiro] += reg_eventos[id].fs;
            reg_eventos.eb(primeiro, -1);

            // cout << id << ' ' << primeiro << ' ' << reg_eventos[id].fs << endl; 

            eventos.push({t+reg_eventos[id].sc, sz(reg_eventos) - 1});
        } else {
            pq.push(reg_eventos[id].fs);
        }
    }

    for(int i = 1; i <=n; i++) cout << cont[i] << endl;

    return 0;
}
