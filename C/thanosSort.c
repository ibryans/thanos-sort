/*
* @author Diogo Neiss
* @date Oct 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/** 
 * Para evitar a erros nas outras funcoes, fiz uma struct só pro arranjo.
 */
typedef struct EstruturaArranjo
{

    int *arranjoInteiros;
    int tam;

} EstruturaArranjo;


void snap(EstruturaArranjo *objeto);
bool estaOrdenado(EstruturaArranjo *objeto);
void inserir(EstruturaArranjo *arranjo, int x);
void remover(EstruturaArranjo *arranjo);
void erase(EstruturaArranjo *arranjo, int pos);
EstruturaArranjo *construtorTAD();
int main();
void snap(EstruturaArranjo *objeto);
bool estaOrdenado(EstruturaArranjo *objeto);


int main()
{
    //setar a semente do rand()
    srand(time(NULL));
    srand(rand());

    EstruturaArranjo *arranjoObjeto = construtorTAD();
    for (int i = 0; i < 100; i++)
    {
        inserir(arranjoObjeto, rand() % 20);
    }

    snap(arranjoObjeto);

    printf("Arranjo ordenado de maneira extremamente eficiente: ");
    for (int i = 0; i < arranjoObjeto->tam; i++)
        printf("%d ", arranjoObjeto->arranjoInteiros[i]);

    printf("\n");
}


void inserir(EstruturaArranjo *arranjo, int x)
{
    arranjo->arranjoInteiros[arranjo->tam] = x;
    arranjo->tam++;
}

void remover(EstruturaArranjo *arranjo)
{
    arranjo->arranjoInteiros[arranjo->tam] = 0;
    arranjo->tam--;
}
void erase(EstruturaArranjo *arranjo, int pos)
{
    int *antigo = arranjo->arranjoInteiros;
    int *novo = (int *)malloc(sizeof(int) * (arranjo->tam - 1));

    int contador = 0;
    for (int i = 0; i < arranjo->tam; i++)
    {
        if (i != pos)
        {
            novo[contador] = antigo[i];
            contador++;
        }
    }
    arranjo->tam--;
    free(antigo);
    arranjo->arranjoInteiros = novo;
}

EstruturaArranjo *construtorTAD()
{
    EstruturaArranjo *novoArranjo = (EstruturaArranjo *)malloc(sizeof(EstruturaArranjo));
    novoArranjo->arranjoInteiros = (int*)malloc(101* sizeof(int));
    novoArranjo->tam = 0;

    return novoArranjo;
}

void snap(EstruturaArranjo *objeto)
{

    while (!estaOrdenado(objeto))
    {
        for (int i = 0; i < objeto->tam; i++)
        {
            printf("%d ", objeto->arranjoInteiros[i]);
        }

        int halfLength = objeto->tam / 2;

        // Vai remover length/2 elementos aleatórios
        for (int i = 0; i < halfLength; i++)
        {
            erase(objeto, rand() % objeto->tam);
        }

        printf("\nSNAP!\n");
    }
}

bool estaOrdenado(EstruturaArranjo *objeto)
{

    bool ordenado = true;

    for (int i = 0; i < objeto->tam && ordenado; i++)
    {
        if (objeto->arranjoInteiros[i] > objeto->arranjoInteiros[i + 1])
        {
            ordenado = false;
        }
    }
    return ordenado;
}
