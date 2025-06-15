# 🧮 Fibonacci Process Lab (EEX5335) — Live Demo & Report

[![Platform: WSL2 + Ubuntu](https://img.shields.io/badge/Platform-WSL2--Ubuntu-blue)](https://ubuntu.com/wsl)
[![Language: C](https://img.shields.io/badge/Language-C-blue)](https://gcc.gnu.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

This repository contains my implementation for the **EEX5335 Operating Systems Lab 01**. Here, I demonstrate inter-process communication in Linux by generating the Fibonacci sequence in a child process using `fork()` and `wait()`, with real-time error handling and process management.

---

## 🚀 Live Action / Demo

### 🏁 Step 1: Install WSL2 and Ubuntu

#### Enable Required Windows Features

1. **Open Start Menu** → Search for **"Windows Features"** → Open **Turn Windows Features on or off**.
2. Enable:
   - ✅ **Windows Subsystem for Linux**
   - ✅ **Virtual Machine Platform**
3. Click **OK** and **Restart** your computer.

#### Install WSL and Ubuntu

- Open **Windows PowerShell** and run:
  ```sh
  wsl --install
  ```
  This command installs WSL2 and sets Ubuntu as the default Linux distribution.

#### Create a Linux User

- After installation, a terminal window will prompt you to:
  - Enter a **username**
  - Set a **password**

#### Launch Ubuntu Terminal

- Open the Ubuntu terminal from the Start Menu.  
  (You should see a dedicated Ubuntu terminal with a maroon interface.)

---

### 🔧 Step 2: Initial Setup in Ubuntu

#### Update Package Lists

```sh
sudo apt update && sudo apt upgrade
```

#### Install Required Tools

```sh
sudo apt install build-essential gcc
```

---

### 👨‍💻 Step 3: Clone This Repository

```sh
git clone https://github.com/Wanni46/EEX5335-Lab01-Fibonacci-Process.git
cd EEX5335-Lab01-Fibonacci-Process
```

---

### ⚙️ Step 4: Compile the C Program

```sh
gcc fibonacci_fork.c -o fibonacci_fork
```

---

### ▶️ Step 5: Run the Program

```sh
./fibonacci_fork
```

---

### 🎥 Example Live Session

```plaintext
Enter the number of Fibonacci terms: 8

[Child Process] PID: 3456
Fibonacci Sequence: 0 1 1 2 3 5 8 13 
[Child Process] Computation complete. Exiting...

[Parent Process] PID: 3455
Child process has completed execution.
```

**Invalid Input Example:**
```
Enter the number of Fibonacci terms: 0
Please enter a number between 1 and 50.
```

---

## 📝 About the Code

- Prompts user for a number (1–50) for Fibonacci terms.
- Uses `fork()` to spawn a child process.
- Child process calculates and prints the Fibonacci sequence (and its PID).
- Parent waits for the child (`wait()`), then prints its own PID.
- Handles invalid input and fork failures gracefully.

### Main Source

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

## 💻 Tools & Environment

- **OS:** Windows 10 (64-bit)
- **Linux:** Ubuntu 24.04.2 LTS via WSL2
- **Compiler:** GCC 13.4
- **Editor:** Visual Studio Code
- **Terminal:** Ubuntu Terminal in WSL2

---

## 🧑‍🎓 What I Learned

- Creating and synchronizing processes using `fork()` & `wait()`
- Understanding parent/child memory separation and PIDs
- Robust error handling in system programming
- Efficient workflow using VS Code, WSL2, and GitHub

---

## 🔗 GitHub Repository

[github.com/Wanni46/EEX5335-Lab01-Fibonacci-Process](https://github.com/Wanni46/EEX5335-Lab01-Fibonacci-Process)

---

## 📚 References

[1] A. Silberschatz, P. B. Galvin, and G. Gagne, _Operating System Concepts_, 8th ed. Hoboken, NJ, USA: Wiley, 2008.  
[2] “fork(2) - Linux manual page,” [Online]. Available: https://man7.org/linux/man-pages/man2/fork.2.html. [Accessed: 15-Jun-2025].  
[3] “wait(2) - Linux manual page,” [Online]. Available: https://man7.org/linux/man-pages/man2/wait.2.html. [Accessed: 15-Jun-2025].  
[4] “task_struct — Core kernel documentation,” [Online]. Available: https://www.kernel.org/doc/html/latest/core-api/task_struct.html. [Accessed: 15-Jun-2025].  

---

## 📝 License

MIT License - see [LICENSE](LICENSE) for details.

---

## 📷 Screenshots

> _Add your own live terminal screenshots here for full marks!_

---
