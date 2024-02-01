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

priority_queue<int, vector<int>, greater<int> > retirados_menor;
priority_queue<int> retirados_maior;
priority_queue<int, vector<int>, greater<int> > pqmenor;
priority_queue<int> pqmaior;
queue<int> fila;

int n, b, soma = 0, nota;
long long int total;

int main(){_

    while(cin >> n >> b){

        soma=0;
        total = 0;

        for (int i=0; i<b; i++){
            cin >> nota;
            pqmenor.push(nota);
            pqmaior.push(nota);
            fila.push(nota);
            soma+=nota;
        }

        total += soma - (pqmaior.top() + pqmenor.top());
        // cout << soma << ' ' << pqmenor.top() << ' ' << pqmaior.top() << endl;

        for (int i=b; i<n; i++){
            cin >> nota;
            fila.push(nota);
            pqmaior.push(nota);
            pqmenor.push(nota);
            soma+= nota;

            retirados_menor.push(fila.front());
            retirados_maior.push(fila.front());
            soma-= fila.front();
            fila.pop();

            while(!retirados_menor.empty() and pqmenor.top() == retirados_menor.top()){
                pqmenor.pop();
                retirados_menor.pop();
            }

            while(!retirados_maior.empty() and pqmaior.top() == retirados_maior.top()){
                pqmaior.pop();
                retirados_maior.pop();
            }

            // cout << '*' << soma << ' ' << pqmenor.top() << ' ' << pqmaior.top() << endl;
            total+= soma - (pqmenor.top() + pqmaior.top());

        }
        cout << total << endl;

        while(!pqmenor.empty()) pqmenor.pop();
        while(!pqmaior.empty()) pqmaior.pop();
        while(!retirados_menor.empty()) retirados_menor.pop();
        while(!retirados_maior.empty()) retirados_maior.pop();
        while(!fila.empty()) fila.pop();
    }

    return 0;
}