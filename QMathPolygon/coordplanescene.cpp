#include "coordplanescene.h"

CoordPlaneScene::CoordPlaneScene(const QRectF& size_, const QPointF& gridsize_)
    :QGraphicsScene(size_)
    ,gridsize(gridsize_)
{
    //Set background color
    setBackgroundBrush (QBrush(Qt::white));
    //Add X and Y axis lines
    addLine(QLineF(-width(), 0, width(), 0),QPen(QBrush(Qt::black),1));
    addLine(QLineF(0, -height(), 0, height()),QPen(QBrush(Qt::black),1));
    //Add vertical grid lines
    for(qreal i = -int(width()/gridsize.x())*gridsize.x(); i <= width(); i += gridsize.x())
    {
        griditems.append(addLine(QLineF(i, -height(), i, height()),QPen(QBrush(Qt::black),1,Qt::DashLine)));
        ReversedText* temp = new ReversedText(QString::number(i));
        addItem(temp);
        temp->moveBy(i,0);
        coordinates.append(temp);
    }
    //Add horizontal grid lines
    for(qreal i = -int(height()/gridsize.y())*gridsize.y(); i <= height(); i += gridsize.y())
    {
        griditems.append(addLine(QLineF(-width(), i, width(), i),QPen(QBrush(Qt::black),1,Qt::DashLine)));
        ReversedText* temp = new ReversedText(QString::number(i));
        addItem(temp);
        temp->moveBy(0,i);
        coordinates.append(temp);
    }
}

//Function to set new grid size
void CoordPlaneScene::setGrid(const QPointF& gridsize_)
{
    //Delete previous grid from scene
    for(int i =0; i < griditems.size(); i++)
    {
        removeItem(griditems[i]);
        removeItem(coordinates[i]);
    }
    griditems.clear();
    coordinates.clear();
    //Set new grid
    gridsize = gridsize_;
    //Add vertical grid lines
    for(qreal i = -int(width()/gridsize.x())*gridsize.x(); i <= width(); i += gridsize.x())
    {
        griditems.append(addLine(QLineF(i, -height(), i, height()),QPen(QBrush(Qt::black),1,Qt::DashLine)));
        ReversedText* temp = new ReversedText(QString::number(i));
        addItem(temp);
        temp->moveBy(0,i);
        coordinates.append(temp);
    }
    //Add horizontal grid lines
    for(qreal i = -int(height()/gridsize.y())*gridsize.y(); i <= height(); i += gridsize.y())
    {
        griditems.append(addLine(QLineF(-width(), i, width(), i),QPen(QBrush(Qt::black),1,Qt::DashLine)));
        ReversedText* temp = new ReversedText(QString::number(i));
        addItem(temp);
        temp->moveBy(i,0);
        coordinates.append(temp);
    }
}

//Function that increases grid size by 5
void CoordPlaneScene::incGridSize()
{
    setGrid(QPointF(gridsize.x()+5,gridsize.y()+5));
}

//Function that decreases grid size by 5
void CoordPlaneScene::decGridSize()
{
    if (gridsize.x()-5 >= 5 && gridsize.y()-5 >= 10)
        setGrid(QPointF(gridsize.x()-5,gridsize.y()-5));
}

