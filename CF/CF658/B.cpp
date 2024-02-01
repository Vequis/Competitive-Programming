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

using namespace std;

int t, a, n, cont;
vector<int> v;
vector<bool> venc;
int ganhando;

int main(){_

    cin >> t;

    for (int i=0; i<t; i++){
        cin >> n;

        v = vi(n);
        venc = vector<bool>(n);

        cont = 0;

        ganhando = 1;

        for (int j=0; j<n-1; j++){
            int num;
            cin >> num;
            v[j] = num;
        }

        cin >> v[n-1];

        venc[n-1] = 1;
        for (int j=n-1; j>=0; j--){
            if (v[j] > 1){
                venc[j] = 1;
            } else if(v[j] == 1) {
                venc[j] = 1 - venc[j+1];
            }
        }

        if (venc[0] == 1){
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }

        v.clear();
        venc.clear();
    }

    return 0;
}