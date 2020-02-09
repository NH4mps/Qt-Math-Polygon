#include "anymathpolygon.h"

AnyMathPolygon::AnyMathPolygon(const QPolygonF &polygon, QGraphicsItem *parent)
    : QGraphicsPolygonItem(parent)
{
    setPolygon(sortPoints(polygon));
    // Sets polygon's properties
    setPen(QPen(QBrush(Qt::black),2));
    setBrush(QBrush(Qt::green));
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
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

void AnyMathPolygon::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    QAction *selectAction = menu.addAction("Select");
    QAction *removeAction = menu.addAction("Remove");
    QAction *selectedAction = menu.exec(event->screenPos());
    if(selectedAction == removeAction)
        delete this;
    else if(selectedAction == selectAction)
        setSelected(1);
}

QPolygonF AnyMathPolygon::sortPoints( const QPolygonF &polygon)
{
    // Sorts points by height
    QPolygonF points = polygon;
    std::sort(points.begin(), points.end(), [](const QPointF &a,const QPointF &b){return a.y() < b.y();});
    // Result vector
    QPolygonF res_polygon;
    // line to compare with
    QLineF line(points[0], points[points.size()-1]);
    // Puts points below the line in the result vector
    for(int i = 0; i < points.size();)
        if(points[i] < line)
        {
            res_polygon.push_back(points[i]);
            points.remove(i);
        }
        else
            ++i;
    // Puts remaining points in reverse order in the result vector
    for(auto it = points.rbegin(); it != points.rend(); ++it)
        res_polygon.push_back(*it);

    return res_polygon;
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

/* It splits any polygon at triangles,
 * calculate square for each of them using triSquare function and accamulate it
*/
qreal AnyMathPolygon::square() const
{
    QPolygonF pnt = polygon();

    qreal square = 0;
    for (int i = 0; i < pnt.size() - 2; i++)
        square += triSquare(pnt[0], pnt[i+1], pnt[i+2]);

    return square;
}

qreal triSquare(QPointF fst, QPointF snd, QPointF thd)
{
    // Side lengths
    qreal a = QLineF(fst,snd).length();
    qreal b = QLineF(snd,thd).length();
    qreal c = QLineF(thd,fst).length();
    // Half of perimeter
    qreal p = (a+b+c)/2;
    // Heron's formula
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

bool operator<(const QPointF &p, const QLineF &l)
{
    if(l.dx() == 0)
        return p.x() < l.x1();
    else
    {
        qreal a = l.dy()/l.dx();
        qreal b = l.y2() - a*l.x2();
        return p.y() < a*p.x() + b;
    }
}

