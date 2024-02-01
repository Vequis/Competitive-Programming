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

stack<int> pilha;
vi nsmr, nsml; //proximo menor direita(r) e proximo menor esquerda(l)
vector<ll> altura;
ll n, larg; 
long long int atual, maior;

int main(){_

    while((cin >> n) && (n)){
        altura = vector<ll>(n);

        for (int i=0; i<n; i++){
            cin >> altura[i];
        }

        nsmr = vi(n, n); //Definindo todos os valores como n e -1 para que, aquelas posições que não tenham barras menores que elas mesmas, apontem para os extremos (n e -1)
        nsml = vi(n, -1);

        for (int i=0; i<n; i++){
            while( !pilha.empty() and altura[pilha.top()] > altura[i]){
                nsmr[pilha.top()] = i;
                pilha.pop();
            }

            pilha.push(i);
        }

        while(!pilha.empty()) pilha.pop();

        for (int i=n-1; i>=0; i--){
            while( !pilha.empty() and altura[pilha.top()] > altura[i]){
                nsml[pilha.top()] = i;
                pilha.pop();
            }

            pilha.push(i);
        }

        while(!pilha.empty()) pilha.pop();

        maior = 0;
        for (int i=0; i<n; i++){
            larg = nsmr[i] - nsml[i] - 1; // Larg denota a quantidade de barras com altura maior ou igual que a barra atual;

            atual = larg*altura[i]; //Area atual;

            maior = max(maior, atual);
        }

        cout << maior << endl;

        altura.clear();
    }

    return 0;
}