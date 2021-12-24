#include "qtcomponentstools.h"

#include <QPainter>

QPixmap QtComponentsTools::fromSvg2Pixmap(const QString& svg, const QSize& size)
{
    QSvgRenderer SvgRenderer(svg);
    QPixmap Image(size);
    QPainter Painter;
    Image.fill(Qt::transparent);
    Painter.begin(&Image);
    SvgRenderer.render(&Painter);
    Painter.end();
    return Image;
}
