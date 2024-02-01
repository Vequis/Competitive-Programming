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

int n;

vector<int> V = {2,3,5};

char c;
int soma = 0;

int main(){_

    while(cin >> c){
        soma+= (c-'0');
    }

    if ((c-'0')%2){
        cout << "N" << endl;
    } else {
        cout << "S" << endl;
    }

    if (soma%3){ 
        cout << "N" << endl;
    } else {
        cout << "S" << endl;
    }

    if ((c-'0')%5){
        cout << "N" << endl;
    } else {
        cout << "S" << endl;
    }

    return 0;
}