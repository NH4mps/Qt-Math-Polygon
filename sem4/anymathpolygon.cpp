#include "anymathpolygon.h"

AnyMathPolygon::AnyMathPolygon(const QPolygonF &polygon, QGraphicsItem *parent) : QGraphicsPolygonItem(polygon,parent)
{
    setPen(QPen(QBrush(Qt::black),2));
    setBrush(QBrush(Qt::green));
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    //setFillRule(Qt::FillRule::WindingFill);
}

void AnyMathPolygon::setPolygon(const QPolygonF &polygon)
{
    QGraphicsPolygonItem::setPolygon(polygon);
}

QVariant AnyMathPolygon::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if(change == QGraphicsItem::ItemSelectedHasChanged)
    {
        if(value != 0)
        {
            QPen pent = pen();
            pent.setBrush(Qt::blue);
            setPen(pent);
        }
        else
        {
            QPen pent = pen();
            pent.setBrush(Qt::black);
            setPen(pent);
        }
    }
    return QGraphicsItem::itemChange(change, value);
}

qreal AnyMathPolygon::perimeter() const
{
    QPolygonF pnt = polygon();

    qreal p = 0;
    for (int i = 0; i < pnt.size(); i ++)
    {
        p += QLineF(pnt[i], pnt[(i + 1) % pnt.size()]).length();
    }

    return p;
}

qreal AnyMathPolygon::square() const
{
    QPolygonF pnt = polygon();

    qreal square = 0;
    for (int i = 0; i < pnt.size() - 2; i++)
    {
        square += triSquare(pnt[0], pnt[i+1], pnt[i+2]);
    }

    return square;
}

qreal triSquare(QPointF fst, QPointF snd, QPointF thd)
{
    //Side lengths
    qreal a = QLineF(fst,snd).length();
    qreal b = QLineF(snd,thd).length();
    qreal c = QLineF(thd,fst).length();

    //Half of perimeter
    qreal p = (a+b+c)/2;

    //Heron's formula
    return qSqrt(p*(p-a)*(p-b)*(p-c));
}

qreal intersectedSquare(const AnyMathPolygon &one, const AnyMathPolygon &another)
{
    AnyMathPolygon pol(one.polygon().intersected(another.polygon()));
    return pol.square();
}

qreal intersectedSquare(const QPolygonF &one, const QPolygonF &another)
{
    AnyMathPolygon pol(one.intersected(another));
    return pol.square();
}
