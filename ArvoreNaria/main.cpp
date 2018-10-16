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
        MinhaInformacao* mi2 = new MinhaInformacao(10);
        MinhaInformacao* mi3 = new MinhaInformacao(4);
        MinhaInformacao* mi4 = new MinhaInformacao(6);
        MinhaInformacao* mi5 = new MinhaInformacao(12);
        MinhaInformacao* mi6 = new MinhaInformacao(14);
        MinhaInformacao* mi7 = new MinhaInformacao(16);
        MinhaInformacao* mi8 = new MinhaInformacao(18);

        cout << ar << "\n";

        ar.inserir(mi1);
        ar.inserir(mi2);
        ar.inserir(mi3);
        ar.inserir(mi4);
        ar.inserir(mi5);
        ar.inserir(mi6);
        ar.inserir(mi7);
        ar.inserir(mi8);

        cout << ar << "\n";
        ar.excluir(mi1);

        cout << ar << "\n";

        ar.excluir(mi6);
        cout << ar << "\n";

        ar.excluir(mi8);
        cout << ar << "\n";

    }
    catch(char* e)
    {
        cout << e;
    }

    return 0;
}
