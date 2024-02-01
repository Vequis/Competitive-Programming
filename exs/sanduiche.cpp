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

using namespace std;

vi V;
int n, d;

int main(){_

    cin >> n >> d;
    V = vi(n);

    int somaT = 0;

    for (int i=0; i<n ; i++){
        cin >> V[i];
        somaT+= V[i];
    }

    int ini = 0, fim = 0;

    int soma = V[0];
    int cont = 0;

    while(ini<n){
        if( soma == d){
            cont++;
            if (ini == fim){
                ini++;
                fim++;
                soma = V[ini];
            } else {
                soma-=V[ini];
                ini++;
            }

        } else if (soma > d){
            if (ini == fim){
                ini++;
                fim++;
                soma = V[ini];
            } else {
                soma-=V[ini];
                ini++;
            }
        } else if (soma < d){
            if (fim==n-1) break;
            fim++;
            soma+=V[fim];
        }
    }

    if (soma==d) cont++;

    soma = V[1];

    int inv = somaT-d;

    if (inv==0){

        cont+=n-1;

    } else {

        ini = 1; fim = 1;

        while(ini<n-1 ){
            if( soma == inv){
                cont++;
                if (ini == fim){
                    ini++;
                    fim++;
                    soma = V[ini];
                } else {
                    soma-=V[ini];
                    ini++;
                }

            } else if (soma > inv){
                if (ini == fim){
                    ini++;
                    fim++;
                    soma = V[ini];
                } else {
                    soma-=V[ini];
                    ini++;
                }
            } else if (soma < inv){
                if (fim == n-2) break;
                fim++;
                soma+=V[fim];
            } 
        }
    }

    if (soma == d) cont++;

    cout << cont << endl;

    return 0;
}