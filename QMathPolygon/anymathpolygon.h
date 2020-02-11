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
#include <iterator>

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

template<class Iter>
qreal intersectedSquare(Iter beg, Iter end);

template<class Iter>
qreal intersectedSquare(Iter beg, Iter end, AnyMathPolygon *)
{
    // Сontainer is empty
    if (beg == end) return 0;

    QVector<QPolygonF> polygons;
    for (; beg != end; ++beg)
    {
        QPolygonF temp = (*beg)->polygon();
        temp.translate((*beg)->scenePos());
        polygons.push_back(temp);
    }

    return intersectedSquare(polygons.begin(), polygons.end());
}

template<class Iter>
qreal intersectedSquare(Iter beg, Iter end, QPolygonF)
{
    // Сontainer is empty
    if (beg == end) return 0;

    QPolygonF res = *beg;

    // Container has only one element
    if (++beg == end) return AnyMathPolygon(res).square();

    for (; beg != end; ++beg)
        res = res.intersected(*beg);

    return res.size() ? AnyMathPolygon(res).square() : 0;
}

template<class Iter>
qreal intersectedSquare(Iter beg, Iter end)
{
    return intersectedSquare(beg, end, typename std::iterator_traits<Iter>::value_type());
};

bool operator< (const QPointF &p, const QLineF &l);

#endif // ANYMATHPOLYGON_H
