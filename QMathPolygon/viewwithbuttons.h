#ifndef VIEWWITHBUTTONS_H
#define VIEWWITHBUTTONS_H

#include "coordplaneview.h"

class ViewWithButtons : public CoordPlaneView
{
    Q_OBJECT
public:
    ViewWithButtons(CoordPlaneScene *scene, QWidget *parent = nullptr);
    ~ViewWithButtons();

signals:
    void toChangeGridSize(qreal dx, qreal dy);

protected slots:
    void incGridSize();
    void decGridSize();

private:
    QPushButton* gridplus;
    QPushButton* gridminus;
};

#endif // VIEWWITHBUTTONS_H
