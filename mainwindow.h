#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include "QGraphicsView"
#include "QGraphicsScene"
#include "QGraphicsPixmapItem"
#include "QVector"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGraphicsScene *scene;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool hod;

private:
    Ui::MainWindow *ui;
    QPoint previousPoint;
    QPoint nextPoint;
    void mousePressEvent(QMouseEvent *event);
    void generateBoard();
};

#endif // MAINWINDOW_H
