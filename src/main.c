#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define FICHIER_SCORES "scores.txt"

// Prototypes
void afficher_menu();
void Addition(int *score, const char *nom);
void Soustraction(int *score, const char *nom);
void Multiplication(int *score, const char *nom);
void Division(int *score);
void tablesMultiplication();
void exerciceTableMultiplication(int *score);
void SauvegarderScore(const char *nom, int score);
int ChargerScore(const char *nom);
int jeu_nombre_en_lettres(int *score, const char *nom);
int jeu_conversion_duree(int *score, const char *nom);
void AfficherDernierScoreJoueur(const char *nom, int sessionScore);

// Tableaux pour l'écriture en lettres
const char* unites[] = {"", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf"};
const char* dizaines[] = {"", "dix", "vingt", "trente", "quarante", "cinquante", "soixante", "soixante-dix", "quatre-vingt", "quatre-vingt-dix"};
const char* dix_vingt[] = {"dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};




int main() {
    int i, choix; 
    int score = 0; 
    char nom[50]; 
    srand(time(NULL)); // Initialise le générateur aléatoire avec l'heure actuelle.
    
    printf("Entrez votre nom : "); 
    scanf("%s", nom); // Saisie du nom de l'utilisateur.
    
    score = ChargerScore(nom); // Charge le dernier score enregistré pour l'utilisateur.
    printf("Votre score actuel est : %d\n", score); // Affiche le score actuel.

    do {
        afficher_menu(); // Affiche le menu principal.
        scanf("%d", &choix); // Demande à l'utilisateur de faire un choix.

        switch (choix) {
            case 1:
                Addition(&score, nom); // Lancer le jeu d'addition.
                break;
            case 2:
                Soustraction(&score, nom); // Lancer le jeu de soustraction.
                break;
            case 3:
                Multiplication(&score, nom); // Lancer le jeu de multiplication.
                break;
            case 4:
                tablesMultiplication(); // Afficher une table de multiplication.
                break;
            case 5:
                Division(&score); // Lancer le jeu de division.
                break;
            case 6:
                exerciceTableMultiplication(&score); // Exercice sur une table de multiplication.
                break;
            case 7:
                jeu_nombre_en_lettres(&score, nom); // Jeu : écrire un nombre en chiffres.
                break;
            case 8:
                jeu_conversion_duree(&score, nom); // Jeu : conversion de durée.
                break;
            case 0:
                printf("Merci de votre visite ! \n"); // Fin du programme.
                break;
            default:
                printf("Choix invalide. Veuillez recommencer. \n"); // Gestion des erreurs de choix.
        }
    } while (choix != 0);

    SauvegarderScore(nom, score); // Sauvegarde le score de l'utilisateur.
    AfficherDernierScoreJoueur(nom, score); // Affiche le dernier score sauvegardé.
    
    return 0; // Fin du programme.
}




		void afficher_menu() {

			printf("+-----------------------------------+\n");

			printf("|1 : Addition                       |\n");

			printf("|2 : Soustraction                   |\n");

			printf("|3 : Multiplication                 |\n");

			printf("|4 : Tables des multiplications     |\n");

			printf("|5 : Division                       |\n");

			printf("|6 : exerciceTableMultiplication    |\n");

			printf("|7 : Ecriture des grands nombres    |\n");

			printf("|8 : Jeu conversion de duree        |\n");

			printf("|0 : Sortir du jeu                  |\n");

			printf("+-----------------------------------+\n");

			printf("Quel est votre choix ? ");

		}



		void Addition(int *score, const char *nom) {

    int nb1 = rand() % 101, nb2 = rand() % 101, reponse, essais = 0;

    int resultat = nb1 + nb2;

    

    do {

        essais++;

        printf("\nCombien fait %d + %d ? ", nb1, nb2);

        scanf("%d", &reponse);

        

        if (reponse == resultat) {

            if (essais == 1) {

                printf("Bravo ! +10 points\n");

                (*score) += 10;

            } else if (essais == 2) {

                printf("Bien joué ! +5 points\n");

                (*score) += 5;

            } else {

                printf("Correct mais tard ! +1 point\n");

                (*score) += 1;

            }

            SauvegarderScore(nom, *score);

            return;

        } else {

            printf("Mauvaise réponse. Réessayez.\n");

        }

    } while (essais < 3);



    printf("Échec ! La réponse était %d\n", resultat);

}



	void Soustraction(int *score, const char *nom) {

    int nb1 = rand() % 101, nb2 = rand() % 101, reponse, essais = 0;

    if (nb1 < nb2) { int temp = nb1; nb1 = nb2; nb2 = temp; }

    int resultat = nb1 - nb2;

    do {

        essais++;

        printf("\nCombien fait %d - %d ? ", nb1, nb2);

        scanf("%d", &reponse);

        if (reponse == resultat) {

            if (essais == 1) {

                printf("Bravo ! +10 points\n");

                (*score) += 10;

            } else if (essais == 2) {

                printf("Bien joué ! +5 points\n");

                (*score) += 5;

            } else {

                printf("Correct mais tard ! +1 point\n");

                (*score) += 1;

            }

            SauvegarderScore(nom, *score);

            return;

        } else {

            printf("Mauvaise réponse. Réessayez.\n");

        }

    } while (essais < 3);



    printf("Échec ! La réponse était %d\n", resultat);

}

        



	void Multiplication(int *score, const char *nom) {

    int nb1 = rand() % 101;

    int nb2 = rand() % 101;

    int resultat = nb1 * nb2;

    int reponse, essais = 0;



    printf("\nCombien fait %d x %d ?\n", nb1, nb2);



    while (essais < 3) {

        printf("Essai %d : ", essais + 1);

        scanf("%d", &reponse);



        if (reponse == resultat) {

            if (essais == 0) {

                *score += 10;

                printf("Bravo ! Vous avez gagné 10 points.\n");

            } else if (essais == 1) {

                *score += 5;

                printf("Bien joué ! Vous avez gagné 5 points.\n");

            } else {

                *score += 1;

                printf("Correct, mais vous gagnez seulement 1 point.\n");

            }

            SauvegarderScore(nom, *score);

            return;

        } else {

            printf("Mauvaise réponse.\n");

        }

        essais++;

    }



    printf("Dommage ! La bonne réponse était %d.\n", resultat);

    // Pas de points ajoutés

}



		void Division(int *score) {

			int nb2 = rand() % 10 + 1, multiple = rand() % 10 + 1, nb1 = nb2 * multiple, reponse,essais=0;

			int resultat= nb1/nb2;

			printf("\nCombien fait %d / %d ? ", nb1, nb2);

			  while (essais < 3) {

        printf("Essai %d : ", essais + 1);

        scanf("%d", &reponse);



        if (reponse == resultat) {

            if (essais == 0) {

                *score += 10;

                printf("Bravo ! Vous avez gagné 10 points.\n");

            } else if (essais == 1) {

                *score += 5;

                printf("Bien joué ! Vous avez gagné 5 points.\n");

            } else {

                *score += 1;

                printf("Correct, mais vous gagnez seulement 1 point.\n");

            }

            return;

        } else {

            printf("Mauvaise réponse.\n");

        }

        essais++;

    }



    printf("Dommage ! La bonne réponse était %d.\n", resultat);

}



		void tablesMultiplication() {

			int table;

			printf("\nChoisissez une table de multiplication (1 C  10) : ");

			scanf("%d", &table);

			if (table < 1 || table > 10) {

				printf("Table invalide !\n");

				return;

			}

			printf("\nTable de %d :\n", table);

			for (int i = 1; i <= 10; i++) {

				printf("%d x %d = %d\n", table, i, table * i);

			}

		}



		void exerciceTableMultiplication(int *score) {

			int table;

			printf("\nSur quelle table voulez-vous vous exercer ? (1 a  10) : ");

			scanf("%d", &table);

			if (table < 1 || table > 10) {

				printf("Table invalide !\n");

				return;

			}

			int correct = 1;

			for (int i = 1; i <= 10; i++) {

				int reponse;

				printf("\nCombien fait %d x %d ? ", table, i);

				scanf("%d", &reponse);

				if (reponse != table * i) {

					printf("Perdu ! La bonne reponse etait %d.\n", table * i);

					correct = 0;

				}

			}

			if (correct) {

				printf("Gagne !\n");

				(*score) += 5;

			}

		}

		void convertir_centaines(int n, char* buffer) {

    if (n == 0) return;

    if (n >= 100) {

        int centaines = n / 100;

        if (centaines == 1)

            strcat(buffer, "cent");

        else {

            strcat(buffer, unites[centaines]);

            strcat(buffer, " cent");

        }

        if (n % 100 != 0)

            strcat(buffer, " ");

    }

    int reste = n % 100;

    if (reste >= 10 && reste <= 19) {

        strcat(buffer, dix_vingt[reste - 10]);

    } else {

        int d = reste / 10;

        int u = reste % 10;

        if (d != 0) {

            strcat(buffer, dizaines[d]);

            if (u != 0)

                strcat(buffer, "-");

        }

        if (u != 0)

            strcat(buffer, unites[u]);

    }

}



void nombre_en_lettres(int n, char* buffer) {

    buffer[0] = '\0';

    if (n == 0) {

        strcpy(buffer, "zéro");

        return;

    }

    if (n >= 1000000) {

        int millions = n / 1000000;

        if (millions > 1) {

            convertir_centaines(millions, buffer);

            strcat(buffer, " millions ");

        } else {

            strcat(buffer, "un million ");

        }

        n %= 1000000;

    }

    if (n >= 1000) {

        int milliers = n / 1000;

        if (milliers > 1) {

            char temp[200] = "";

            convertir_centaines(milliers, temp);

            strcat(buffer, temp);

            strcat(buffer, " mille ");

        } else {

            strcat(buffer, "mille ");

        }

        n %= 1000;

    }

    if (n > 0) {

        char temp[200] = "";

        convertir_centaines(n, temp);

        strcat(buffer, temp);

    }

}



		int jeu_nombre_en_lettres(int *score, const char *nom) {

    int nombre = rand() % 9000000 + 1000000;

    char lettres[1000];

    int reponse, essais = 0;



    nombre_en_lettres(nombre, lettres);

    printf("\nECRITURE DE GRANDS NOMBRES - CM1\n");

    printf("Écris ce nombre en chiffres :\n%s\n", lettres);



    while (essais < 3) {

        printf("Essai %d : ", essais + 1);

        scanf("%d", &reponse);

        if (reponse == nombre) {

            if (essais == 0) {

                printf("Bravo ! +10 points\n");

                *score += 10;

            } else if (essais == 1) {

                printf("Bien joué ! +5 points\n");

                *score += 5;

            } else {

                printf("Tu y es arrivé ! +1 point\n");

                *score += 1;

            }

            SauvegarderScore(nom, *score);

            return 1;

        } else {

            printf("Mauvaise réponse.\n");

        }

        essais++;

    }



    printf("Désolé, la bonne réponse était : %d\n", nombre);

    return 0;

}



		int jeu_conversion_duree(int *score, const char *nom) {

    int heures = rand() % 10 + 1;       // 1 à 10 h

    int minutes = rand() % 60;          // 0 à 59 min

    int bonne_reponse = heures * 60 + minutes;

    int reponse, essais = 0;



    printf("\nLES DURÉES - CM1 difficile\n");

    printf("%d h %d min = ? min\n", heures, minutes);



    while (essais < 3) {

        printf("Essai %d : ", essais + 1);

        scanf("%d", &reponse);

        if (reponse == bonne_reponse) {

            if (essais == 0) {

                printf("Bravo ! +10 points\n");

                *score += 10;

            } else if (essais == 1) {

                printf("Bien joué ! +5 points\n");

                *score += 5;

            } else {

                printf("Tu y es arrivé ! +1 point\n");

                *score += 1;

            }

            SauvegarderScore(nom, *score);

            return 1;

        } else {

            printf("Mauvaise réponse.\n");

        }

        essais++;

    }



    printf("La bonne réponse était : %d minutes\n", bonne_reponse);

    return 0;

}


		void SauvegarderScore(const char *nom, int score) {

			FILE *f = fopen(FICHIER_SCORES, "a");  // "a" pour ajouter sans effacer l'ancien contenu

			if (f == NULL) {

				printf("Erreur lors de l'ouverture du fichier\n");

				return;

			}



			// Obtenir la date et l'heure actuelles

			time_t now = time(NULL);

			struct tm *t = localtime(&now);



			// C	crire dans le fichier : nom, date, heure et score

			fprintf(f, "%s %02d/%02d/%04d %02d:%02d:%02d %d\n",

			        nom, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900,

			        t->tm_hour, t->tm_min, t->tm_sec, score);



			fclose(f);

			printf("Score sauvegarder avec succes\n");

		}



		void AfficherScores() {

			FILE *f = fopen(FICHIER_SCORES, "r");

			if (f == NULL) {

				printf("Aucun score enregistre pour le moment.\n");

				return;

			}



			char ligne[100];

			printf("\n--- Scores enregistres ---\n");

			while (fgets(ligne, sizeof(ligne), f) != NULL) {

				printf("%s", ligne);

			}

			fclose(f);

		}
void AfficherDernierScoreJoueur(const char *nom, int sessionScore) {
    FILE *f = fopen(FICHIER_SCORES, "r"); // Ouvre le fichier des scores en mode lecture.
    if (f == NULL) {
        printf("Aucun score enregistré pour le moment.\n"); // Message si le fichier n'existe pas.
        return;
    }

    char nomFichier[50], date[20], heure[10];
    int scoreFichier, dernierScore = 0;
    char derniereDate[20], derniereHeure[10];

    // Parcourt le fichier pour trouver les scores du joueur.
    while (fscanf(f, "%s %s %s %d", nomFichier, date, heure, &scoreFichier) == 4) {
        if (strcmp(nom, nomFichier) == 0) { // Vérifie si le nom correspond.
            dernierScore = scoreFichier;
            strcpy(derniereDate, date); // Copie la date.
            strcpy(derniereHeure, heure); // Copie l'heure.
        }
    }
    fclose(f); // Ferme le fichier après utilisation.

    // Affiche les informations sur le dernier score.
    printf("\nDernier score enregistré de %s : %d (Date : %s, Heure : %s)\n", 
           nom, dernierScore, derniereDate, derniereHeure);
}


		int ChargerScore(const char *nom) {

    FILE *f = fopen(FICHIER_SCORES, "r");

    if (f == NULL) {

        return 0;

    }

    char nomFichier[50];

    int scoreFichier=0, dernierScore = 0;

    char date[20],heure[20];

    while (fscanf(f, "%s %s %s %d", nomFichier,date,heure, &scoreFichier) == 4) {

        if (strcmp(nom, nomFichier) == 0) {

            dernierScore = scoreFichier;

        }

    }

    fclose(f);

    return dernierScore;


}   
