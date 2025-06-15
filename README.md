# 🧮 Fibonacci Sequence with Process Management (EEX5335 Lab 01)

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Platform: WSL2 + Ubuntu](https://img.shields.io/badge/Platform-WSL2--Ubuntu-blue)](https://ubuntu.com/wsl)

Welcome! This repository contains my solution for the EEX5335 Operating Systems Lab 01: **Fibonacci Sequence Generation using Process Management in C**.  
As a 3rd-year Computer Engineering undergraduate, this project demonstrates practical use of `fork()` and `wait()` system calls, process IDs, and memory isolation in Linux.

---

## 🚀 Project Overview

- **Purpose:**  
  To understand and demonstrate how parent and child processes work, how process IDs are managed, and how memory is separated in a Linux environment using C.
- **What it does:**  
  - Prompts the user for the number of Fibonacci terms (1–50).
  - Uses `fork()` to create a child process.
  - The child process computes and prints the Fibonacci sequence with its PID.
  - The parent waits for the child to finish, then prints its own PID.
  - Handles invalid input and process creation errors.

---

## 📂 Repository Structure

```plaintext
.
├── fibonacci_fork.c      # Main source code
├── README.md             # This file
├── LICENSE               # License file (MIT)
```

---

## 🛠️ Environment & Tools

- **Laptop OS:** Windows 10 (64-bit)
- **Linux:** Ubuntu 24.04.2 LTS via [WSL 2](https://learn.microsoft.com/en-us/windows/wsl/)
- **Compiler:** GCC 13.4
- **Editor:** Visual Studio Code
- **Terminal:** Ubuntu Terminal in WSL 2
- **Version Control:** Git & GitHub

---

## 🔗 GitHub Repository

> **Find all code and lab documentation here:**  
> [github.com/Wanni46/EEX5335-Lab01-Fibonacci-Process](https://github.com/Wanni46/EEX5335-Lab01-Fibonacci-Process)

---

## 🏁 Quick Start

### 1. Clone the Repository

```sh
git clone https://github.com/Wanni46/EEX5335-Lab01-Fibonacci-Process.git
cd EEX5335-Lab01-Fibonacci-Process
```

### 2. Compile the Program

```sh
gcc fibonacci_fork.c -o fibonacci_fork
```

### 3. Run the Program

```sh
./fibonacci_fork
```

---

## 📋 Example Usage

```plaintext
Enter the number of Fibonacci terms: 7

[Child Process] PID: 2311
Fibonacci Sequence: 0 1 1 2 3 5 8 
[Child Process] Computation complete. Exiting...

[Parent Process] PID: 2310
Child process has completed execution.
```

- **If you enter a number outside 1–50:**
  ```
  Please enter a number between 1 and 50.
  ```

---

## 🧑‍💻 Code Summary

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int sequence[50];

void generate_fibonacci(int count) {
    sequence[0] = 0;
    if (count > 1)
        sequence[1] = 1;
    for (int i = 2; i < count; ++i)
        sequence[i] = sequence[i - 1] + sequence[i - 2];
}

void display_fibonacci(int count) {
    for (int i = 0; i < count; ++i)
        printf("%d ", sequence[i]);
    printf("\n");
}

int main() {
    int terms;
    pid_t child_pid;
    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &terms);

    if (terms < 1 || terms > 50) {
        fprintf(stderr, "Please enter a number between 1 and 50.\n");
        return 1;
    }

    child_pid = fork();

    if (child_pid < 0) {
        perror("Process creation failed");
        return 1;
    } else if (child_pid == 0) {
        generate_fibonacci(terms);
        printf("\n[Child Process] PID: %d\n", getpid());
        printf("Fibonacci Sequence: ");
        display_fibonacci(terms);
        printf("[Child Process] Computation complete. Exiting...\n");
        exit(0);
    } else {
        wait(NULL);
        printf("\n[Parent Process] PID: %d\n", getpid());
        printf("Child process has completed execution.\n");
    }
    return 0;
}
```

---

## 💡 Learning Outcomes

- **Process creation & synchronization** with `fork()` and `wait()`
- **Parent/child memory separation** and unique process IDs
- **Robust input validation** and error handling
- **Linux development workflow** using VS Code, WSL 2, and GitHub

---

## 📷 Screenshots

> _(Insert terminal screenshots here for demonstration if submitting for course assessment)_

---

## 📚 References

[1] A. Silberschatz, P. B. Galvin, and G. Gagne, _Operating System Concepts_, 8th ed. Hoboken, NJ, USA: Wiley, 2008.  
[2] “fork(2) - Linux manual page,” [Online]. Available: https://man7.org/linux/man-pages/man2/fork.2.html. [Accessed: 15-Jun-2025].  
[3] “wait(2) - Linux manual page,” [Online]. Available: https://man7.org/linux/man-pages/man2/wait.2.html. [Accessed: 15-Jun-2025].  
[4] “task_struct — Core kernel documentation,” [Online]. Available: https://www.kernel.org/doc/html/latest/core-api/task_struct.html. [Accessed: 15-Jun-2025].  

---

## 🙋‍♂️ Author

**Wanni46**  
3rd Year Undergraduate, Computer Engineering  
[GitHub Profile](https://github.com/Wanni46)

---

## 📝 License

This project is licensed under the [MIT License](LICENSE).

---
