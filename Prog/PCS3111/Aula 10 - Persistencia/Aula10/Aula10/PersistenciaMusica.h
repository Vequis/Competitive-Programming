#ifndef PERSISTENCIA_MUSICA_H
#define  PERSISTENCIA_MUSICA_H

#include <string>

#include "Musica.h"

using namespace std;

class PersistenciaMusica {
public:
    PersistenciaMusica(string arquivo);
    ~PersistenciaMusica();

    void inserir(Musica* m);

    Musica** obter(int& quantidade);
private:
    string arquivo;
};

#endif /* PERSISTENCIA_MUSICA_H */
