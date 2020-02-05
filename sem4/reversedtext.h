#ifndef REVERSEDTEXT_H
#define REVERSEDTEXT_H
#include <QGraphicsItem>
#include <QPainter>

class ReversedText : public QGraphicsTextItem
{
    Q_OBJECT
public:
    ReversedText(QString text);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QPainterPath shape() const;
    QPainterPath opaqueArea() const;
    bool isObscuredBy(const QGraphicsItem *item) const;
    bool contains(const QPointF &point) const;
private:

};

#endif // REVERSEDTEXT_H
