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

int a, b, c, n, cont, atual, total;
int visitados[1000010];
vi primos;

void crivo(int n){
    for (int i=2; i<=n; i++){
        if (!visitados[i]){
            primos.eb(i);
            if (i <= sqrt(INT_MAX)) for (int j=i*i; j<=n; j+=i) visitados[j] = 1;
        }
    }    
}

int numdivs(int n){

    total = 1;

    for (int i=0; i<primos.size(); i++){
        atual = 0;
        if (n%primos[i] == 0){
            while (n%primos[i] == 0){
                atual++;
                n = n/primos[i];
            }

            total = total * (atual + 1);
        }
    }

    return total;
}

int main(){_

    cin >> n;

    crivo(n);

    for (int i=1; i<=n-1; i++){
        cont+=numdivs(n-i);
    }

    cout << cont << endl;

    return 0;
}   