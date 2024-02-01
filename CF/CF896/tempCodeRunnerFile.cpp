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

int find(int x) {
    int resp = 1;

    while(resp <= x) {
        resp = (resp << 1);
    }

    return resp;
}

bool verifica(int y) {
    int ainda0 = 1;

    while(y > 0) {
        if ((y%2 == 1)) ainda0 = 0;
        else {
            if (ainda0 == 0) return false;
        }

        // cout << '*' << y << endl;
        y = y/2;
    }

    return 1;
}

signed main(){_

    // cout << verifica(8) << endl;
    // cout << verifica(7) << endl;
    // cout << verifica(6) << endl;
    // cout << verifica(4) << endl;
    // cout << 5 << ' ' << verifica(5) << endl;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vi v(n+1);

        int media = 0;
        for(int i = 1; i <=n; i++) {
            cin >> v[i];
            media+=v[i];
        }

        if (media%n) {
            cout << "No" << endl;
            continue;
        }

        media/=n;

        map<int, int> in;
        // map<int, int> out;

        int cont0 = 0;

        bool deuruim = 0;
        for(int i = 1; i <=n; i++) {
            int sobra = media - v[i];

            int x = find(abs(sobra));
            int y = x - abs(sobra);
            if (!verifica(y)) {
                deuruim = 1;
            }

            if (sobra < 0) {
                in[x - abs(sobra)]++;
                in[x]--;
            } else if (sobra > 0) {
                in[x - abs(sobra)]--;
                in[x]++;

            } else {
                cont0++;
            }
        }

        if(deuruim) {
            cout << "No" << endl;
            continue;
        }

        int flag = 1;
        for (ii p : in) {
            if (p.sc != 0) {
                flag = 0;
            }
        }

        if(flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        in.clear();
    }

    return 0;
}
