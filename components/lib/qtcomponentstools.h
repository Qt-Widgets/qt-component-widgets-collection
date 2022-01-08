#ifndef QTCOMPONENTSTOOLS_H
#define QTCOMPONENTSTOOLS_H

#include <QObject>
#include <QPixmap>
#include <QtXml/QDomDocument>
#include <QtSvg/QSvgRenderer>
#include <QApplication>
#include <QFont>

class QtComponentsToolsPrivate;

class QtComponentsTools : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsTools)
    Q_DECLARE_PRIVATE(QtComponentsTools)

public:

    inline static QtComponentsTools& inst();

    void setColor(const QString& key, const QColor& color);
    QColor getColor(const QString& key)const;

    QPixmap pixmap(const QString& category, const QString& icon, const QSize& size = QSize());
    QPixmap pixmap(const QString& path, QSize size = QSize());
    QPixmap pixmap(const QString& category, const QString& icon, const QColor& color, const QSize& size = QSize());
    QPixmap pixmap(const QString& path, const QColor& color, const QSize& size = QSize());

    QSize fontMetrics(const QString& text, const QFont& font = QApplication::font());

    void splitText(QString& text, int width, QFont font);

protected:

    const QSharedPointer<QtComponentsToolsPrivate>  d_ptr;

private:

    QPixmap fromSvg2Pixmap(QString svg, const QColor& color, const QSize& size = QSize());

    void setAttrRecur(QDomElement &elem, QString name, QString attr, QString val);
    QString rgb2HexStr(const QColor& color);

    QtComponentsTools(QObject* parent = NULL);

};

inline QtComponentsTools& QtComponentsTools::inst()
{
    static QtComponentsTools t;
    return t;
}



#endif //QTCOMPONENTSTOOLS_H