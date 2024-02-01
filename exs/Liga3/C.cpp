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

int preco, n;
int menor, indmenor;

vector< char > v;

int main(){_

    cin >> n;

    menor = 0;

    for (int i=0; i<n-1; i++){
        char c;
        cin >> c;
        v.pb(c);

        if (c == 'A'){
            preco++;
        } else {
            preco--;
            if (menor > preco){
                indmenor = i;
                menor = preco; 
            }
        }
    }

    preco = abs(menor);
    for (int i=0; i<n; i++){
        cout << preco << " ";
        if (v[i] == 'A'){
            preco++;
        } else {
            preco--;
        }
    }

    return 0;
}