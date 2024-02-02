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


int defeated = 0;
int count_monsters = 1;
int count_med = 0;
int cur_str = 1;
int med[513];
priority_queue<ii, vii, greater<ii>> pq; //Monstro mais fraco
int s[513];
int g[513];
vi adj[513];

int vis[513];
int reachable[513];

int t[513];

int last_med = -1;
priority_queue<ii, vii, greater<ii>> pq_entrada[13]; //Monstro mais fraco
int in_reachable[13][513];

int maximo = 0;

bool dfs_permutation() {
    int in_str = cur_str;
    int in_def = defeated;

    int in_last = last_med;
    if (last_med == -1) in_last = 0;
    pq_entrada[in_last] = pq;

    for(int i = 1; i <= count_med; i++) in_reachable[in_last][med[i]] = reachable[med[i]];


    if(last_med != -1) {
        cur_str*=g[med[last_med]];
        if(cur_str > maximo) return true;
        for (int enemy : adj[med[last_med]]) {
            if (t[enemy] == 1) pq.push({s[enemy], enemy});
            else reachable[enemy] = 1;
        }
    }

    while(!pq.empty() and cur_str >= pq.top().fs) {
        ii enemy = pq.top();

        // cout << "MED" << endl;
        // for (int i = 1; i <= count_med; i++) cout << vis[i] << ' ';
        // cout << endl;
        // cout << cur_str << ' ' << enemy.fs << ' ' << enemy.sc << endl;

        // retirados.push(enemy);
        pq.pop();

        cur_str+=g[enemy.sc];
        if(cur_str > maximo) return true;

        for(int v: adj[enemy.sc]) {
            if (t[v] == 1) pq.push({s[v], v});
            else reachable[v] = 1;
        }

        defeated++;
        if(defeated == count_monsters) return true;
    }

    // cout << "REACH" << endl;
    // for (int i = 1; i <= count_med; i++) cout << reachable[med[i]] << ' ';
    // cout << endl;

    for(int i = 1; i <= count_med; i++) {
        if(vis[med[i]] == -1 and reachable[med[i]]) {
            vis[med[i]] = 1;

            last_med = i;

            if (dfs_permutation()) return true;
            vis[med[i]] = -1;
        }
    }

    for(int i = 1; i <= count_med; i++) reachable[med[i]] = in_reachable[in_last][med[i]];
    last_med = in_last;
    pq = pq_entrada[in_last];
    cur_str = in_str;
    defeated = in_def;

    return false;
}

// int lastt = 0;
// int pai[513];
// void initial_dfs(int node) {
//     int in_last = 
//     if (t[node] == 2) {
//         pai[node] = lastt;
//         lastt = node;
//     }

//     for(int v : adj[node]) {
//         initial_dfs(v);
//     }

//     if(t[node] == 2) lastt = node;
// }

signed main(){_

    memset(vis, -1, sizeof(vis));
    memset(reachable, 0, sizeof(reachable));

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p >> t[i];
        cin >> s[i] >> g[i];
    
        adj[p].pb(i);

        if (t[i]==2) {
            med[++count_med] = i;
        } else {
            count_monsters++;
        }

        maximo = max(maximo, s[i]);
    }

    pq.push({0, 1});
    g[1] = 0;

    if(dfs_permutation()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
