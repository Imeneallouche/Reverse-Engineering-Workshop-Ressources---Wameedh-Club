# 📚 **Tracing with ltrace and strace**

---

## 🎯 **Goal of This Lesson**

To understand how to use `strace` and `ltrace` to trace **system calls** and **library function calls** made by a binary, and how this helps in reverse engineering, debugging, and malware analysis.

---

## 🧠 1. What is Tracing?

**Tracing** means watching what a program does **in real time**. We're particularly interested in:

- Which **system calls** it makes (like reading a file, creating a process, etc.)
- Which **library functions** it uses (like `printf`, `malloc`, etc.)
- What arguments it sends and what it gets in return

---

## 🧪 2. Tools We’ll Use

| Tool     | What It Traces                  | Usage Example              |
| -------- | ------------------------------- | -------------------------- |
| `strace` | **System calls**                | File access, network, etc. |
| `ltrace` | **Library calls (glibc, etc.)** | `malloc`, `printf`, etc.   |

---

## 🧩 3. Basic Concepts

### 🔧 What is a **System Call**?

A request from a program to the OS kernel to do something: open files, read, write, create sockets...

### 🔧 What is a **Library Call**?

A function from a **shared library** (like glibc) used in your code, e.g., `printf()` or `strcpy()`.

---

## 🖥️ 4. Example C Code for Testing

```c
// trace_me.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("Hello, tracing world!\n");
    char* name = malloc(20);
    strcpy(name, "Imene");
    printf("Name: %s\n", name);
    free(name);
    return 0;
}
```

### 🔨 Compile:

```bash
gcc -o trace_me trace_me.c
```

---

## 🔍 5. Using `strace`

### ✅ Run:

```bash
strace ./trace_me
```

### 📦 Output (snippet):

```
write(1, "Hello, tracing world!\n", 23) = 23
brk(NULL) = 0x55b70aa42000
mmap(NULL, 4096, PROT_READ|PROT_WRITE, ...) = 0x7f...
...
```

### 🧠 Interpretation:

- `write` is used by `printf()` under the hood
- `brk`, `mmap` → memory management
- You see everything the **kernel** is asked to do

---

## 🔍 6. Using `ltrace`

### ✅ Run:

```bash
ltrace ./trace_me
```

### 📦 Output (snippet):

```
__libc_start_main(...)
printf("Hello, tracing world!\n") = 23
malloc(20) = 0x555555559260
strcpy(0x555555559260, "Imene") = 0x555555559260
printf("Name: %s\n", "Imene") = 12
free(0x555555559260)
```

### 🧠 Interpretation:

- You can see calls to **standard C library functions** like `malloc`, `strcpy`, `printf`
- You even see return values and arguments

---

## 📎 7. Key Differences Between strace & ltrace

| Feature                    | `strace`              | `ltrace`                   |
| -------------------------- | --------------------- | -------------------------- |
| Traces                     | System calls          | Library (shared) calls     |
| Layer                      | Kernel interface      | User-space libc functions  |
| Works even without symbols | ✅ Yes                | ❌ Needs symbols sometimes |
| Use case                   | I/O, networking, etc. | Debugging logic, memory    |

---

## 🚀 8. Advanced Usage

### 🛠️ Filter a specific syscall:

```bash
strace -e openat ./trace_me
```

### 🛠️ Save output to file:

```bash
strace -o trace.log ./trace_me
```

### 🛠️ Attach to running process:

```bash
strace -p <pid>
ltrace -p <pid>
```

---

## 🧠 9. Why It’s Useful in Reverse Engineering

- See **what files** a malware or binary opens
- Know if it connects to the **network**
- Understand **what’s happening without source code**
- Helps **trace errors**, **memory leaks**, and **hidden behavior**

---

## ⚠️ 10. Limitations

- `strace` can't show user-level logic or non-syscall functions
- `ltrace` doesn’t work well with statically linked or stripped binaries
- Obfuscated or encrypted binaries might hide real calls

---

## 💡 Final Tips

- Use both `strace` and `ltrace` **together** for full visibility
- Pair with tools like `gdb`, `radare2`, `ghidra` for deeper reversing
- Use `-f` with both to trace child processes:

```bash
strace -f ./binary
ltrace -f ./binary
```
