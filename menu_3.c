#include <stdio.h>




// MENU estatisticas


int menu_1(void)
{
	
printf("M�dia de golos por jogo\n");

getch();
}
int menu_2(void)
{

printf("Qual a equipa?\n");

getch();
}
int menu_3(void)
{

printf("Melhor marcador\n");
getch();
}
int main()
{


	int op; // variável de opção para o menu

	system("chcp 1252>null"); //CODEPAGE PT

	// MENU ESTATISTICAS
	do{
		system ("cls");
        printf("+     Estatisticas     +\n\n");
        printf("| 1.M�dia de golos por jogo   |\n");
        printf("| 2.M�dia de idades por equipa |\n");
        printf("| 3.Melhor marcador     |\n");
        printf("| 0.Sair             |\n");
        printf("\n");

        scanf("%d", &op); //op=getchar(); // ou getch(); em windows

         // ou system("cls"); em windows
        switch (op) {
            case 1:
                    menu_1(); // chama fun��o media de golos
                    break;
            case 2:
                    menu_2(); // chama fun��o media de idades
                    break;
            case 3:
                    menu_3(); // chama fun��o melhor marcador
                    break;

            case 0:
                   break;
                   //break; // sai do programa
        }


	} while (op !=0 );//getchar(); //system("pause");


}
