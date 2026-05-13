cmake_minimum_required(VERSION 3.20)
project(rubiks_cube_solver)

# ------------------ C++ standard ------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------ OpenCV ------------------
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")

# ------------------ Executable ------------------
add_executable(rubiks_cube_solver
        main.cpp

        Model/RubiksCube.cpp
        Model/RubiksCube.h
        Model/RubiksCube3dArray.cpp
        Model/RubiksCube1dArray.cpp
        Model/RubiksCubeBitboard.cpp


        # -------- Scanner --------
        Scanner/CubeScanner.cpp
        Scanner/CubeScanner.h

        Solver/DFSSolver.h
        Solver/BFSSolver.h
        Solver/IDDFSSolver.h
        Solver/IDAstarSolver.h

        PatternDatabases/NibbleArray.cpp
        PatternDatabases/NibbleArray.h
        PatternDatabases/PatternDatabase.cpp
        PatternDatabases/PatternDatabase.h
        PatternDatabases/PermutationIndexer.h
        PatternDatabases/CornerPatternDatabase.cpp
        PatternDatabases/CornerPatternDatabase.h
        PatternDatabases/CornerDBMaker.cpp
        PatternDatabases/CornerDBMaker.h
        PatternDatabases/math.cpp
        PatternDatabases/math.h
)

# ------------------ Include directories ------------------
target_include_directories(rubiks_cube_solver PRIVATE
        ${OpenCV_INCLUDE_DIRS}
        Model
        Solver
        PatternDatabases
)

# ------------------ Link libraries ------------------
target_link_libraries(rubiks_cube_solver
        ${OpenCV_LIBS}
)
