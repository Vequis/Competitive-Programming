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


    int vis[111][111];
    int resp = 0;

    int h, w;

    char grid[111][111];

    void dfs(int a, int b, int k) {
        if (a <= 0 or b<= 0 or a>h or b > w) return;
        if (grid[a][b] == '#') return;
        if (vis[a][b]) return;

        if (k==0) {
            resp++;
            return;
        }

        vis[a][b] = 1;

        dfs(a+1, b, k-1);
        dfs(a-1, b, k-1);
        dfs(a, b+1, k-1);
        dfs(a, b-1, k-1);

        vis[a][b] = 0;

    }


    void solve() {
        int k;
        cin >> h >> w >> k;

        for (int i = 1; i <=h; i++) {
            for (int j = 1; j <=w; j++) {
                cin >> grid[i][j];
            }
        }

        for (int i = 1; i <=h; i++) {
            for (int j = 1; j<=w; j++) {
                dfs(i, j, k);
            }
        }

        cout << resp << endl;
    }

    signed main(){_
        int t;
        // cin >> t;
        t=1;

        while(t--) {
            solve();
        }

        return 0;
    }