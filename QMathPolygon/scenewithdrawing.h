#ifndef SCENEWITHDRAWING_H
#define SCENEWITHDRAWING_H

#include "coordplanescene.h"
#include "anymathpolygon.h"

#include <QKeyEvent>

class SceneWithDrawing : public CoordPlaneScene
{
public:
     SceneWithDrawing(const QRectF& size_ = QRectF(-100, -100, 100, 100), const QPointF& gridsize_ = QPointF(10,10), QObject *parent = nullptr);

protected:
     void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
     void keyPressEvent(QKeyEvent *keyEvent) override;

private:
     QPolygonF tempPoints;
     QList<QGraphicsEllipseItem*> tempCircles;
};

#endif // SCENEWITHDRAWING_H
