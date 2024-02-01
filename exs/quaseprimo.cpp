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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

vi primos;
// vi visitados(1000000007);
int n,k,aux;
ll cont;

// void crivo(){
//     for (int i=0; i<k; i++){
//         for(int j= (primos[i]*primos[i]) ; j<=n; j+=i){
//             if(visitados[j] == 0) cont++;
//             visitados[j] = 1;
//         }
//     }
// }

int main(){_

    cin >> n >> k;

    for (int i=0; i<k; i++) {
        cin >> aux;
        primos.pb(aux);
    }

    for(int i=1; i<=n; i++){
        bool ok = true;
        for (int j=0; j<k; j++){
            ok = (ok && (i%primos[j]));
            if(!ok) break;
        }
        if (ok) cont++;
    }

    cout << cont << endl;

    return 0;
}