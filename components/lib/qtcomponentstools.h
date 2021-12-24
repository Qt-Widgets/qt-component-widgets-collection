#ifndef QTCOMPONENTSTOOLS_H
#define QTCOMPONENTSTOOLS_H

#include <QObject>
#include <QtSvg/QSvgRenderer>
#include <QPixmap>

class QtComponentsTools : public QObject
{
    Q_OBJECT
public:

    inline static QtComponentsTools& inst();

    QPixmap fromSvg2Pixmap(const QString& svg, const QSize& size = QSize());

private:

    QtComponentsTools(){}
    QtComponentsTools(QtComponentsTools const&) = delete;
    void operator=(QtComponentsTools const&) = delete;
};

inline QtComponentsTools& QtComponentsTools::inst()
{
    QtComponentsTools t;
    return t;
}



#endif //QTCOMPONENTSTOOLS_H