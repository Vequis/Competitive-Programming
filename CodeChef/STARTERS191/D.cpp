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

void solve() {
    int n;
    cin >> n;
    
    // vii pares_diferentes;
    map<int, int> busy;
    map<int, set<int>> pares;
    map<int, int> alreadyprocessed;

    int resp = 0;
    int filled = 0;

    vii v(n+1);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        v[i] = {a, b};

        if (a==b) {
            if (busy[a] == 0) busy[a] = 1;
            else resp += 2;

            filled++;
        } else {
            pares[a].insert(i);
            pares[b].insert(i);
        }
    }

    set<ii> cj;
    for (int i = 1; i <=n; i++) {
        if (sz(pares[i])) cj.insert({sz(pares[i]), i});
    }

    while(!cj.empty()) {
        ii topo = *cj.begin(); cj.erase(cj.begin());
        int num = topo.sc;

        // cout << '*' << num << sz(cj) << endl;
        if (busy[num]) continue;

        // ii p = pares[num][0]; // as vezes esse primeiro par ja foi usado


        int x = *pares[num].begin();
        int outro = v[x].fs + v[x].sc - num;

        busy[num] = 1;
        filled++;
        resp++;


        if (!busy[outro]) {
            cj.erase(cj.find({sz(pares[outro]), outro}));
            pares[outro].erase(pares[outro].find(x));
            if (sz(pares[outro]) != 0) cj.insert({sz(pares[outro]), outro});
        }
    }

    // cout << resp << endl;

    resp += 2*(n - filled);

    cout << resp << endl;

    // pq com {freq, number};
}

signed main(){
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}