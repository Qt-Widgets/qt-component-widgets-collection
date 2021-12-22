#ifndef QTCOMPONENTSCALENDAR_INTERNAL_H
#define QTCOMPONENTSCALENDAR_INTERNAL_H

#include <QObject>
#include <QLabel>
#include <QWidget>

#include "qtcomponentscalendar.h"

class QPushButton;


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

class QtComponentsCalendarWidgetTitle : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsCalendarWidgetTitle)

    Q_PROPERTY(QString date READ dateText WRITE setDateText)

public:

    QtComponentsCalendarWidgetTitle(QtComponentsCalendarWidget* parent);
    ~QtComponentsCalendarWidgetTitle();

    inline void setDateText(const QString& date);
    inline QString dateText()const;


private:

    void init();

    QtComponentsCalendarWidget*const    _pCalendar;

    QPushButton*                        _pLastYear;
    QPushButton*                        _pLastMonth;
    QPushButton*                        _pNextYear;
    QPushButton*                        _pNextMonth;
    QLabel*                             _pText;
};

inline void QtComponentsCalendarWidgetTitle::setDateText(const QString &date)
{
    _pText->setText(date);
    _pCalendar->update();
}

inline QString QtComponentsCalendarWidgetTitle::dateText()const
{
    return _pText->text();
}

#endif // QTCOMPONENTSCALENDAR_INTERNAL_H
