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
#define INF (1ll << 60)
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

//Fixando o maior i tal que a[i] vai ser usado
//posso fazer uma pq que vai adicionando?
// Como ver eficientemente qual é a soma dos n menores?

void solve() {
    int n, k;
    cin >> n >> k;

    vi a(n);
    vi b(n);
    vii ap(n);
    vii bp(n);
    vi descartado(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ap[i] = {a[i], i};
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        bp[i] = {b[i], i};
    }

    sort(all(ap));
    sort(all(bp));

    map<int, int> t;
    for (int i = 0; i < n; i++) {
        t[bp[i].sc] = i;
    }

    int usados = k-1;

    int soma = 0;
    for (int i =0; i <k; i++) soma += bp[i].fs;

    int resp = INF;
    for (int i = n-1; i>=k-1; i--) {
        int cur = ap[i].fs * (soma);
        if (cur < resp) resp = cur;

        descartado[t[ap[i].sc]] = 1;
        if (t[ap[i].sc] <= usados) {
            soma -= bp[t[ap[i].sc]].fs;
            usados++;
            while(descartado[usados] == 1) usados++;
            soma+=bp[usados].fs;
        }
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