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

map<int, int> f;

int valid(int n) {
    int v[12];

    for(int i = 0; i <= 9; i++) v[i] = 0;

    while(n > 0) {
        int digit = n%10;
        n/=10;
        v[digit]++;
        // if (v[digit] > f[digit]) return false;
    }

    for(int i = 1; i <= 9; i++) if (v[i] != f[i]) return false;

    return true;
}

int binexpo(int a, int pot) {
    int resp = 1;
    int pote = a;

    while(pot >= 1) {
        if (pot & 1) resp= (resp*pote);
        pot = pot>>1;
        // cout << '*' <<  pot << ' ' << resp << ' ' <<pote << endl;
        pote = (pote*pote);
    }

    return resp;
}

signed main(){_

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        f[(int)(c - '0')]++;
    }


    // cout << valid(1) << endl;
    // cout << valid(100) << endl;

    int resp = 0;
    for(int i = 0; i*i <= binexpo(10, n) -1; i++) {
        if (valid(i*i)) resp++;
        // if (valid(i*i)) cout << i*i << endl;
    }

    cout << resp << endl;

    return 0;
}
