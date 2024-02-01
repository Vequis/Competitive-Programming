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

int fat(int n){
    if(n<=1){
        return 1;
    }
    return fat(n-1) * n;
}

double v[1123];

double potencia(double a, int b){
    double resultado = 1;
    double potatual = a;

    while(b>0){
        if(b%2 == 1){
            resultado*=potatual;
        }

        b/=2;
        potatual *= potatual;
    }

    return resultado;
}

double calculaTaylor(int n, double x0, double x){
    if(n<0) return 0;

    double atual = (v[n]*potencia(x-x0, n))/((double)fat(n));
    return atual + calculaTaylor(n-1, x0, x);
}

signed main(){

    double n, x0, x;

    cout << "Forneca a ordem do polinomio desejado" << endl;

    cin >> n;

    cout << "Forneca o ponto de referencia" << endl;
    
    cin >> x0;

    cout << "Forneca o ponto desejado" << endl;
    
    cin >> x;

    for(int i=0; i<=n; i++){
        cout << "Forneca o valor de f na " << i << "-esima derivada" << endl;
        cin >> v[i];
    }

    cout << calculaTaylor(n, x0, x) << endl;

    

    return 0;
}
