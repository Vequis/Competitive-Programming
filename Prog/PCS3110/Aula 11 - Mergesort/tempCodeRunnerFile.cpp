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

void merge(int inicio, int fim){
    int meio = inicio + (fim - inicio)/2;

    for(int i = inicio; i<=meio; i++){
        l[i - inicio] = a[i];
        // cout << l[i - inicio] << ' ' ;
    }
    l[meio - inicio + 1] = INT_MAX;
    // cout << endl;

    for(int i = meio + 1; i<=fim; i++){
        r[i - (meio + 1)] = a[i];
        // cout << r[i - (meio + 1)] << ' ' ;
    }
    r[fim - (meio + 1) + 1] = INT_MAX;
    // cout << endl;

    int i = 0, j = 0;

    for(int k = inicio; k<=fim; k++){
        cont++;
        if (l[i] < r[j]){
            a[k] = l[i];
            i++;
        } else {
            a[k] = r[j];
            j++;
        }
    }
}

void mergesort(int inicio, int fim){
    if (inicio == fim){
        return;
    }

    int meio = inicio + (fim - inicio)/2;
    mergesort(inicio, meio);
    mergesort(meio + 1, fim);
    merge(inicio, fim);
}

signed main(){_

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    mergesort(0, n-1);

    for(int i=0; i<n; i++) cout << a[i] << ' ';
    cout << endl;

    cout << cont << endl;

    return 0;
}
