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

char grid[2123][2123];

int lines[2123];
int col[2123];

signed main(){_

    int n;
    cin >> n;

    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=n; j++) {
            char c;
            cin >> c;

            grid[i][j] = c;

            if (c=='o') {
                lines[i]++;
                col[j]++;
            }
        }
    }

    int resp = 0;

    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=n; j++) {
            if (grid[i][j]=='o') {
                resp += (lines[i] - 1)*(col[j] - 1);
            }
        }
    }

    cout << resp << endl;

    return 0;
}
