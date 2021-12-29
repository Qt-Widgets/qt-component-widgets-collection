#include "qtcomponentstools.h"
#include "qtcomponentstools_p.h"
#include "qtcomponentstheme.h"

#include <QPainter>
#include <QFile>
#include <QTextStream>


QPixmap QtComponentsTools::fromSvg2Pixmap(QString svg, const QSize& size)
{
    QPainter painter;
    QDomDocument dom;
    QPixmap Image(size);
    Image.fill(Qt::transparent);
    if (!size.isEmpty())
    {
        QFile file(svg);
        if (!file.open(QFile::ReadOnly))
        {
            return QPixmap();
        }
        dom.setContent(file.readAll());
        file.close();
        setAttrRecur(dom.documentElement(), "svg", "width", QString::number(size.width()));
        setAttrRecur(dom.documentElement(), "svg", "height", QString::number(size.height()));
        QSvgRenderer SvgRenderer(dom.toByteArray());
        painter.begin(&Image);
        SvgRenderer.render(&painter);
        painter.end();
    }
    else
    {
        QSvgRenderer SvgRenderer(svg);
        painter.begin(&Image);
        SvgRenderer.render(&painter);
        painter.end();
    }
    return Image;
}

void QtComponentsTools::setAttrRecur(QDomElement &elem, QString name, QString attr, QString val)
{
    if (elem.tagName().compare(name) == 0)
    {
        elem.setAttribute(attr, val);
    }
    // loop all children
    for (int i = 0; i < elem.childNodes().count(); i++)
    {
        if (!elem.childNodes().at(i).isElement())
        {
            continue;
        }
        setAttrRecur(elem.childNodes().at(i).toElement(), name, attr, val);
    }
}

QtComponentsTools::QtComponentsTools(QObject* parent)
    : QObject(parent)
    , d_ptr(new QtComponentsToolsPrivate(this))
{
    
}

QtComponentsToolsPrivate::QtComponentsToolsPrivate(QtComponentsTools* q)
    : q_ptr(q)
{
    _components = new QtComponents(q);
}

QtComponentsToolsPrivate::~QtComponentsToolsPrivate()
{

}


void QtComponentsTools::setColor(const QString& key, const QColor& color)
{
    Q_D(QtComponentsTools);
    d->_components->setColor(key, color);
}

QColor QtComponentsTools::getColor(const QString& key)const
{
    Q_D(const QtComponentsTools);
    return d->_components->getColor(key);
}

QPixmap QtComponentsTools::pixmap(QString category, QString icon, QSize size) 
{
    QString svgPath = tr(":/icons/%1/ic_%2.svg").arg(category).arg(icon);
    return fromSvg2Pixmap(svgPath, size);
}

QSize QtComponentsTools::fontMetrics(const QString& text, const QFont& font)
{
    QFontMetrics fm(font);
    QRect rec = fm.boundingRect(text);
    return rec.size();
}
