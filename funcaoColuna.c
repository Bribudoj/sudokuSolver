#include <stdio.h>
#define TAMANHO 0
int main(void){
	  int i,j,n_existe,n=0,jogo[9][TAMANHO]={1,0,3,0,5,0,7,8,0},resultado[9]={0};
	  for(j=1;j<10;j++){
			n_existe=1;
	    for(i=0;i<9;i++){
	    	if(jogo[i][0]==j){
					n_existe=0;
					break;
				}
			}
			if(n_existe==1){
				resultado[n]=j;
				n++;
			}
	  }
		for(i=0;i<9;i++)
			printf("%d ",b[i]);
}
void valoresAusentesColuna(int jogo[][TAMANHO], int col, int resultado[],
													 int tam);
