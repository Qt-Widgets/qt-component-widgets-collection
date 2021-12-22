#ifndef QTCOMPONENTSCALENDAR_INTERNAL_H
#define QTCOMPONENTSCALENDAR_INTERNAL_H

#include <QObject>

#include "qtcomponentscalendar.h"

class QtComponentsCalendarWidgetDelegate : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsCalendarWidgetDelegate)

public:

    QtComponentsCalendarWidgetDelegate(QtComponentsCalendarWidget* parent);
    ~QtComponentsCalendarWidgetDelegate();

private:

    QtComponentsCalendarWidget*const _calendar;


};




#endif // QTCOMPONENTSCALENDAR_INTERNAL_H
