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

int matriz[4][14]; //naipe, num
map<char, int> mp;
int atual, cont, erro;

int main(){_

    mp['C'] = 0;
    mp['E'] = 1;
    mp['U'] = 2;
    mp['P'] = 3;

    string s;

    cin >> s;

    for(int i=0; i<sz(s); i+=3){
        atual = 10*(int)(s[i] - '0') + (int)(s[i+1] - '0');
        matriz[mp[s[i+2]]][atual]++;
    }

    for(int i=0; i<4; i++){
        cont=0;
        erro = 0;
        for(int j=1; j<=13; j++){
            if(matriz[i][j]==0) cont++;
            else if(matriz[i][j]>1) erro=1;
        }

        if(erro){
            cout << "erro" << endl;
        } else {
            cout << cont << endl;
        }   
    }

    return 0;
}

//13P02P01P03P04P05P06P07P08P09P10P11P12P13C02C01C03C04C05C06C07C08C09C10C11C12C13E02E01E03E04E05E06E07E08E09E10E11E12E13U02U01U03U04U05U06U07U08U09U10U11U12U