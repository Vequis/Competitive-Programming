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

int s(int n ) {
    return 2*n*n - 1;
}

int cont = 0;

signed main(){_

    for (int i = 2; i < 200; i++) {
        int atual = s(i);
        cout << i << ' ' << atual << ' ';

        bool ehPrimo = true;

        for(int i = 2; i <= sqrt(atual); i++) {
            while (atual%i == 0 && atual != 1) {
                ehPrimo = false;
                atual/=i;
                cout << i << ' ';
            }
        }

        if (ehPrimo) {
            cout << "--------------------------------------------------------";
            cont++;
        } else if (atual != 1) {
            cout << atual << ' ';
        }

        cout << endl;
    }

    cout << cont << endl;
    return 0;
}
