# C-Code

A collection of C programming exercises, projects, and implementations created during my IMPR (Imperative Programming) course.

## 📋 Table of Contents

- [Overview](#overview)
- [Repository Structure](#repository-structure)
- [Projects](#projects)
- [Lecture Exercises](#lecture-exercises)
- [LeetCode Solutions](#leetcode-solutions)
- [Building and Running](#building-and-running)
- [License](#license)

## 🎯 Overview

This repository contains various C programs ranging from basic exercises to complex projects, including algorithm implementations, games, and problem-solving challenges. The code demonstrates concepts like data structures, algorithms, file I/O, pointers, and memory management.

## 📁 Repository Structure

```
C-Code/
├── CMakeProjects/          # Standalone CMake projects
│   ├── project1/          # Calculator project
│   ├── project2/          # Game of Lines (Tic-Tac-Toe variant)
│   ├── miniproject2/      # Mini project 2
│   └── miniproject3/      # Mini project 3
├── src/                   # Source files for various exercises
├── lib/                   # Header files
├── leetcode/              # LeetCode problem solutions
├── main.c                 # Main entry point with test cases
└── CMakeLists.txt         # CMake configuration
```

## 🚀 Projects

### Project 1: Calculator
**Location:** `CMakeProjects/project1/`

A command-line calculator with an accumulator that supports basic arithmetic operations.

**Features:**
- Persistent accumulator across operations
- Supports operators: `+`, `-`, `*`, `/`, `#`, `!`
- Interactive command-line interface
- Quit functionality with final result display

### Project 2: Game of Lines
**Location:** `CMakeProjects/project2/`

A customizable tic-tac-toe variant with AI opponent support.

**Features:**
- Configurable arena size (NxN grid)
- Adjustable win condition (K in a row)
- Play against another player or AI
- Dynamic memory allocation for game board

## 📚 Lecture Exercises

The `src/` directory contains implementations from various lectures:

### Core Exercises
- **Aflevering1-3**: Assignment submissions
- **lecture1-12**: Weekly lecture exercises covering: 
  - Basic I/O operations
  - Control structures
  - Functions and pointers
  - Arrays and strings
  - File handling
  - Command-line arguments

### Algorithms & Data Structures
- **mergesort. c**: Merge sort implementation
- **searchCompare.c**:  Comparison of search algorithms
- **nlognfac.c**: Time complexity demonstrations
- **hashtables**:  Hash table implementations
  - `openAddressing-hashtables.c`: Open addressing collision resolution
  - `externalChaning-hashtables.c`: Separate chaining collision resolution

### Utility Programs
- **sqrt.c**: Multiple square root implementations
  - Heron's method
  - Binary search approach
  - Quake's fast inverse square root
  - Floating-point iteration
- **printingPatterns.c**: ASCII pattern printing (pyramids, diamonds, etc.)
- **stensakspapir.c**: Rock-Paper-Scissors game
- **lommeregner.c**: Calculator implementation
- **cashier.c**: Cash register simulation
- **sudoSolver.c**: Sudoku solver using backtracking

## 💻 LeetCode Solutions

Solutions to various LeetCode problems in C:

| Problem | File | Difficulty |
|---------|------|-----------|
| Two Sum | `leetcode/TwoNumbers.c` | Easy |
| Add Two Numbers | `leetcode/AddTwoNumbers.c` | Medium |
| Roman to Integer | `leetcode/romanToInt.c` | Easy |
| Ransom Note | `leetcode/ransomNotes.c` | Easy |
| Lowest Common Ancestor | `leetcode/LowestCommonAncestor.c` | Medium |
| Minimum Number of Operations | `leetcode/MinimumNumberofOperations. c` | - |

## 🔧 Building and Running

### Prerequisites
- C compiler (GCC/Clang)
- CMake (version 3.0 or higher)

### Build Instructions

#### Using CMake (Recommended)
```bash
# Clone the repository
git clone https://github.com/LukasLLaebel/C-Code.git
cd C-Code

# Create build directory
mkdir build && cd build

# Generate build files
cmake ..

# Build the project
cmake --build .

# Run the executable
./C-Code
```

#### For Individual Projects
```bash
cd CMakeProjects/project1  # or project2
mkdir build && cd build
cmake ..
cmake --build .
./project1  # or ./project2
```

### Running Specific Exercises

Edit `main.c` and uncomment the function you want to run:

```c
int main() {
    // Uncomment the exercise you want to run
    // exercise1_1();
    // stensakspapir_game();
    // SudokuSolver();
    
    return 0;
}
```

Then rebuild and run. 

## 📝 Usage Examples

### Calculator (Project 1)
```
Enter operation (e. g., + 5) or 'q' to quit:  + 10
Output: 10. 00
Enter operation (e.g., + 5) or 'q' to quit: * 5
Output: 50.00
Enter operation (e.g., + 5) or 'q' to quit: q
Final result is:  50.000000
```

### Game of Lines (Project 2)
```
Welcome to Game of Lines!
Play against (0) another player or (1) the computer?  1
Enter arena size (e.g.  3 for 3x3): 3
Enter how many in a row to win:  3
```

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🎓 Course Information

This repository was created as part of the **IMPR (Imperative Programming)** course, containing exercises, assignments, and projects completed throughout the semester. 

## 👤 Author

**Lukas L. Laebel** ([@LukasLLaebel](https://github.com/LukasLLaebel))

---

*Feel free to explore, learn, and use this code as a reference for your own C programming journey!*
