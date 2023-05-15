#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca de Strings
//funções:
int registro() //Função responsaveu por cadastrar usuários no Sistema
{
	//Inicio criação de variaveis/Strings
	char arquivo[11];
	char cpf[11];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final de criação de variaveis
	
	printf ("Digite o CPF a ser cadastrado:"); //Coletando informações de usuários
	scanf ("%s", cpf); //%s de string
	
	strcpy (arquivo, cpf);//Copiar valor de Strings
	
	FILE *file; // Cria o Arquivo no Banco de Dados
	file = fopen(arquivo, "w"); // "w" significa escrever
	fprintf (file, cpf);// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, ",");// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	printf ("Digite o Nome a ser cadastrado: "); //Coletando informações de usuários
	scanf ("%s", nome);//%s de string
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, nome);// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, ",");// Salvar Valor
	fclose (file);// Fechar Arquivo
		
	printf ("Digite o Sobrenome a ser cadastrado: "); //Coletando informações de usuários
	scanf ("%s", sobrenome);//%s de string
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, sobrenome);// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, ",");// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	printf ("Digite o Cargo a ser cadastrado: "); //Coletando informações de usuários
	scanf ("%s", cargo);//%s de string
	
	file = fopen(arquivo, "a");// Abrir arquivo
	fprintf (file, cargo);// Salvar Valor
	fclose (file);// Fechar Arquivo
	
	system ("pause");//manter na tela para conseguir ler
}	

int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //Definindo Linguagem
	
	//Inicio criação de variaveis/Strings
	char cpf[11];
	char conteudo[150];
	//Final de criação de variaveis
	
	printf ("Digite o CPF a ser consultado: ");//Coletando informações de usuários
	scanf ("%s",cpf);//%s de string
	
	FILE *file;// Chamar ao arquivo file
	file = fopen(cpf, "r");// Abrir arquivo
	
	if(file == NULL)// Validação caso o arquivo não exista
	{
		printf ("Não foi possivel abrir o arquivo, não localizado! \n");// Mensagem de não localizado
	}
	
	while(fgets(conteudo, 150, file) != NULL)// Laço para imprimir informações do arquivo
	{
		printf ("\nEssas são as informações do usuário: ");
		printf ("%s", conteudo);
		printf("\n\n");
	}	
	
	system ("pause");// manter na tela para usuario ler
}

int deletar()
{
	//Inicio criação de variaveis/Strings
	char cpf[11];
	//Final de criação de variaveis
	
	printf ("Digite o CPF a ser deletado: ");//Coletando informações de usuários
	scanf ("%s", cpf);//%s de string
	
	remove(cpf);// Função para remover o arquivo cpf digitado
	
	FILE *file;// Chamar ao arquivo file
	file = fopen (cpf, "r");// Abrir arquivo para consulta "r"
	
	if (file == NULL)// Validação se existe o arquivo
	{
		printf ("O usuário não se encontra no sistema!.\n");// Mensagem de retorno
		system ("pause");// manter na tela para usuario ler
	}
}

//Função Principal
int main()
{
	int opcao=0;//Variaveis
	int laco=1;
	
	for(laco=1; laco=1; )//Laço de Repetição do Menu
	{
		
		system ("cls");//Limpar a Tela
		
		setlocale (LC_ALL, "Portuguese"); //Definindo Linguagem
	
		printf ("##### CARTÓRIO DA EBAC #####\n\n");//Inicio do Menu
		printf ("Escolha a opção desejada no Menu:\n\n");
		printf ("\t1 - Registrar Nomes\n");
		printf ("\t2 - Consutar Nomes\n");
		printf ("\t3 - Deletar Nomes\n");
		printf ("\t4 - Sair do Sistema\n\n");
		printf ("Opção:");
		
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
				printf ("Essa opcão não está disponível\n");
				system ("pause");
				break;
		}
	   	//Fim da Seleção		 
	}
}

