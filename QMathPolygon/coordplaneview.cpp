#include "coordplaneview.h"

CoordPlaneView::CoordPlaneView(CoordPlaneScene *scene, QWidget *parent)
    :QGraphicsView(scene, parent)
{
    gridplus = new QPushButton("Grid +", this);
    gridminus = new QPushButton("Grid -", this);
    gridplus->move(5,5);
    gridminus->move(5,40);
    gridplus->show();
    gridminus->show();
    connect(gridplus, SIGNAL(clicked()), scene, SLOT(incGridSize()));
    connect(gridminus, SIGNAL(clicked()), scene, SLOT(decGridSize()));

    x=1;
    y=1;
    scale(1,-1);
}

CoordPlaneView::~CoordPlaneView()
{
    delete gridplus;
    delete gridminus;
}
void CoordPlaneView::standartScale()
{
    scale(1/x,1/y);
    x=1;
    y=1;
}

void CoordPlaneView::zoomIn()
{
    if(x * 1.1 <= 5 && y * 1.1 <= 5)
    {
        x*=1.1;
        y*=1.1;
        scale(1.1,1.1);
    }
    else
    {
        QMessageBox* pmbx =
        new QMessageBox(QMessageBox::Warning,
        "MessageBox",
        "You reach the maximum zoom",
        QMessageBox::Ok
        ) ;
        pmbx->exec();
        delete pmbx;
    }
}

void CoordPlaneView::zoomOut()
{
    if(x * 0.9 > 0.1 && y * 0.9 > 0.1)
    {
        x*=0.9;
        y*=0.9;
        scale(0.9,0.9);
    }
    else
    {
        QMessageBox* pmbx =
        new QMessageBox(QMessageBox::Warning,
        "MessageBox",
        "You reach the minimum zoom",
        QMessageBox::Ok
        ) ;
        pmbx->exec();
        delete pmbx;
    }
}

void CoordPlaneView::keyPressEvent(QKeyEvent* pe)
{
    switch  (pe->key())
    {
        case Qt::Key_Equal:
            if((pe->modifiers() & Qt::ControlModifier))
               zoomIn();
            break;
        case Qt::Key_Minus:
            if(pe->modifiers() & Qt::ControlModifier)
                zoomOut();
            break;
        case Qt::Key_0:
            if(pe->modifiers() & Qt::ControlModifier)
                standartScale();
            break;
        default:
           qDebug() << "You pressed wrong buttons\n";
    }
}
