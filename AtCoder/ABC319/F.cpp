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
int in_str;
int in_def;
int med[512];
priority_queue<ii, vii, greater<ii>> pq; //Monstro mais fraco
priority_queue<ii, vii, greater<ii>> pq_entrada; //Monstro mais fraco
int s[512];
int g[512];
vi adj[512];

int vis[512];
int reachable[512];
int in_reachable[512];

int t[512];

int last_med = -1;

bool dfs_permutation() {
    pq_entrada = pq;
    in_str = cur_str;
    in_def = defeated;
    for(int i = 1; i <= count_med; i++) in_reachable[med[i]] = reachable[med[i]];


    if(last_med != -1) {
        cur_str*=g[last_med];
        if(cur_str > MODN) return true;
        for (int enemy : adj[last_med]) {
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

        pq.pop();

        cur_str+=g[enemy.sc];
        if(cur_str > MODN) return true;

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

            last_med = med[i];

            if (dfs_permutation()) return true;
            vis[med[i]] = -1;
        }
    }

    for(int i = 1; i <= count_med; i++) reachable[med[i]] = in_reachable[med[i]];
    pq = pq_entrada;
    cur_str = in_str;
    defeated = in_def;

    return false;
}

signed main(){

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
