#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Adds coordinate system to the GUI
    coordSystem = new CoordPlaneScene(QRectF(-525,-300,1050,600), QPointF(50,50));
    systemView = new ViewWithButtons(coordSystem);
    ui->gridLayout->addWidget(systemView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_triangle_button_clicked()
{
    //Shows dialog window with coordinate fields
    AddTriangle wind(this);
    wind.show();

    //Adds riangle to the scene
    if(wind.exec() == QDialog::Accepted)
    {
        QPolygonF res = wind.getPoints();
        AnyMathPolygon* triangle = new AnyMathPolygon(res);
        coordSystem->addItem(triangle);
    }
}

void MainWindow::on_quadrangle_button_clicked()
{
    //Shows dialog window with coordinate fields
    AddQuadrangle wind(this);
    wind.show();

    //Adds triangle to the scene
    if(wind.exec() == QDialog::Accepted)
    {
        QPolygonF res = wind.getPoints();
        AnyMathPolygon* triangle = new AnyMathPolygon(res);
        coordSystem->addItem(triangle);
    }
}

void MainWindow::on_pentagon_button_clicked()
{
    //Shows dialog window with coordinate fields
    AddPentagon wind(this);
    wind.show();

    //Adds quadrangle to th scene
    if(wind.exec() == QDialog::Accepted)
    {
        QPolygonF res = wind.getPoints();
        AnyMathPolygon* triangle = new AnyMathPolygon(res);
        coordSystem->addItem(triangle);
    }
}

void MainWindow::on_square_button_clicked()
{
    //Gets list of selected polygons
    QList<QGraphicsItem *> toCalculate = coordSystem->selectedItems();
    qreal sumSquare = 0;

    //Counts and sums square for each of these items
    for (int i = 0; i < toCalculate.size(); i++)
    {
       sumSquare += qgraphicsitem_cast<AnyMathPolygon *>(toCalculate[i])->square();
    }

    //Displays square
    ui->lcdNumber->display(sumSquare);
}

void MainWindow::on_xsquare_button_clicked()
{
    qreal sumSquare = 0;

    //Gets list of selected polygons
    QList<QGraphicsItem *> toCalculate = coordSystem->selectedItems();

    if(toCalculate.size() != 0)
    {
        qDebug() << toCalculate.size();
        //Adds scene item coordinate to each of point of first polygon
        AnyMathPolygon* scenePolZero = qgraphicsitem_cast<AnyMathPolygon *>(toCalculate[0]);
        QPolygonF polZero;
        for (int i = 0; i < scenePolZero->polygon().size(); i++)
            polZero << scenePolZero->polygon()[i] + scenePolZero->scenePos();

        //Gets intersection polygon
        for (int i = 0; i < toCalculate.size(); i++)
        {
            //Adds scene item coordinate to each of point of each polygon
           AnyMathPolygon* pol = qgraphicsitem_cast<AnyMathPolygon *>(toCalculate[i]);
           QPolygonF tempPol;
           for (int j = 0; j < pol->polygon().size(); j++)
               tempPol << pol->polygon()[j] + pol->scenePos();

           //Gets polygon that is intersection of previous polygons and current polygon
           polZero = polZero.intersected(tempPol);
           for (int i = 0; i < polZero.size(); i++)
               qDebug() << polZero[i];
        }

        sumSquare = AnyMathPolygon(polZero).square();
    }

    //Displays square
    ui->lcdNumber->display(sumSquare);
}
