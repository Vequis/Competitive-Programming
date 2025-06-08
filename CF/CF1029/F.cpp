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

vi adj[212345];
int vis[212345];
int dist[212345];

int mult(int a, int b) {
    return (a*b)%MODN;
}

int binexpo(int base, int expo) {
    int exp = base;
    int resp = 1;

    while(expo > 0) {
        int cur = mult(expo%2, exp);
        if (cur != 0) resp = (resp * cur)%MODN;
        exp = (exp * exp) % MODN;
        expo/=2;
    }

    return resp;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <=n; i++) adj[i].clear();

    for (int i = 1; i <n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    for (int i = 1; i <=n; i++) {
        dist[i] = -1;
        vis[i] = 0;
    }

    queue<int> fila;
    fila.push(1);
    vis[1] = 1;

    int t = 1;
    bool begin = 1;
    dist[1] = 0;

    int a = -1, b = -1;
    while(!fila.empty()) {
        int numberfilhos = 0;
        
        int u = fila.front(); fila.pop();
        
        vis[u] = 1;
        for (int v : adj[u]) {
            if (!vis[v]) {
                numberfilhos++;
                fila.push(v);
                dist[v] = dist[u] + 1;
            }
        }

        // cout << u << ' ' << numberfilhos << endl;

        if (numberfilhos == 1 and begin) t++;
        else if (numberfilhos == 2 and begin) {
            begin = 0;
        } else if (numberfilhos == 0 and !begin) {
            if (a==-1) a = dist[u] - t + 1;
            else b = dist[u] - t + 1;
        } else     
        {
            if (numberfilhos > 1) {
                cout << 0 << endl;
                return;
            }
        }
    }

    if (b > a) swap(a, b);

    // cout << t << ' ' << a << ' ' << b << endl;

    if (a == -1 and b == -1) {
        cout << binexpo(2, t) << endl;
    } else if (a==b) {
        cout << mult(2, binexpo(2, t)) << endl;
    } else {
        cout << mult(mult(3, binexpo(2, t)), binexpo(2, a-b-1)) << endl;
    }
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}