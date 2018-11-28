#ifndef ARVORENARIA_H
#define ARVORENARIA_H
#include "Informacao.h"
#include "No.h"
#include <iostream>

class ArvoreNaria
{
    public:
        ArvoreNaria(int);
        virtual ~ArvoreNaria();
        void inserir(Informacao*);
        void excluir(Informacao*);
        bool tem(Informacao*);
        friend ostream& operator<<(ostream&, const ArvoreNaria&);
    private:
        int ordem;
        No* inserir(No*, Informacao*);
        No* excluir(No*, Informacao*);
        bool tem(No*, Informacao*);
        No* raiz;
        Informacao* getMaiorDosMenores(No*);
        Informacao* getMenorDosMaiores(No*);
};

#endif // ARVORENARIA_H
