# Rubik’s Cube Solver (C++17)

### Bitboard | 1D | 3D | Heuristic Search (IDA\*) | Pattern Database | Full 18-Move Support

A high-performance Rubik’s Cube solver written in modern **C++17**, featuring multiple cube representations, classical search algorithms, and an optimized **IDA\*** solver powered by a **Corner Pattern Database (PDB)** heuristic.

This project demonstrates several important concepts from:

- Artificial Intelligence
- Heuristic Search
- State Space Optimization
- Admissible Heuristics
- Graph Search Algorithms
- Compact Data Representation

---

# Features

## AI & Heuristic Search
- **IDA\*** (Iterative Deepening A\*)
- Pattern Database heuristic
- Admissible heuristic search
- State-space pruning
- Optimized search using precomputed states

---

## Cube Representations
Implemented multiple internal cube models:

- **3D Array Representation**
- **1D Linear Representation**
- **Bitboard Representation** (fastest & memory efficient)

---

## Solvers Implemented
- DFS
- BFS
- IDDFS
- **IDA\*** + Pattern Database

---

## Move Support

All standard **18 Rubik’s Cube moves** are implemented:

```text
U  U'  U2
D  D'  D2
L  L'  L2
R  R'  R2
F  F'  F2
B  B'  B2
```

---

# Solver Performance Comparison (Experimental)

### System Note
Benchmarks were measured locally.  
Actual timings may vary depending on CPU, memory, cache usage, and operating system scheduling.

*Depth refers to shuffle depth, not necessarily optimal solution depth.*

| Solver | Shuffle Depth | Representation | Time Taken |
| :--- | :---: | :---: | :---: |
| DFS | 6 | 3D Array | 3.6 s |
| BFS | 6 | Bitboard | 13.9 s |
| IDDFS | 7 | Bitboard | 69.7 s |
| **IDA\* + PDB** | **13** | **Bitboard** | **1.2 s** |

---

# Clone and Build

## Clone Repository

```bash
git clone https://github.com/Soumalyakarak/OpenQbeSolver.git
cd OpenQbeSolver
```

---

## Build Project

```bash
mkdir build
cd build
cmake ..
make
```

---

## Run Solver

```bash
./rubiks_cube_solver
```

---

# How To Use

The project is now organized into **separate clean sections** inside `main.cpp`.

Each section is grouped and commented separately for:

- Cube testing
- Database creation
- DFS testing
- BFS testing
- IDDFS testing
- IDA\* testing
- Scanner testing

### Important
Keep **only one section uncommented at a time** while testing.

Example:

```cpp
// =========================================================
// SECTION 6 : IDA* SOLVER TEST
// =========================================================
```

This makes debugging and benchmarking much easier.

---

# Pattern Database (Optional)

The project already includes a pre-generated:

```text
cornerDepth5V1.txt
```

So users can directly run the solver without generating the database again.

---

## Creating Corner Pattern Database (Optional)

If you still want to generate your own Corner Pattern Database:

1. Open `main.cpp`
2. Uncomment only the **DATABASE CREATION SECTION**
3. Run the program

Example:

```cpp
CornerDBMaker dbMaker("cornerDepth5V1.txt", 0x99);
dbMaker.bfsAndStore();
```

---

## PDB Generation Notes

Higher depths improve heuristic quality but increase preprocessing time and memory usage.

| Depth | Estimated States |
| :---: | :---: |
| 4 | 43.25 K |
| 5 | 577.36 K |
| 6 | 7.67 M |
| 7 | 102.03 M |
| 8 | 1.35 B |

---

# Why IDA\* + Pattern Database?

A normal brute-force search becomes impractical because the Rubik’s Cube has an enormous state space.

Using:

- IDA\*
- Admissible heuristics
- Pattern Databases

allows the solver to drastically reduce explored states and solve cubes significantly faster.

---

# Future Scope

## OpenCV Real Cube Scanner
Planned feature:

- Scan a real Rubik’s Cube using webcam
- Detect sticker colors with OpenCV
- Convert scanned colors into cube state
- Solve digitally using IDA\*
- Display move-by-move solution

---

# Technologies Used

- C++17
- STL
- CMake
- OpenCV (planned)

---

# Author

Soumalya Karak  