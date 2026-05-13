#ifndef RUBIKS_CUBE_BITBOARD_H
#define RUBIKS_CUBE_BITBOARD_H

#include "RubiksCube.h"
#include <cstdint>
#include <string>

class RubiksCubeBitboard : public RubiksCube {
private:
    friend struct HashBitboard;
    uint64_t solved_side_config[6]{};
    uint64_t bitboard[6]{};

    int arr[3][3] = {
        {0, 1, 2},
        {7, 8, 3},
        {6, 5, 4}
    };

    uint64_t one_8 = (1ULL << 8) - 1;
    uint64_t one_24 = (1ULL << 24) - 1;

    // Helpers
    void rotateFace(int ind);
    void rotateSide(int s1, int s1_1, int s1_2, int s1_3,
                    int s2, int s2_1, int s2_2, int s2_3);

    int get5bitCorner(std::string corner);

public:
    RubiksCubeBitboard();

    COLOR getColor(FACE face, unsigned row, unsigned col) const override;
    void setColor(FACE face, int row, int col, COLOR color) override;
    bool isSolved() const override;

    MOVE parseMove(const std::string &s);

    // Moves
    RubiksCube &u() override;
    RubiksCube &uPrime() override;
    RubiksCube &u2() override;

    RubiksCube &l() override;
    RubiksCube &lPrime() override;
    RubiksCube &l2() override;

    RubiksCube &f() override;
    RubiksCube &fPrime() override;
    RubiksCube &f2() override;

    RubiksCube &r() override;
    RubiksCube &rPrime() override;
    RubiksCube &r2() override;

    RubiksCube &b() override;
    RubiksCube &bPrime() override;
    RubiksCube &b2() override;

    RubiksCube &d() override;
    RubiksCube &dPrime() override;
    RubiksCube &d2() override;

    // Operators
    bool operator==(const RubiksCubeBitboard &r1) const;
    RubiksCubeBitboard &operator=(const RubiksCubeBitboard &r1);

    // Corner encoding
    uint64_t getCorners();
};

// Hash function for unordered_map
struct HashBitboard {
    size_t operator()(const RubiksCubeBitboard &r1) const;
};

#endif // RUBIKS_CUBE_BITBOARD_H
