#ifndef NO_H
#define NO_H
#include "Informacao.h"
#include <iostream>
using namespace std;

class No
{
    public:
        No(int) throw(char*);
        virtual ~No();
        Informacao* getInfo(int) throw(char*);
        No*         getPtr(int) throw(char*);
        void        setPtr(int, No*) throw(char*);
        void        printar(ostream&);
        void        inserirInfo(Informacao*) throw(char*);
        void        excluir(Informacao*);
        int         getOrdem();
        int         getQtsInformacoes();
        bool        temEspaco();
        bool        ehFolha();
    private:
        Informacao** vetInfo;
        No**         vetPtr;
        int          ordem;
        int          qtsInformacoes;
        void         inserir(int, Informacao*);
        void         moverParaEsq(int);
};

#endif // NO_H
