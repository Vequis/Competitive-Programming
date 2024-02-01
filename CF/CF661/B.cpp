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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

int menor1, menor2;
vii v;
int t, n;
int aux1, aux2;

int main(){_

    cin >> t;

    while(t--){
        cin >> n;

        menor1 = INT_MAX; menor2 = INT_MAX;

        v = vii(n);

        for (int i=0; i<n; i++){
            cin >> aux1;
            menor1 = min(menor1, aux1);
            v[i] = {aux1, 0};
        }

        for (int i=0; i<n; i++){
            cin >> aux1;
            menor2= min(menor2, aux1);
            v[i] = {v[i].fs, aux1};
        }   

        ll cont = 0;

        for (int i=0; i<n; i++){
            cont += max(v[i].fs - menor1, v[i].sc - menor2);
        }

        cout << cont << endl;

    }

    return 0;
}