#ifndef INFORMACAO_H
#define INFORMACAO_H


class Informacao
{
    public:
        virtual int compareTo(Informacao*) = 0;
        virtual int getCodigo() = 0;
        virtual Informacao* clone() = 0;
    protected:

    private:
};

#endif // INFORMACAO_H
