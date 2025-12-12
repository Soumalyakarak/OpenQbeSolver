#include "RubiksCube3dArray.h"
#include <string>

void RubiksCube3dArray::rotateFace(int ind) {
    char temp_arr[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp_arr[i][j] = cube[ind][i][j];

    for (int i = 0; i < 3; i++) cube[ind][0][i] = temp_arr[2 - i][0];
    for (int i = 0; i < 3; i++) cube[ind][i][2] = temp_arr[0][i];
    for (int i = 0; i < 3; i++) cube[ind][2][2 - i] = temp_arr[i][2];
    for (int i = 0; i < 3; i++) cube[ind][2 - i][0] = temp_arr[2][2 - i];
}

RubiksCube3dArray::RubiksCube3dArray() {
    for (int f = 0; f < 6; f++)
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                cube[f][r][c] = getColorLetter(COLOR(f));
}

RubiksCube::COLOR RubiksCube3dArray::getColor(RubiksCube::FACE face, unsigned row, unsigned col) const {
    char color = cube[static_cast<int>(face)][row][col];

    switch (color) {
        case 'B': return RubiksCube::COLOR::BLUE;
        case 'R': return RubiksCube::COLOR::RED;
        case 'G': return RubiksCube::COLOR::GREEN;
        case 'O': return RubiksCube::COLOR::ORANGE;
        case 'Y': return RubiksCube::COLOR::YELLOW;
        default:  return RubiksCube::COLOR::WHITE;
    }
}

bool RubiksCube3dArray::isSolved() const {
    for (int f = 0; f < 6; f++)
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                if (cube[f][r][c] != getColorLetter(COLOR(f)))
                    return false;

    return true;
}

// ------------------------
//       MOVE U
// ------------------------
RubiksCube& RubiksCube3dArray::u() {
    rotateFace(0);

    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube[4][0][2 - i];

    for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
    for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
    for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
    for (int i = 0; i < 3; i++) cube[3][0][2 - i] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube3dArray::uPrime() {
    u(); u(); u();
    return *this;
}

RubiksCube& RubiksCube3dArray::u2() {
    u(); u();
    return *this;
}

// ------------------------
//       MOVE L
// ------------------------
RubiksCube& RubiksCube3dArray::l() {
    rotateFace(1);

    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube[0][i][0];

    for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
    for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
    for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
    for (int i = 0; i < 3; i++) cube[2][i][0] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube3dArray::lPrime() { l(); l(); l(); return *this; }
RubiksCube& RubiksCube3dArray::l2() { l(); l(); return *this; }

// ------------------------
//       MOVE F
// ------------------------
RubiksCube& RubiksCube3dArray::f() {
    rotateFace(2);

    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube[0][2][i];

    for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
    for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
    for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
    for (int i = 0; i < 3; i++) cube[3][i][0] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube3dArray::fPrime() { f(); f(); f(); return *this; }
RubiksCube& RubiksCube3dArray::f2() { f(); f(); return *this; }

// ------------------------
//       MOVE R
// ------------------------
RubiksCube& RubiksCube3dArray::r() {
    rotateFace(3);

    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube[0][2 - i][2];

    for (int i = 0; i < 3; i++) cube[0][2 - i][2] = cube[2][2 - i][2];
    for (int i = 0; i < 3; i++) cube[2][2 - i][2] = cube[5][2 - i][2];
    for (int i = 0; i < 3; i++) cube[5][2 - i][2] = cube[4][i][0];
    for (int i = 0; i < 3; i++) cube[4][i][0] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube3dArray::rPrime() { r(); r(); r(); return *this; }
RubiksCube& RubiksCube3dArray::r2() { r(); r(); return *this; }

// ------------------------
//       MOVE B
// ------------------------
RubiksCube& RubiksCube3dArray::b() {
    rotateFace(4);

    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube[0][0][2 - i];

    for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
    for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
    for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
    for (int i = 0; i < 3; i++) cube[1][i][0] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube3dArray::bPrime() { b(); b(); b(); return *this; }
RubiksCube& RubiksCube3dArray::b2() { b(); b(); return *this; }

// ------------------------
//       MOVE D
// ------------------------
RubiksCube& RubiksCube3dArray::d() {
    rotateFace(5);

    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube[2][2][i];

    for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
    for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
    for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
    for (int i = 0; i < 3; i++) cube[3][2][i] = tmp[i];

    return *this;
}

RubiksCube& RubiksCube3dArray::dPrime() { d(); d(); d(); return *this; }
RubiksCube& RubiksCube3dArray::d2() { d(); d(); return *this; }

// ------------------------
//      OPERATORS
// ------------------------
bool RubiksCube3dArray::operator==(const RubiksCube3dArray &r1) const {
    for (int f = 0; f < 6; f++)
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                if (cube[f][r][c] != r1.cube[f][r][c])
                    return false;
    return true;
}

RubiksCube3dArray& RubiksCube3dArray::operator=(const RubiksCube3dArray &r1) {
    for (int f = 0; f < 6; f++)
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                cube[f][r][c] = r1.cube[f][r][c];

    return *this;
}

// ------------------------
//        HASH
// ------------------------
size_t Hash3d::operator()(const RubiksCube3dArray &r1) const {
    std::string str;
    str.reserve(54);

    for (int f = 0; f < 6; f++)
        for (int r = 0; r < 3; r++)
            for (int c = 0; c < 3; c++)
                str += r1.cube[f][r][c];

    return std::hash<std::string>()(str);
}
