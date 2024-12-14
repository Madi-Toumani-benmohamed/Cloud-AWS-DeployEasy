# Cloud-AWS-DeployEasy


**Easy Deploy** est un programme C conçu pour simplifier la mise en place d'environnements de travail pour des labs d'étude, notamment pour des travaux pratiques (TP) dans des domaines comme le pentesting, la programmation, et bien d'autres. L'objectif du projet est de faciliter le déploiement d'infrastructures de tests et d'exercices dans des contextes d'apprentissage, en offrant un moyen rapide et facile de préparer des environnements adaptés à l'étude et à la pratique.

## Fonctionnalités

- **Bannière personnalisée** : Affiche une bannière stylée lors du démarrage du programme pour un accueil immersif.
- **Déploiement d'infrastructure de TP** : Permet de déployer des environnements de travail pour des TP de pentesting, de programmation, et autres travaux pratiques.
- **Interface en ligne de commande** : Utilise des entrées de commandes et des options pour automatiser le déploiement et l'exécution des tâches spécifiques aux environnements d'étude.

## Objectif à Court Terme

Le but immédiat du projet est de fournir un outil permettant de déployer rapidement des infrastructures de travail pour des étudiants dans des domaines tels que :

- **Pentesting** : Déploiement rapide de machines et environnements pour des tests de pénétration.
- **Programmation** : Mise en place d'environnements de développement pour des exercices de programmation en C ou dans d'autres langages.
- **Autres** : Automatisation de la préparation d'infrastructures pour divers TP et exercices d'apprentissage.

## Prérequis

Avant de pouvoir compiler et exécuter le programme, assure-toi d'avoir installé un compilateur C, tel que `gcc`, et d'avoir les outils de développement nécessaires.

- `gcc` (GNU Compiler Collection) pour compiler le programme.
- Un terminal pour exécuter les commandes.

## Installation

Clone ce dépôt ou télécharge le projet, puis compile-le en suivant les étapes ci-dessous :

1. **Clone le dépôt** (si nécessaire) :
   ```bash
   git clone https://example.com/ton-depot.git](https://github.com/Madi-Toumani-benmohamed/Cloud-AWS-DeployEasy.git
   cd Cloud-AWS-DeployEasy
   ```

2. **Compiler le programme** :
   Si tu as un fichier `Makefile` dans le projet, tu peux compiler le code avec la commande suivante :
   ```bash
   make
   ```
   Cela génère un fichier exécutable nommé `deployEasy`.

## Utilisation

### Lancer le programme

Une fois le programme compilé, tu peux exécuter le binaire avec la commande suivante dans ton terminal :

```bash
./deployEasy
```

Lorsque le programme démarre, une bannière stylée s'affichera pour t'accueillir.

### Exemple d'exécution

Voici un exemple de sortie du programme :

```
**************************************************************
*  EEEEE  AAAAA  SSSSS  Y   Y                                *
*  E      A   A  S       Y Y                                 *
*  EEEE   AAAAA  SSSSS    Y                                  *
*  E      A   A      S    Y                                  *
*  EEEEE  A   A  SSSSS    Y                                  *
*                                                            *
*  DDDD  EEEEE  PPPP   L      OOO   Y   Y                    *
*  D   D E      P   P  L     O   O   Y Y                     *
*  D   D EEEE   PPPP   L     O   O    Y                      *
*  D   D E      P      L     O   O    Y                      *
*  DDDD  EEEEE  P      LLLLL  OOO     Y                      *
**************************************************************
               Welcome to Easy Deploy Program!               
                *** Version 1.0 ***                           
**************************************************************

### Commandes supplémentaires

- **Nettoyage du projet** : Pour supprimer les fichiers générés (objets et exécutable), utilise la commande suivante :
  ```bash
  make clean
  ```

- **Reconstruction complète** : Pour nettoyer et recompiler le projet :
  ```bash
  make rebuild
  ```

## Structure des fichiers

Voici une vue d'ensemble des fichiers principaux dans le projet :

- `deployEasy.c` : Le fichier source principal du programme.
- `file.h` : Le fichier d'en-tête contenant les déclarations des fonctions.
- `Makefile` : Le fichier de build pour compiler le projet facilement.
- `README.md` : Ce fichier, contenant des informations sur l'installation et l'utilisation.

## Contribuer

Si tu souhaites contribuer au projet, n'hésite pas à soumettre une pull request avec tes améliorations ou corrections. Les contributions sont toujours les bienvenues !

1. Fork le dépôt.
2. Crée une nouvelle branche (`git checkout -b feature-nouvelle-fonctionnalite`).
3. Effectue tes modifications et commit-les (`git commit -am 'Ajout d'une nouvelle fonctionnalité'`).
4. Push ta branche sur ton fork (`git push origin feature-nouvelle-fonctionnalite`).
5. Soumets une pull request.

## Auteurs

- **Madi Toumani** : Créateur et développeur principal.


