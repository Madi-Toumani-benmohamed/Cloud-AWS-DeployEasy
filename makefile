# Variables
CC = gcc                    # Compilateur C
CFLAGS = -Wall -Wextra -std=c99  # Options de compilation (ajoute des avertissements et utilise le standard C99)
SRC = deployEasy.c           # Fichier source (ici deployEasy.c)
OBJ = deployEasy.o           # Fichier objet généré à partir de deployEasy.c
EXEC = deployEasy            # Nom de l'exécutable final

# Cible par défaut (l'exécutable)
all: $(EXEC)

# Règle pour générer l'exécutable
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Règle pour générer les fichiers objets
%.o: %.c file.h
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJ) $(EXEC)

# Règle pour nettoyer et recompiler
rebuild: clean all

# Pour éviter la recompilation excessive des fichiers dépendants
.PHONY: all clean rebuild
