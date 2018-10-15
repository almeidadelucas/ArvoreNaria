#include "No.h"
#include <iostream>

No::No(int n) throw(char*)
{
    if(n <= 1)
        throw("A ordem deve ser no mínimo 2!");

    this->ordem = n;
    this->vetInfo = new Informacao*[n - 1];
    this->vetPtr  = new No*[n];
    this->qtsInformacoes = 0;

    for(int i = 0; i < n; i++)
    {
        this->vetInfo[i] = NULL;
        this->vetPtr[i]  = NULL;
    }

    this->vetPtr[n] = NULL;
}

No::~No()
{
}

Informacao* No::getInfo(int pos) throw(char*)
{
    if(pos >= this->ordem)
        throw("Posição inválida!");
    return vetInfo[pos];
}

No* No::getPtr(int pos) throw(char*)
{
    if(pos > this->ordem)
        throw("Posição inválida!");
    return vetPtr[pos];
}

void No::setPtr(int pos, No* no) throw(char*)
{
    if(pos > this->ordem)
        throw("Posição inválida!");
    this->vetPtr[pos] = no;
}

int No::getOrdem()
{
    return this->ordem;
}

bool No::temEspaco()
{
    return this->qtsInformacoes != (this->getOrdem()-1);
}

void No::inserirInfo(Informacao* in) throw(char*)
{
    if(in == NULL)
        throw("A informação não pode ser nula");
    if(!this->temEspaco())
        throw("O nó está cheio");

    if(this->qtsInformacoes == 0)
        this->inserir(0, in);
    else
    {
        int i;
        for(i = 0; i < this->ordem; i++)
        {
            if(vetInfo[i] == NULL)
            {
                this->inserir(i, in);
                break;
            }
            int c = in->compareTo(vetInfo[i]);
            if(c < 0)
            {
                this->inserir(i, in);
                break;
            }
        }
        if(i == this->ordem)
            this->inserir(i, in);
    }
}

void No::inserir(int pos, Informacao* in)
{
    Informacao* aux;
    if(this->qtsInformacoes == 0)
        vetInfo[pos] = in;
    else
    {
        for(int i = this->ordem; i > pos; i--)
        {
            aux = vetInfo[i];
            vetInfo[i] = vetInfo[i - 1];
            vetInfo[i - 1] = aux;
        }

        vetInfo[pos] = in;
    }

    this->qtsInformacoes++;
}

void No::printar(ostream& os)
{
    os << "( ";

    for(int i = 0; i < this->ordem; i++)
    {
        if(this->getPtr(i) != NULL)
            this->getPtr(i)->printar(os);
        if(this->getInfo(i) != NULL)
            os << this->getInfo(i)->getCodigo() << " ";
    }

    if(this->getPtr(this->ordem) != NULL)
        this->getPtr(this->ordem)->printar(os);

    os << ")";
}

int No::getQtsInformacoes()
{
    return this->qtsInformacoes;
}

bool No::ehFolha()
{
    for(int i = 0; i < ordem; i++)
        if(vetPtr[i] != NULL)
            return false;
    return true;
}

void No::excluir(Informacao* in)
{
    if(ehFolha())
        for(int i = 0; i < this->ordem-1; i++)
            if(vetInfo[i]->compareTo(in) == 0)
            {
                vetInfo[i] = NULL;
                this->moverParaEsq(i);
                break;
            }
}

void No::moverParaEsq(int pos)
{
    int i;
    for(i = pos; i < this->ordem-2; i++)
        vetInfo[i] = vetInfo[i+1];

    vetInfo[i] = NULL;
}

void No::setInfo(Informacao* in, int pos)
{
    vetInfo[pos] = in;
}

int No::getPos(Informacao* in)
{
    for(int i = 0; i < qtsInformacoes; i++)
        if(vetInfo[i]->compareTo(in) == 0)
            return i;
    return -1; // não existe essa informação nesse nó
}
