#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , coordSystem(new SceneWithDrawing(QRectF(-525,-300,1050,600), QPointF(50,50), this))
    , systemView(new ViewWithButtons(coordSystem, this))
{
    // Sets UI
    ui->setupUi(this);

    // Adds coordinate system to the UI
    ui->gridLayout->addWidget(systemView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_triangle_button_clicked()
{
    // Shows dialog window with coordinate fields
    AddPolygonDialog wind(3, QRectF(-525,-300,1050,600), this);
    wind.show();

    // Adds triangle to the scene
    if (wind.exec() == QDialog::Accepted)
    {
        QPolygonF res = wind.getPoints();
        AnyMathPolygon* triangle = new AnyMathPolygon(res);
        coordSystem->addItem(triangle);
    }
}

void MainWindow::on_quadrangle_button_clicked()
{
    // Shows dialog window with coordinate fields
    AddPolygonDialog wind(4, QRectF(-525,-300,1050,600), this);
    wind.show();

    // Adds quadrangle to the scene
    if (wind.exec() == QDialog::Accepted)
    {
        QPolygonF res = wind.getPoints();
        AnyMathPolygon* triangle = new AnyMathPolygon(res);
        coordSystem->addItem(triangle);
    }
}

void MainWindow::on_pentagon_button_clicked()
{
    // Shows dialog window with coordinate fields
    AddPolygonDialog wind(5, QRectF(-525,-300,1050,600), this);
    wind.show();

    // Adds pentagon to the scene
    if (wind.exec() == QDialog::Accepted)
    {
        QPolygonF res = wind.getPoints();
        AnyMathPolygon* triangle = new AnyMathPolygon(res);
        coordSystem->addItem(triangle);
    }
}

void MainWindow::on_square_button_clicked()
{
    // Gets list of selected polygons
    QList<QGraphicsItem *> toCalculate = coordSystem->selectedItems();
    qreal sumSquare = 0;

    // Calculates and accumulates square for each of these items
    for (int i = 0; i < toCalculate.size(); i++)
       sumSquare += qgraphicsitem_cast<AnyMathPolygon *>(toCalculate[i])->square();

    // Displays square
    ui->lcdNumber->display(sumSquare);
}

void MainWindow::on_xsquare_button_clicked()
{
    // Gets list of selected items
    QList<QGraphicsItem *> toCalculate = coordSystem->selectedItems();

    // Selects polygons from items
    QList<AnyMathPolygon *> selPolygons;
    for (QGraphicsItem * item : toCalculate)
    {
        AnyMathPolygon* polygon = qgraphicsitem_cast<AnyMathPolygon *>(item);
        if (polygon) selPolygons.push_back(polygon);
    }

    // Displays square
    //ui->lcdNumber->display(intersectedSquare(selPolygons));
    ui->lcdNumber->display(intersectedSquare(selPolygons.begin(), selPolygons.end()));
}
