# C-Code Repository Walkthrough

This document is a **full guided walkthrough** of the C-Code repository. It explains **every major element**, with special focus on **C concepts learned**, **lecture-based modules**, and how everything is tied together through `main.c`.

> Scope note: This walkthrough **intentionally ignores CMake** and build configuration and focuses purely on **C code, concepts, and learning outcomes**.

---

## 1. Repository Purpose

This repository is a learning archive from the **IMPR (Imperative Programming)** course. It progresses from **fundamental C syntax** to **data structures, algorithms, memory management, file handling, and exam-style problems**.

The code is organized into:

* **Lecture modules** (incremental learning)
* **Assignments / afleveringer**
* **Mini-projects**
* **Algorithmic exercises (LeetCode-style)**

All concepts are *manually testable* from `main.c`.

---

## 2. main.c – The Central Control File

`main.c` is the **navigation hub** of the repository.

### Key characteristics

* Includes **all lecture headers**
* Includes **assignment modules**
* Contains **commented-out function calls** grouped by topic
* Allows selective execution of specific lessons

### What this teaches

* Program structure
* Modular compilation
* Header/source separation
* How to design a "test harness" in C

Each commented section in `main.c` corresponds to a **lecture or topic area**, making it a learning index.

---

## 3. Lecture Modules (Core Learning Path)

Lecture files are located in `lib/lectureX.c/.h`.

Each lecture introduces **new C concepts**, building on previous ones.

---

### Lecture 1 – Basics of C

**Files**

* `lecture1.c`
* `lecture1.h`

**Concepts learned**

* `printf` and basic I/O
* Variables and data types
* Arithmetic operations
* Function definition and calls

**Key takeaway**

> Understanding how C executes line-by-line and how data flows through functions.

---

### Lecture 2 – Control Flow

**Concepts**

* `if / else`
* `switch`
* Boolean logic
* Relational operators

**Why it matters**
Control flow is the backbone of all algorithms and decision-making logic.

---

### Lecture 3 – Loops

**Concepts**

* `for`, `while`, `do-while`
* Loop counters
* Nested loops

**Applied learning**

* Pattern printing
* Repetitive calculations

---

### Lecture 4 – Functions and Scope

**Concepts**

* Function parameters
* Return values
* Local vs global variables

**Important idea**

> Functions encapsulate logic and reduce repetition.

---

### Lecture 5–7 – Arrays and Strings

**Concepts**

* Arrays
* Indexing
* Character arrays (C strings)
* Manual string traversal

**Why this is critical**
C does **not** manage strings automatically—this teaches memory awareness.

---

### Lecture 8–9 – Pointers

**Concepts**

* Address-of (`&`)
* Dereferencing (`*`)
* Pointer arithmetic

**Mental shift**

> Variables are memory locations, not just values.

---

### Lecture 10–11 – Dynamic Memory

**Concepts**

* `malloc`, `calloc`, `free`
* Heap vs stack
* Memory ownership

**Key lesson**
Improper memory handling causes **leaks and crashes**.

---

### Lecture 12 – Structs

**Concepts**

* `struct` definitions
* Passing structs to functions
* Arrays of structs

**Why it matters**
Structs enable modeling real-world data.

---

### Lecture 13 – File I/O

**Concepts**

* `fopen`, `fclose`
* Reading/writing files
* Parsing formatted data

**Practical use**
Used later in projects and exam exercises.

---

## 4. Assignments (Afleveringer)

Located in `lib/AfleveringX.*`

### Aflevering 1

**Focus**

* Basic logic
* Functions
* Input/output

---

### Aflevering 2

**Focus**

* Arrays
* Loops
* Modular problem-solving

---

### Aflevering 3

**Focus**

* Structs
* Dynamic memory
* More complex state handling

---

## 5. Data Structures & Algorithms

### Search & Complexity

Functions demonstrate:

* Linear search
* Logarithmic complexity
* Big-O reasoning

---

### Hash Tables (Experimental)

**Concepts introduced**

* Hash functions
* Buckets
* Collisions

These files represent **advanced / extra credit learning**.

---

## 6. Cashier System

**Files**

* `cashier.c`
* `cashier.h`

**What it teaches**

* Struct-based modeling
* State machines
* Input validation

A realistic example of procedural system design.

---

## 7. Example Exam Problems

**Files**

* `exampleExam.c`

**Purpose**

* Simulate real exam difficulty
* Combine multiple concepts

These problems require:

* Clean logic
* Memory discipline
* Algorithmic thinking

---

## 8. Mini Projects

Located in `CMakeProjects/`

### Project 1 – Calculator

**Concepts used**

* Switch statements
* User input
* Modular functions

---

### Project 2 – Game of Lines

**Concepts used**

* 2D arrays
* Game state
* Turn handling

---

## 9. LeetCode Folder

Contains algorithmic challenges:

* String parsing
* Linked lists
* Trees
* Sliding window techniques

These improve:

* Problem-solving speed
* Interview readiness

---

## 10. What This Repository Teaches Overall

By the end of this repository, you have learned:

* ✅ Core C syntax
* ✅ Memory management
* ✅ Pointers and structs
* ✅ File handling
* ✅ Algorithmic thinking
* ✅ Modular program design

This repository represents a **complete foundation in C programming**.

---

## 11. How to Use This Walkthrough

Recommended learning order:

1. Follow lectures numerically
2. Run examples from `main.c`
3. Study afleveringer
4. Attempt exam exercises
5. Explore LeetCode solutions

---

## Final Note

This codebase is not just a collection of files—it is a **learning journey**.

If you can explain *why* each file exists and *what* it teaches, you understand C.

💪

---

## 12. Deep Dive: Core C Data Types

Understanding **data types** is fundamental in C because memory management is explicit. Below is a complete overview of all core data types used throughout this repository.

> ⚠️ Sizes are architecture-dependent. The sizes listed below assume a **64-bit system**, which is what you should expect on modern Linux/macOS systems.

### Integer Types

| Type             | Size    | Description                    | Typical Use              |
| ---------------- | ------- | ------------------------------ | ------------------------ |
| `char`           | 1 byte  | Smallest addressable unit      | Characters, byte buffers |
| `signed char`    | 1 byte  | Signed character (-128 to 127) | Raw numeric bytes        |
| `unsigned char`  | 1 byte  | 0 to 255                       | Binary data              |
| `short`          | 2 bytes | Small integer                  | Compact counters         |
| `unsigned short` | 2 bytes | Positive small integer         | Sizes, flags             |
| `int`            | 4 bytes | Default integer type           | Loop counters, indexes   |
| `unsigned int`   | 4 bytes | Non-negative int               | Array sizes              |
| `long`           | 8 bytes | Large integer                  | File sizes, timestamps   |
| `unsigned long`  | 8 bytes | Positive large integer         | Memory sizes             |
| `long long`      | 8 bytes | Very large integer             | Big calculations         |

**Key lessons from the repo**

* Use `int` by default unless size matters
* Use `unsigned` for sizes and indexes
* Avoid mixing signed and unsigned

---

### Floating-Point Types

| Type          | Size     | Precision  | Use Case                   |
| ------------- | -------- | ---------- | -------------------------- |
| `float`       | 4 bytes  | ~6 digits  | Performance-sensitive math |
| `double`      | 8 bytes  | ~15 digits | Most calculations          |
| `long double` | 16 bytes | Extended   | Scientific calculations    |

Used sparingly in the repo, but critical for:

* Averages
* Measurements
* Mathematical formulas

---

### Boolean Type

| Type    | Size   | Description              |
| ------- | ------ | ------------------------ |
| `_Bool` | 1 byte | Built-in boolean         |
| `bool`  | 1 byte | Alias from `<stdbool.h>` |

Used heavily for:

* Flags
* State machines
* Condition tracking

---

### Pointer Types

| Type | Size    | Meaning             |
| ---- | ------- | ------------------- |
| `T*` | 8 bytes | Address of type `T` |

**Critical rule**

> All pointers have the same size, regardless of what they point to.

Core lessons taught:

* Passing data by reference
* Dynamic memory ownership
* Avoiding dangling pointers

---

### Arrays

Arrays are **contiguous blocks of memory**.

```c
int arr[10];
```

* Total size = `sizeof(type) * length`
* Arrays decay into pointers when passed to functions

The repo teaches:

* Manual bounds control
* Why C does NOT track array size

---

### Structs

Structs combine multiple data types into one unit.

```c
typedef struct {
    int id;
    char name[50];
    float price;
} Product;
```

Memory layout:

* Members are laid out sequentially
* Padding may be added for alignment

Used extensively for:

* Modeling real-world entities
* Grouping related data

---

### Enums

```c
typedef enum {
    FALSE,
    TRUE
} Boolean;
```

* Stored as integers
* Improve readability
* Used for program states

---

## 13. Memory Model Deep Dive

### Stack vs Heap

| Stack        | Heap     |
| ------------ | -------- |
| Automatic    | Manual   |
| Fast         | Flexible |
| Limited size | Large    |

Stack usage:

* Local variables
* Function calls

Heap usage:

* Dynamic arrays
* Structs with unknown lifetime

The repository repeatedly emphasizes:

> If you `malloc`, you must `free`.

---

## 14. Pointer & Memory Pitfalls (Seen in Exercises)

Common mistakes addressed in the repo:

* ❌ Forgetting to `free`
* ❌ Double-free
* ❌ Returning pointers to stack memory
* ❌ Using uninitialized pointers

Correct patterns demonstrated:

```c
int *arr = malloc(sizeof(int) * n);
if (!arr) return NULL;
// use arr
free(arr);
```

---

## 15. How main.c Ties Everything Together

Each section in `main.c` represents:

* A lecture
* An assignment
* A problem category

By uncommenting sections, the student practices:

* Isolated testing
* Debugging
* Incremental development

This mirrors **real-world C development workflows**.

---

## 16. Final Learning Outcomes (Expanded)

After completing this repository, you can confidently:

* Reason about memory layout
* Debug pointer issues
* Design modular C programs
* Translate real problems into C logic
* Read and understand legacy C code

This is **not beginner-level knowledge**—this is a solid systems foundation.

---

## 17. Suggested Improvements (Optional)

If this were expanded further:

* Add Valgrind exercises
* Introduce unit testing
* Add documentation comments (`/** */`)

---

End of walkthrough.
