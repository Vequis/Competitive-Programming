#include<bits/stdc++.h>

using namespace std;

bool vis[1000000100];
vector<int> passado;
int n, t, validos;

int indice(int x){
    int resp = x;
    for(int a : passado){
        resp+=x/a;
    }

    if(resp == x) return resp;
    else return indice(resp);
}

int op(int x){
    int resp = 0;
    resp+=x;
    for(int a : passado){
        resp-=resp/a;
    }

    return resp;
}

int busca(int x){
    int ini = 1;
    int fim = n;
    while(ini<=fim){
        int mid = ini + (fim-ini)/2;
        while(vis[mid]) mid--;
        int oper = op(mid);
        if(oper == x) return mid;
        else if (oper > x) fim = mid-1;
        else ini = mid+1;
    }

    return -1;
}

int localiza(int x){
    int pt = x;
    while(vis[pt]){
        if (pt > n) return 0;
        pt++;
    }

    return pt;
}

int main(){

    cin >> n;
    cin >> t;

    validos = n;
    int desc_atual;

    for(int i=0; i<t; i++){
        int num;
        cin >> num;
        
        desc_atual = 0;

        int ptr = num;

        int resultado = busca(ptr);
        while(resultado <= n and resultado != -1){
            cout << ptr << ' ' << busca(ptr) << endl;
            vis[resultado] = 1;

            desc_atual++;
            ptr+=num;
            resultado = busca(ptr);
        }

        validos -= desc_atual;
        passado.push_back(num);
    }

    int jaimprimiu = 0;
    for(int i=1; i<=n; i++){
        if (!vis[i]) {
            cout << i << endl;
            jaimprimiu++;
        }
        if (jaimprimiu == 10000) break;
    }

    return 0;
}