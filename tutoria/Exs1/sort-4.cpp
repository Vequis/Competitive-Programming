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

struct pais{
    int o,p,br,id;
};

int ordem (pais a, pais b){
    if (a.o != b.o) return a.o>b.o;
    else if (a.p!=b.p) return a.p>b.p;
    else if (a.br!=b.br) return a.br > b.br;
    return 0;
}

vector <pais> paises;

int n,m;


int main(){_

    cin >> n >> m;
    
    paises = vector<pais>(n+1);

    for (int i=1; i<=n; i++) paises[i].id = i;

    for (int i=0; i<m; i++){
        int ouro, prata, bronze;
        cin >> ouro >> prata >> bronze;

        paises[ouro].o++;
        paises[prata].p++;
        paises[bronze].br++;
    }

    stable_sort(1+all(paises), ordem);

    for (int i=1; i<=n ; i++){
        cout << paises[i].id << " ";
    }
    cout << endl;

    return 0;
}