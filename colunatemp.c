#include <stdio.h>
#define TAMANHO 9

void showVet(int vetor[], int tam) {
  int i;
  for (i = 0; i < tam; i++) {
    printf(" %1d ", vetor[i]);
  }
}
void showMat(int mat[][TAMANHO], int tam) {
  int i, j;
  printf("\n +-----------+-----------+-----------+\n");
  for (i = 0; i < tam; i++) {
    printf(" | ");
    for (j = 0; j < tam; j++) {
      if (mat[i][j] > 0) {
        printf(" %1d ", mat[i][j]);
      } else {
        printf(" _ ");
      }
      if (j == 2 || j == 5 || j == 8) {
        printf(" | ");
      }
    }
    if (i % 3 == 2) { // mesma coisa que i%3 == 0
      printf("\n +-----------+-----------+-----------+\n");
    } else
      printf("\n");
  }
}

void valoresAusentesGrupo(int jogo[][TAMANHO], int grp, int resultado[],
                          int tam) {
  int lin, col, i, j, k, n, n_existe;
  lin = ((int)((grp) / 3)) * 3;
  col = (grp - lin) * 3;
  for (k = 1; k < 10; k++) {
    n_existe = 1;
    for (i = lin; i < 3; i++) {
      for (j = col; j < 3; j++) {
        if (jogo[i][j] == k) {
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

int main() {
  int i, j, k,
      tam =9, grupo, resultado[9] = {0},
      jogo[9][9] = {{9, 4, 0, 1, 0, 2, 0, 5, 8}, {6, 0, 0, 0, 5, 0, 0, 0, 4},
                    {0, 0, 2, 4, 0, 3, 1, 0, 0}, {0, 2, 0, 0, 0, 0, 0, 6, 0},
                    {5, 0, 8, 0, 2, 0, 4, 0, 1}, {0, 6, 0, 0, 0, 0, 0, 8, 0},
                    {0, 0, 1, 6, 0, 8, 7, 0, 0}, {7, 0, 0, 0, 4, 0, 0, 0, 3},
                    {4, 3, 0, 5, 0, 9, 0, 1, 2}};
  for (i = 0; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      k = ((int)(i / 3)) * 3 + ((int)(j / 3));
      valoresAusentesGrupo(jogo, k, resultado, tam);
      showVet(resultado, tam);
    }
  }
}
