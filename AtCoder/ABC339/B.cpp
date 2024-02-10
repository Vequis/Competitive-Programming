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

ii dir[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int grid[123][123];

signed main(){_

    int d = 0;
    int h, w;
    int n;
    cin >> h >> w >> n;

    int i = 0, j= 0;

    while(n--) {
        if (grid[i][j]) {
            grid[i][j] = 0;
            d = (4 + d - 1)%4;
            i = (h + i + dir[d].fs)%h;
            j = (w + j + dir[d].sc)%w;

        } else {
            grid[i][j] = 1;
            d = (4 + d + 1)%4;
            i = (h + i + dir[d].fs)%h;
            j = (w + j + dir[d].sc)%w;
        }
    }

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if (grid[i][j]) cout << '#';
            else cout << ".";
        }
        cout << endl;
    }

    return 0;
}
