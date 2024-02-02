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
int med[513];
priority_queue<ii, vii, greater<ii>> pq; //Monstro mais fraco
priority_queue<ii, vii, greater<ii>> pq_entrada; //Monstro mais fraco
int s[513];
int g[513];
vi adj[513];

int vis[513];
int reachable[513];
int in_reachable[513];

int t[513];

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

        // retirados.push(enemy);
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

    pq.push({3,1});
    pq.push({2,1});
    pq.push({3,1});

    pq_entrada.push({5,1});
    pq_entrada.push({6,1});
    pq_entrada.push({7,1});

    pq = pq_entrada;

    cout <<pq.top().fs << endl;
    pq.push({1, 2});
    cout <<pq.top().fs << endl;

    return 0;
}
