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

    QPixmap pixmap(QString category, QString icon, QSize size = QSize());

    QSize fontMetrics(const QString& text, const QFont& font = QApplication::font());

protected:

    const QSharedPointer<QtComponentsToolsPrivate>  d_ptr;

private:

    QPixmap fromSvg2Pixmap(QString svg, const QSize& size = QSize());

    void setAttrRecur(QDomElement &elem, QString name, QString attr, QString val);

    QtComponentsTools(QObject* parent = NULL);

};

inline QtComponentsTools& QtComponentsTools::inst()
{
    static QtComponentsTools t;
    return t;
}



#endif //QTCOMPONENTSTOOLS_H