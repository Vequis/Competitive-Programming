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

using namespace std;
// Ler n pares de a e b;

pair<int,int> par;
vector<pair<int, int> > v;

int n, a ,b;


int main(){_

    cin >> n;

    for (int &[a,b] : v){
        cin >> a >> b;
    }

    for (auto [a,b] : v){ // Auto detecta automaticamente o tipo
        cout << a << " " << b << endl;
    }
    cout << endl;

    return 0;
}