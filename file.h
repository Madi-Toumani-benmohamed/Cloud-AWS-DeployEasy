#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARAM_LENGTH 128

void afficher_banniere();
void afficher_menu();
void configurer_vm();
void afficher_params_disponibles(const char *type_item);
void generer_fichier_terraform(const char *template_file, const char *output_file, const char *nom_item, const char **params, int param_count);
int executer_commande(const char *commande);
void demarrer_lab();
void initialiser_provider();
void supprimer_ressources(); 

// Fonction pour afficher le menu principal
void afficherMenu(int choix) {
    int max_choices = 6; // Augmenté pour inclure l'option d'aide
    for (int i = 1; i <= max_choices; i++) {
        if (i == choix) {
            printf("-> %d. %s\n", i, 
                (i == 1) ? "Configurer les ressources" : 
                (i == 2) ? "Quitter" :
                (i == 3) ? "Démarrer un lab" : 
                (i == 4) ? "Initialisation du provider" :
                (i == 5) ? "Supprimer les ressources" :
                "Afficher de l'aide");
        } else {
            printf("   %d. %s\n", i, 
                (i == 1) ? "Configurer les ressources" : 
                (i == 2) ? "Quitter" :
                (i == 3) ? "Démarrer un lab" : 
                (i == 4) ? "Initialisation du provider" :
                (i == 5) ? "Supprimer les ressources" :
                "Afficher de l'aide");
        }
    }
}

// Fonction pour afficher l'aide
void afficherAide() {
    printf("\n=== Aide ===\n");
    printf("1. Configurer les ressources :\n");
    printf("   Permet de générer le script des ressources Terraform.\n");
    printf("2. Quitter :\n");
    printf("   Ferme le programme.\n");
    printf("3. Démarrer un lab :\n");
    printf("   Déploie les ressources via Terraform.\n");
    printf("4. Initialisation du provider :\n");
    printf("   Initialise le provider Terraform utilisé pour la gestion des ressources.\n");
    printf("5. Supprimer les ressources :\n");
    printf("   Détruit les ressources déployées avec Terraform.\n");
    printf("6. Afficher de l'aide :\n");
    printf("   Montre ce menu explicatif.\n\n");
}

void configurer_vm() {
    char type_item[MAX_PARAM_LENGTH];
    char nom_item[MAX_PARAM_LENGTH];
    char params[MAX_PARAM_LENGTH][MAX_PARAM_LENGTH];
    int param_count = 0;

    printf("\nTypes de Ressources disponibles : aws_instance, infra_complete, provider, serveur_web, vpc\n");
    printf("\nEntrez le type de Ressource (en miniscule) : ");
    getchar();  // Pour consommer le '\n' restant dans le buffer
    fgets(type_item, sizeof(type_item), stdin);
    type_item[strcspn(type_item, "\n")] = 0;  // Supprimer le '\n' à la fin

    afficher_params_disponibles(type_item);

    printf("\nEntrez le nom de la Ressource : ");
    fgets(nom_item, sizeof(nom_item), stdin);
    nom_item[strcspn(nom_item, "\n")] = 0;  // Supprimer le '\n' à la fin

    printf("\nEntrez les paramètres pour la Ressource (format clé=valeur). Tapez 'fin' pour terminer :\n");
    while (1) {
        char param[MAX_PARAM_LENGTH];
        printf("Paramètre %d : ", param_count + 1);
        fgets(param, sizeof(param), stdin);
        param[strcspn(param, "\n")] = 0;  // Supprimer le '\n' à la fin

        if (strcmp(param, "fin") == 0) {
            break;
        }

        strcpy(params[param_count], param);
        param_count++;

        if (param_count >= MAX_PARAM_LENGTH) {
            printf("\nNombre maximal de paramètres atteint.\n");
            break;
        }
    }

    // Créer un répertoire pour les fichiers Terraform
    if (executer_commande("mkdir -p terraform_files") != 0) {
        printf("\nErreur : Impossible de créer le répertoire terraform_files.\n");
        return;
    }

    // Construire le chemin du fichier modèle
    char template_file[MAX_PARAM_LENGTH];
    snprintf(template_file, sizeof(template_file), "templates/%s.template", type_item);

    // Construire le chemin du fichier de sortie
    char output_file[MAX_PARAM_LENGTH];
    snprintf(output_file, sizeof(output_file), "terraform_files/%s.tf", nom_item);

    // Générer le fichier Terraform
    const char *param_ptrs[MAX_PARAM_LENGTH];
    for (int i = 0; i < param_count; i++) {
        param_ptrs[i] = params[i];
    }
    generer_fichier_terraform(template_file, output_file, nom_item, param_ptrs, param_count);

    printf("\nFichiers Terraform générés avec succès.\n");
}

void initialiser_provider() {
    // Créer un répertoire pour les fichiers Terraform s'il n'existe pas
    if (executer_commande("mkdir -p terraform_files") != 0) {
        printf("\nErreur : Impossible de créer le répertoire terraform_files.\n");
        return;
    }

    printf("\n **********   Il n'y a qu'un seul provider de disponible pour l'instant et c'est AWS déso déso  *********** \n");
    // Construire le chemin du fichier modèle pour le provider AWS
    char template_file[MAX_PARAM_LENGTH];
    snprintf(template_file, sizeof(template_file), "templates/provider_aws.template");

    // Construire le chemin du fichier de sortie pour le provider
    char output_file[MAX_PARAM_LENGTH];
    snprintf(output_file, sizeof(output_file), "terraform_files/provider_aws.tf");

    // Générer le fichier Terraform pour le provider
    generer_fichier_terraform(template_file, output_file, "provider_aws", NULL, 0);

    printf("\nProvider AWS initialisé avec succès.\n");
}


void demarrer_lab() {
    // Exécuter les commandes Terraform
    printf("\nDémarrage du lab : Déploiement des ressources Terraform...\n");
    if (executer_commande("cd terraform_files && terraform init ") != 0) {
        printf("\nErreur : L'initialisation de Terraform a échoué.\n");
        return;
    }

    printf("\nApplication de la configuration Terraform...\n");
    if (executer_commande("cd terraform_files && terraform apply") != 0) {
        printf("\nErreur : L'application de Terraform a échoué.\n");
        return;
    }

    printf("\nDéploiement des ressources terminé avec succès.\n");
}

void supprimer_ressources() {
    // Exécuter les commandes Terraform
    printf("\nSuppression des ressources : Suppression des ressources Terraform...\n");
    if (executer_commande("cd terraform_files && terraform destroy ") != 0) {
        printf("\nErreur : L'initialisation de Terraform a échoué.\n");
        return;
    }


    printf("\n Suppression des ressources terminé avec succès.\n");
}

void afficher_params_disponibles(const char *type_item) {
    if (strcmp(type_item, "aws_instance") == 0) {
        printf("\nParamètres disponibles pour aws_instance :\n");
        printf("  - vpc_id : Identifiant du VPC\n");
        printf("  - subnet_cidr : CIDR du sous-réseau (ex : 10.0.1.0/24)\n");
        printf("  - key_name : Nom de la clé SSH\n");
        printf("  - user_data : Fichier user_data\n");
    } else if (strcmp(type_item, "provider") == 0) {
        printf("\nParamètres disponibles pour Provider :\n");
        printf("  Il n'y a qu'un seul provider de disponible sur cette version.\n");
        printf("  - Il s'agit du provider AWS");
    } else if (strcmp(type_item, "serveur_web") == 0) {
        printf("\nParamètres disponibles pour Serveur web :\n");
        printf("  - vpc_id : Identifiant du VPC\n");
        printf("  - subnet_cidr : CIDR du sous-réseau (ex : 10.0.1.0/24)\n");
        printf("  - key_name : Nom de la clé SSH\n");
        printf("  - user_data : Fichier user_data\n");
    } else if (strcmp(type_item, "vpc") == 0) {
        printf("\nParamètres disponibles pour le VPC :\n");
        printf("  - subnet_cidr : CIDR du sous-réseau (ex : 10.0.1.0/24)\n");
    } else if (strcmp(type_item, "infra_complete") == 0) {
        printf("\nParamètres disponibles pour le Infra complète :\n");
        printf("  - cidr block VPC : CIDR du VPC (ex : 10.0.0.0/16)\n");
        printf("  - subnet_cidr : CIDR du sous-réseau (ex : 10.0.1.0/24)\n");
        printf("  - Nombre d'instance : Combien d'instance tu veux ?\n");
        printf("  - key_name : Nom de la clé SSH\n");
        printf("  - user_data : Fichier user_data\n");
    } 
    else {
        printf("\nType de ressource inconnu. Aucun paramètre spécifique disponible.\n");
    }
}

void generer_fichier_terraform(const char *template_file, const char *output_file, const char *nom_item, const char **params, int param_count) {
    FILE *template = fopen(template_file, "r");
    if (template == NULL) {
        perror("Erreur lors de l'ouverture du fichier modèle");
        return;
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        perror("Erreur lors de la création du fichier de sortie");
        fclose(template);
        return;
    }

    char line[MAX_PARAM_LENGTH];
    while (fgets(line, sizeof(line), template)) {
        // Remplacer les espaces réservés dans le modèle
        char *placeholder;
        while ((placeholder = strstr(line, "<###ITEM_NAME###>")) != NULL) {
            char buffer[MAX_PARAM_LENGTH];
            strncpy(buffer, line, placeholder - line);
            buffer[placeholder - line] = '\0';
            strcat(buffer, nom_item);
            strcat(buffer, placeholder + strlen("<###ITEM_NAME###>"));
            strcpy(line, buffer);
        }

        for (int i = 0; i < param_count; i++) {
            char param_placeholder[32];
            snprintf(param_placeholder, sizeof(param_placeholder), "<###PARAM_%d###>", i + 1);

            while ((placeholder = strstr(line, param_placeholder)) != NULL) {
                char buffer[MAX_PARAM_LENGTH];
                strncpy(buffer, line, placeholder - line);
                buffer[placeholder - line] = '\0';
                strcat(buffer, params[i]);
                strcat(buffer, placeholder + strlen(param_placeholder));
                strcpy(line, buffer);
            }
        }

        fputs(line, output);
    }

    fclose(template);
    fclose(output);
}

int executer_commande(const char *commande) {
    int ret = system(commande);
    if (ret != 0) {
        printf("\nCommande échouée : %s\n", commande);
    }
    return ret;
}

void afficher_banniere() {
    printf("**************************************************************\n");
    printf("*  EEEEE  AAAAA  SSSSS  Y   Y                                *\n");
    printf("*  E      A   A  S       Y Y                                 *\n");
    printf("*  EEEE   AAAAA  SSSSS    Y                                  *\n");
    printf("*  E      A   A      S    Y                                  *\n");
    printf("*  EEEEE  A   A  SSSSS    Y                                  *\n");
    printf("*                                                            *\n");
    printf("*  DDDD  EEEEE  PPPP   L      OOO   Y   Y                    *\n");
    printf("*  D   D E      P   P  L     O   O   Y Y                     *\n");
    printf("*  D   D EEEE   PPPP   L     O   O    Y                      *\n");
    printf("*  D   D E      P      L     O   O    Y                      *\n");
    printf("*  DDDD  EEEEE  P      LLLLL  OOO     Y                      *\n");
    printf("**************************************************************\n");
    printf("               Welcome to Easy Deploy Program!               \n");
    printf("                *** Version 1.0 ***                           \n");
    printf("**************************************************************\n");
}

#endif // FILE_H
