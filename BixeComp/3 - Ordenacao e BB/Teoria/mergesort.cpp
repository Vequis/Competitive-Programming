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

using namespace std;

vi v, aux;

void mergesort(int a, int b){
    if (a>=b) return;

    int mid = a + (b-a)/2;
    mergesort(a, mid);
    mergesort(mid+1, b);

    aux = v;

    int cont = a;
    int final = b;
    while(a<=mid){
        while(v[a] < v[b] and a<=mid) {
            aux[cont] = v[a];
            cout << aux[cont] << endl;
            a++;
            cont++;
        }
        if(b<=final){
            aux[cont] = v[b];
            cout << aux[cont] << endl;
            b++;
            cont++;
        }
    }

    while(b <= final){
        aux[cont] = v[b];
        cout << aux[cont] << endl;
        b++;
        cont++;
    }

    v = aux;

    return;
}

int main(){_

    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        v.pb(num);
    }

    mergesort(0,n-1);

    for (auto x : v) cout << x << ' ';
    cout << endl;

    return 0;
}