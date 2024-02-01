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

void tt(int tes) {
    cout<<"Case #"<<tes<<": ";
}

int n;
set<string> words;
set<string> nodes[1123456];
vi adj[1123456];
int p[1123456];
int cntleafs[1123456];
int grau[1123456];

int invalido;

void dfs_cntleafs(int node) {
    cntleafs[node] = 0;
    for( int v : adj[node] ){
        if (cntleafs[v] == -1) {
            dfs_cntleafs(v);
        }
        cntleafs[node] += cntleafs[v]; 
    }
}

int dfs_word(int node, string s) {
    if (invalido) return -1;
    int resp = 0;
    for( int v : adj[node] ){
        resp += dfs_word(v, s);
    }

    if (nodes[node].find(s) != nodes[node].end()) resp++;

    // cout << s << ' ' << node << ' ' <<resp << ' ' << cntleafs[node] << endl;

    if (cntleafs[node] > 1 and resp < cntleafs[node]) invalido = 1;

    return resp;
}

void solve() {
    cin >> n;

    vi leafs;

    for(int i = 1; i <=n; i++) grau[i] = 0;

    for(int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adj[a].pb(i);
        p[i] = a;
        grau[a]++;
    }

    for(int i = 1; i <=n; i++) {
        int m;
        cin >> m;

        while(m--) {
            string s;
            cin >> s;
            nodes[i].insert(s);
            words.insert(s);
        }
    }

    for(int i = 1; i <=n; i++) cntleafs[i] = -1;

    for(int i = 1; i <=n; i++) {
        if(grau[i] == 0) {
            leafs.eb(i);
            cntleafs[i] = 1;
        }
    }

    dfs_cntleafs(1);

    for(int i = 1; i <=n; i++) {
        if (grau[i] == 1) {
            int v = adj[i][0];
            for(string s : nodes[i]) {
                nodes[v].insert(s);
            }


            for(int j = 0; j < sz(adj[p[i]]); j++) {
                if (adj[p[i]][j] == i) {
                    adj[p[i]][j] = v;
                    break;
                }
            }
        }
    }

    int resp = 0;
    for(string s : words) {
        invalido = 0;
        dfs_word(1, s);

        if (!invalido) {
            // cout << s << endl;
            resp++;
        }
    }

    cout << resp << endl;

    for(int i = 1; i <=n; i++) adj[i].clear();
    for(int i = 1; i <=n; i++) nodes[i].clear();
    words.clear();
}

signed main(){_

    freopen("wiki_race_validation_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        tt(i);
        solve();
    }

    return 0;
}
