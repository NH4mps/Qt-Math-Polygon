#ifndef COORDPLANEVIEW_H
#define COORDPLANEVIEW_H
#include <QGraphicsView>
#include <QDebug>
#include <QKeyEvent>
#include <QMessageBox>
#include <QPushButton>
#include "coordplanescene.h"

class CoordPlaneView : public QGraphicsView
{
    Q_OBJECT
public:
    CoordPlaneView(CoordPlaneScene *scene, QWidget *parent = nullptr);
    ~CoordPlaneView();
    void zoomIn();
    void zoomOut();
    void standartScale();
protected:
    void keyPressEvent(QKeyEvent *event);
private:
    QPushButton* gridplus;
    QPushButton* gridminus;
    qreal x;
    qreal y;
};

#endif // COORDPLANEVIEW_H
