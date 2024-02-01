#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream output;

    output.open("passindo77.txt");

    output << "Clique em 'expandir' " << endl;
    for(int i = 0; i < 5; i++) output << endl;
    
    //output << "Essa é em homenagem a todos os meus amigos santistas!" << endl;

    for(int i = 0; i < 250; i++) {
        // output << "passin do 77" << endl;
        // output << "é o passin do 77" << endl;
        output << "naruto dublado eh " << i << "x melhor" << endl;
    
    }

    output.close();

    return 0;
}