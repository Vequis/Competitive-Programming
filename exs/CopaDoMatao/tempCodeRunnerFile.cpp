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

int l, r, d;
int n, q;
int x, y, z;
int a[22000];
int aux[22000];

signed main(){_

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int resp = 0; 

    while(q--) {
        cin >> x >> y >> z;

        l = 1 + (x + resp - 1)%n;
        r = 1 + (y + resp - 1)%n;
        d = (z + resp);

        for (int i = l; i<=r; i++) aux[i] = a[i];
        sort(aux + l + 1, aux + r + 1);

        int atual = 0;

        for (int i = l; i <=r; i++) {
            while (i < r && aux[i] == aux[i+1]) {
                atual+=aux[i];
                i++;
            }

            atual += aux[i];

            if (atual <= d) resp = atual;
            else break;
        }

        cout << resp << endl;
    }

    return 0;
}
