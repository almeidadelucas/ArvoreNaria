#include "ArvoreNaria.h"
ArvoreNaria::ArvoreNaria(int n) throw(char*)
{
    if(n <= 1)
        throw("A ordem precisa ser no m�nimo 2!");

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
        throw("A informa��o n�o pode ser nula!");
    if(tem(in))
        throw("A informa��o j� existe na �vore!");
    this->raiz = inserir(this->raiz, in);
}

void ArvoreNaria::excluir(Informacao* in) throw(char*)
{
    if(in == NULL)
        throw("A informa��o n�o pode ser nula!");
    if(!tem(in))
       throw("A informa��o n�o existe na �vore!");

    this->raiz = excluir(this->raiz, in);
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

    for(i = 0; i < this->ordem-1; i++)
    {
        int c = in->compareTo(no->getInfo(i));
        if(c < 0)
        {
            no->setPtr(i, this->inserir(no->getPtr(i), in));
            break;
        }
    }
    if(i == this->ordem-1)
        no->setPtr(i, this->inserir(no->getPtr(i), in));

    return no;
}

No* ArvoreNaria::excluir(No* no, Informacao* in)
{
    bool ehFolha = no->ehFolha();
    int c, i;

    if(no == NULL || no->getQtsInformacoes() == 0)
        return no;

    // verifica se a informa��o est� nesse n�
    for(i = 0; i < no->getQtsInformacoes(); i++)
    {
        int c = in->compareTo(no->getInfo(i));
        if(c == 0)
            break;
        if(c < 0)
        {
            no->setPtr(i,excluir(no->getPtr(i), in));
            return no;
        }
    }

    if(i == no->getQtsInformacoes()) // significa q saiu do for pq acabou o for e n�o pq a informacao est� no n�
    {
        no->setPtr(i, excluir(no->getPtr(i), in));
        return no;
    }

    if(ehFolha && no->getQtsInformacoes() == 1)
    {
        delete(no);
        return NULL;
    }

    if(ehFolha)
    {
        no->excluir(in);
        if(no->getQtsInformacoes() == 0)
        {
            delete(no);
            return NULL;
        }

        return no;
    }

    if(!ehFolha)
    {
        int pos = no->getPos(in);
        if(no->getPtr(pos) != NULL)
        {
            Informacao* info = getMaiorDosMenores(no->getPtr(pos))->clone();
            excluir(info);
            no->setInfo(info, pos);
            return no;
        }
        if(no->getPtr(pos + 1) != NULL)
        {
            Informacao* info = getMenorDosMaiores(no->getPtr(pos+1))->clone();
            excluir(info);
            no->setInfo(info, pos);
            return no;
        }
        // Os dois ponteiros s�o nulos
        for(i = 1; ; i++)
        {
            if(pos + i < no->getOrdem()-1)
            {
                if(no->getPtr(pos+i) != NULL)
                {
                    Informacao* in = getMenorDosMaiores(no->getPtr(pos+i))->clone();
                    excluir(in);
                    no->setInfo(in, pos);
                    no->ordenar();
                    return no;
                }
            }
            else if(pos - i >= 0)
                if(no->getPtr(pos-i) != NULL)
                {
                    Informacao* in = getMaiorDosMenores(no->getPtr(pos-i))->clone();
                    excluir(in);
                    no->setInfo(in, pos);
                    no->ordenar();
                    return no;
                }
        }
    }
}

Informacao* ArvoreNaria::getMaiorDosMenores(No* no)
{
    if(no->getPtr(no->getQtsInformacoes()) != NULL)
        return getMaiorDosMenores(no->getPtr(no->getQtsInformacoes()));
    else
    {
        Informacao* in = no->getInfo(no->getQtsInformacoes()-1);
        return in;
    }
}

Informacao* ArvoreNaria::getMenorDosMaiores(No* no)
{
    if(no->getPtr(0) != NULL)
        return getMenorDosMaiores(no->getPtr(0));
    else
    {
        Informacao* in = no->getInfo(0);
        return in;
    }
}

bool ArvoreNaria::tem(Informacao* in) throw(char*)
{
    if(in == NULL)
        throw("A informa��o n�o pode ser nula");

    return tem(this->raiz, in);
}

bool ArvoreNaria::tem(No* no, Informacao* in)
{
    if(no == NULL)
        return false;
    int i;
    for(i = 0; i < no->getQtsInformacoes(); i++)
    {
        int c = in->compareTo(no->getInfo(i));
        if(c < 0)
            return tem(no->getPtr(i), in);
        if(c == 0)
            return true;
    }
    return tem(no->getPtr(i), in);
}

ostream& operator<<(ostream& os, const ArvoreNaria& ar)
{
    if(ar.raiz == NULL)
        os << "()";
    else
        ar.raiz->printar(os);

    return os;
}
