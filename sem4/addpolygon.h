#ifndef ADDTRIANGLE_H
#define ADDTRIANGLE_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QString>

class AddTriangle : public QDialog
{
    Q_OBJECT
public:
    AddTriangle(QWidget* parent = nullptr);
    ~AddTriangle();
    virtual QPolygonF getPoints();

protected:
    QGridLayout* layout;
    QDoubleSpinBox* x1;
    QDoubleSpinBox* y1;
    QDoubleSpinBox* x2;
    QDoubleSpinBox* y2;
    QDoubleSpinBox* x3;
    QDoubleSpinBox* y3;

};

class AddQuadrangle : public AddTriangle
{
public:
    AddQuadrangle (QWidget* parent = nullptr);
    ~AddQuadrangle();
    virtual QPolygonF getPoints();

protected:
    QDoubleSpinBox* x4;
    QDoubleSpinBox* y4;
};

class AddPentagon : public AddQuadrangle
{
public:
    AddPentagon(QWidget* parent = nullptr);
    ~AddPentagon ();
    virtual QPolygonF getPoints();

protected:
    QDoubleSpinBox* x5;
    QDoubleSpinBox* y5;
};

#endif // ADDTRIANGLE_H
