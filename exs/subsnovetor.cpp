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

using namespace std;

vi v;
int menor;

signed main(){_

    menor = INT_MAX;
    for(int i=0; i<10; i++){
        int num;
        cin >> num;
        v.eb(num);
        menor = min(menor, num);
    }

    cout << "Menor: " << menor << endl;

    cout << "Ocorrencias: ";
    for(int i=0; i<10; i++){
        if(v[i] == menor){
            cout << i << ' ';
            v[i] = -1;
        }
    }

    cout << endl;

    for(int i=0; i<10; i++){
        cout << v[i] << ' ';
    }

    return 0;
}
