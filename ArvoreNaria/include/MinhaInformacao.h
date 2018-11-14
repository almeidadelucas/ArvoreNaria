#ifndef MINHAINFORMACAO_H
#define MINHAINFORMACAO_H
#include "Informacao.h"

class MinhaInformacao : public Informacao
{
    public:
        MinhaInformacao(int);
        virtual ~MinhaInformacao();
        int getCodigo();
        int compareTo(Informacao*) throw(char*);
        Informacao* clone();
    private:
        int codigo;
};

#endif // MINHAINFORMACAO_H
