#include "figure.h"

using namespace std;

int pole[8][8] = {  {13, 0,12, 0, 0, 0,11,12},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0,22, 0, 0,23, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0},
                    {0,21, 0, 0,21, 0, 0, 0},
                    {0,22, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0,23, 0},
                    {13, 0, 0,11, 0, 0, 0, 0}};

figure::figure()
{
    //x = y;
}

void figure::horse_hod(int i, int j,int k, int l,const int m)   //ход конем
{
    if (k == (i+1) || k == (i-1))
    {
        if (l == (j-2) || l == (j+2))
        {
            if (pole[k][l] == 0)
            {pole[k][l] = m;} //обычный ход
            else if (pole[k][l] > 20 && m == 11)
            {} //рубим конем
            else if (pole[k][l] > 20 && m == 21)
            {QMessageBox::critical(0,"Ошибка!","Нельзя сделать ход!");} // ошибка на хода на свою фигуру
            else if ((pole[k][l] > 10) && (pole[k][l] < 14) && m == 11)
            {QMessageBox::critical(0,"Ошибка!","Нельзя сделать ход!");} //ошибка на хода на свою фигуру
            else if ((pole[k][l] > 10) && (pole[k][l] < 14) && m == 21)
            {} //рубим конем
        }
    }
    else if (k == (i+2) || k == (i-2))
    {
        if (l == (j-1) || l == (j+1))
        {

        }
    }
    else if (k == i && l == j) {}//снимаем ход
    else {QMessageBox::critical(0,"Ошибка!","Нельзя сделать ход!");}

}

void figure::rook_hod(int i, int j,int k, int l,const int m)
{
    if (i == k || j == l)
    {
        if (pole[k][l] == 0)
        {} //обычный ход
        else if (pole[k][l] > 20 && m == 12)
        {} //рубим слоном
        else if (pole[k][l] > 20 && m == 22)
        {QMessageBox::critical(0,"Ошибка!","Нельзя сделать ход!");} // ошибка на хода на свою фигуру
        else if ((pole[k][l] > 10) && (pole[k][l] < 14) && m == 12)
        {QMessageBox::critical(0,"Ошибка!","Нельзя сделать ход!");} //ошибка на хода на свою фигуру
        else if ((pole[k][l] > 10) && (pole[k][l] < 14) && m == 22)
        {} //рубим слоном
    }
    else if (k == i && l == j) {}//снимаем ход
    else {QMessageBox::critical(0,"Ошибка!","Нельзя сделать ход!");}
}

void figure::bishop_hod(int i, int j,int k, int l,const int m)
{
    if (abs(i-k) == abs(j-l))
    {
        if (k == i && l == j) {}
        else {
            if (pole[k][l] == 0)
            {} //обычный ход
            else if (pole[k][l] > 20 && m == 13)
            {} //рубим ладьей
            else if (pole[k][l] > 20 && m == 23)
            {QMessageBox::critical(0,"Ошибка!","Нельзя сделать ход!");} // ошибка на хода на свою фигуру
            else if ((pole[k][l] > 10) && (pole[k][l] < 14) && m == 13)
            {QMessageBox::critical(0,"Ошибка!","Нельзя сделать ход!");} //ошибка на хода на свою фигуру
            else if ((pole[k][l] > 10) && (pole[k][l] < 14) && m == 23)
            {} //рубим ладьей
             }
    }
    else {QMessageBox::critical(0,"Ошибка!","Нельзя сделать ход!");}
}

figure::~figure()
{
}
