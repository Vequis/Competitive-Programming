#include<bits/stdc++.h>
#define maxn 21234
#define sz(x) (int)(x).size()
#define int long long 

using namespace std;

string senhas[maxn];
int n;
int resp_final;
int resp[maxn];
bool fraco[maxn];
int pai[maxn];

bool comp(string a, string b){
    return sz(a) < sz(b);
}

int find(int a){
    if (pai[a] == a) return a;
    return find(pai[a]);
}

void unite(int a, int b){
    pai[find(a)] = b;
}

bool eh_substr(int b, int a){ //Verifica se b está contido em a 
    for(int i=0; i<sz(senhas[a]); i++){
        int ptr = 0;
        while( senhas[a][i+ptr] == senhas[b][ptr] ){
            ptr++;
            if(ptr == sz(senhas[b])) return true;
        }
    }

    return false;
}

signed main(){

    cin >> n;

    for(int i=1; i<=n; i++) cin >> senhas[i];
    for(int i=1; i<=n; i++) pai[i] = i;

    sort(senhas + 1, senhas + 1 + n, comp);
    senhas[0] = ".";

    resp_final = 0;

    for(int i=1; i<=n; i++){

        for(int j = i-1; j>=1; j--){
            if(eh_substr(i, j)) resp_final++;
        
            if (find(j) != i and eh_substr(j, i)){
                if(pai[j]!=j) resp[pai[j]] -= resp[j] + 1;
                pai[j] = i;
                resp[i] += resp[j] + 1;
            }
        }
        resp_final += resp[i];

        // cout << resp[i] << endl;
    }

    cout << resp_final << endl;

    return 0;

}