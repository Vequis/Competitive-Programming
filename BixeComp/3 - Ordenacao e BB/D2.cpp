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

ll v[3][1123456]; //tem subida? menor; maior;
ll n, l;
ll ant, num, menor, maior;
ll cont=0, conta=0, resp=0;
ll meno[1123456];

int bb(int x){ // Verifica quantos numeros são menores que x;
    int ini = 0, fim = conta, mid;
    while(ini < fim){
        mid = ini + (fim-ini)/2;
        if (meno[mid] >= x) fim = mid;
        else ini = mid+1;
    }
    return ini;
}

int main(){_

    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> l;

        cin >> ant;
        menor = ant;
        maior = ant;

        for (int j=0; j<(l-1); j++){
            cin >> num;

            if (ant < num) {
                v[0][i] = 1;
                cont++;
            }
            
            menor = min(menor, num);
            maior = max(maior, num);
            ant = num;
        }

        v[2][i] = maior;
        if(!v[0][i]) {
            meno[conta] = menor;
            conta++;
        }
    }

    sort(meno, meno+conta);

    resp = (2*n - cont);
    resp*=cont;
    
    for (int i=1; i<=n; i++){
        if (!v[0][i]){
            resp+=bb(v[2][i]);
        } 
    }

    cout << resp << endl;

    return 0;
}