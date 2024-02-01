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
int grid[111][112];

signed main(){_

    int n;
    cin >> n;


    for(int i = 1; i <=n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for(int J = a; J<b;J++) {
            for(int k = c; k<d; k++) {
                grid[J][k] = 1;
            }
        }

    }

    int resp = 0;

    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j<=100; j++) {
            resp+=(grid[i][j] == 1);
        }
    }

    cout << resp << endl;

    return 0;
}
