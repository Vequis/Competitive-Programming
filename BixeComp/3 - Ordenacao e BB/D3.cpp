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

int n, l, cac, d;
int ant, atual;

int maior[112345], menor[112345];
bool decr[112345];
int maiorat, menorat;
ll resp;

int bb(int x){ // Quantos números são maiores ou iguais
    int ini=0, fim = cac, mid;
    while(ini < fim){
        mid = ini + (fim-ini)/2;
        if(menor[mid]>=x) fim=mid;
        else ini = mid+1;
    }
    return cac-(ini);
}

int main(){

    cin >> n;

    cac=0;

    for (int i=0; i<n; i++){
        cin >> l;
        cin >> ant;
        maiorat = ant;
        menorat = ant;
        decr[i] = 1;

        for (int j=0; j<(l-1); j++){
            cin >> atual;

            if (atual > ant){
                decr[i] = 0;
            }

            maiorat = max(maiorat, atual);
            menorat = min(menorat, atual);

            ant = atual;
        }

        maior[i] = maiorat;
        if(decr[i]){
            menor[cac]= menorat;
            cac++;
        }
    }

    sort(menor, menor+cac);

    resp = n;
    resp*=n;

    for (int i=0; i<n; i++){
        if (decr[i]){
            resp-=bb(maior[i]);
        }
    }

    cout << resp << endl;

    return 0;
}