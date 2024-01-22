#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em mémoria 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca respónsavel por cuidar da string

int registro() //Função responsável por cadastrar os usuários no sistema 
{
	// inicio da criação da variáveis/string = conjunto de variáveis
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação da variáveis/string 
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s referen-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // criar o arquivo
	file = fopen(arquivo, "w"); //criar o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); // fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" de atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",nome); //%S refere-se a string
	
	file = fopen(arquivo, "a");  
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //"a" de atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",sobrenome); //%S refere-se a string
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuáio
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
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n");
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
		printf("usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
	
	
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	 system("cls"); //responsavel por limpar a tela
	
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	  printf("###cartorio da ebac ###\n\n"); //inicio do menu
	  printf("Escolha a opção desejada do menu\n\n");
	  printf("\t1 - Registrar nomes\n");
	  printf("\t2 - Consultar nomes\n");
	  printf("\t3 - Deletar nomes\n"); 
	  printf("opcao: "); //fim do menu
	
	scanf("%d" , &opcao); //armazenando a escolha do usuario
	
	system("cls");
	
	
	switch(opcao) //inicio da selecao do menu
	{
		case 1:
		registro(); //chamada de funções 
		break;
		
		case 2:
		consulta(); //chamada de funções 
		break;
		
		case 3:
		deletar(); //chamda de funções 
		break;
		
		default:
		printf("Essa opcao nao esta disponivel!\n");
		system("pause");
		break;	//fim da selecao
			
		
	}
	

  }
}
