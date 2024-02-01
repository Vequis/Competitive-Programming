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
// #define int long long -> solução divina?

using namespace std;

int v[3][1123456]; //é crescente? menor; maior;
int n, l, ant, num, menor, maior, cont;
ll resp;
vi maio, meno;

int bbmaior(int x){
    int ini = 0, fim = sz(maio) , mid;
    while(ini < fim){
        mid = ini + (fim-ini)/2;
        // cout << x << ini << ' ' << fim << ' ' << mid << endl;
        if (maio[mid] > x) fim = mid;
        else ini = mid+1;
    }
    return ini;
}

int bbmenor(int x){
    int ini = 0, fim = sz(meno), mid;
    while(ini < fim){
        mid = ini + (fim-ini)/2;
        if (maio[mid] >= x) fim = mid;
        else ini = mid+1;
    }
    return ini;
}

int main(){_

    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> l;

        cin >> ant;
        menor = maior = ant;

        for (int j=0; j<(l-1); j++){
            cin >> num;
            menor = min(menor, num);
            maior = max(maior, num);

            
            if (ant < num) {
                v[0][i] = 1;
            }
            ant = num;
        }
        v[1][i] = menor;
        v[2][i] = maior;
        // cout << menor << ' ' << maior << endl;
    }

    for (int i=1; i<=n; i++){
        // cout << i << ' ' << v[1][i] << ' ' << v[2][i] <<  endl;

        if (!v[0][i]){
            resp+=2*cont;
            // cout << i << ' ' << bbmaior(v[1][i]) << ' ' << bbmenor(v[2][i]) << endl;
            resp+=sz(maio) - bbmaior(v[1][i]);
            resp+=bbmenor(v[2][i]);
            maio.pb(v[2][i]);
            meno.pb(v[1][i]);
            sort(all(maio));
            sort(all(meno));

            if (v[1][i] < v[2][i]) {
                resp++;
            }
        } else {
            cont++;
            resp+=2*(i-1) + 1;
        }

        // cout << resp << endl;
    }

    cout << resp << endl;

    return 0;
}