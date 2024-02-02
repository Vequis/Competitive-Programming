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

vii v;
int n;

int main(){_
    //Ler n pares a,b e ordenar por ordem crescente de a, usando b como desempate, ordem crescente de b
    cin >> n;
    v = vii(n);

    for (int i=0; i<n; i++){
        cin >> v[i].fs >> v[i].sc;
    }

    sort(all(v)); // C++ Ja ordena naturalmente o pair 

    for (int i=0; i<n; i++){
        cout << v[i].fs << " " << v[i].sc << endl;
    }

    cout << endl;

    v.clear();
    return 0;
}