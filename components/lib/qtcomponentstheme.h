#ifndef __QTCOMPONENTSTHEME_H__
#define __QTCOMPONENTSTHEME_H__

#include <QObject>
#include <QSharedPointer>

namespace Components
{
    enum AlertTextFlag
    {
        AlertLeft = Qt::AlignLeft,
        AlertRight = Qt::AlignRight,
        AlertCenter = Qt::AlignCenter
    };

    enum AlertStyle
    {
        NoStyle,
        Details
    };

    enum AlertMsgType
    {
        Success,
        Warning,
        Info,
        Error
    };

    enum Color
    {
        green50,
        green100,
        grey50,
        grey100,
        yellow50,
        yellow100,
        red50,
        red100
    };

}

class QColor;
class QtComponentsPrivate;

class QtComponents : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponents)
    Q_DECLARE_PRIVATE(QtComponents)

public:

    explicit QtComponents(QObject* parent = NULL);
    ~QtComponents();

    QColor getColor(const QString& key)const;

    void setColor(const QString& key, const QColor& color);
    void setColor(const QString& key, Components::Color color);

protected:

    const QSharedPointer<QtComponentsPrivate>   d_ptr;
};




#endif  //__QTCOMPONENTSTHEME_H__