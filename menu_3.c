#include <stdio.h>

// função que calcula a media de golos por jogo
int medgolos (void)
{
    int a,b,numgolos=0, numjogos=0,i,aux=0;
    float media;
    for (i=0;i<R;i++)
        {
            if  (result[i].ativo==1)
              {
              a=result[i].golos_a;
              b=result[i].golos_b;
              numgolos=a+b;
              aux=aux+numgolos;
              numjogos++;
                }
         }
    media=(float)aux/numjogos; // "cast" do valor ((float)aux/numjogos), transforma inteiro em float

    printf("\n\-> Numero de jogos realizados: %d",numjogos);
    printf("\n\-> Total de golos marcados: %d",aux);
    printf("\n\-> Media de golos marcados no total de jogos realizados: %.2f",media);
    printf("\n\nQualquer tecla para continuar...");
    getchar();
    getchar();

}

// função menu_3
int menu_3()
{
	int op; // variavel de opção para o menu
	//system("chcp 1252>null"); //CODEPAGE PT
	// MENU ESTATISTICAS
	do{
		system ("clear");
        printf("+         ESTATISTICAS         +\n\n");
        printf("| 1.Media de golos por jogo    |\n");
        printf("| 2.Media de idades por equipa |\n");
        printf("| 3.Melhor marcador            |\n");
        printf("| 0.Sair                       |\n");
        printf("\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                    medgolos(); // chama função media de golos
                    break;
            case 2:
                    // medidades(); // chama função media de idades
                    break;
            case 3:
                    // melhor(); // chama função melhor marcadord
                    break;

            case 0:
                   return;
                   // sai do menu_3
        }


	} while (op !=0 );


}
