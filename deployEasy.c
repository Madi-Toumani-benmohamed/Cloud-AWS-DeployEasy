#include "file.h"



void afficher_banniere();
void afficher_menu();
void configurer_vm();
void afficher_params_disponibles(const char *type_item);
void generer_fichier_terraform(const char *template_file, const char *output_file, const char *nom_item, const char **params, int param_count);
int executer_commande(const char *commande);
void demarrer_lab();
void initialiser_provider();
void supprimer_ressources(); 






int main() {
    int choix = 1; // Option sélectionnée par défaut
    int quitter = 0;
    afficher_banniere();
    while (!quitter) {
        printf("\n=== Menu principal ===\n");
        afficherMenu(choix);
        printf("\nChoisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("\nQuelles ressources voulez vous ?...\n");
                configurer_vm();
                break;
            case 2:
                printf("\nQuitter le programme.\n");
                quitter = 1;
                break;
            case 3:
                printf("\nDémarrage du lab...\n");
               demarrer_lab();
                break;
            case 4:
                printf("\nInitialisation du provider...\n");
               initialiser_provider();
                break;
            case 5:
                printf("\nSuppression des ressources...\n");
                supprimer_ressources();
                break;
            case 6:
                afficherAide();
                break;
            default:
                printf("\nOption invalide. Veuillez réessayer.\n");
        }
    }

    return 0;
}





