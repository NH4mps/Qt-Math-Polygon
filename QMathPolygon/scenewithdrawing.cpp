#include "scenewithdrawing.h"

SceneWithDrawing::SceneWithDrawing(const QRectF &size_, const QPointF &gridsize_, QObject *parent)
    :CoordPlaneScene(size_, gridsize_, parent)
{}

void SceneWithDrawing::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    CoordPlaneScene::mouseReleaseEvent(event);
    if(event->button() == Qt::RightButton && qgraphicsitem_cast<AnyMathPolygon*>(itemAt(event->scenePos(), QTransform())) == nullptr)
    {
        QPointF tempPoint(event->scenePos());
        tempPoints.push_back(tempPoint);
        QGraphicsEllipseItem* tempEllipse = addEllipse(tempPoint.x() - 3, tempPoint.y() - 3, 6, 6, QPen(), QBrush(Qt::blue));
        tempCircles.push_back(tempEllipse);
    }
    else
    {
        for(QGraphicsEllipseItem* circle : tempCircles)
        {
            removeItem(circle);
            delete circle;
        }
        tempCircles.clear();
        tempPoints.clear();
    }
}

void SceneWithDrawing::keyPressEvent(QKeyEvent *keyEvent)
{
    CoordPlaneScene::keyPressEvent(keyEvent);
    if(keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
    {
        addItem(new AnyMathPolygon(tempPoints));
        for(QGraphicsEllipseItem* circle : tempCircles)
        {
            removeItem(circle);
            delete circle;
        }
        tempCircles.clear();
        tempPoints.clear();
    }
}
