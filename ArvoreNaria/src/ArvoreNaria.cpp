#include "ArvoreNaria.h"

ArvoreNaria::ArvoreNaria(int n) throw(char*)
{
    if(n <= 1)
        throw("A ordem precisa ser no mínimo 2!");

    this->ordem = n;
    this->raiz = NULL;
}

ArvoreNaria::~ArvoreNaria()
{
    delete this->raiz;
}

void ArvoreNaria::inserir(Informacao* in) throw(char*)
{
    if(in == NULL)
        throw("A informação não pode ser nula!");
    if(tem(in))
        throw("A informação já existe na ávore!");

    this->raiz = inserir(this->raiz, in);
}

No* ArvoreNaria::inserir(No* no, Informacao* in)
{
    if(no == NULL)
    {
        No* aux = new No(this->ordem);
        aux->inserirInfo(in);
        return aux;
    }

    if(no->temEspaco())
    {
        no->inserirInfo(in);
        return no;
    }

    int i;

    for(i = 0; i < this->ordem; i++)
    {
        int c = in->compareTo(no->getInfo(i));
        if(c < 0)
        {
            no->setPtr(i, this->inserir(no->getPtr(i), in));
            break;
        }
    }
    if(i == this->ordem)
        no->setPtr(i, this->inserir(no->getPtr(i), in));

    return no;
}

bool ArvoreNaria::tem(Informacao* in) throw(char*)
{
    if(in == NULL)
        throw("A informação não pode ser nula");

    return tem(this->raiz, in);
}

bool ArvoreNaria::tem(No* no, Informacao* in)
{
    if(no == NULL)
        return false;

    for(int i = 0; i < this->ordem; i++)
    {
        int c = in->compareTo(no->getInfo(i));
        if(c < 0)
            return tem(no->getPtr(i), in);
        if(c > 0)
            return tem(no->getPtr(i+1), in);
        // c == 0
        return true;
    }

    return tem(no->getPtr(this->ordem), in);
}

ostream& operator<<(ostream& os, const ArvoreNaria& ar)
{
    if(ar.raiz == NULL)
        os << "()";
    else
        ar.raiz->printar(os);

    return os;
}
