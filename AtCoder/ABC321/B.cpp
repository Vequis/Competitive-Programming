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

signed main(){_

    int n;
    cin >> n;

    int x;
    cin >> x;

    int soma = 0;
    int menor = INF;
    int maior = -1;

    for(int i = 0; i < n-1; i++) {
        int a; 
        cin >> a;

        soma+=a;

        menor = min(menor, a);
        maior = max(maior, a);
    }

    soma-= (maior + menor);

    int sobra = max(0LL, x - soma);

    if (sobra > maior) {
        cout << -1 << endl;
    } else if (menor >= sobra) {
        cout << 0 << endl;
    } else {
        cout << sobra << endl;
    }

    return 0;
}
