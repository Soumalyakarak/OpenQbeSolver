#include "RubiksCube1dArray.h"
#include <string>

// Rotate a face clockwise
void RubiksCube1dArray::rotateFace(int ind) {
    char temp_arr[9]{};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp_arr[i * 3 + j] = cube[getIndex(ind, i, j)];

    for (int i = 0; i < 3; i++) cube[getIndex(ind, 0, i)]     = temp_arr[getIndex(0, 2 - i, 0)];
    for (int i = 0; i < 3; i++) cube[getIndex(ind, i, 2)]     = temp_arr[getIndex(0, 0, i)];
    for (int i = 0; i < 3; i++) cube[getIndex(ind, 2, 2 - i)] = temp_arr[getIndex(0, i, 2)];
    for (int i = 0; i < 3; i++) cube[getIndex(ind, 2 - i, 0)] = temp_arr[getIndex(0, 2, 2 - i)];
}

// Constructor — set each face to a single color
RubiksCube1dArray::RubiksCube1dArray() {
    for (int face = 0; face < 6; face++)
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                cube[getIndex(face, row, col)] =
                    getColorLetter(static_cast<COLOR>(face));
}

RubiksCube::COLOR RubiksCube1dArray::getColor(FACE face, unsigned row, unsigned col) const {
    char color = cube[getIndex((int)face, (int)row, (int)col)];
    switch (color) {
        case 'B': return COLOR::BLUE;
        case 'R': return COLOR::RED;
        case 'G': return COLOR::GREEN;
        case 'O': return COLOR::ORANGE;
        case 'Y': return COLOR::YELLOW;
        default:  return COLOR::WHITE;
    }
}

bool RubiksCube1dArray::isSolved() const {
    for (int f = 0; f < 6; f++)
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                if (cube[getIndex(f, r, c)] != getColorLetter(static_cast<COLOR>(f)))
                    return false;

    return true;
}

// -------------------- MOVE U --------------------
RubiksCube& RubiksCube1dArray::u() {
    rotateFace(0);

    char tmp[3]{};
    for (int i = 0; i < 3; i++) tmp[i] = cube[getIndex(4, 0, 2 - i)];

    for (int i = 0; i < 3; i++) cube[getIndex(4, 0, 2 - i)] = cube[getIndex(1, 0, 2 - i)];
    for (int i = 0; i < 3; i++) cube[getIndex(1, 0, 2 - i)] = cube[getIndex(2, 0, 2 - i)];
    for (int i = 0; i < 3; i++) cube[getIndex(2, 0, 2 - i)] = cube[getIndex(3, 0, 2 - i)];
    for (int i = 0; i < 3; i++) cube[getIndex(3, 0, 2 - i)] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube1dArray::uPrime() { u(); u(); u(); return *this; }
RubiksCube& RubiksCube1dArray::u2()     { u(); u(); return *this; }

// -------------------- MOVE L --------------------
RubiksCube& RubiksCube1dArray::l() {
    rotateFace(1);

    char tmp[3]{};
    for (int i = 0; i < 3; i++) tmp[i] = cube[getIndex(0, i, 0)];

    for (int i = 0; i < 3; i++) cube[getIndex(0, i, 0)] = cube[getIndex(4, 2 - i, 2)];
    for (int i = 0; i < 3; i++) cube[getIndex(4, 2 - i, 2)] = cube[getIndex(5, i, 0)];
    for (int i = 0; i < 3; i++) cube[getIndex(5, i, 0)] = cube[getIndex(2, i, 0)];
    for (int i = 0; i < 3; i++) cube[getIndex(2, i, 0)] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube1dArray::lPrime() { l(); l(); l(); return *this; }
RubiksCube& RubiksCube1dArray::l2()     { l(); l(); return *this; }

// -------------------- MOVE F --------------------
RubiksCube& RubiksCube1dArray::f() {
    rotateFace(2);

    char tmp[3]{};
    for (int i = 0; i < 3; i++) tmp[i] = cube[getIndex(0, 2, i)];

    for (int i = 0; i < 3; i++) cube[getIndex(0, 2, i)] = cube[getIndex(1, 2 - i, 2)];
    for (int i = 0; i < 3; i++) cube[getIndex(1, 2 - i, 2)] = cube[getIndex(5, 0, 2 - i)];
    for (int i = 0; i < 3; i++) cube[getIndex(5, 0, 2 - i)] = cube[getIndex(3, i, 0)];
    for (int i = 0; i < 3; i++) cube[getIndex(3, i, 0)] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube1dArray::fPrime() { f(); f(); f(); return *this; }
RubiksCube& RubiksCube1dArray::f2()     { f(); f(); return *this; }

// -------------------- MOVE R --------------------
RubiksCube& RubiksCube1dArray::r() {
    rotateFace(3);

    char tmp[3]{};
    for (int i = 0; i < 3; i++) tmp[i] = cube[getIndex(0, 2 - i, 2)];

    for (int i = 0; i < 3; i++) cube[getIndex(0, 2 - i, 2)] = cube[getIndex(2, 2 - i, 2)];
    for (int i = 0; i < 3; i++) cube[getIndex(2, 2 - i, 2)] = cube[getIndex(5, 2 - i, 2)];
    for (int i = 0; i < 3; i++) cube[getIndex(5, 2 - i, 2)] = cube[getIndex(4, i, 0)];
    for (int i = 0; i < 3; i++) cube[getIndex(4, i, 0)] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube1dArray::rPrime() { r(); r(); r(); return *this; }
RubiksCube& RubiksCube1dArray::r2()     { r(); r(); return *this; }

// -------------------- MOVE B --------------------
RubiksCube& RubiksCube1dArray::b() {
    rotateFace(4);

    char tmp[3]{};
    for (int i = 0; i < 3; i++) tmp[i] = cube[getIndex(0, 0, 2 - i)];

    for (int i = 0; i < 3; i++) cube[getIndex(0, 0, 2 - i)] = cube[getIndex(3, 2 - i, 2)];
    for (int i = 0; i < 3; i++) cube[getIndex(3, 2 - i, 2)] = cube[getIndex(5, 2, i)];
    for (int i = 0; i < 3; i++) cube[getIndex(5, 2, i)] = cube[getIndex(1, i, 0)];
    for (int i = 0; i < 3; i++) cube[getIndex(1, i, 0)] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube1dArray::bPrime() { b(); b(); b(); return *this; }
RubiksCube& RubiksCube1dArray::b2()     { b(); b(); return *this; }

// -------------------- MOVE D --------------------
RubiksCube& RubiksCube1dArray::d() {
    rotateFace(5);

    char tmp[3]{};
    for (int i = 0; i < 3; i++) tmp[i] = cube[getIndex(2, 2, i)];

    for (int i = 0; i < 3; i++) cube[getIndex(2, 2, i)] = cube[getIndex(1, 2, i)];
    for (int i = 0; i < 3; i++) cube[getIndex(1, 2, i)] = cube[getIndex(4, 2, i)];
    for (int i = 0; i < 3; i++) cube[getIndex(4, 2, i)] = cube[getIndex(3, 2, i)];
    for (int i = 0; i < 3; i++) cube[getIndex(3, 2, i)] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube1dArray::dPrime() { d(); d(); d(); return *this; }
RubiksCube& RubiksCube1dArray::d2()     { d(); d(); return *this; }

// -------------------- Operators --------------------
bool RubiksCube1dArray::operator==(const RubiksCube1dArray& other) const {
    for (int i = 0; i < 54; i++)
        if (cube[i] != other.cube[i])
            return false;
    return true;
}

RubiksCube1dArray& RubiksCube1dArray::operator=(const RubiksCube1dArray& other) {
    if (this == &other) return *this;

    for (int i = 0; i < 54; i++)
        cube[i] = other.cube[i];

    return *this;
}

// -------------------- Hash --------------------
size_t Hash1d::operator()(const RubiksCube1dArray& r1) const {
    std::string s;
    s.reserve(54);

    for (int i = 0; i < 54; i++)
        s.push_back(r1.cube[i]);

    return std::hash<std::string>()(s);
}
