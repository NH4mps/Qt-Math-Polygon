#ifndef ADDTRIANGLE_H
#define ADDTRIANGLE_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QString>

class AddPolygonDialog : public QDialog
{
    Q_OBJECT
public:
    AddPolygonDialog(size_t vertice_cnt_,QWidget* parent = nullptr);

    QPolygonF getPoints();

private:
    QList<QDoubleSpinBox*> spinBoxes;
    size_t vertice_cnt;
};

#endif // ADDTRIANGLE_H
