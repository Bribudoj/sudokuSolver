#include <stdio.h>

void printaVetor(int v[],int tam){
    int i;
    for (i = 0; i < tam; i++) {
        printf("%d",v[i]);
    }
    printf("\n---------------------\n");
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

/*void interseccao2Vetores(int v1[], int v2[], int resultado[], int tam) {
  int i, j, k = 0;
  for (i = 0; i < tam; i++) {
    if(v1[i]!= 0){
        for (j = 0; j < tam; j++) {
            if (v1[i] == v2[j]) {
                resultado[k] = v1[i];
                k++;
            }
        }
    }
  }
}*/
void interseccao2Vetores(int v1[], int v2[], int resultado[], int tam) {
  int i, j, k = 0;
  for (i = 0; i < tam; i++) {
    for (j = 0; j < tam; j++) {
      if (v1[i] == v2[j] && v1[i] != 0) {
        resultado[k] = v1[i];
        k++;
      }
    }
  }
}

int main(){
    int k,i,linha[9]={1,2,3,0,0,0,0,0,0,0,0,0},coluna[9]={1,2,3,4,5,6,0,0,0},grupo[9]={1,2,3,0,0,0,7,8,0}, aux[9], possibilidades = 0,tam=9,resultado[9];

    inicializaVetor(aux,tam);
    inicializaVetor(resultado,tam);
    interseccao2Vetores(linha, coluna, aux, tam);
    interseccao2Vetores(aux, grupo, resultado, tam);
    printaVetor(linha,tam);
    printaVetor(coluna,tam);
    printaVetor(grupo,tam);
    printaVetor(aux,tam);
    printaVetor(resultado,tam);
    for (k = 0; k < tam; k++) {
        if (resultado[k] != 0) {
            possibilidades++;
        }
    }
    printf("%d",possibilidades);

}
