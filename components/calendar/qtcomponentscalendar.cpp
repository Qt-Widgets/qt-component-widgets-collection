#include "qtcomponentscalendar.h"
#include "qtcomponentscalendar_p.h"
#include "qtcomponentscalendar_internal.h"

#include <QLayout>
#include <QLocale>
#include <QPainter>
#include <QTextCharFormat>

void QtComponentsCalendarWidgetPrivate::init()
{
    Q_Q(QtComponentsCalendarWidget);

    _pStyle = new QtComponentsCalendarWidgetStyle(q);

    _pTitle = new QtComponentsCalendarWidgetTitle(q);

    _pWeek = new QtComponentsCalendarWidgetWeek(q);

    q->setNavigationBarVisible(false);
    q->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    q->setHorizontalHeaderFormat(QCalendarWidget::NoHorizontalHeader);
    q->setStyle(_pStyle);

    QTextCharFormat format;
    format.setForeground(QColor("#60627F"));
    format.setBackground(Qt::white);
    QFont font;
    font.setPixelSize(12);
    format.setFont(font);

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
    vBodyLayout->insertWidget(1, _pWeek);
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