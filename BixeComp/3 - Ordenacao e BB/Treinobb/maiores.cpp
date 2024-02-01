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

//Dado um número x e um vetor v. Determine quantos valores do vetor são maiores que x;

int n, q;
vi v;

int bb(int x){
    int ini=0, fim=n, mid;
    while(ini < fim){
        mid = ini+(fim-ini)/2;
        if (v[mid] > x) fim = mid;
        else ini = mid+1; 
    }
    return n-ini;
}

int main(){_
    cin >> n;

    v = vi(n);
    for (int i=0; i<n; i++) cin >> v[i];

    cin >> q;
    for (int i=0; i<q; i++){
        int num;
        cin >> num;
        cout << bb(num) << endl;
    }

    return 0;
}