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

vi receita(3); //BSC
vi ings(3);
int total;
long long int r, cont;
vi precos(3);
string st;

int main(){_

    cin >> st;

    for (int i=0; i<sz(st); i++){
        if (st[i] == 'B'){
            receita[0]++;
        } else if (st[i] == 'S'){
            receita[1]++;
        } else if (st[i] == 'C'){
            receita[2]++;
        }
    }

    for (int i=0; i<3; i++){
        cin >> ings[i];
    }

    for (int i=0; i<3; i++){
        cin >> precos[i];
    }

    cin >> r;

    while(1){
        if (!((ings[0] and receita[0])||(ings[1] and receita[1])||(ings[2] and receita[2]))){
            cont+=r/(receita[0]*precos[0] + receita[1]*precos[1] + receita[2]*precos[2]);
            break;
        }

        for (int i=0; i<3; i++){
            if (ings[i]==0){
                r-=(precos[i]*receita[i]);
            }
            else {
                ings[i] -= receita[i];
                if (ings[i] < 0){
                    r-=(abs(ings[i]) * precos[i]);
                    ings[i] = 0;
                }
            }
        }

        if (r<0) break;
        else cont++;
    }

    cout << cont << endl;

    return 0;
}