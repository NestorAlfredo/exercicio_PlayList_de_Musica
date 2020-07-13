#include<stdio.h>							   
#include<stdlib.h>
#include<string.h>


int menu();
void Listar();
void InserirInicio(char musica[], char banda[], float tempo);
void InserirFim(char musica[], char banda[], float tempo);

struct NovaMusica {  //Declaração da Struct para o armazenamento dos dados
	char musica[51];
	char banda[21];
	float tempo;
	struct NovaMusica* prox;
} *Head;

int  main() {
	int op, c, loc;
	float tempo;
	char musica[51], banda[21];
	Head = NULL;

	while (1) {
		op = menu();
		switch (op) {
		case 1:
			printf("Nome da Musica\n");
			gets_s(musica);
			//while ((c = getchar()) != '\n' && c != EOF) {} // limpeza do buffer do teclado.
			printf("Banda/Artista\n");
			gets_s(banda);
			//while ((c = getchar()) != '\n' && c != EOF) {} // limpeza do buffer do teclado.
			printf("Tempo de duracao\n");
			scanf_s("%f", &tempo);
			//while ((c = getchar()) != '\n' && c != EOF) {} // limpeza do buffer do teclado.
			printf("\nEscolha onde deseja inserir\n\n");
			printf("1.Inserir no INICIO da Playlist\n");
			printf("2.Inserir no FINAL da Playlist\n");
			printf("\nDigite a opcao desejada: ");
			scanf_s("%d", &loc);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpeza do buffer do teclado.
			if (loc == 1) {
				InserirInicio(musica, banda, tempo); // Chamada da função para inserir no Inicio
				printf("\nInserido com sucesso no INICIO da Playlist\n");
			}
			else {
				if (loc == 2) {
					InserirFim(musica, banda, tempo);; //Chamada para a função inserir no Fim
					printf("\nInserido com sucesso no FINAL da Playlist\n");
				}
				else {
					printf("\nDigitou uma Opcao INVALIVA\n");
				}
			}
			printf("\n");
			system("pause");
			//while ((c = getchar()) != '\n' && c != EOF) {} // limpeza do buffer do teclado.
			break;
		case 2:
			Listar(); //Chamada para a função mostrar Playlist
			break;
		case 3:
			return 0;
		default:
			printf("Invalido\n");
		}
	}
	return 0;
}


int menu() { //Funcao menu
	int op, c;
	system("Cls");
	printf("\n\n======== MENU da Playlist ==========\n");
	printf("\n=  1.Inserir Musica na Playlist    =\n");
	printf("=  2.Mostrar Playlist              =\n");
	printf("=  3.Sair                          =\n\n");
	printf("Digite sua escolha: ");

	scanf_s("%d", &op);
	while ((c = getchar()) != '\n' && c != EOF) {} // sempre limpe o buffer do teclado.

	system("Cls");
	return op;
}

void Listar() //Função para mostrar playlist
{
	char nome[7] = "MUSICA";//criei variaveis para conseguir enquadrar a saida
	char artista[8] = "BANDA";
	char duracao[9] = "DURACAO";

	NovaMusica* ElementoVarredura;
	ElementoVarredura = (struct NovaMusica*)malloc(sizeof(struct NovaMusica));

	ElementoVarredura = Head;
	if (ElementoVarredura == NULL) {
		printf("Nao ha musicas para na playlist\n");
		system("pause");
		return;
	}
	printf("%-50s",nome);	//forma que encontrei para formatar a saida
	printf("%-20s",artista);
	printf("%-10s",duracao);
	printf("\n");
	while (ElementoVarredura != NULL) {   //varrendo toda a estrutura e imprimindo na tela
		printf("%-50s", ElementoVarredura->musica);
		printf("%-20s", ElementoVarredura->banda);
		printf("%.2f ", ElementoVarredura->tempo);
		ElementoVarredura = ElementoVarredura->prox;
		printf("\n");
	}
	printf("\n");

	system("pause");
	return;
}

void InserirInicio(char musica[], char banda[], float tempo) //Função para inserir no inicio
{
	NovaMusica* NovoElemento;
	NovoElemento = (struct NovaMusica*)malloc(sizeof(struct NovaMusica)); //alocando na memoria
	strcpy_s(NovoElemento->musica, musica);
	strcpy_s(NovoElemento->banda, banda);
	NovoElemento->tempo = tempo;

	if (Head == NULL) //verificando se a playlist esta vazia
	{
		Head = NovoElemento;
		Head->prox = NULL; 
	}
	else //inserindo antes do head
	{
		NovoElemento->prox = Head;
		Head = NovoElemento;
	}
}

void InserirFim(char musica[], char banda[], float tempo) //Função para inserir no fim
{
	NovaMusica* NovoElemento;
	NovoElemento = (struct NovaMusica*)malloc(sizeof(struct NovaMusica));	//alocando na memoria
	NovaMusica* ElementoVarredura;
	ElementoVarredura = (struct NovaMusica*)malloc(sizeof(struct NovaMusica));   

	strcpy_s(NovoElemento->musica, musica);
	strcpy_s(NovoElemento->banda, banda);
	NovoElemento->tempo = tempo;

	if (Head == NULL)	//vefificando se a lista esta vazia
	{
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else   //inserindo apos o ultimo elemento encontrado
	{
		ElementoVarredura = Head;
		while (ElementoVarredura->prox != NULL)
			ElementoVarredura = ElementoVarredura->prox;

		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = NULL;
	}
}
