#include<bits/stdc++.h>

using namespace std;

int n, resp;
int numero[1111];
string s, inicial;
map<char, int> mp;

bool f(){
    for(int i = 0; i<((int)s.size()); i++){
        if (mp[s[i]] != numero[i])
            return false;
    }

    return true;
}

int main(){

    for(int i=2; i<7; i++){
        for(int j=0; j<3; j++){
            mp[(char)('a' + 3*(i-2) + j)] = i;
        }
    }

    mp['p'] = 7;
    mp['q'] = 7;
    mp['r'] = 7;
    mp['s'] = 7;
    mp['t'] = 8;
    mp['u'] = 8;
    mp['v'] = 8;
    mp['w'] = 9;
    mp['x'] = 9;
    mp['y'] = 9;
    mp['z'] = 9;

    cin >> inicial;

    for(int i=0; i<(int)inicial.size(); i++){
        numero[i] = (int)(inicial[i] - '0');
    }

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> s;
        if ((int)s.size() != (int)inicial.size()) continue;
        if (f()) resp++;
    }

    cout << resp << endl;

    return 0;
}