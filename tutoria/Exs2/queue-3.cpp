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

queue<int> fila;
vector<int> proibidos;
int o, d, k, n, atual;
vi v(100100, -1);

void processo(int m){
    if (m<=100000 and m>=1 and v[m]==-1){
        v[m] = v[n]+1;
        fila.push(m);
    }
}

int main(){_

    while (cin >> o >> d >> k){
        v = vi(100100, -1);

        bool ok = false;

        if (o ==0 and d==0 and k==0){
            break;
        }

        for (int i=0; i<k; i++){
            int num;
            cin >> num;
            v[num] = -2;
        }

        v[o] = 0;

        fila.push(o);

        while(!fila.empty()){
            n = fila.front();
            fila.pop();

            if (n==d) {
                ok = true;
                break;
            }

            atual = n*2;
            processo(atual);

            atual = n*3;
            processo(atual);

            if (n%2==0){
                atual = n/2;
                processo(atual);
            }

            atual = n-1;
            processo(atual);
           
            atual = n+1;
            processo(atual);
        }

        if (ok){
            cout << v[d] << endl;
        } else {
            cout << -1 << endl;
        }

        v.clear();
        while(!fila.empty()) fila.pop();

    }

    return 0;
}