#ifndef ANYMATHPOLYGON_H
#define ANYMATHPOLYGON_H
#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>

class AnyMathPolygon : public QGraphicsPolygonItem
{
public:
    explicit AnyMathPolygon(const QPolygonF &polygon, QGraphicsItem *parent = nullptr);

    qreal perimeter() const;
    qreal square() const;
    void setPolygon(const QPolygonF &polygon);
protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant & value);
};

qreal triSquare(QPointF fst, QPointF snd, QPointF thd);
qreal intersectedSquare(const AnyMathPolygon & one, const AnyMathPolygon & another);
qreal intersectedSquare(const QPolygonF &one, const QPolygonF &another);

#endif // ANYMATHPOLYGON_H
