#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca de Strings
//fun��es:
int registro() //Fun��o responsaveu por cadastrar usu�rios no Sistema
{
	//Inicio cria��o de variaveis/Strings
	char arquivo[11];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final de cria��o de variaveis
	
	printf ("Digite o CPF a ser cadastrado:"); //Coletando informa��es de usu�rios
	scanf ("%s", cpf); //%s de string
	
	strcpy (arquivo, cpf);//Copiar valor de Strings
	
	FILE *file; // Cria o Arquivo no Banco de Dados
	file = fopen(arquivo, "w"); // "w" significa escrever
	fprintf (file, cpf);// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, ",");// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	printf ("Digite o Nome a ser cadastrado: "); //Coletando informa��es de usu�rios
	scanf ("%s", nome);//%s de string
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, nome);// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, ",");// Salvar Valor
	fclose (file);// Fechar Arquivo
		
	printf ("Digite o Sobrenome a ser cadastrado: "); //Coletando informa��es de usu�rios
	scanf ("%s", sobrenome);//%s de string
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, sobrenome);// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, ",");// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	printf ("Digite o Cargo a ser cadastrado: "); //Coletando informa��es de usu�rios
	scanf ("%s", cargo);//%s de string
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, cargo);// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	system ("pause");//manter na tela para conseguir ler
}	

int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definindo Linguagem
	
	//Inicio cria��o de variaveis/Strings
	char cpf[11];
	char conteudo[150];
	//Final de cria��o de variaveis
	
	printf ("Digite o CPF a ser consultado: ");//Coletando informa��es de usu�rios
	scanf ("%s",cpf);//%s de string
	
	FILE *file;// Chamar ao arquivo file
	file = fopen(cpf, "r");// Abrir arquivo
	
	if(file == NULL)// Valida��o caso o arquivo n�o exista
	{
		printf ("N�o foi possivel abrir o arquivo, n�o localizado! \n");// Mensagem de n�o localizado
	}
	
	while(fgets(conteudo, 150, file) != NULL)// La�o para imprimir informa��es do arquivo
	{
		printf ("\nEssas s�o as informa��es do usu�rio: ");
		printf ("%s", conteudo);
		printf("\n\n");
	}	
	
	system ("pause");// manter na tela para usuario ler
}

int deletar()
{
	//Inicio cria��o de variaveis/Strings
	char cpf[11];
	//Final de cria��o de variaveis
	
	printf ("Digite o CPF a ser deletado: ");//Coletando informa��es de usu�rios
	scanf ("%s", cpf);//%s de string
	
	remove(cpf);// Fun��o para remover o arquivo cpf digitado
	
	FILE *file;// Chamar ao arquivo file
	file = fopen (cpf, "r");// Abrir arquivo para consulta "r"
	
	if (file == NULL)// Valida��o se existe o arquivo
	{
		printf ("O usu�rio n�o se encontra no sistema!.\n");// Mensagem de retorno
		system ("pause");// manter na tela para usuario ler
	}
}

//Fun��o Principal
int main()
{
	int opcao=0;//Variaveis
	int laco=1;
	
	for(laco=1; laco=1; )//La�o de Repeti��o do Menu
	{
		
		system ("cls");//Limpar a Tela
		
		setlocale (LC_ALL, "Portuguese"); //Definindo Linguagem
	
		printf ("##### CART�RIO DA EBAC #####\n\n");//Inicio do Menu
		printf ("Escolha a op��o desejada no Menu:\n\n");
		printf ("\t1 - Registrar Nomes\n");
		printf ("\t2 - Consutar Nomes\n");
		printf ("\t3 - Deletar Nomes\n");
		printf ("\t4 - Sair do Sistema\n\n");
		printf ("Op��o:");
		
		scanf ("%d", &opcao);//Armazenamento de Escolha do Menu
		
		system("cls");//Limpar a Tela
		
		switch (opcao)//Switch Case para Escolhas do Menu
		{
			case 1:
				registro();
				break;
		
			case 2: 
				consulta();
				break;
		
			case 3:
				deletar();
				break;
			
			case 4:
				printf ("Obrigado por utilizar nosso Sistema!\n");
				return 0;
				break;
					
			default:
				printf ("Essa opc�o n�o est� dispon�vel\n");
				system ("pause");
				break;
		}
	   	//Fim da Sele��o		 
	}
}

