#ifndef QTCOMPONENTSPROGRESS_INTERNAL_H
#define QTCOMPONENTSPROGRESS_INTERNAL_H

#include <QObject>

#include "qtcomponentsprogress.h"

class QtComponentsProgressDelegate : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsProgressDelegate)
    Q_PROPERTY(qreal offset READ offset WRITE setOffset)

public:

    QtComponentsProgressDelegate(QtComponentsProgress* parent);
    ~QtComponentsProgressDelegate();

    inline void setOffset(qreal offset);
    inline qreal offset()const;

private:

    QtComponentsProgress*const _pProgress;
    qreal                      _offset;
};

inline void QtComponentsProgressDelegate::setOffset(qreal offset)
{
    _offset = offset;
    _pProgress->update();
}
inline qreal QtComponentsProgressDelegate::offset() const
{
    return _offset;
}

#endif // QTCOMPONENTSPROGRESS_INTERNAL_H
