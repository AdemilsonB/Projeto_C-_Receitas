/*
Ademilson Alves Bertolin de Lima     		Email:ademilsonbertolinnn@gmail.com
Unidade Osorio
*/

//termino da prova: 12:00

#include <stdio.h>
#include <string.h>
#define N 100

typedef struct {
    char nome [40], ingPri[40];
    int tempo;
} Receita;

int cont= -1;
Receita r1[N];


#FUN��ES DO PROGRAMA
void addReceita(char nome[40], char ingPri[40], int tempo);
int calcMediaTempo(char ingPri[40]);
void mostraReceitaIngrediente(char ingPri[40]);
int buscaReceita(char nome[40]);
void ordenaReceitas();
void mostraReceitas();

int Menu(){
int op;

	do
	{
		printf("\n # CADASTRO DE RECEITAS #"); 
		printf("\n 1.Inserir receita"); 
		printf("\n 2.Calcular o tempo medio de preparo com um ingrediente");
		printf("\n 3.Listar receita com um ingrediente"); 
		printf("\n 4.Buscar receita pelo nome"); 
		printf("\n 5.Ordenar receitas"); 
		printf("\n 6.Mostrar receitas"); 
		printf("\n 7.sair"); 
		printf("\n\n Opcao:");
		scanf("%d", &op);
		fflush(stdin);
    } while (op<1 || op>7);
    
 return op;   
}

int main(){
	int op, i,result,encontrado;
	char nome[40];
	char ingPri[40];
	int tempo;
    
    do
    {
    
	op = Menu();
		
        switch (op) 
		{
			
            case 1:	
            if(cont<N -1){
    
            	printf("\n Nome da receita: ");
            	scanf("%s", nome);
            	fflush(stdin);
            	
            	printf("\n Ingrediente principal: ");
            	scanf("%s", ingPri);
            	fflush(stdin);
            	
            	printf("\n Tempo de preparo(min): ");
            	scanf("%d", &tempo);
            	fflush(stdin);
            	
                addReceita(nome, ingPri, tempo);
            }else{
                   printf("\n\n A lista esta cheia!!! \n\n");	
            	 }
                break;

            case 2:
            
            	printf("\n Calcular o tempo baseado no ingrediente principal: ");
            	scanf("%s", ingPri);
            	fflush(stdin);
            	calcMediaTempo(ingPri);
            	break;
            	
            	
            case 3:
            	
            	printf("\n Listar receitas que possuem o mesmo ingrediente principal: ");
            	scanf("%s", &ingPri);
            	fflush(stdin);
            	mostraReceitaIngrediente(ingPri);
            
				break;
            	
            case 4:
            	
            	printf("\n Digite o nome da receita que deseja buscar: ");
            	scanf("%s", &nome);
            	fflush(stdin);
            	encontrado=0;
            	
            	for(i=0;i<N;i++)
				  {
					result = strcmp(nome, r1[i].nome);
					if (result == 0)
						{
						  encontrado++;
						  printf("\nIndice: %d", i);
						  printf("  Nome: %s", r1[i].nome);
						  printf("  ingrediente: %s", r1[i].ingPri);
						  printf("  Tempo: %d\n", r1[i].tempo);
						}
				  }
				  
				  
				  if (encontrado < 1)
				  	{
					  printf(" Que pena! Nao ha nenhuma receita cadastrada com o nome: %s !!! \n",nome);	
					}
				  
            /* buscaReceita(nome);
            	if(encontrado > 0){
            		printf("\n Receita Encontrada : \n ");	
					printf("\nIndice: %d", i);
					printf("  Nome: %s", r1[i].nome);
					printf("  ingrediente: %s", r1[i].ingPri);
					printf("  Tempo: %d\n", r1[i].tempo);
				  } */
				  
            	break;
            
			case 5:
				 ordenaReceitas();
				 mostraReceitas();
				break;
				
			case 6:
				 mostraReceitas();
				 break;
        }
    } while (op!=7);
    
    return 0;
}



void addReceita(char nome[40], char ingPri[40], int tempo) //func1
{
	cont++;
	strcpy(r1[cont].nome, nome);
	strcpy(r1[cont].ingPri, ingPri);
	r1[cont].tempo = tempo;
}



int calcMediaTempo(char ingPri[40]) //func2
{
	int i, result, soma=0, fat=0,media;
	for(i=0;i<N;i++)
	{
		result = strcmp(ingPri, r1[i].ingPri);
		if(result == 0)
		{
			soma+=r1[i].tempo;
			fat++;
		}
	}
	media = (soma/fat);
	printf("\n Ingrediente principal: %s",ingPri);
	printf("\n Tempo medio das receitas que possuem esse ingrediente: %d\n",media);
}
	
	void mostraReceitaIngrediente(char ingPri[40])
	{
		
		int i, result ,encontrado=0;
            	
        for(i=0;i<N;i++)
            {
            	result = strcmp(ingPri, r1[i].ingPri);
            		
				if(result==0)
				  {
					printf("\nIndice: %d", i);
					printf("  Nome: %s", r1[i].nome);
					printf("  Ing. Principal: %s", r1[i].ingPri);
					printf("  Tempo: %d\n", r1[i].tempo);
					encontrado++;
				  }					
            }
        if(encontrado==0)
		  printf("\n Nenhuma receita com este ingrediente foi encontrada!!!\n");
	}
	

int buscaReceita(char nome[40]) //func4
{
	int i,encontrado;
	int teste;
	
	for(i=0;i<N;i++)
	{
		teste = strcmp(nome, r1[i].nome);
		if (teste == 0)
		{
		 encontrado = i;
		}
	}
	return encontrado;
}

void ordenaReceitas( )  //func5
{
    int i, j, aux2;
	char aux[40],aux1[40];

    for (i= 0; i< N; i++) 
	{
        for (j=i+1; j< N; ++j) 
		{
            if(r1[i].tempo > r1[j].tempo) 
			{				
				strcpy(aux, r1[i].nome);
				strcpy(aux1, r1[i].ingPri);
                aux2 = r1[i].tempo;
                
                
                strcpy(r1[i].nome, r1[j].nome);
				strcpy(r1[i].ingPri, r1[j].ingPri);
                r1[i].tempo = r1[j].tempo;
                
				    
                strcpy(r1[j].nome, aux);
				strcpy(r1[j].ingPri, aux1);
                r1[j].tempo = aux2;
                
            }
        }
    }
}



void mostraReceitas() //func6
{
	int i;
	
	for(i=0;i<N;i++)
	{
		
		if(r1[i].tempo != 0)
		{
		  printf("Indice: %d", i);
		  printf("  Nome: %s", r1[i].nome);
		  printf("  Ing principal: %s", r1[i].ingPri);
		  printf("  Tempo: %d\n", r1[i].tempo);
		}
	}
}

/*
  1. A estrutura de dados utilizada e uma lista,  
  pois no caso desta questao nao importa a ordem em que os dados entram ou saem,
  ja que a qualquer momente o usuario pode ordenar as receitas, o que tira o motivo de
  utilizar uma pilha ou fila.

2. O metodo de busca utilizado e a busca sequencial, pois ha a posibilidade dos dados
nao estarem organizados no momento queo usuario fizer a pesquisa.

3. Foi utilizado o bubble sort, devido a sua simplicidade de implementacao e
 ao prazo estipulado para a realizacao deste trabalho.


4. Depende da dificuldade do programa. Se for algo que seja mais complicado de fazer sem recursividade
 (como a Sequ�ncia de Fibonacci, e outros teoremas matematicos mais complexos), eu escolheria usar recursividade.
 Caso seja algo mais simples e que tenha um prazo menor, implementaria de forma n�o recursiva.
 
*/
