#ifndef QTCOMPONENTSCALENDAR_INTERNAL_H
#define QTCOMPONENTSCALENDAR_INTERNAL_H

#include <QObject>
#include <QLabel>
#include <QWidget>
#include <QProxyStyle>

#include "qtcomponentscalendar.h"


class QPushButton;
class QtComponentsCalendarWidgetStyle;
class QtComponentsCalendarWidgetTitle;


class QtComponentsCalendarWidgetTitle : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsCalendarWidgetTitle)

    Q_PROPERTY(QDate date READ dateText WRITE setDateText)

public:

    QtComponentsCalendarWidgetTitle(QtComponentsCalendarWidget* parent);
    ~QtComponentsCalendarWidgetTitle();

public slots:

    inline void setDateText(const QDate& date);
    inline QDate dateText()const;
    
protected:

    virtual void paintEvent(QPaintEvent * event);

private:

    void init();

    QtComponentsCalendarWidget*const    _pCalendar;
    QPushButton*                        _pLastYear;
    QPushButton*                        _pLastMonth;
    QPushButton*                        _pNextYear;
    QPushButton*                        _pNextMonth;
    QLabel*                             _pText;
};

inline void QtComponentsCalendarWidgetTitle::setDateText(const QDate &date)
{
    _pText->setText(date.toString(QString::fromLocal8Bit("yyyy 年 MM 月")));
    _pCalendar->update();
}

inline QDate QtComponentsCalendarWidgetTitle::dateText()const
{
    return _pCalendar->selectedDate();
}

class QtComponentsCalendarWidgetStyle : public QProxyStyle
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsCalendarWidgetStyle)

public:

    QtComponentsCalendarWidgetStyle(QtComponentsCalendarWidget* parent);
    ~QtComponentsCalendarWidgetStyle();

private:

    virtual void drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const;

    QtComponentsCalendarWidget*const        _pCalendar;

};



#endif // QTCOMPONENTSCALENDAR_INTERNAL_H
