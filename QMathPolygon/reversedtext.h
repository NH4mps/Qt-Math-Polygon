/* It copies QGraphicsText item, but text displays flipped vertically.
 * Needed because qGraphicsScene coordinate system is left-handed while we usually use right-handed coordinate systems
 * Works with some visual bugs conected with repainting, but it is Ok for me
 * I guess they will never be fixed
 */

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
private:

};

#endif // REVERSEDTEXT_H
