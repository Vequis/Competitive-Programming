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

int movesup[212345];
int movesdown[212345];
int psaup[212345];
int psadown[212345];

int grid[2][212345];

int INFLL = INF;

void solve() {
    
    int n;
    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;

        grid[0][i] = (c == '1');
    }

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;

        grid[1][i] = (c == '1');
    }

    int counter = 0;
    for (int i = 1; i <=n; i++) {
        if (grid[0][i]) {
            counter++;
            movesup[counter] = i - counter;
            psaup[counter] = psaup[counter-1] + movesup[counter];
        }
        
        // cout << grid[0][i] << ' ' << i << ' ' << counter << ' ' << movesup[counter] << endl;
    }
    int counterup = counter;
    
    counter = 0;
    for (int i = n; i >= 1; i--) {
        if (grid[1][i]) {
            counter++;
            movesdown[counter] = (n + 1 - counter) - i;
            psadown[counter] = psadown[counter-1] + movesdown[counter];
        }
    }

    if (counter + counterup < n+1 or counterup == 0 or counter == 0) {
        cout << -1 << endl;
        return;
    }

    int resp = INFLL;
    for (int i = 1; i <=n; i++) {
        int j = n+1 - i;

        if (j > counter or i > counterup) continue;

        resp = min(resp, psaup[i] + psadown[j]);
    }

    cout << resp << endl;    
}

signed main(){_
    int t;
    cin >> t;
    INFLL *= INF;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}