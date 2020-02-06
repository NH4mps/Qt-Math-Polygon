#ifndef COORDPLANESCENE_H
#define COORDPLANESCENE_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QPushButton>
#include "reversedtext.h"
#include <QApplication>
#include <QGraphicsSceneMouseEvent>

class CoordPlaneScene : public QGraphicsScene
{
    Q_OBJECT
public:
    CoordPlaneScene(const QRectF& size_ = QRectF(-100, -100, 100, 100), const QPointF& gridsize_ = QPointF(10,10));
    void setGrid(const QPointF& gridsize_);

private:
    void drawGrid();

    QPointF gridsize;
    QList<QGraphicsLineItem *> griditems;
    QList<ReversedText *> coordinates;
    bool isPressed;

protected slots:
    void incGridSize();
    void decGridSize();
    void changeGridSize(qreal dx, qreal dy);
};

#endif // COORDPLANESCENE_H
