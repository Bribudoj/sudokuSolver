/*
 *  Trabalho 1 - Passos para resolver o sudoku
 *  Autor:
 *  Data:
 */
#include <stdio.h>
#include <string.h>

#define TAMANHO 9
//-------------------------------------------------------------------
//   Prototipo das funcoes - isso permite que elas sejam colocados
// dentro do arquivo C, em qualquer ordem.
//
void inicializaVetor(int v[], int tam);
void inicializa3Vetor(int v1[], int v2[], int v3[], int tam);
void showMat(int mat[][TAMANHO], int tam);
void showVet(int vetor[], int tam);
void interseccao2Vetores(int v1[], int v2[], int resultado[], int tam);

// funcoes principais
void valoresAusentesLinha(int jogo[][TAMANHO], int lin, int resultado[],
                          int tam)
{
    int n_existe, j, i, n = 0;
    for (j = 1; j < tam + 1; j++)
    {
        n_existe = 1;
        for (i = 0; i < tam; i++)
        {
            if (jogo[lin][i] == j)
            {
                n_existe = 0;
                break;
            }
        }
        if (n_existe == 1)
        {
            resultado[n] = j;
            n++;
        }
    }
}
void valoresAusentesColuna(int jogo[][TAMANHO], int col, int resultado[],
                           int tam)
{
    int i, j, n_existe, n = 0;
    for (j = 1; j < tam + 1; j++)
    {
        n_existe = 1;
        for (i = 0; i < tam; i++)
        {
            if (jogo[i][col] == j)
            {
                n_existe = 0;
                break;
            }
        }
        if (n_existe == 1)
        {
            resultado[n] = j;
            n++;
        }
    }
}
void valoresAusentesGrupo(int jogo[][TAMANHO], int grp, int resultado[],
                          int tam)
{
    int lin, col, i, j, k, n = 0, n_existe;
    lin = ((int)((grp) / 3)) * 3;
    col = (grp - lin) * 3;
    for (k = 1; k < 10; k++)
    {
        n_existe = 1;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (jogo[lin + i][col + j] == k)
                {
                    n_existe = 0;
                }
            }
        }
        if (n_existe == 1)
        {
            resultado[n] = k;
            n++;
        }
    }

}
void valoresPossiveisCelula(int resultado[], int linha[], int coluna[],
                            int grupo[], int tam){
    int k, aux[9], possibilidades = 0;
    inicializaVetor(aux, tam);
    interseccao2Vetores(linha, coluna, aux, tam);
    interseccao2Vetores(aux, grupo, resultado, tam);
}

void valoresNaoPodemCelula(int resultado[], int linha[], int coluna[],
                           int grupo[], int tam){
    int aux[9]={1,2,3,4,5,6,7,8,9};

}

int numPossibilidades(int resultado[],int linha[], int coluna[], int grupo[], int tam){
    int k, possibilidades = 0;
    valoresPossiveisCelula(resultado, linha, coluna, grupo, tam);
    for (k = 0; k < tam; k++)
    {
        if (resultado[k] != 0)
        {
            possibilidades++;
        }
    }
    return possibilidades;
}
int resolvePuzzle(int solucao[][TAMANHO], int tam)
{
    int possibilidades[TAMANHO][TAMANHO];
    int linha[TAMANHO], coluna[TAMANHO], grupo[TAMANHO],
        valoresPossiveis[TAMANHO];
    int i, j, k, possib;
    char recomecar = 0, temLacuna = 0;
    do
    {
        recomecar = 0, temLacuna = 0;
        for (i = 0; i < tam; i++)
        {
            for (j = 0; j < tam; j++)
            {
                if (solucao[i][j] == 0)
                {
                    temLacuna = 1;
                    // avalia as possibilidades
                    inicializa3Vetor(linha, coluna, grupo, tam);
                    inicializaVetor(valoresPossiveis, tam);
                    valoresAusentesLinha(solucao, i, linha, tam);
                    valoresAusentesColuna(solucao, j, coluna, tam);
                    // grupo (vejam a planilha no moodle)
                    k = ((int)(i / 3)) * 3 + ((int)(j / 3));
                    valoresAusentesGrupo(solucao, k, grupo, tam);
                    //
                    possib = numPossibilidades(valoresPossiveis, linha,
                                               coluna, grupo, tam);
                    if (possib == 1)
                    {
                        solucao[i][j] = valoresPossiveis[0]; // Observar que e esperado que
                        // o valor venha na 1a posicao
                        //
                        // esse tipo de quebra do fluxo de execucao deve ser usado com
                        // cautela.
                        recomecar = 1;
                        break;
                    }
                    else
                    {
                        possibilidades[i][j] = possib;

                    }
                }

                else
                {
                    possibilidades[i][j] = 0;
                }

            }
        }
    }
    while (temLacuna);
}

int main()
{
    int jogoInicial[9][9] =
    {
        {9, 4, 0, 1, 0, 2, 0, 5, 8},
        {6, 0, 0, 0, 5, 0, 0, 0, 4},
        {0, 0, 2, 4, 0, 3, 1, 0, 0},
        {0, 2, 0, 0, 0, 0, 0, 6, 0},
        {5, 0, 8, 0, 2, 0, 4, 0, 1},
        {0, 6, 0, 0, 0, 0, 0, 8, 0},
        {0, 0, 1, 6, 0, 8, 7, 0, 0},
        {7, 0, 0, 0, 4, 0, 0, 0, 3},
        {4, 3, 0, 5, 0, 9, 0, 1, 2}
    };
    int solucao[9][9];
    int linha[9], coluna[9], grupo[9], i, j;

    // copia os valores de jogoInicial para solucao
    memcpy(solucao, jogoInicial, sizeof(int) * 81);

    printf("Configuracao inicial do jogo:\n");
    showMat(solucao, 9);
    //
    // chama a funcao que resolve o problema
    resolvePuzzle(solucao, 9);
    showMat(solucao, 9);

    return 0;
}

//-------------------------------------------------------------------
// funcoes auxiliares
void inicializaVetor(int v[], int tam)
{
    int i;
    for (i = 0; i < tam; i++)
    {
        v[i] = 0;
    }
}

void inicializa3Vetor(int v1[], int v2[], int v3[], int tam)
{
    inicializaVetor(v1, tam);
    inicializaVetor(v2, tam);
    inicializaVetor(v3, tam);
}

void showMat(int mat[][TAMANHO], int tam)
{
    int i, j;
    printf("\n +-----------+-----------+-----------+\n");
    for (i = 0; i < tam; i++)
    {
        printf(" | ");
        for (j = 0; j < tam; j++)
        {

            if (mat[i][j] > 0)
            {
                printf(" %1d ", mat[i][j]);
            }
            else
            {
                printf(" _ ");
            }
            if (j == 2 || j == 5 || j == 8)
            {
                printf(" | ");
            }
        }
        if (i % 3 == 2)   // mesma coisa que i%3 == 0
        {
            printf("\n +-----------+-----------+-----------+\n");
        }
        else
            printf("\n");
    }
}
void interseccao2Vetores(int v1[], int v2[], int resultado[], int tam)
{
    int i, j, k = 0;
    for (i = 0; i < tam; i++)
    {
        if(v1[i]!=0)
        {
            for (j = 0; j < tam; j++)
            {
                if (v1[i] == v2[j])
                {
                    resultado[k] = v1[i];
                    k++;
                }
            }
        }
    }
}

