#ifndef QTCOMPONENTSPROGRESS_P_H
#define QTCOMPONENTSPROGRESS_P_H

#include <QtGlobal>
#include <QColor>


class QtComponentsProgress;
class QtComponentsProgressDelegate;

class QtComponentsProgressPrivate
{
    Q_DISABLE_COPY(QtComponentsProgressPrivate)
    Q_DECLARE_PUBLIC(QtComponentsProgress)

public:

    QtComponentsProgressPrivate(QtComponentsProgress* q);
    virtual ~QtComponentsProgressPrivate();

    void init();

    QtComponentsProgress*const          q_ptr;
    QtComponentsProgressDelegate*       _delegate;
    QColor                              _inputColor;
    QColor                              _frontColor;
};


#endif // QTCOMPONENTSPROGRESS_P_H
