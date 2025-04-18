Voici une **fiche complète** des fonctions autorisées dans Pipex, avec pour chacune :

- Une **description détaillée**
- Un **exemple simple en C**
- La **librairie à inclure** pour pouvoir l’utiliser

---

## 🔧 FONCTIONS BAS NIVEAU : GESTION DES FICHIERS & I/O

---

### `open`
**📚 Lib :** `<fcntl.h>`  
**🧾 Description :**  
Ouvre un fichier et retourne un **descripteur de fichier**. Peut aussi créer un fichier si le flag `O_CREAT` est utilisé.

**🧪 Exemple :**
```c
#include <fcntl.h>
int fd = open("file.txt", O_RDONLY);
if (fd < 0) perror("open");
```

---

### `close`
**📚 Lib :** `<unistd.h>`  
**🧾 Description :**  
Ferme un descripteur de fichier. Libère la ressource côté noyau.

**🧪 Exemple :**
```c
#include <unistd.h>
close(fd);
```

---

### `read`
**📚 Lib :** `<unistd.h>`  
**🧾 Description :**  
Lit des octets depuis un descripteur de fichier dans un buffer.

**🧪 Exemple :**
```c
#include <unistd.h>
char buf[100];
ssize_t bytes = read(fd, buf, 100);
```

---

### `write`
**📚 Lib :** `<unistd.h>`  
**🧾 Description :**  
Écrit des octets sur un descripteur de fichier (stdout, un fichier, etc.)

**🧪 Exemple :**
```c
#include <unistd.h>
write(1, "Hello\n", 6); // écrit sur stdout
```

---

## 🧠 MÉMOIRE & ERREURS

---

### `malloc` / `free`
**📚 Lib :** `<stdlib.h>`  
**🧾 Description :**  
Alloue / libère de la mémoire dynamique.

**🧪 Exemple :**
```c
#include <stdlib.h>
char *str = malloc(10);
if (!str) perror("malloc");
free(str);
```

---

### `perror`
**📚 Lib :** `<stdio.h>`  
**🧾 Description :**  
Affiche un message d’erreur associé à `errno` précédé d’un message personnalisé.

**🧪 Exemple :**
```c
#include <stdio.h>
perror("Erreur lors de l'ouverture");
```

---

### `strerror`
**📚 Lib :** `<string.h>`  
**🧾 Description :**  
Retourne une chaîne de caractères décrivant l’erreur (selon `errno`).

**🧪 Exemple :**
```c
#include <stdio.h>
#include <string.h>
#include <errno.h>
printf("Erreur : %s\n", strerror(errno));
```

---

## 🛡️ DROITS, DUPLICATION, REDIRECTION

---

### `access`
**📚 Lib :** `<unistd.h>`  
**🧾 Description :**  
Vérifie si un fichier existe et/ou a les droits nécessaires (lecture, écriture, exécution).

**🧪 Exemple :**
```c
#include <unistd.h>
if (access("commande", X_OK) == 0) printf("exécutable !\n");
```

---

### `dup`
**📚 Lib :** `<unistd.h>`  
**🧾 Description :**  
Duplique un descripteur de fichier sur le **plus petit descripteur libre**.

**🧪 Exemple :**
```c
#include <unistd.h>
int copy = dup(fd);
```

---

### `dup2`
**📚 Lib :** `<unistd.h>`  
**🧾 Description :**  
Redirige un descripteur de fichier vers un autre **de manière ciblée** (ex : rediriger stdout).

**🧪 Exemple :**
```c
#include <unistd.h>
dup2(fd, 1); // fd devient la nouvelle sortie standard
```

---

## 🧬 PROCESSUS & EXÉCUTION

---

### `execve`
**📚 Lib :** `<unistd.h>`  
**🧾 Description :**  
Exécute un programme **remplaçant** le processus courant. Nécessite le chemin, les arguments, et l’environnement.

**🧪 Exemple :**
```c
#include <unistd.h>
char *args[] = {"/bin/ls", "-l", NULL};
execve("/bin/ls", args, environ);
```

---

### `exit`
**📚 Lib :** `<stdlib.h>`  
**🧾 Description :**  
Termine le programme avec un code de sortie (0 pour succès, >0 pour erreur).

**🧪 Exemple :**
```c
#include <stdlib.h>
exit(1); // quitte avec code erreur
```

---

### `fork`
**📚 Lib :** `<unistd.h>`  
**🧾 Description :**  
Crée un **nouveau processus** (copie du parent). Retourne 0 dans le fils, >0 dans le parent.

**🧪 Exemple :**
```c
#include <unistd.h>
pid_t pid = fork();
if (pid == 0) printf("Processus fils\n");
else printf("Processus parent\n");
```

---

### `pipe`
**📚 Lib :** `<unistd.h>`  
**🧾 Description :**  
Crée un **pipe anonyme** (tableau de 2 fd : `pipefd[0]` pour lecture, `pipefd[1]` pour écriture).

**🧪 Exemple :**
```c
#include <unistd.h>
int pipefd[2];
pipe(pipefd);
```

---

### `unlink`
**📚 Lib :** `<unistd.h>`  
**🧾 Description :**  
Supprime un fichier du système (comme `rm`), libère l’inode si plus aucun lien.

**🧪 Exemple :**
```c
#include <unistd.h>
unlink("tempfile.txt");
```

---

### `wait`
**📚 Lib :** `<sys/wait.h>`  
**🧾 Description :**  
Attend la fin d’un processus fils, retourne son PID.

**🧪 Exemple :**
```c
#include <sys/wait.h>
int status;
wait(&status);
```

---

### `waitpid`
**📚 Lib :** `<sys/wait.h>`  
**🧾 Description :**  
Comme `wait`, mais permet de **spécifier un PID**. Peut aussi être non-bloquant avec des flags.

**🧪 Exemple :**
```c
#include <sys/wait.h>
int status;
waitpid(pid, &status, 0);
```

---
