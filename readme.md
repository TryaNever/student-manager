## 🎓 Projet : Student Manager

Objectif : créer un programme C permettant de gérer une liste d'étudiants stockée dans un fichier.

Lancement :

```bash
./student_manager students.txt
```

Chaque étudiant contient :

```c
typedef struct
{
    int id;
    char *last_name;
    char *first_name;
    int age;
    float average;
} Student;
```

### Fonctionnalités

1. **Ajouter un étudiant**
   - `malloc`
   - `realloc`
   - pointeurs
   - `Student **`

2. **Supprimer un étudiant**
   - recherche par ID
   - décalage dans le tableau
   - `free`

3. **Afficher les étudiants**
   - tableaux
   - pointeurs
   - `const`

4. **Rechercher**
   - par ID
   - par nom
   - recherche linéaire
   - bonus : recherche binaire

5. **Trier**
   - par ID
   - nom
   - âge
   - moyenne
   - implémenter toi-même un algorithme de tri

6. **Charger depuis un fichier**

```text
1;Dupont;Jean;19;14.5
2;Martin;Lucas;21;12.7
```

avec :

```c
fopen()
fgets()
fclose()
```

7. **Sauvegarder dans le fichier**

8. **Menu interactif**

```text
==============================
      STUDENT MANAGER
==============================

1. Add student
2. Remove student
3. Find student
4. List students
5. Sort students
6. Save
7. Reload
0. Exit
```

9. **Statistiques**
   - nombre d'étudiants
   - moyenne générale
   - meilleure moyenne
   - pire moyenne
   - plus jeune
   - plus âgé

10. **Arguments CLI**

```c
int main(int argc, char **argv)
```

avec gestion des erreurs :

```bash
./student_manager
```

→ afficher l'utilisation correcte.

---

## 📁 Organisation

```text
student_manager/
├── Makefile
├── include/
│   └── student.h
├── src/
│   ├── main.c
│   ├── student.c
│   ├── file.c
│   ├── sort.c
│   └── utils.c
└── students.txt
```

Makefile avec :

```text
make
make clean
make fclean
make re
```

et :

```text
-Wall -Wextra -Werror
```

---

## 🔥 Bonus niveau B3

Une fois le projet fonctionnel :

- réimplémenter `strlen`
- réimplémenter `strcmp`
- réimplémenter `strcpy`
- créer ton propre `strdup`
- gérer proprement toutes les erreurs de `malloc/realloc`
- zéro memory leak
- tester avec Valgrind/AddressSanitizer
- mesurer la complexité des algorithmes
- éventuellement remplacer le tableau dynamique par une **liste chaînée**
