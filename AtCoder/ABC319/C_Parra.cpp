#include <bits/stdc++.h>
#define int long long int
using namespace std;

int m[3][3];
int seen[3][3];

int cont = 0;

bool got_disappointed() {
    // line
    for (int i = 0; i < 3; i++) {
        if (
            (m[i][0] == m[i][1] && seen[i][0] > seen[i][2] && seen[i][1] > seen[i][2]) || 
            (m[i][0] == m[i][2] && seen[i][0] > seen[i][1] && seen[i][2] > seen[i][1]) || 
            (m[i][1] == m[i][2] && seen[i][1] > seen[i][0] && seen[i][2] > seen[i][0])
        )
            return true;
    }
    // column
    for (int i = 0; i < 3; i++) {
        if (
            (m[0][i] == m[1][i] && seen[0][i] > seen[2][i] && seen[1][i] > seen[2][i]) || 
            (m[0][i] == m[2][i] && seen[0][i] > seen[1][i] && seen[2][i] > seen[1][i]) || 
            (m[1][i] == m[2][i] && seen[1][i] > seen[0][i] && seen[2][i] > seen[0][i])
        )
            return true;
    }

    // diag1
    if (
        (m[0][0] == m[1][1] && seen[0][0] > seen[2][2] && seen[1][1] > seen[2][2]) || 
        (m[0][0] == m[2][2] && seen[0][0] > seen[1][1] && seen[2][2] > seen[1][1]) || 
        (m[1][1] == m[2][2] && seen[1][1] > seen[0][0] && seen[2][2] > seen[0][0])
    )
        return true;

    // diag2
    if (
        (m[0][2] == m[1][1] && seen[0][2] > seen[2][0] && seen[1][1] > seen[2][0]) || 
        (m[0][2] == m[2][0] && seen[0][2] > seen[1][1] && seen[2][0] > seen[1][1]) || 
        (m[1][1] == m[2][0] && seen[1][1] > seen[0][2] && seen[2][0] > seen[0][2])
    )
        return true;

    return false;
}

int dfs(int i, int j, int depth) {
    seen[i][j] = depth;
    int ans = 0;

    if (depth == 9) return got_disappointed();

    for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
            if (seen[k][l] == -1) {
                ans += dfs(k, l, depth + 1);
                seen[k][l] = -1;
            }
        }
    }


    // if (ans == 0) return got_disappointed();
    return ans;
}

void solve() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> m[i][j];
        }
    }

    int disappointments = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            seen[i][j] = -1;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            disappointments += dfs(i, j, 1);
            seen[i][j] = -1;
        }
    }


    // cout << disappointments << endl;
    cout << setprecision(12);
    cout << fixed;
    cout << 1 - (long double) disappointments / (long double) (9*8*7*6*5*4*3*2*1) << endl;
}

signed main() {
    solve();
}