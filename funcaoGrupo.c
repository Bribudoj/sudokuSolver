#include <stdio.h>
#define TAMANHO 9

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

int main(void) {
  int i, j, k, m, n, z, pos_lin=0, pos_col=0, lin, col, grupo, tam = 9,
      resultado[TAMANHO][TAMANHO] = {0}, n_existe,
      jogo[9][9] = {0};

  for (i = 0; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      z = ((int)(i / 3)) * 3 + ((int)(j / 3));
      lin = ((int)((z) / 3)) * 3;
      col = ((z) - lin) * 3;
      for (k = 1; k < 10; k++) {
        n_existe = 1;
        for (m = 0; m < 3; m++) {
          for (n = 0; n < 3; n++) {
            if (jogo[lin + m][col + n] == k) {
              n_existe = 0;
            }
          }
        }
        if (n_existe == 1) {
          resultado[pos_lin][pos_col] = k;
					pos_lin++;
					if(pos_lin==8){
						pos_lin=0;
						pos_col++;
					}

        }
      }
    }
  }
  showMat(resultado, 9);
}
