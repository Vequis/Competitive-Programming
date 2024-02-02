#include <iostream>
#include <cmath>

using namespace std;

int stoi (string s, int in, int fim){
    int resp = 0;

    for (int i=in; i<= fim; i++){
        resp *= 10;
        resp += (int)s[i]-'0';
    }

    return resp;
}

string itos (int n){
    string s;
    while(n!=0){
        s+= ('0' + n%10);
        n-= n%10;
        n/=10;
    }

    string sCorr = s;
    for (int i=0; i<(int)s.size(); i++) {
        sCorr[i] = s[s.size() - 1 - i];
    }

    return sCorr;
}

//ACBNUM --> num
string atob(string s){

    int indIn;

    int col = 0;
    int l = 0;
    int siz = (int)s.size();

    for (int i=0 ; i<(int)s.size(); i++){
        if ((s[i]-'0' > 0) and (s[i]-'0' <= 9 )){
            l = stoi(s, i, siz-1);
            indIn = i;
            break;
        }
    }

    for (int i=0; i<indIn; i++){
        col += (s[indIn-1-i] - 'A' + 1)* pow(26, i);
    }

    string resp = "R";
    resp+=itos(l);
    resp+="C";
    resp+=itos(col);
    return resp;
}

string btoa(string s, int indC){
    int col = 0;
    int l = 0;
    int siz = (int)s.size();

    l = stoi(s, 1, indC-1);
    col = stoi(s, indC+1, siz-1);

    string st;

    while(col!=0){
            st+= (char)('A'-1 + ((col-1)%26) + 1);
            col-= ((col-1)%26) + 1;
            col/=26;
    }


    string stI = st;
    for (int i=0; i<(int)st.size(); i++){
        stI[i] = st[st.size()-1 - i];
    }

    string resp = stI;
    resp+=itos(l);
    return resp;
}

int main() {

    int n;
    cin >> n;

    string v[n];

    for (int i=0; i<n; i++) {

        string exp;
        cin >> exp;

        bool ok = false;

        for (int j=1; j<exp.size(); j++) {
            if (exp[j]=='C' and (exp[j-1]>='0' and exp[j-1]<='9')){
                v[i] = btoa(exp, j);
                ok = true;
            }
        }
        if (!ok){
            v[i] = atob(exp);
        }
    }

    for (int i=0; i<n; i++){
        cout << v[i] << endl;
    }

    return 0;
}
