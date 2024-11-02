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

string s;
char grid[1111][1111];

void shift(char new_char) {
    s.erase(0, 1);
    s = s + new_char;
}

int verify(char c) {
    if (sz(s) < 4) s = s + c;
    else shift(c);
    return s == "1543";
}

ii next_pos(ii cur_pos, int a, int b, int c, int d) {
    ii resp = cur_pos;

    if (resp.fs == a and resp.sc < d) resp.sc+=1;
    else if (resp.sc == d and resp.fs < c) resp.fs+=1;
    else if (resp.fs == c and resp.sc > b) resp.sc-=1;
    else if (resp.sc == b and resp.fs > a) resp.fs-=1;

    return resp;
}

int verify(int a, int b, int c, int d) { //Coordenadas das quinas
    ii ptr = {a, b};
    int resp = 0;
    s = "";

    for (int i = 1; i <= 2*(c - a + d - b ) + 3; i++) {
        // cout << ptr.fs << ' ' << ptr.sc << endl;
        resp += verify(grid[ptr.fs][ptr.sc]);
        ptr = next_pos(ptr, a, b, c, d);
    }

    return resp;
}   

void solve() {
    // string s = "1543";
    // s.pop_back();
    // s = '1' + s;
    // cout << s << endl;   

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <=n; i++) {
        for (int j = 1; j<=m; j++) {
            cin >> grid[i][j];
        }
    }

    int resp =0 ;
    for (int i = 1; i <=(min(n,m) / 2); i++) {
        resp += verify(i, i, n+1 - i, m+1 - i);
    }

    cout << resp << endl;


}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}