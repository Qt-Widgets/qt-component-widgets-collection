#include "qtcomponentscalendar.h"
#include "qtcomponentscalendar_p.h"
#include "qtcomponentscalendar_internal.h"

#include <QLayout>
#include <QLocale>
#include <QTextCharFormat>

void QtComponentsCalendarWidgetPrivate::init()
{
    Q_Q(QtComponentsCalendarWidget);
    
    _pTitle = new QtComponentsCalendarWidgetTitle(q);
    _pStyle = new QtComponentsCalendarWidgetStyle(q);

    q->setLocale(QLocale(QLocale::Chinese));
    q->setNavigationBarVisible(false);
    q->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    q->setHorizontalHeaderFormat(QCalendarWidget::SingleLetterDayNames);
    q->setStyle(_pStyle);

    QTextCharFormat format;
    format.setForeground(QColor(160, 160, 160));
    format.setBackground(QColor(255, 255, 255));

    q->setHeaderTextFormat(format);
    q->setWeekdayTextFormat(Qt::Saturday, format);
    q->setWeekdayTextFormat(Qt::Sunday, format);
    q->setWeekdayTextFormat(Qt::Monday, format);
    q->setWeekdayTextFormat(Qt::Tuesday, format);
    q->setWeekdayTextFormat(Qt::Wednesday, format);
    q->setWeekdayTextFormat(Qt::Thursday, format);
    q->setWeekdayTextFormat(Qt::Friday, format);

    QVBoxLayout *vBodyLayout = qobject_cast<QVBoxLayout *>(q->layout());
    vBodyLayout->insertWidget(0, _pTitle);
}

QtComponentsCalendarWidget::~QtComponentsCalendarWidget()
{

}

QtComponentsCalendarWidget::QtComponentsCalendarWidget(QWidget* parent /*= NULL*/)
    : QCalendarWidget(parent)
    , d_ptr(new QtComponentsCalendarWidgetPrivate(this))
{
    d_func()->init();
}

QtComponentsCalendarWidget::QtComponentsCalendarWidget(QtComponentsCalendarWidgetPrivate& d, QWidget* parent /*= NULL*/)
    : QCalendarWidget(parent)
    , d_ptr(&d)
{
    d_func()->init();
}

QtComponentsCalendarWidgetPrivate::QtComponentsCalendarWidgetPrivate(QtComponentsCalendarWidget* q)
    : q_ptr(q)
{
    Q_ASSERT(q);
}

QtComponentsCalendarWidgetPrivate::~QtComponentsCalendarWidgetPrivate()
{

}