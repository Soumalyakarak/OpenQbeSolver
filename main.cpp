#include <bits/stdc++.h>
#include "Scanner/CubeScanner.h"
#include "Model/RubiksCube3dArray.h"
#include "Model/RubiksCube1dArray.h"
#include "Model/RubiksCubeBitboard.h"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
#include "PatternDatabases/CornerPatternDatabase.h"
#include "PatternDatabases/CornerDBMaker.h"
#include <chrono>
using namespace std::chrono;
using namespace std;

int main()
{
    //    RubiksCube3dArray object3DArray;
    //    RubiksCube1dArray object1dArray;
    //    RubiksCubeBitboard objectBitboard;

    //    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    objectBitboard.u();
    //    object3DArray.u();
    //    object1dArray.u();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.l();
    //    object3DArray.l();
    //    object1dArray.l();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.f();
    //    object3DArray.f();
    //    object1dArray.f();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.r();
    //    object3DArray.r();
    //    object1dArray.r();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.b();
    //    object3DArray.b();
    //    object1dArray.b();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.d();
    //    object3DArray.d();
    //    object1dArray.d();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    objectBitboard.dPrime();
    //    object3DArray.dPrime();
    //    object1dArray.dPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.bPrime();
    //    object3DArray.bPrime();
    //    object1dArray.bPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.rPrime();
    //    object3DArray.rPrime();
    //    object1dArray.rPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.fPrime();
    //    object3DArray.fPrime();
    //    object1dArray.fPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.lPrime();
    //    object3DArray.lPrime();
    //    object1dArray.lPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    objectBitboard.uPrime();
    //    object3DArray.uPrime();
    //    object1dArray.uPrime();
    //    objectBitboard.print();
    //    object3DArray.print();
    //    object1dArray.print();
    //
    //    if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";
    //
    //    if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
    //    else cout << "NOT SOLVED\n\n";


    // Create two Cubes ------------------------------------------------------------------------------------------


    //    RubiksCube3dArray cube1;
    //    RubiksCube3dArray cube2;
    //    cube1.print();
    //    cube2.l();
    //    cube2.print();

    //    cube2 = cube1;
    //    cube2.print();

    //    RubiksCube1dArray cube1;
    //    RubiksCube1dArray cube2;

    //    RubiksCubeBitboard cube1;
    //    RubiksCubeBitboard cube2;

    //  Equality and assignment of cubes --------------------------------------------------------------------------


    //    if(cube1 == cube2) cout << "Is equal\n";
    //    else cout << "Not Equal\n";
    //
    //    cube1.randomShuffleCube(1);
    //
    //    if(cube1 == cube2) cout << "Is equal\n";
    //    else cout << "Not Equal\n";
    //
    //    cube2 = cube1;
    //
    //    if(cube1 == cube2) cout << "Is equal\n";
    //    else cout << "Not Equal\n";

    //  Unordered_map of Cubes  ------------------------------------------------------------------------------------


    //    unordered_map<RubiksCube3dArray, bool, Hash3d> mp1;

    //    unordered_map<RubiksCube1dArray, bool, Hash1d> mp1;

    //    unordered_map<RubiksCubeBitboard, bool, HashBitboard> mp1;
    //
    //    mp1[cube1] = true;
    //    cube2.randomShuffleCube(8);
    //    if (mp1[cube1]) cout << "Cube1 is present\n";
    //    else cout << "Cube1 is not present\n";
    //
    //    if (mp1[cube2]) cout << "Cube2 is present\n";
    //    else cout << "Cube2 is not present\n";
    //

    //------------------------------ DFS Solver Testing -------------------------------------------------------


    //   RubiksCube3dArray cube;
    //   cube.print();

    //   vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
    //   for (auto move : shuffle_moves)
    //       cout << cube.getMove(move) << " ";
    //   cout << "\n";
    //   cube.print();

    //   auto start = std::chrono::high_resolution_clock::now();

    //   DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 6);
    //   vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();

    //   auto end = std::chrono::high_resolution_clock::now();
    //   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    //   for (auto move : solve_moves)
    //       cout << cube.getMove(move) << " ";
    //   cout << "\n";
    //   dfsSolver.rubiksCube.print();

    //   cout << "Time taken (DFS): " << duration.count() << " ms\n";


    // ----------------------------------BFS Solver --------------------------------------------------------------


    //    RubiksCubeBitboard cube;
    //    cube.print();

    //   vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    //   for (auto move : shuffle_moves)
    //       cout << cube.getMove(move) << " ";
    //   cout << "\n";
    //   cube.print();

    //   auto start = std::chrono::high_resolution_clock::now();

    //   BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube);
    //   vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();

    //   auto end = std::chrono::high_resolution_clock::now();
    //   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    //   for (auto move : solve_moves)
    //       cout << cube.getMove(move) << " ";
    //   cout << "\n";
    //   bfsSolver.rubiksCube.print();

    //   cout << "Time taken (BFS): " << duration.count() << " ms\n";


    //-------------------------------------------- IDDFS Solver ----------------------------------------------------


    //   RubiksCubeBitboard cube;
    //   cube.print();

    //   vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
    //   for (auto move : shuffle_moves)
    //       cout << cube.getMove(move) << " ";
    //   cout << "\n";
    //   cube.print();

    //   auto start = std::chrono::high_resolution_clock::now();

    //   IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cube, 7);
    //   vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();

    //   auto end = std::chrono::high_resolution_clock::now();
    //   auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    //   for (auto move : solve_moves)
    //       cout << cube.getMove(move) << " ";
    //   cout << "\n";
    //   iddfsSolver.rubiksCube.print();

    //   cout << "Time taken (IDDFS): " << duration.count() << " ms\n";


    //-------------------- DATABASE CREATION SECTION,UNCOMMENT ONLY WHEN CREATING DATABASE-----------------------------

     // If you clone this repository , update the path below:
    //  string fileName = "/home/somu/Documents/OpenQbeSolver/Databases/cornerDepth5V1.txt";

    // Code to create Corner Database
    // CornerDBMaker dbMaker(fileName, 0x99);
    // dbMaker.bfsAndStore();


    //------------------------------------------------- IDA* SOLVER ----------------------------------------------------


    RubiksCubeBitboard cube;
    cube.print();
    
    int n;
    cout << "Enter number of scramble moves: ";
    cin >> n;
    
    vector<RubiksCube::MOVE> scramble_moves;
    cout << "Enter moves (like U, U', U2, R, R', R2 ...):\n";
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
    
        RubiksCube::MOVE move = cube.parseMove(s);
        scramble_moves.push_back(move);
        cube.move(move);
    }
    
    cout << "Scrambled cube:\n";
    cube.print();
    
    IDAstarSolver<RubiksCubeBitboard, HashBitboard>
        idAstarSolver(cube, "cornerDepth5V1.txt");
    
    vector<RubiksCube::MOVE> solve_moves =
        idAstarSolver.solve();
    
    cout << "Solution moves: ";
    for (auto move : solve_moves)
        cout << cube.getMove(move) << " ";
    
    cout << "\n";
    
    cout << "Solved cube:\n";
    idAstarSolver.rubiksCube.print();


    //-------------------------------------------------CornerPatternDatabase Testing ----------------------------------------------


    //    CornerPatternDatabase cornerDB;
    //    RubiksCubeBitboard cube;
    //    cube.print();

    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";

    //    cornerDB.setNumMoves(cube, 5);

    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";

    //    cube.randomShuffleCube(1);
    //    cube.print();
    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";

    //    cornerDB.setNumMoves(cube, 6);

    //    cout << (int)cornerDB.getNumMoves(cube) << "\n";


    //-------------------------------------------- CornerDBMaker Testing -------------------------------------------------------------


    // cout << "OpenCV version: " << CV_VERSION << endl;
    // RubiksCubeBitboard cube;
    // auto shuffleMoves = cube.randomShuffleCube(13);

    // cube.print();

    // auto start = high_resolution_clock::now();

    // for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    // cout << "\n";

    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, "cornerDepth5V1.txt");
    // auto moves = idaStarSolver.solve();

    // auto end = high_resolution_clock::now();
    // auto duration = duration_cast<milliseconds>(end - start);

    // idaStarSolver.rubiksCube.print();

    // cout << "Solution in moves:\n";
    // for (auto move: moves) cout << cube.getMove(move) << " ";
    // cout << "\n";

    // cout << "Time taken: " << duration.count() << " ms\n";


    /*----------------------------------CubeScanner Testing---------------------------------------------------------*/


    // string fileName = "/home/somu/Documents/OpenQbeSolver/Databases/cornerDepth5V1.txt";

    // CubeScanner scanner(0);
    // RubiksCubeBitboard cube;
    // scanner.scan(cube);
    // cube.print();

    // if (!cube.isValidCube()) {
    //     cout << "Cube is invalid. Please rescan carefully.\n";
    //     return 0;
    // }

    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> idAstarSolver(cube, fileName);
    // auto solve_moves = idAstarSolver.solve();

    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // idAstarSolver.rubiksCube.print();


    /*--------------------------------------------------------------------------------*/


    // RubiksCubeBitboard testCube;
    // testCube.u().l();
    // cout << "Programmatic U L:\n";
    // testCube.print();

    // cout << "Scanned U L:\n";
    // cube.print();  // your scanned cube
    return 0;
}