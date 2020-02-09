#include "addpolygon.h"

AddPolygonDialog::AddPolygonDialog(size_t vertice_cnt_, const QRectF& window_range_, QWidget* parent)
    : QDialog(parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint)
    , vertice_cnt(vertice_cnt_)
    , window_range(window_range_)
{
    QGridLayout* layout = new QGridLayout(this);
    // Sets window properties
    setWindowTitle ("Add Triangle");
    setModal(true);
    // Adds default buttons
    QPushButton* ok = new QPushButton("&Ok", this);
    QPushButton* cancel = new QPushButton("&Cancel", this);
    // Sets layout
    size_t i = 0;
    for(; i < vertice_cnt; ++i)
    {
        // Sets field ranges and adds sniboxes to the list
        QDoubleSpinBox* spinBoxX = new QDoubleSpinBox(this);
        QDoubleSpinBox* spinBoxY = new QDoubleSpinBox(this);
        spinBoxX->setRange(window_range.left(), window_range.right());
        spinBoxY->setRange(window_range.top(), window_range.bottom());
        spinBoxes.append(spinBoxX);
        spinBoxes.append(spinBoxY);
        // Adds labels
        QLabel* p_number = new QLabel("Point " + QString::number(i + 1));
        // Adds created widgets to the layout
        layout->addWidget(p_number, i, 0);
        layout->addWidget(spinBoxX, i, 1);
        layout->addWidget(spinBoxY, i, 2);
    }
    layout->addWidget(cancel, i, 2);
    layout->addWidget(ok, i, 1);
    setLayout(layout);
    // Connects slots
    connect(ok, SIGNAL(clicked()), SLOT(accept()));
    connect(cancel, SIGNAL(clicked()), SLOT(reject()));
}

QPolygonF AddPolygonDialog::getPoints()
{

    QPolygonF pol;
    for(size_t i = 0; i < vertice_cnt; ++i)
        pol << QPointF(spinBoxes[2*i]->value(), spinBoxes[2*i + 1]->value());
    return pol;
}

