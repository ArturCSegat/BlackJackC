// Online C compiler to run C program online
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// srand(time(NULL));

struct Player{ // define o usuario com suas caracteristicas, duas cartas inicias, um total e uma possivel adicional

    int carta1;
    int carta2;
    int total;
    int carta3;
};

struct Player getPlayerInitial(){ // da a um usiario suas caracteristicas basicas

    srand(time(NULL));

    struct Player p1; // o usuario a ser gerado

    int carta1, carta2;

    do{
        carta1 = rand() % 11; // garante que as cartas sejam um numero aleatorio entre 0 e 11 diferente de 0
    }while(carta1 == 0);

     do{
        carta2 = rand() % 11;
    }while(carta2 == 0);

    p1.carta1 = carta1;
    p1.carta2 = carta2;

    p1.total = p1.carta1 + p1.carta2;


    return p1;
}

struct Player playDealer(struct Player dealer){
    sleep(1);
    printf("\nA segunda carta do dealer era um %d para um total de %d\n", dealer.carta2, dealer.total);

    while(dealer.total < 17){
        int c3;

        do{
            c3 = rand() % 11;
        }while(c3 == 0);

        dealer.carta3 = c3;
        sleep(1);
        printf("\no dealer puxou um %d, seu total agora e %d", c3, dealer.total + c3);

        dealer.total = dealer.total + c3;
    }

    sleep(2);

    return dealer;

}

int main() {

   printf("Bem vindo ao 21, o objetivo do jogo e chegar o mais proximo possivel de 21 pontos sem passar\n");
   printf("Voce pode pedir quantas cartas quiser\n");
   printf("O dealer ira pedir cartas ate 17 mas ele pode passar.\n");
   printf("Tenha mais pontos que o dealer ou 21 para vencer, passar de 21 resultara em derrota instantanea, boa sorte!\n");
   printf("\n");

   sleep(1);

    int temp = 0;
    int jogando = 1;

   while(jogando == 1){
        struct Player p1 = getPlayerInitial(); // inicia o avatar do usuario como p1
        struct Player dealer = getPlayerInitial(); // inicia o dealer


        printf("As sua primeira carta e %d e a sua segunda carta e %d para um total de %d"
        ,p1.carta1, p1.carta2, p1.total);

        sleep(2);

        printf("\n");

        printf("\nO dealer tem %d mais uma carta secreta\n", dealer.carta1);

        sleep(2);

        do{
            printf("\nVoce deseja uma carta adicional? 1 = sim, 0 = nao: ");
            scanf("%d", &temp);

            if (temp == 1){

                srand(time(NULL));

                int c3;

                do{
                    c3 = rand() % 11;
                }while(c3 == 0);

                p1.carta3 = c3;
                p1.total = p1.total + c3;

                if (p1.total > 21){
                    printf("\nSua carta adicional e %d e o seu novo total e %d, isso excede 21, logo, voce perdeu",
                    p1.carta3, p1.total);

                    temp = 0;
                    jogando = 0;
                    sleep(1);
                    break;
                }

                else if (p1.total == 21){

                    printf("\nSua carta adicional e %d e o seu novo total e %d, parabens, voce ganhou",
                    p1.carta3, p1.total);

                    temp = 0;
                    jogando = 0;
                    sleep(1);
                    break;
                }

                printf("\nSua carta adicional e %d e o seu novo total e %d", p1.carta3, p1.total);

            }

            else{
                temp = 0;
            }

        }while(temp == 1);

        if(jogando ==1){
            printf("\n");
            printf("Sua vez acabou com um total de %d", p1.total);
            sleep(2);
            printf("\nAgora e vez do dealer, que ira pedir cartas extras ate atingir 17(regra de cassino)\n");
            sleep(2);

            dealer = playDealer(dealer);

            if(dealer.total > 21){
                printf("\nO dealer estourou com um total de %d, voce ganhou\n", dealer.total);

            }
            else if(dealer.total == 21 && p1.total != 21){
                printf("\nO dealer atingiu 21, voce perdeu\n");
            }
            else{
                if(dealer.total > p1.total){
                    printf("\nO total do dealer(%d) e maior que o seu(%d), voce perdeu", dealer.total, p1.total);
                }
                else if(p1.total > dealer.total){
                    printf("\nO seu total(%d) e maior que o do dealer(%d), voce ganhou", p1.total, dealer.total);
                }

                else{
                    printf("\nO total do dealer(%d) e igual ao seu, voce ganha por vantagem",dealer.total);
                }
            }

        }


        printf("\n o jogo acabou, obrigado por jogar =)\n");
        printf("Deseja jogar novamente? 1 = sim 0 = nao: ");
        scanf("%d", &jogando);

        if(jogando == 1){
            system("cls");
        }

    }



    return 0;
}
