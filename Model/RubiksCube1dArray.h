#ifndef RUBIKS_CUBE_1D_ARRAY_H
#define RUBIKS_CUBE_1D_ARRAY_H

#include "RubiksCube.h"
#include <cstddef>
#include <string>

class RubiksCube1dArray : public RubiksCube {
private:
    /*
     * Given a face index, row and col, return its flattened 1D index.
     */
    static inline int getIndex(int face, int row, int col) {
        return (face * 9) + (row * 3) + col;
    }

    void rotateFace(int face);

public:
    char cube[54]{};  // 6 faces × 9 entries

    RubiksCube1dArray();

    // Required overrides
    COLOR getColor(FACE face, unsigned row, unsigned col) const override;
    bool isSolved() const override;

    RubiksCube& u() override;
    RubiksCube& uPrime() override;
    RubiksCube& u2() override;

    RubiksCube& l() override;
    RubiksCube& lPrime() override;
    RubiksCube& l2() override;

    RubiksCube& f() override;
    RubiksCube& fPrime() override;
    RubiksCube& f2() override;

    RubiksCube& r() override;
    RubiksCube& rPrime() override;
    RubiksCube& r2() override;

    RubiksCube& b() override;
    RubiksCube& bPrime() override;
    RubiksCube& b2() override;

    RubiksCube& d() override;
    RubiksCube& dPrime() override;
    RubiksCube& d2() override;

    // Comparison and assignment
    bool operator==(const RubiksCube1dArray& other) const;
    RubiksCube1dArray& operator=(const RubiksCube1dArray& other);
};

// Hash functor for unordered_map
struct Hash1d {
    size_t operator()(const RubiksCube1dArray& r1) const;
};

#endif // RUBIKS_CUBE_1D_ARRAY_H
