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
#define int long long

using namespace std;


signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vii v;
        vii vs;

        int somat = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.eb(a, i);
            somat+=a;
        }
        vs = v;
        sort(all(vs), greater<ii>());

        int soma = 0;
        int resp[212345];
        soma = vs[0].fs;
        resp[vs[0].sc] = n*vs[0].fs - somat + n;


        for (int i = 1; i < n; i++) {
            resp[vs[i].sc] = resp[vs[0].sc] + n*(vs[i].fs - vs[0].fs) + 2*(soma - i*(vs[i].fs));
            soma+=vs[i].fs;
        }

        for (int i = 0; i < n; i++) cout << resp[i] << ' ';
        cout << endl;

    }

    return 0;
}
