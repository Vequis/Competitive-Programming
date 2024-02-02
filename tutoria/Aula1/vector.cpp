#include<bits/stdc++.h>
#include<vector>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()

using namespace std;

vi v;
int n, x;

int main(){_

    cin >> n;

    //Definindo um tamanho especifico:
    v = vi(n, -1); //Da para determinar um valor padrão para todos
    for (int i=0; i<n; i++){
        // cin >> v[i]; Se ja tivermos o tamanho do vetor, podemos fazer dessa forma 
        cin >> x;
        // v.push_back(x);
        v.eb(x);
    }

    //Mostrando o for iterado
    for (int &x : v){ //Aqui o x pega o valor, entao não da pra alterar
        // Adicionando o &, vira referencia, e portanto podemos alterar
        cin >> x;

    }

    sort(all(x));

    cout << " " << v.size() << endl; //Não retorna um número inteiro (tipo: sizeT)
    cout << " " << sz(v) << endl;

    for (int i=0; i<n; i++){
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;

}