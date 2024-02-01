#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long

using namespace std;

vector<int> v, coord;
int n, soma = 0, cont = 0;

int buscabinaria(int x){
    int ini = 1, fim = n, mid;
    while(ini < fim){
        mid = ini + (fim - ini)/2;
        if(coord[mid] >= x) fim = mid;
        else ini = mid+1;
    }

    if(coord[ini] == x) return ini;
    return -1;
}

signed main(){_
    cin >> n;

    v = vector<int>(n+1);
    coord = vector<int>(n+1);
    
    for(int i=1; i<=n; i++){
        cin >> v[i];
        if(i!=1){
            coord[i] = coord[i-1] + v[i];
        } else {
            coord[i] = v[i];
        }
        soma += v[i];
    }

    if(soma%2 == 1){
        cout << "N" << endl;
        return 0;
    }

    int meioarco = soma/2;

    for(int i=1; i<=n; i++){
        if(coord[i] < meioarco) continue;

        if(buscabinaria(coord[i] - meioarco) != -1){
            cont++;
            if(cont==2) break;
        }
    }

    if(cont>1){
        cout << "S" << endl;
    } else {
        cout << "N" << endl;
    }

    return 0;
}