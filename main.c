#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct ordena{

    int qnt_change;
    char vet[6000];

}ordena;


int compare(const void *str1, const void *str2)
{
    int vetcompare;

    struct ordena *sstr1 = (struct ordena *)str1;
    struct ordena *sstr2 = (struct ordena *)str2;

    vetcompare = strcmp(sstr1->vet, sstr2->vet);
    if (sstr1->qnt_change == sstr2->qnt_change)
    {
        return vetcompare;
    }
    else
    {
        if(sstr1->qnt_change < sstr2->qnt_change)
        {
        	return -1;
        }
        else
        {
        	return 1;
        }
    }
}

int calc_minimo(int above, int diag, int left)
{
    int aux = 0;

    aux = above;
    if(diag <= aux)
    {
    	if(diag <= left)
    	{
    		return diag;
    	}
    	else if(diag > left)
    	{
    		return left;
    	}
        
    }
    if(left <= aux)
    {
    	if(left <= diag)
    	{
    		return left;
    	}
    	else if(left > diag)
    	{
    		return diag;
    	}
        
    }
return aux;
}

int main()
{
    int i = 0;
    int j = 0;
    int n = 0;
    int m = 0;
    int k = 0;
    int change = 0;
    int exit = 0;
	int tam = 6002;
	int comparation = 0;
	int size_pattern = 0;
	int size_word = 0;
	int entrance_dic = 0;
	int above = 0;
	int diag = 0;
	int left = 0;
	int minimo = 0;
	int result = 0;
	int count_change = 0;
	char *vet_pattern;
	char *vet_word;
	int **matrix;

	//struct ordena vetOrdena[300];
	struct ordena *vetOrdena;

	vetOrdena = (ordena*)calloc(tam,sizeof(ordena));

	vet_pattern = (char*)calloc(tam,sizeof(char));
	vet_word = (char*)calloc(tam,sizeof(char));

	scanf("%d",&entrance_dic);
	scanf("%d",&change);
	scanf("%s",vet_pattern);

	size_pattern = strlen(vet_pattern)+1; //+1 para colocar o 0

    //Alocacao da Matriz (nxm) - STEP 1
	matrix = (int**)calloc(tam,sizeof(int*)); //Linha
	for(i = 0; i < tam; i++)
	{
		matrix[i] = (int*)calloc(tam,sizeof(int)); //Coluna
	}

	//Enquanto nao acabar as comparacoes faca:
	while(exit != entrance_dic)
	{
        //Levenshtein Distance
        scanf("%s",vet_word);
        size_word = strlen(vet_word)+1;

        //STEP 2
        matrix[0][0] = 0;
        for(i = 1; i < size_pattern; i++)
        {
            matrix[i][0] = i;
        }

        for(j = 1; j < size_word; j++)
        {
            matrix[0][j] = j;
        }

        //STEP 3 e STEP 4
        for(i = 1; i < size_pattern; i++)
        {
            for(j = 1; j <  size_word; j++)
            {

                //STEP 5
                if(vet_pattern[i-1] == vet_word[j-1])
                {
                    comparation = 0;
                }
                else
                {
                    comparation = 1;
                }

                //STEP 6
                above = matrix[i][j-1];
                diag = matrix[i-1][j-1];
                left = matrix[i-1][j];

                minimo = calc_minimo(above+1,diag+comparation,left+1);
                matrix[i][j] = minimo;
            }
        }

        //STEP 7
        n = size_pattern;
        m = size_word;
        result = matrix[n-1][m-1];

        if(result <= change)
        {
            count_change++;
            vetOrdena[k].qnt_change = result;
            strcpy(vetOrdena[k].vet,vet_word);
            k++;
        }

        exit++;
	}

	qsort(vetOrdena,k, sizeof(struct ordena), compare);
	for(i = 0; i < k; i++)
    {
        printf("%s\n",vetOrdena[i].vet);
        //printf("vetOrdena[%d].qnt_change = %d\n",i,vetOrdena[i].qnt_change);
    }


    for(i = 0; i < tam; i++)
    {
    	free(matrix[i]);
    }
    free(matrix);

    free(vet_pattern);
    free(vet_word);   
    free(vetOrdena);
}
