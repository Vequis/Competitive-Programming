#include <iostream>
#include "PersistenciaMusica.h"

using namespace std;

void teste() {

    try {
        PersistenciaMusica* p = new PersistenciaMusica("teste.txt");
        Musica** musicas = new Musica*[10];

        int quantidade;

        musicas = p->obter(quantidade);

        cout << quantidade << " musica(s)" << endl;

        for (int i = 0; i < quantidade; i++) {
            musicas[i]->imprimir();
        }

        delete[] musicas;
        delete p;
    } catch (invalid_argument *e) {
        cout << e->what() << endl;
        delete e;
    } catch (logic_error* e) {
        cout << e->what() << endl;
        delete e;
    }
}

/*
int main() {
    teste();
    return 0;
}
*/
