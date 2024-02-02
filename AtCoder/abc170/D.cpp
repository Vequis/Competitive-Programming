#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> V;
vector<int> resposta;
int vis[1001000];

int crivo(int limite, int ind){
    int cont = 0;
    for (int i=0; i<ind; i++){
        if(vis[V[i]] == 0){
            vis[V[i]] = 2;
            cont++;
            for (int j=2*V[i]; j<=limite; j+=V[i]) vis[j] = 1;
        }else if (vis[V[i]] == 2){ //Ja foi contado
            vis[V[i]] = 3;
            cont--;
        }
    }
    return cont;
}

int main(){

    int n;
    cin >> n;

    int limite = 0;
    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        if (num > limite) limite = num;
        V.push_back(num);
    }

    sort(V.begin(), V.end());
    cout << crivo(limite, n) << endl; 
    return 0;
}
