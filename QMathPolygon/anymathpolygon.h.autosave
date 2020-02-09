/* A graphics polygon that supports some math operations.
 * It sorts points in the constructor to display polygon correctly
 * at any permutation of points in argument.
*/

#ifndef ANYMATHPOLYGON_H
#define ANYMATHPOLYGON_H

#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>
#include <QDebug>
#include <algorithm>

class AnyMathPolygon : public QGraphicsPolygonItem
{
public:
    explicit AnyMathPolygon(const QPolygonF &polygon, QGraphicsItem *parent = nullptr);

    qreal perimeter() const;
    qreal square() const;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant & value) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;

private:
    QPolygonF sortPoints(const QPolygonF &polygon);

};

qreal triSquare(QPointF fst, QPointF snd, QPointF thd);
qreal intersectedSquare(const AnyMathPolygon & one, const AnyMathPolygon & another);
qreal intersectedSquare(const QPolygonF &one, const QPolygonF &another);

bool operator< (const QPointF &p, const QLineF &l);

#endif // ANYMATHPOLYGON_H
