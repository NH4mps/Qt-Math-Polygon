/* A graphics polygon that supports some math operations
 * It should sort points in the constructor to display polygon correctly
 * at any permutation of points in argument.
 * But I haven't implemented it yet.
*/

#ifndef ANYMATHPOLYGON_H
#define ANYMATHPOLYGON_H

#include <QGraphicsItem>
#include <QtMath>
#include <QPainter>
#include <QMenu>
#include <QGraphicsSceneContextMenuEvent>

class AnyMathPolygon : public QGraphicsPolygonItem
{
public:
    explicit AnyMathPolygon(const QPolygonF &polygon, QGraphicsItem *parent = nullptr);

    qreal perimeter() const;
    qreal square() const;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant & value) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override;
};

qreal triSquare(QPointF fst, QPointF snd, QPointF thd);
qreal intersectedSquare(const AnyMathPolygon & one, const AnyMathPolygon & another);
qreal intersectedSquare(const QPolygonF &one, const QPolygonF &another);

#endif // ANYMATHPOLYGON_H
