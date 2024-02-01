#ifndef ROTEADORCOMQOS_H
#define ROTEADORCOMQOS_H

#include "Roteador.h"
#include <vector>
#include "FilaComPrioridade.h"

class RoteadorComQoS : public Roteador {
public:
	RoteadorComQoS(int endereco);
	virtual ~RoteadorComQoS();

	virtual void priorizar(int destino);
	virtual vector<int>* getDestinosPriorizados();

	//Redefinicao
	virtual void receber(Datagrama* d);
protected:
	vector<int>* destinosPriorizados;
};

#endif
