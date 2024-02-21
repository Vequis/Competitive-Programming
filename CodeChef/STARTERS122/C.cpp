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

int grid[512][512];
map<int, int> f;

int power(int a, int b) {
    int resp = 1;
    int pot = a;

    while (b > 0) {
        if (b % 2) resp = (resp*pot)%MODN;
        pot = (pot*pot)%MODN;
        b/=2;
    }

    return resp;
}

int modinv(int n) {
    return power(n, MODN-2);
}

int mult(int a, int b) {return (a*b)%MODN;}

vi fat(512);

int cont(int n, int mn, int a) {
    a = a%mn;
    int resp = (n*n)/mn;
    if (a <= (n*n)%mn and a!=0) resp++;
    return resp;
}

void solve() {


    f.clear();
    int n;
    cin >> n;

    for(int i = 1; i <=n; i++) {
        for(int j = 1; j<=n; j++) {
            cin >> grid[i][j];
        }
    }

    int mn = n/2;
    if (n == 1) {
        if (grid[1][1] == 1) cout << 0 << endl;
        else cout << 1 << endl;
    // } else if (n==2) {
    //     if ((grid[1][2]%3 != 1 and grid[1][2] != 0) or (grid[2][1]%3 != 1 and grid[2][1] != 0) or grid[1][1]%3 == 1 or grid[1][1]%3 == 1) {
    //         cout << 0 << endl;
    //     } else {
    //         int a = (grid[1][1] == 0) + (grid[2][2] == 0);
    //         int b = (grid[1][2] == 0) + (grid[2][1] == 0);
    //         cout << a*b << endl;    
    //     }
    } else {
        int mn = n/2;

        for(int i = 1; i <=n*n-1; i++) {
            int r = (n*n)%i;
            int contimpar = 0;
            for(int j = 1; j<= i - 1; j++) {
                int cur = (n*n)/i;
                if (j <= r) cur++;

                if (cur%2 == 1) contimpar++;
            }
            if ((n/i)%2 == 1) contimpar++;

            // cout << i << ' ' << contimpar << endl;
            if (contimpar <= n) mn = i;
        }

        // cout << mn << endl;

        int contpares = 0;
        for(int i = 1; i <=n; i++) {
            for(int j = i + 1; j<=n; j++) {
                int a = grid[i][j]%mn;
                int b = grid[j][i]%mn;

                if ((a!=b and (grid[i][j]!=0 and grid[j][i]!=0))) {
                    cout << 0 << endl;
                    return;
                }

                if (grid[i][j] == 0 and grid[j][i] == 0) contpares++;

                if (grid[i][j] == 0 and grid[j][i] != 0) {
                    f[b]+=2;
                    grid[i][j] = grid[j][i];
                } else if (grid[i][j] != 0 and grid[j][i] == 0) {
                    f[a]+=2;
                    grid[j][i] = grid[i][j];
                } else if (grid[i][j] != 0 and grid[j][i] != 0) {
                    f[a]+=2;
                }

                if (f[a] > cont(n, mn, a) or f[b] > cont(n, mn, b)) {
                    cout << 0 << endl;
                    return;
                }
            }
        }

        int livrediag = 0;
        for(int i = 1; i <=n; i++) livrediag += (grid[i][i] == 0);
        for(int i = 1; i <=n; i++) {
            if (grid[i][i] != 0) f[grid[i][i]]++;
            if (grid[i][i] != 0 and f[grid[i][i]] > cont(n, mn, grid[i][i])) {
                cout << 0 << endl;
                return;
            }
        }

        int sobrapares = 0;
        for(int i = 0; i < mn; i++) {
            sobrapares += (cont(n, mn, i) - f[i])/2;
            // cout << i << ' ' << (cont(n, mn, i)) << ' ' << (f[i]) << endl;
        }

        // cout << sobrapares << ' ' << contpares << ' ' << livrediag << endl;

        int resp = mult(fat[sobrapares],modinv(fat[sobrapares - contpares]));
        resp = mult(resp, power(2, contpares));
        resp = mult(resp, fat[livrediag]);

        cout << resp << endl;
    }
}

signed main(){_
    int t;
    cin >> t;

    fat[0] = 1;

    for(int i = 1; i <=500; i++) {
        fat[i] = (fat[i-1]*i)%MODN;
        // fatinv[i] = modinv(fat[i]);
    }

    while(t--) {
        solve();
    }

    return 0;
}
