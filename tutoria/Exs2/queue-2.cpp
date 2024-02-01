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

queue<int> inversao;
queue<int> fila;
vector<int> v;

int a, b;

int inverte(int n){
    while(n!=0){
        inversao.push(n%10);
        n/=10;
    }

    while(!inversao.empty())  {
        n*=10;
        n+=inversao.front();
        inversao.pop();
    }

    return n;
}

int t;

int main(){_
    cin >> t;

    for (int i=0; i<t; i++){
        v = vi(100100);

        cin >> a >> b;

        fila.push(a);

        v[a] = 1;

        while(1){
            int f = fila.front();
            fila.pop();
            int invf = inverte(f);

            if (f == b) break;

            if (v[invf] == 0 and invf<=10000 and invf > 0) {
                v[invf] = v[f]+1;
                fila.push(invf);
            }

            if (v[f+1] == 0 and f+1<=10000 and f+1 >= 0) {
                v[f+1] = v[f] + 1;
                fila.push(f+1);
            }

        }

        v[b]--;

        cout << v[b] << endl;

        while(!fila.empty()) fila.pop();

        v.clear();
    }

    return 0;
}