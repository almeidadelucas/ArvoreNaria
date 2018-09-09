#include <iostream>
#include "MinhaInformacao.h"
#include "ArvoreNaria.h"

using namespace std;

int main()
{
    try
    {
        ArvoreNaria ar(3);
        MinhaInformacao* mi1 = new MinhaInformacao(8);
        MinhaInformacao* mi2 = new MinhaInformacao(12);
        MinhaInformacao* mi3 = new MinhaInformacao(11);
        MinhaInformacao* mi4 = new MinhaInformacao(10);
        ar.inserir(mi1);
        ar.inserir(mi2);
        ar.inserir(mi3);
        ar.inserir(mi4);
        cout << ar;
    }
    catch(char* e)
    {
        cout << e;
    }

    return 0;
}
