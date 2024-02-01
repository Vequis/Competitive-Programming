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
#define maxn 1123456

using namespace std;

struct carta{
    int naipe;
    int numero;
};

carta a[maxn];
int n;

int partition (int inicio, int fim) {
    int pivo = fim;
    int pmenor = inicio - 1;

    for(int i = inicio; i<fim; i++){
        if ( (a[i].naipe < a[pivo].naipe) || ((a[i].naipe == a[pivo].naipe) && (a[i].numero < a[pivo].numero)) ){
            pmenor++;
            swap(a[i], a[pmenor]);
        }
    }

    pmenor++;
    swap(a[pivo], a[pmenor]);

    for(int i = 1; i<=n; i++) cout << a[i].naipe << '-' << a[i].numero << ' ';
    cout << endl;

    return pmenor;
}

void quicksort(int inicio, int fim){
    if (inicio < fim){
        int pivo = partition(inicio, fim);
        quicksort(inicio, pivo - 1);
        quicksort(pivo + 1, fim);
    }
}

signed main(){_

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i].naipe >> a[i].numero;
    }

    quicksort(1, n);

    return 0;
}
