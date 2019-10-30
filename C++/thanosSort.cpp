/*
* @author Diogo Neiss
* @date Oct 2019
*/


#include <iostream>
#include <vector>
#include <random>

/** 
 * Para evitar a sintaxe de vetor nas outras funcoes, fiz uma classe só pra ele.
 */ 
class EstruturaArranjo
{
public:
    std::vector<int> arranjo;

    void inserir(int x)
    {
        arranjo.push_back(x);
    }
    void remover()
    {
        arranjo.pop_back();
    }
};

void snap(EstruturaArranjo &objeto);
bool estaOrdenado(EstruturaArranjo &objeto);

int main()
{
    //setar a semente do rand()
    srand(100);
    srand(rand());

    EstruturaArranjo *arranjoObjeto = new EstruturaArranjo();
    for (int i = 0; i < 100; i++)
    {
        arranjoObjeto->inserir(rand() % 20);
    }

    snap(*arranjoObjeto);

    printf("Arranjo ordenado de maneira extremamente eficiente: ");
    for (int i = 0; i < arranjoObjeto->arranjo.size(); i++)
        printf("%d ", arranjoObjeto->arranjo[i]);

    printf("\n");
}

void snap(EstruturaArranjo &objeto)
{

    while (!estaOrdenado(objeto))
    {
        for (int i = 0; i < objeto.arranjo.size(); i++)
        {
            printf("%d ", objeto.arranjo[i]);
        }

        int halfLength = objeto.arranjo.size() / 2;

        // Vai remover length/2 elementos aleatórios
        for (int i = 0; i < halfLength; i++)
        {
            objeto.arranjo.erase(objeto.arranjo.begin() + rand() % objeto.arranjo.size());
        }

        printf("\nSNAP!\n");
    }
}

bool estaOrdenado(EstruturaArranjo &objeto)
{

    bool ordenado = true;

    for (int i = 0; i < objeto.arranjo.size() && ordenado; i++)
    {
        if (objeto.arranjo[i] > objeto.arranjo[i + 1])
        {
            ordenado = false;
        }
    }
    return ordenado;
}
