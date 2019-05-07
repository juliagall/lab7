#ifndef FIGURE_H
#define FIGURE_H

#include <QMessageBox>

class figure
{
    int x;
    int i,j,k,l;
public:
    figure();
    ~figure();
    int pole[8][8];

    int horse_black;
    int bishop_black;
    int rook_black;

    int horse_white;
    int bishop_white;
    int rook_white;

    void horse_hod(int,int,int,int, int);
    void bishop_hod(int,int,int,int, int);
    void rook_hod(int,int,int,int, int);

};

#endif // FIGURE_H
