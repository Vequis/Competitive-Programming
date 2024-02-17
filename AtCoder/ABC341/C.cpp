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

char grid[512][512];

string t;
int n;

int valido(int a, int b, int i) {

    if (grid[a][b] == '#') return 0;

    if (i == n - 1) return 1;
    
    if (t[i+1] == 'L') return valido(a, b-1, i+1);
    if (t[i+1] == 'R') return valido(a, b+1, i+1);
    if (t[i+1] == 'U') return valido(a-1, b, i+1);
    if (t[i+1] == 'D') return valido(a+1, b, i+1);
}

void solve() {

    int h, w;
    cin >> h >> w;
    cin >> n;

    cin >> t;

    for(int i = 1; i <=h; i++) {
        string s;
        cin >> s;

        for(int j = 1; j<=w; j++) {
            grid[i][j] = s[j-1];
        }
    }

    ii atual;
    int resp = 0;
    for(int i = 2; i < h; i++) {
        for(int j = 2; j< w; j++) {
            if (valido(i, j, -1)) {
                // cout << i << ' ' << j << endl;
                resp++;
            }
        }
    }

    cout << resp << endl;


}

signed main(){_
    solve();

    return 0;
}
