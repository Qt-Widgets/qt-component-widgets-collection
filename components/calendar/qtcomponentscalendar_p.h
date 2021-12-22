#ifndef QTCOMPONENTSCALENDAR_P_H
#define QTCOMPONENTSCALENDAR_P_H

#include <QtGlobal>

class QtComponentsCalendarWidget;
class QtC

class QtComponentsCalendarWidgetPrivate
{
    Q_DISABLE_COPY(QtComponentsCalendarWidgetPrivate)
    Q_DECLARE_PUBLIC(QtComponentsCalendarWidget)

public:
    QtComponentsCalendarWidgetPrivate(QtComponentsCalendarWidget* q);
    virtual ~QtComponentsCalendarWidgetPrivate();

    void init();

    QtComponentsCalendarWidget*const    q_ptr;

};



#endif // QTCOMPONENTSCALENDAR_P_H
