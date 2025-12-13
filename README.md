# Rubik’s Cube Solver (C++17)
### **Bitboard | 1D | 3D | Heuristic Search (A\*, IDA\*) | Pattern Database | Full 18-Move Support**

A high-performance Rubik’s Cube solver written in modern **C++17**, featuring **heuristic search algorithms**, optimized cube representations, and a **Pattern Database** heuristic for extremely fast optimal solving.

This project demonstrates advanced topics in **Artificial Intelligence** such as:

- **Heuristic Search Algorithms (A\*, IDA\*)**
- **Creating & Using Pattern Databases (PDBs)**
- **State-space pruning**
- **Admissible heuristics**
- **Optimal solving under large branching factors**

---

## Features

### **AI & Heuristic Search**
- **A\*** and **IDA\*** algorithms implemented
- Uses **Corner Pattern Database** as an admissible heuristic  
- Demonstrates AI concepts used in real search engines

### Cube Representations
- **3D Array model**
- **1D Linear Array model**
- **Bitboard model** (compact & extremely fast)

### Solvers Implemented
- DFS  
- BFS  
- IDDFS  
- **IDA\*** (**Iterative Deepening A\***)

### Move Support
**All 18 face moves implemented:**
U U' U2 (Up)
D D' D2 (Down)
L L' L2 (Left)
R R' R2 (Right)
F F' F2 (Front)
B B' B2 (Back)

---

### Build Instructions

### Prepare the Pattern Database (PDB)

The Corner Pattern Database (PDB) file is crucial for the IDA* heuristic. Recruiters must ensure two conditions are met before running the solver:

1.  **Adjust the PDB File Path (in Main Solver File)**
    * **Action:** Open your main solver file (e.g., `main.cpp`).
    * **Detail:** Change the hardcoded PDB file path (e.g., `string fileName = "/home/somu/..."`) to the exact location where the `cornerDepth5V1.txt` file will be stored/read from on your system.

2.  **Adjust Generation Depth (in `CornerDBMaker.cpp`)**
    * **Action:** Open the `CornerDBMaker.cpp` file within the `PatternDatabases` directory.
    * **Detail:** Find the constant controlling the maximum BFS depth. The memory and time for generation are system-dependent. Start with a depth of **4 or 5**. All states not computed will be initialized with a value one greater than the max depth, serving as a valid **admissible heuristic**.

---

### Build
```bash
mkdir build
cd build
cmake ..
make
./rubiks_cube_solver
```
### Future Scope

### Real Cube Scanner Using OpenCV**
Planned future feature:

- Scan a real Rubik’s Cube using your **webcam**
- Detect sticker colors using OpenCV  
- Convert into digital cube state  
- Solve using IDA\*  
- Display the solution step-by-step  
