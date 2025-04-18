---

## 🧭 Plan étape par étape pour continuer Pipex

Voici un plan détaillé pour t’aider à progresser dans le projet Pipex :

---
### 1. **Création du pipe** ✅

Utilise la fonction `pipe()` pour créer un canal de communication entre les deux processus.

```c
int pipe_fd[2];
if (pipe(pipe_fd) == -1)
{
    perror("pipe");
    exit(EXIT_FAILURE);
}
```
---

### 2. **Fork du premier processus (cmd1)** ✅

Crée un processus enfant pour exécuter la première commande.

```c
pid_t pid1 = fork();
if (pid1 == -1)
{
    perror("fork");
    exit(EXIT_FAILURE);
}
if (pid1 == 0)
{
    // Code pour le premier enfant
}
```

---

### 3. **Dans le premier enfant : exécution de cmd1**

- Redirige l'entrée standard vers `fd_in` (le fichier d'entrée).
- Redirige la sortie standard vers le côté écriture du pipe.
- Ferme les descripteurs inutiles.
- Parse la commande `cmd1` et utilise `execve` pour l'exécuter.

```c
dup2(fd_in, STDIN_FILENO);
dup2(pipe_fd[1], STDOUT_FILENO);
close(pipe_fd[0]);
close(fd_in);
close(pipe_fd[1]);
// Parse cmd1 et exécute avec execve
```

---

### 4. **Fork du second processus (cmd2)**

Crée un second processus enfant pour exécuter la deuxième commande.

```c
pid_t pid2 = fork();
if (pid2 == -1)
{
    perror("fork");
    exit(EXIT_FAILURE);
}
if (pid2 == 0)
{
    // Code pour le second enfant
}
```

---

### 5. **Dans le second enfant : exécution de cmd2**

- Redirige l'entrée standard vers le côté lecture du pipe.
- Redirige la sortie standard vers `fd_out` (le fichier de sortie).
- Ferme les descripteurs inutiles.
- Parse la commande `cmd2` et utilise `execve` pour l'exécuter.

```c
dup2(pipe_fd[0], STDIN_FILENO);
dup2(fd_out, STDOUT_FILENO);
close(pipe_fd[1]);
close(fd_out);
close(pipe_fd[0]);
// Parse cmd2 et exécute avec execve
```

---

### 6. **Dans le processus parent**

- Ferme tous les descripteurs de fichiers.
- Attend la fin des deux processus enfants avec `waitpid`.

```c
close(fd_in);
close(fd_out);
close(pipe_fd[0]);
close(pipe_fd[1]);
waitpid(pid1, NULL, 0);
waitpid(pid2, NULL, 0);
```

---

### 7. **Parsing des commandes**

Écris une fonction pour parser les commandes en utilisant `ft_split` sur les espaces. Par exemple :

```c
char **parse_cmd(char *cmd)
{
    return ft_split(cmd, ' ');
}
```

---

### 8. **Recherche du chemin de la commande**

Écris une fonction pour rechercher le chemin absolu de la commande en utilisant la variable d'environnement `PATH`.

```c
char *get_cmd_path(char *cmd, char **envp)
{
    // Implémente la recherche du chemin de la commande
}
```

---

### 9. **Gestion des erreurs**

Assure-toi de gérer les erreurs à chaque étape : ouverture de fichiers, création de pipe, fork, duplication de descripteurs, exécution de commandes, etc.

---

### 10. **Tests**

Teste ton programme avec différentes commandes et fichiers pour t'assurer qu'il fonctionne correctement.

---
