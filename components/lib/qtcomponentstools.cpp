#include "qtcomponentstools.h"
#include "qtcomponentstools_p.h"
#include "qtcomponentstheme.h"

#include <QPainter>
#include <QFile>
#include <QTextStream>
#include <QColor>

#if 0
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
        QDomElement element = dom.documentElement();
        setAttrRecur(element, "svg", "width", QString::number(size.width()));
        setAttrRecur(element, "svg", "height", QString::number(size.height()));
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
#endif

QPixmap QtComponentsTools::fromSvg2Pixmap(QString svg, const QColor& color, const QSize& size /*= QSize()*/)
{
    QPainter painter;
    QDomDocument dom;
    QPixmap Image(size);
    Image.fill(Qt::transparent);
    if (!size.isEmpty() || color.isValid())
    {
        QFile file(svg);
        if (!file.open(QFile::ReadOnly))
        {
            return QPixmap();
        }
        dom.setContent(file.readAll());
        file.close();
        QDomElement element = dom.documentElement();
        if (!size.isEmpty())
        {
            setAttrRecur(element, "svg", "width", QString::number(size.width()));
            setAttrRecur(element, "svg", "height", QString::number(size.height()));
        }
        if (color.isValid())
        {
            setAttrRecur(element, "path", "fill", rgb2HexStr(color));
        }
        QSvgRenderer SvgRenderer(dom.toByteArray());
        painter.begin(&Image);
        SvgRenderer.render(&painter);
        painter.end();
        return Image;
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
        QDomElement element = elem.childNodes().at(i).toElement();
        setAttrRecur(element, name, attr, val);
    }
}

QString QtComponentsTools::rgb2HexStr(const QColor& color)
{
    QString redStr = QString("%1").arg(color.red(), 2, 16, QChar('0'));
    QString greenStr = QString("%1").arg(color.green(), 2, 16, QChar('0'));
    QString blueStr = QString("%1").arg(color.blue(), 2, 16, QChar('0'));
    QString key = "#" + redStr + greenStr + blueStr;
    return key;
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

QPixmap QtComponentsTools::pixmap(const QString& category, const QString& icon, const QSize& size)
{
    QString svgPath = tr(":/icons/%1/ic_%2.svg").arg(category).arg(icon);
    return fromSvg2Pixmap(svgPath, QColor(), size);
}

QPixmap QtComponentsTools::pixmap(const QString& category, const QString& icon, const QColor& color, const QSize& size)
{
    QString svgPath = tr(":/icons/%1/ic_%2.svg").arg(category).arg(icon);
    return fromSvg2Pixmap(svgPath, color, size);
}

QPixmap QtComponentsTools::pixmap(const QString& path, QSize size)
{
    return fromSvg2Pixmap(path, QColor(), size);
}

QPixmap QtComponentsTools::pixmap(const QString& path, const QColor& color, const QSize& size)
{
    return fromSvg2Pixmap(path, color, size);
}

QSize QtComponentsTools::fontMetrics(const QString& text, const QFont& font)
{
    QFontMetrics fm(font);
    QRect rec = fm.boundingRect(text);
    return rec.size();
}

void QtComponentsTools::splitText(QString& text, int width, QFont font)
{
    if (text.isEmpty())
    {
        return;
    }

    QFontMetrics fm(font);

    int w = fm.width(text);

    if ((w + 32) >= width)
    {
        w /= text.size();
        int number = width / (w * 2);
        if (number % 2 != 0)
        {
            number--;
        }
        text = text.mid(0, number);
        text.append("...");
    }
}
