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

// O(N log N)

map<int, int> idtox;
map<int, int> xtoid;

vector<int> compress(const vector<int>& a) {
    vi sorted = a;
    sort(all(sorted));
    sorted.erase(unique(all(sorted)), sorted.end());

    vi compressed;
    for (int val : a) {
        int idx = lower_bound(all(sorted), val) - sorted.begin() + 1;
        compressed.pb(idx);
        xtoid[val] = idx;
        idtox[idx] = val;
    }

    return compressed;
}

vii points;
int removido[212345];

int count_segments(int x) {
    int resp = 0;
    for (int i = 1; i <= sz(points) - 1; i++) {
        if (!removido[i] and points[i].fs <= x and x <= points[i].sc)  resp++;
    }

    return resp;
}


void solve() {
    
    int n, k;
    cin >> n >> k;

    points = vii(n+1);
    points[0] = {0, 0};
    vi singlepoints;
    for (int i = 1; i <=n; i++) {
        int a, b;
        cin >> a >> b;
        singlepoints.pb(a);
        singlepoints.pb(b);

        points[i] = {a, b};
    }

    vi compressed = compress(singlepoints);
    for (int i = 1; i <=n; i++) {
        points[i] = {xtoid[points[i].fs], xtoid[points[i].sc]};
        // cout << points[i].fs << ' ' << points[i].sc << endl;
    }

    sort(all(compressed));
    int cont_removido = 0;

    for (int x : compressed) {
        int delta = count_segments(x);
        if (delta > k) {
            // vamos ter que tirar segmentos
            // idealmente ja limpamos tudo pra esquerda, então queremos pegar um que pegue 
            // o mais da direita possível
            // cout << x << ' ' << delta << '*' << endl;
            delta -= k;
            
            while(delta--) {
                int maioridx = 0;
                for (int i = 1; i <= n; i++) {
                    if (!removido[i] and points[i].fs <= x and x <= points[i].sc and points[i].sc > points[maioridx].sc) {
                        maioridx = i;
                    }
                }

                removido[maioridx] = 1;
                cont_removido++;
            }
        }
    }

    cout << cont_removido << endl;
    for (int i = 1; i <=n; i++) {
        if (removido[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;
}

signed main(){_
    // vi original = {100, 500, 100, 2000, 500};
    // vi compressed = compress(original);
    
    // for (int x : compressed) {
    //     cout << x << ' ';
    // }
    // cout << endl;
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}