#ifndef NO_H
#define NO_H
#include "Informacao.h"
#include <iostream>

using namespace std;

class No
{
    public:
        No(int);
        virtual ~No();
        Informacao* getInfo(int);
        No*         getPtr(int);
        void        setPtr(int, No*);
        void        printar(ostream&);
        void        inserirInfo(Informacao*);
        void        excluir(Informacao*);
        int         getOrdem();
        int         getQtsInformacoes();
        int         getPos(Informacao*);
        void        setInfo(Informacao*, int);
        void        moverParaEsq(int);
        bool        temEspaco();
        bool        ehFolha();
        void        ordenar();
    private:
        Informacao** vetInfo;
        No**         vetPtr;
        int          ordem;
        int          qtsInformacoes;
        void         inserir(int, Informacao*);
};

#endif // NO_H
