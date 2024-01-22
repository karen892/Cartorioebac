#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em m�moria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca resp�nsavel por cuidar da string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema 
{
	// inicio da cria��o da vari�veis/string = conjunto de vari�veis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o da vari�veis/string 
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s referen-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" de atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",nome); //%S refere-se a string
	
	file = fopen(arquivo, "a");  
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //"a" de atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",sobrenome); //%S refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�io
	scanf("%s",cargo); //%S refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); //pausa de sistema
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	
	if(file==NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	char cpf[40];
	
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s" ,cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf ,"r");
	fclose(file);
	
	if(file == NULL);
	{
		printf("usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
	
	
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	 system("cls"); //responsavel por limpar a tela
	
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	  printf("###cartorio da ebac ###\n\n"); //inicio do menu
	  printf("Escolha a op��o desejada do menu\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n"); 
	  printf("opcao: "); //fim do menu
	
	scanf("%d" , &opcao); //armazenando a escolha do usuario
	
	system("cls");
	
	
	switch(opcao) //inicio da selecao do menu
	{
		case 1:
		registro(); //chamada de fun��es 
		break;
		
		case 2:
		consulta(); //chamada de fun��es 
		break;
		
		case 3:
		deletar(); //chamda de fun��es 
		break;
		
		default:
		printf("Essa opcao nao esta disponivel!\n");
		system("pause");
		break;	//fim da selecao
			
		
	}
	

  }
}
