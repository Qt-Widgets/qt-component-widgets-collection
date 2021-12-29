#ifndef QTCOMPONENTSCIRCLEPROGRESSDELEGATE_H
#define QTCOMPONENTSCIRCLEPROGRESSDELEGATE_H

#include <QObject>

#include "qtcomponentscircleprogress.h"

class QtComponentsCircleProgressDelegate : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsCircleProgressDelegate)

    Q_PROPERTY(qreal offset READ offset WRITE setOffset)
    Q_PROPERTY(qreal angle READ angle WRITE setAngle)
    Q_PROPERTY(qreal len READ len WRITE setLen)

public:

    QtComponentsCircleProgressDelegate(QtComponentsCircleProgress* parent);
    ~QtComponentsCircleProgressDelegate();

    inline void setOffset(qreal offset);
    inline qreal offset()const;

    inline void setAngle(qreal angle);
    inline qreal angle()const;

    inline void setLen(qreal len);
    inline qreal len()const;

private:

    QtComponentsCircleProgress*const _progress;
    qreal                            _offset;
    qreal                            _angle;
    qreal                            _len;
};

inline void QtComponentsCircleProgressDelegate::setOffset(qreal offset)
{
    _offset = offset;
    _progress->update();
}

inline qreal QtComponentsCircleProgressDelegate::offset() const
{
    return _offset;
}

inline void QtComponentsCircleProgressDelegate::setAngle(qreal angle)
{
    _angle = angle;
    _progress->update();
}

inline qreal QtComponentsCircleProgressDelegate::angle()const
{
    return _angle;
}

inline void QtComponentsCircleProgressDelegate::setLen(qreal len)
{
    _len = len;
    _progress->update();
}

inline qreal QtComponentsCircleProgressDelegate::len() const
{
    return _len;
}


#endif // QTCOMPONENTSCIRCLEPROGRESSDELEGATE_H
