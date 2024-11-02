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

int dono[1123][1123];


int r, c;
int k;

bool valido(int a, int b) {
    if (a >= 1 and a <= r and b>=1 and b<=c) return true;
    return false;
}

int acabar(int a, int b, int dist) {

    for (int i = a; i <= a + dist; i++) {
        if (valido(i, b+dist)) {
            if (dono[i][b+dist] != dono[a][b]) {
                k-=2;
                if (k<=0) {
                    return true;
                }
            }
        }

    }

    for (int j = b+dist - 1; j>=b-dist; j--) {
        if (valido(a+dist, j)) {
            if (dono[a+dist][j] != dono[a][b]) {
                k-=2;
                if (k<=0) {
                    return true;
                }
            }
        }
    }

    for (int i = a+dist-1; i>=a+1; i--) {
        if (valido(i, b-dist)) {
            if (dono[i][b-dist] != dono[a][b]) {
                k-=2;
                if (k<=0) {
                    return true;
                }
            }
        }
    } 

    return false;
}

void solve() {
    cin >> r >> c;
    cin >> k;

    for (int i = 1; i <=r; i++) {
        for (int j = 1; j<=c; j++) {
            cin >> dono[i][j];
        }
    }

    int dist = 1;
    while(true) {
        for (int i = 1; i <=r; i++) {
            for (int j = 1; j<=c; j++) {
                if(acabar(i, j, dist)) {
                    cout << dist << endl;
                    return;
                }
            }
        }
        dist++;

        // cout << dist << endl;
    }
}

signed main(){_
    int t;
    cin >> t;
    // t=1;


    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}