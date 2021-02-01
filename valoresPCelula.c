#include <stdio.h>
#define TAMANHO 9

void inicializaVetor(int v[], int tam);
void inicializa3Vetor(int v1[], int v2[], int v3[], int tam);
void intercecta2Vetores(int v1[],int v2[],int resultado[],int tam);

void valoresAusentesLinha(int jogo[][TAMANHO], int lin, int resultado[],
                          int tam) {
  int i, j, n = 0, n_existe;
  for (j = 1; j < tam + 1; j++) {
    n_existe = 1;
    for (i = 0; i < tam; i++) {
      if (jogo[lin][i] == j) {
        n_existe = 0;
        break;
      }
    }
    if (n_existe == 1) {
      resultado[n] = j;
      n++;
    }
  }
}
void valoresAusentesColuna(int jogo[][TAMANHO], int col, int resultado[],
                           int tam) {
  int i, j, n_existe, n = 0;
  for (j = 1; j < tam + 1; j++) {
    n_existe = 1;
    for (i = 0; i < tam; i++) {
      if (jogo[i][col] == j) {
        n_existe = 0;
        break;
      }
    }
    if (n_existe == 1) {
      resultado[n] = j;
      n++;
    }
  }
}
void valoresAusentesGrupo(int jogo[][TAMANHO], int grp, int resultado[],
                          int tam) {
  int lin, col, i, j, k, n = 0, n_existe;
  lin = ((int)((grp) / 3)) * 3;
  col = (grp - lin) * 3;
  for (k = 1; k < 10; k++) {
    n_existe = 1;
    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        if (jogo[lin + i][col + j] == k) {
          n_existe = 0;
        }
      }
    }
    if (n_existe == 1) {
      resultado[n] = k;
      n++;
    }
  }
}
void numPossibilidades(int jogo[][TAMANHO], int lin, int col, int resultado[],
                       int linha[], int coluna[], int grupo[], int tam){
  int k,aux[9],possibilidades=0;
  inicializaVetor(aux,tam);
  intercecta2Vetores(linha,coluna,aux,tam);
  intercecta2Vetores(aux,grupo,resultado,tam);
  for(k=0;k<tam;k++){
      if(resultado[k]!=0){
        possibilidades++;
      }
  }
  //printf("%d ", possibilidades);
}
void intercecta2Vetores(int v1[],int v2[],int resultado[],int tam){
  int i,j,k=0;
  for(i=0;i<tam;i++){
    for(j=0;j<tam;j++){
      if(v1[i]==v2[j] && v1[i]!= 0){
        resultado[k]=v1[i];
        k++;
      }
    }
  }
}

int main() {
  int solucao[9][9] = {{9, 4, 0, 1, 0, 2, 0, 5, 8}, {6, 0, 0, 0, 5, 0, 0, 0, 4},
                       {0, 0, 2, 4, 0, 3, 1, 0, 0}, {0, 2, 0, 0, 0, 0, 0, 6, 0},
                       {5, 0, 8, 0, 2, 0, 4, 0, 1}, {0, 6, 0, 0, 0, 0, 0, 8, 0},
                       {0, 0, 1, 6, 0, 8, 7, 0, 0}, {7, 0, 0, 0, 4, 0, 0, 0, 3},
                       {4, 3, 0, 5, 0, 9, 0, 1, 2}};
  // int solucao[9][9];
  int possibilidades[TAMANHO][TAMANHO];
  int linha[TAMANHO], coluna[TAMANHO], grupo[TAMANHO],
      valoresPossiveis[TAMANHO];
  int i, j, k,tam=9, possib;

  for (i = 0; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      inicializa3Vetor(linha, coluna, grupo, tam);
      inicializaVetor(valoresPossiveis, tam);
      valoresAusentesLinha(solucao, i, linha, tam);
      valoresAusentesColuna(solucao, j, coluna, tam);
      k = ((int)(i / 3)) * 3 + ((int)(j / 3));
      valoresAusentesGrupo(solucao, k, grupo, tam);
      numPossibilidades(solucao, i, j, valoresPossiveis, linha, coluna, grupo,
                        tam);
    }
  }
}

void inicializaVetor(int v[], int tam) {
  int i;
  for (i = 0; i < tam; i++) {
    v[i] = 0;
  }
}
void inicializa3Vetor(int v1[], int v2[], int v3[], int tam) {
  inicializaVetor(v1, tam);
  inicializaVetor(v2, tam);
  inicializaVetor(v3, tam);
}
