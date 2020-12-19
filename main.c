#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char feld[3][3];
const char p1 = 'x';
const char p2 = 'o';
int zug = 1;
int counter = 1;
int gameover = 0;

int main()
{

    for(int i=0; i<3; i++){                             //Spielfeld generieren
        for(int p=0; p<3; p++){
            feld[i][p] = '*';
        }
    }

    while(!gameover){
        int z;
        int s;

        printf("Runde %d\n", counter);

        for(int i=0; i<3; i++){                         //Spielfeld ausgeben
            for(int p=0; p<3; p++){
                printf("%c ", feld[i][p]);
            }
        printf("\n");
        }

        switch(zug){
            case 1:
            printf("Spieler 1 an der Reihe \n");           //Zug Spieler 1
            printf("Zeile: \n");
            scanf("%d", &z);
            printf("Spalte: \n");
            scanf("%d", &s);

            if(z <1 || z>3 || s<1 || s>3){
                printf("Bitte ein leeres Feld angeben\n");
                continue;
            }
            if(feld[z][s]=='x' || feld[z][s]=='o'){         //Überprüfe ob Feld frei ist. Falls nicht, überspringe den aktuellen Schleifendurchlauf
                printf("Bitte ein leeres Feld angeben\n");
                zug = 1;
                continue;
                }
            else{
            feld[z-1][s-1] = p1;

            if (istReihe()){
                for(int i=0; i<3; i++){                         //Spielfeld ausgeben
                    for(int p=0; p<3; p++){
                    printf("%c ", feld[i][p]);
                    }
                printf("\n");
                }
                printf("Spieler 1 gewinnt!\n");
                gameover = 1;
                break;
            }

            zug = 2;

            }

            case 2:
            for(int i=0; i<3; i++){                      //Spielfeld ausgeben
                for(int p=0; p<3; p++){
                printf("%c ", feld[i][p]);
                }
            printf("\n");
            }

            printf("Spieler 2 an der Reihe \n");        //Zug Spieler 2
            printf("Zeile: \n");
            scanf("%d", &z);
            printf("Spalte: \n");
            scanf("%d", &s);


            if(z <1 || z>3 || s<1 || s>3){
            printf("Bitte ein leeres Feld angeben\n");
                continue;
            }
            if(feld[z][s]=='x' || feld[z][s]=='o'){
                printf("Bitte ein leeres Feld angeben\n");
                zug = 2;
                continue;
            }

            else{
            feld[z-1][s-1] = p2;

            if (istReihe()){
            for(int i=0; i<3; i++){                         //Spielfeld ausgeben
                for(int p=0; p<3; p++){
                    printf("%c ", feld[i][p]);
                }
                printf("\n");
            }
                printf("Spieler 2 gewinnt!\n");
                gameover = 1;
                break;
            }
            zug = 1;
            counter++;
            }
        }
    }

    return 0;
}

int istReihe(){
    if(feld[0][0] == feld[1][1] && feld[1][1] == feld[2][2] && feld[1][1] != '*'){
        return 1;
    }
    else if(feld[2][0] == feld[1][1] && feld[1][1] == feld[0][2] && feld[1][1] != '*'){
        return 1;
    }
    else if(feld[0][0] == feld[1][0] && feld[1][0] == feld[2][0] && feld[1][0] != '*'){
        return 1;
    }
    else if(feld[0][1] == feld[1][1] && feld[1][1] == feld[2][1] && feld[1][1] != '*'){
        return 1;
    }
    else if(feld[0][2] == feld[1][2] && feld[1][2] == feld[2][2] && feld[1][2] != '*'){
        return 1;
    }
    else if(feld[0][0] == feld[0][1] && feld[0][1] == feld[0][2] && feld[0][1] != '*'){
        return 1;
    }
    else if(feld[1][0] == feld[1][1] && feld[1][1] == feld[1][2] && feld[1][1] != '*'){
        return 1;
    }
    else if(feld[2][0] == feld[2][1] && feld[2][1] == feld[2][2] && feld[2][1] != '*'){
        return 1;
    }
    else{
    return 0;
    }
}
