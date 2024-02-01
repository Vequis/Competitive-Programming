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
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
// #define int long long -> solução divina?

using namespace std;

int digitos[7][10], q, n, aux[10], baralho[10];

int dfs(int n, int escolhido){
    if(n>q) return 0;
    int resp;

    resp = max(dfs(n+1, 1), dfs(n+1, 0));

    if (escolhido){
        bool possivel = true;
        for(int i=0; i<=9; i++){
            aux[i] -= digitos[n][i];
            if(aux[i]<0){
                possivel=false;
            }
        }
        if (possivel) resp = 1 + max(dfs(n+1, 1), dfs(n+1, 0));

        for(int i=0; i<=9; i++){
            aux[i] += digitos[n][i];
        }
    } else {
        resp = max(dfs(n+1, 1), dfs(n+1, 0));
    }

    return resp;
}

int main(){_

    cin >> q >> n;

    for(int i=0; i<1; i++){
        int num;
        cin >> num;
        while(num>=0){
            if(n==0){
                digitos[i][0]++;
                break;
            }
            digitos[i][num%10]++;
            num/=10;
        }
    }

    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        baralho[num]++;
    }

    cout << max(dfs(2, 1), dfs(2,0));

    return 0;
}