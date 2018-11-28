#include "MinhaInformacao.h"
#include "Informacao.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

using namespace std;

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

int MinhaInformacao::compareTo(Informacao* in)
{
    if(in == NULL)
        throw invalid_argument("A informcação não pode ser nula!");

    MinhaInformacao* mi = (MinhaInformacao*) in;

    if(this->codigo > mi->getCodigo())
        return 1;
    if(this->codigo < mi->getCodigo())
        return -1;
    return 0;
    //return this->codigo - mi->getCodigo()
}

Informacao* MinhaInformacao::clone()
{
    return new MinhaInformacao(this->getCodigo());
}

string MinhaInformacao::toString()
{
    stringstream ss;
    ss << this->codigo;
    return ss.str();
}
