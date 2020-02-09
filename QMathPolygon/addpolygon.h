#ifndef ADDTRIANGLE_H
#define ADDTRIANGLE_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QString>
#include <QDebug>

class AddPolygonDialog : public QDialog
{
    Q_OBJECT
public:
    AddPolygonDialog(size_t vertice_cnt_, const QRectF& window_rang_, QWidget* parent = nullptr);

    QPolygonF getPoints();

private:
    QList<QDoubleSpinBox*> spinBoxes;
    size_t vertice_cnt;
    QRectF window_range;
};

#endif // ADDTRIANGLE_H
