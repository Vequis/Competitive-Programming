#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H

#include "Rede.h"
#include "RoteadorComQoS.h"

class PersistenciaDeRede{
public:
	PersistenciaDeRede(string arquivo);
	virtual ~PersistenciaDeRede();

	virtual Rede* carregar();
private:
	string arquivo;
};

#endif
