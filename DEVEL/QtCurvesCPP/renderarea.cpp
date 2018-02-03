#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor (0, 0, 255),
    mShapeColor (255, 255, 255)
{}


QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}
QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}


void RenderArea::paintEvent(QPaintEvent *event)
{
    // parent of Painter is the RenderArea Clsass
    QPainter painter(this);
    // set the painter Color to blue
    painter.setBrush(mBackgroundColor);
    // we want to use antialiasing
    painter.setRenderHint(QPainter::Antialiasing, true);

    // set colour of lines to be drawn
    painter.setPen(mShapeColor);

    // draw rectangle which fills the entire renderArea
    // drawing area
    painter.drawRect(this->rect());

    // draw simple line from top left corner to bottom right
    painter.drawLine(this->rect().topLeft(), this->rect().bottomRight());


}
