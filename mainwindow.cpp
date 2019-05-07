#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "figure.h"

extern int pole[8][8];
QMouseEvent *event;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    generateBoard();
    hod = 0;
}

void MainWindow::generateBoard()
{
    scene = new QGraphicsScene();
    ui->gView->setScene(scene);

    bool isWhite = true;
    for(int y = 0; y < 400; y += 50)
    {
        for(int x = 0; x < 400; x += 50)
        {
            QBrush brush;
            if(isWhite) brush = QBrush(Qt::white);
            else brush = QBrush(Qt::gray);
            scene->addRect(x, y, 50, 50, QPen(Qt::black), brush);

            if(isWhite) isWhite = false;
            else isWhite = true;
        }
        if(isWhite) isWhite = false;
        else isWhite = true;
    }


    QGraphicsPixmapItem *item1 = new QGraphicsPixmapItem();
    item1->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item2 = new QGraphicsPixmapItem();
    item2->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item3 = new QGraphicsPixmapItem();
    item3->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item4 = new QGraphicsPixmapItem();
    item4->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item5 = new QGraphicsPixmapItem();
    item5->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item6 = new QGraphicsPixmapItem();
    item6->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item7 = new QGraphicsPixmapItem();
    item7->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item8 = new QGraphicsPixmapItem();
    item8->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item9 = new QGraphicsPixmapItem();
    item9->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item10 = new QGraphicsPixmapItem();
    item10->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item11 = new QGraphicsPixmapItem();
    item11->setFlag(QGraphicsItem::ItemIsSelectable, true);
    QGraphicsPixmapItem *item12 = new QGraphicsPixmapItem();
    item12->setFlag(QGraphicsItem::ItemIsSelectable, true);

    QPixmap black_rook1("C:/OOP/lab7/Resourses/black_rook.png");
    item1->setPixmap(black_rook1);
    scene->addItem(item1);
    item1->setPos(250, 100);


    QPixmap black_horse1("C:/OOP/lab7/Resourses/black_horse.png");
    item2->setPixmap(black_horse1);
    scene->addItem(item2);
    item2->setPos(200, 200);


    QPixmap black_bishop1("C:/OOP/lab7/Resourses/black_bishop.png");
    item3->setPixmap(black_bishop1);
    scene->addItem(item3);
    item3->setPos(100, 100);

    QPixmap black_bishop2("C:/OOP/lab7/Resourses/black_bishop.png");
    item4->setPixmap(black_bishop2);
    scene->addItem(item4);
    item4->setPos(50, 250);


    QPixmap black_horse2("C:/OOP/lab7/Resourses/black_horse.png");
    item5->setPixmap(black_horse2);
    scene->addItem(item5);
    item5->setPos(50, 200);


    QPixmap black_rook2("C:/OOP/lab7/Resourses/black_rook.png");
    item6->setPixmap(black_rook2);
    scene->addItem(item6);
    item6->setPos(300, 300);


    QPixmap white_rook1("C:/OOP/lab7/Resourses/white_rook.png");
    item7->setPixmap(white_rook1);
    scene->addItem(item7);
    item7->setPos(0, 0);


    QPixmap white_horse1("C:/OOP/lab7/Resourses/white_horse.png");
    item8->setPixmap(white_horse1);
    scene->addItem(item8);
    item8->setPos(150, 350);


    QPixmap white_bishop1("C:/OOP/lab7/Resourses/white_bishop.png");
    item9->setPixmap(white_bishop1);
    scene->addItem(item9);
    item9->setPos(100, 0);


    QPixmap white_bishop2("C:/OOP/lab7/Resourses/white_bishop.png");
    item10->setPixmap(white_bishop2);
    scene->addItem(item10);
    item10->setPos(350, 0);


    QPixmap white_horse2("C:/OOP/lab7/Resourses/white_horse.png");
    item11->setPixmap(white_horse2);
    scene->addItem(item11);
    item11->setPos(300, 0);


    QPixmap white_rook2("C:/OOP/lab7/Resourses/white_rook.png");
    item12->setPixmap(white_rook2);
    scene->addItem(item12);
    item12->setPos(0, 350);

}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // При нажатии кнопки мыши
    // Сохраняем координаты точки нажатия
    if (hod)
    {
        nextPoint = event->pos();
        int i = previousPoint.x()/50;
        int j = previousPoint.y()/50;
        int k = nextPoint.x()/50;
        int l = nextPoint.y()/50;
        int m = pole[i][j];
        figure p;
        switch (m)
        {
        case 11:
            p.horse_hod(i,j,k,l,m);
            break;
        case 12:
            p.bishop_hod(i,j,k,l,m);
            break;
        case 13:
           p.rook_hod(i,j,k,l,m);
           break;
        case 21:
           p.horse_hod(i,j,k,l,m);
           break;
        case 22:
           p.bishop_hod(i,j,k,l,m);
           break;
        case 23:
           p.rook_hod(i,j,k,l,m);
           break;
        case 0:
           break;
        }
        hod = 0;
    }
    else
    {
        previousPoint = event->pos();
        hod = 1;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



