#ifndef QTCOMPONENTSCIRCLEPROGRESS_P_H
#define QTCOMPONENTSCIRCLEPROGRESS_P_H

#include <QtGlobal>
#include <QColor>

class QtComponentsCircleProgress;
class QtComponentsCircleProgressDelegate;

class QtComponentsCircleProgressPrivate
{
    Q_DISABLE_COPY(QtComponentsCircleProgressPrivate)
    Q_DECLARE_PUBLIC(QtComponentsCircleProgress)

public:

    QtComponentsCircleProgressPrivate(QtComponentsCircleProgress* q);
    virtual ~QtComponentsCircleProgressPrivate();

    void init();

    QtComponentsCircleProgress*const    q_ptr;
    QtComponentsCircleProgressDelegate* _delegate;
    QColor                              _inputColor;
    QColor                              _frontColor;
    int                                 _size;
};



#endif // QTCOMPONENTSCIRCLEPROGRESS_P_H
