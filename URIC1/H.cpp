#include <iostream>

using namespace std;

pair<int,int> pos(string s, int a, int b){
    bool ok = false;
    for (int i=a; i<b-1; i++) {

        for (int j=b; j>=a+1; j--){

            if (s[i]==s[j] and s[i]!='a'){
                return(make_pair(i,j));
                ok = true;
                break;
            }

        }
        if (ok) break;
    }

    if (a==b-1 and s[a]==s[b]) {
        return(make_pair(a,b));
        ok = true;
    }

    if (!ok) return make_pair(0,0);
}

int main() {

    string s;
    cin >> s;

    int pSize=0;

    int n = s.size();
    int indInicial = 0;
    int indFinal = n-1;

    while (true) {

        pair<int,int> p = pos(s, indInicial, indFinal);

        if (p.first==0 and p.second==0){
            break;
        } else {
            indInicial = p.first+1;
            indFinal = p.second-1;
            pSize+=2;
        }
    }

    if (!(indInicial==indFinal+1)){
        pSize++;
    }

    cout << pSize << endl;

    return 0;

}
