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
vi a, b;

int bb(int x) {
    int ini = 0;
    int fim = sz(b);

    while(ini < fim) {
        int mid = ini + (fim - ini)/2;

        if (b[mid] > x) fim = mid;
        else ini = mid + 1;
    }

    return ini;
}

signed main(){_

    int n, m, p;
    cin >> n >> m >> p;


    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.pb(num);
    }

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        b.pb(num);
    }

    sort(all(a));
    sort(all(b));

    int resp = 0;
    // cout << bb(-1) << endl;

    int psa[212345];
    psa[0] = 0;

    for(int i = 1; i <=m; i++) {
        psa[i] = psa[i-1] + b[i-1];
    }

    for(int i = 0; i < n; i++) {
        int cont = bb(p - a[i]);

        resp += cont*a[i] + psa[cont]+ (m-cont)*p;
    }

    cout << resp << endl;

    return 0;
}
