#ifndef QTCOMPONENTSWIDGET_P_H
#define QTCOMPONENTSWIDGET_P_H

#include <QtGlobal>

class QtComponentsWidget;
class QtComponentsCenterWidget;
class QtComponentsWidgetShadowEffect;

class QtComponentsWidgetPrivate
{
    Q_DISABLE_COPY(QtComponentsWidgetPrivate)
    Q_DECLARE_PUBLIC(QtComponentsWidget)

public:

    QtComponentsWidgetPrivate(QtComponentsWidget* q);
    virtual ~QtComponentsWidgetPrivate();

    void init();

    QtComponentsWidget*const            q_ptr;
    QtComponentsCenterWidget*           _center;
    QtComponentsWidgetShadowEffect*     _effect;
};


#endif // QTCOMPONENTSWIDGET_P_H
