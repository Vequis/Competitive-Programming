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

char grid[10][12];

int verify_F_vertical(int a, int b) {
    for (int j = b; j<= b+3; j++) {
        bool flag = true;
        for (int i = a; i<=a+3; i++) {
            if (grid[i][j] == 'C') flag = false;
        }
        if (flag) return true;
    }

    return false;
}


int verify_C_vertical(int a, int b) {
    for (int j = b; j<= b+3; j++) {
        bool flag = true;
        for (int i = a; i<=a+3; i++) {
            if (grid[i][j] == 'F') flag = false;
        }
        if (flag) return true;
    }

    return false;
}

int verify_F_horizontal(int a, int b) {
    for (int i = a+3; i>= a; i--) {
        int flag = true;
        for (int j = b; j<=b+3; j++) {
            if (grid[i][j] == 'C') flag = false;
        }
        if (flag) return i;
    }

    return false;
}


int verify_C_horizontal(int a, int b) {
    for (int i = a+3; i>=a; i--) {
        int flag = true;
        for (int j = b; j<=b+3; j++) {
            if (grid[i][j] == 'F') flag = false;
        }
        if (flag) return i;
    }

    return false;
}

int verify_F_diagonal(int a, int b) {
    int flag1 = true;
    for (int i = 0; i <= 3; i++) {
        if (grid[a+i][b+i] == 'C') flag1 = false;
    }
    if (flag1) return 1;

    int flag = true;
    for (int i = 0; i <=3; i++) {
        if (grid[a+i][b+3-i] == 'C') flag = false;
    }
    if (flag) return -1;
    return 0;
}

int verify_C_diagonal(int a, int b) {
    int flag1 = true;
    for (int i = 0; i <= 3; i++) {
        if (grid[a+i][b+i] == 'F') flag1 = false;
    }
    if (flag1) return 1;

    int flag = true;
    for (int i = 0; i <=3; i++) {
        if (grid[a+i][b+3-i] == 'F') flag = false;
    }
    if (flag) return -1;
    return 0;
}

bool tem_C_acima(int j) {
    int flag = false;
    for (int k = 1; k<=3; k++) if (verify_C_vertical(k, j)) flag = true;
    return flag;
}

bool tem_F_acima(int j) {
    int flag = false;
    for (int k = 1; k<=3; k++) if (verify_F_vertical(k, j)) flag = true;
    return flag;
}

void solve() {
    for (int i = 1; i<=6; i++) {
        for (int j = 1; j<=7; j++) {
            cin >> grid[i][j];
        }
    }

    // for (int j = 1; j<=4; j++) {
    //     for (int i = 3; i>=1; i--) {
    //         if (verify_C_diagonal(i, j) or verify_C_horizontal(i, j) or verify_C_vertical(i, j)) {
    //             cout << 'C' << ' ' << i << ' ' << j << endl;
    //         }

    //         if (verify_F_diagonal(i, j) or verify_F_horizontal(i, j) or verify_F_vertical(i, j)) {
    //             cout << 'F' << ' ' << i << ' ' << j << endl;
    //         }

            
    //     }
    // }

    char geral_winner = '0';

    for (int j = 1; j<=4; j++) {
        char winner = '0';
        for (int i = 3; i>=1; i--) {
            // Verificar caso onde tem coluna em cima de linha

            if (verify_C_horizontal(i, j) and verify_F_horizontal(i, j)) {
                if (verify_C_horizontal(i, j) > verify_F_horizontal(i, j)) winner = (tem_F_acima(j) ? '?' : 'C');
                else winner = (tem_C_acima(j) ? '?' : 'F');
            }
            else if (verify_C_horizontal(i, j)) winner = (tem_F_acima(j) ? '?' : 'C');
            else if (verify_F_horizontal(i, j)) winner = (tem_C_acima(j) ? '?' : 'F');
            if (winner != '0') break;

            if (verify_F_diagonal(i, j) and verify_C_diagonal(i, j)) winner = '?';
            else if (verify_F_diagonal(i, j) and !verify_C_diagonal(i, j)) {
                winner = (tem_C_acima(j) ? '?' : 'F');
                if ((i == 3) and (verify_C_diagonal(1, j) != 0 and verify_C_diagonal(1, j) != verify_F_diagonal(i, j))) winner = '?';
           }
            else if (verify_C_diagonal(i, j) and !verify_F_diagonal(i, j)) {
                winner = (tem_F_acima(j) ? '?' : 'C');
                if ((i == 3) and (verify_F_diagonal(1, j) != 0 and verify_F_diagonal(1, j) != verify_C_diagonal(i, j))) winner = '?';
            }
            if (winner != '0') break;

            if (verify_C_vertical(i, j) and verify_F_vertical(i, j)) winner = '?';
            else if (verify_C_vertical(i, j)) winner = (tem_F_acima(j) ? '?' : 'C');
            else if (verify_F_vertical(i, j)) winner = (tem_C_acima(j) ? '?' : 'F');
            if (winner != '0') break;
        }

        if (winner != '0') {
            if (geral_winner == '0') geral_winner = winner;
            if ((geral_winner == 'C' and winner == 'F') or (geral_winner == 'F' and winner == 'C')) {
                cout << '?' << endl;
                return;
            } 

            if (winner == '?') {
                cout << '?' << endl;
                return;
            }

            // cout << j << ' ' << winner << endl;
        }

        
    }
    cout << geral_winner << endl;
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