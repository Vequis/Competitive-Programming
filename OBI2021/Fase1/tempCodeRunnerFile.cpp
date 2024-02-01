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

int cifra[26][3];
int vogais[] = {0, 4, 8, 14, 20, 26};

signed main(){_

    for(int i=0; i<26; i++){
        cifra[i][0] = 'a'+ i;
    }

    for(int i=0; i<26; i++){
        if('a' + i == 'a' || 'a' + i == 'e' || 'a' + i == 'i' || 'a' + i == 'o' || 'a' + i == 'u'){
            continue;
        }
    
        int resp = 30;
        for(int j=0; j<6; j++){
            if(resp > abs(i-vogais[j])){
                resp = i-vogais[j];
                cifra[i][1] = 'a' + (vogais[j])%26;
            }
        }
    }

    for(int i=0; i<25; i++){
        if(cifra[i+1][1] !=0){
            cifra[i][2] = cifra[i+1][0];
        } else {
            cifra[i][2] = cifra[i+2][0];
        }
    }
    cifra[25][2] = 'z';

    string s;
    cin >> s;

    for(int i=0; i<sz(s); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            cout << s[i];
        } else {
            for(int j=0; j<3; j++){
                cout << (char)(cifra[s[i] - 'a'][j] ) ;
            }
        }
    }

    return 0;
}
