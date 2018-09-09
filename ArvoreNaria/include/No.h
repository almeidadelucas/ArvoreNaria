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
        int         getOrdem();
        void        printar(ostream&);
        bool        temEspaco();
        void        inserirInfo(Informacao*) throw(char*);
    private:
        Informacao** vetInfo;
        No**         vetPtr;
        int          ordem;
        int          qtsInformacoes;
        void         inserir(int, Informacao*);
};

#endif // NO_H
