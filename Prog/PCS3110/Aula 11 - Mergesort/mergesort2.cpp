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
#define int long long // -> solução divina
#define maxn 1123456

using namespace std;

int a[maxn];
int l[maxn], r[maxn];
int cont = 0;
int n;

void merge(int inicio, int fim);

void mergesort(int inicio, int fim){
    if(inicio >= fim) return;

    int meio = inicio + (fim - inicio)/2;

    mergesort(inicio, meio);
    mergesort(meio+1, fim);
    merge(inicio, fim);
}

void merge(int inicio, int fim){

    int meio = inicio + (fim - inicio)/2;

    int n1 = meio - inicio + 1; //Qtd no da esquerda
    int n2 = fim - (meio);

    for(int i=1; i<=n1; i++){
        l[i] = a[inicio + i - 1];
    }

    for(int i=1; i<=n2; i++){
        r[i] = a[meio + i];
    }

    l[n1+1] = INT_MAX;
    r[n2+1] = INT_MAX;

    int i = 1;
    int j = 1;

    for(int k=inicio; k<=fim; k++){
        if (l[i] <= r[j]){
            a[k] = l[i];
            i++;
        } else {
            a[k] = r[j];
            j++;
        }
    }

    cont++;
    if (cont == 3){
        for(int i=1; i<=n; i++) cout << a[i] << ' ';
        cout << endl;
    }

}

signed main(){_

    cin >> n;

    for(int i=1; i<=n; i++) cin >> a[i];

    mergesort(1, n);

    for(int i=1; i<=n; i++) cout << a[i] << ' ';
    cout << endl;

    return 0;
}
