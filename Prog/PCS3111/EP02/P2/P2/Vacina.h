#ifndef VACINA_H
#define VACINA_H

class Vacina {
public:
    Vacina(int dataFabricacao);
    virtual ~Vacina();
    virtual int getLote();
    virtual int getDataFabricacao();
    virtual int getValidade() = 0;

    virtual void imprimir();
private:

protected:
    int dataFabricacao;
    int lote;
    int validade;

    int dose;
};

#endif // VACINA_H
