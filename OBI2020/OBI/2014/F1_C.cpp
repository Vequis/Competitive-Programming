#include <iostream>

using namespace std;

int main(){

    string s;
    getline(cin, s);

    bool var = 0;
    for (int i=0; i<s.size(); i++) {
        if (var == 1){
            cout << s[i];
            var = 0;
        }
        else if (s[i] == ' '){
            var = 0;
            cout << s[i];
        } 
        else if (s[i] == 'p' and var == 0) var = 1;
    }

    return 0;
}