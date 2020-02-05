#include "reversedtext.h"

ReversedText::ReversedText(QString text)
    :QGraphicsTextItem(text)
{}

void ReversedText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->translate(0,boundingRect().height());
    painter->scale(1,-1);
    QGraphicsTextItem::paint(painter,option, widget);
    painter->restore();
}

QPainterPath ReversedText::shape() const
{
    return QGraphicsItem::shape();
}

QPainterPath ReversedText::opaqueArea() const
{
    return QGraphicsItem::opaqueArea();
}

bool ReversedText::isObscuredBy(const QGraphicsItem *item) const
{
    return QGraphicsItem::isObscuredBy(item);
}

bool ReversedText::contains(const QPointF &point) const
{
    return QGraphicsItem::contains(point);
}
