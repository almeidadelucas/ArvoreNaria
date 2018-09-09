#include "MinhaInformacao.h"
#include "Informacao.h"
#include <iostream>

MinhaInformacao::MinhaInformacao(int cod)
{
    this->codigo = cod;
}

MinhaInformacao::~MinhaInformacao()
{
}

int MinhaInformacao::getCodigo()
{
    return this->codigo;
}

int MinhaInformacao::compareTo(Informacao* in) throw(char*)
{
    if(in == NULL)
        throw("A informcação não pode ser nula!");

    MinhaInformacao* mi = (MinhaInformacao*) in;

    if(this->codigo > mi->getCodigo())
        return 1;
    if(this->codigo < mi->getCodigo())
        return -1;
    return 0;
    //return this->codigo - mi->getCodigo()
}
