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

using namespace std;

vi v;
int n;

int main(){_

    cin >> n;
    v = vi(n);

    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    sort(all(v)); //Nao-decrescente: Nao precisa ser estritamente maior 

    for (int i=0; i<n; i++){
        cout << v[i] << " ";
    }

    cout << endl;

    v.clear();
    return 0;
}