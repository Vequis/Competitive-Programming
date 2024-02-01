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

priority_queue<int, vi, greater<int> > atual;
priority_queue<int, vi, greater<int> > retiradas;
queue<int> fila;
int n, k, nota;

int main(){_

    while(cin >> n >> k && (n||k)){
        for (int i=1; i<=k; i++){
            cin >> nota;
            atual.push(nota);
            fila.push(nota);
        }

        cout << atual.top();

        for (int i=k+1; i<=n; i++){
            cin >> nota;
            atual.push(nota);
            fila.push(nota);
            
            retiradas.push(fila.front());
            fila.pop();

            while (!retiradas.empty() and retiradas.top() == atual.top()){
                atual.pop();
                retiradas.pop();
            }

            cout << " " << atual.top();
        }

        while(!fila.empty()) fila.pop();
        while(!retiradas.empty()) retiradas.pop();
        while(!atual.empty()) atual.pop();

        cout << endl;
    }

    return 0;
}