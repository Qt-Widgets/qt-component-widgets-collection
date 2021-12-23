#include "qtcomponentscalendar_internal.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPalette>
#include <QColor>
#include <QPainter>


QtComponentsCalendarWidgetTitle::QtComponentsCalendarWidgetTitle(QtComponentsCalendarWidget *parent)
    : _pCalendar(parent)
    , _pLastMonth(new QPushButton(this))
    , _pLastYear(new QPushButton(this))
    , _pNextMonth(new QPushButton(this))
    , _pNextYear(new QPushButton(this))
    , _pText(new QLabel(this))
{
    Q_ASSERT(parent);
    init();
}


QtComponentsCalendarWidgetTitle::~QtComponentsCalendarWidgetTitle()
{

}

void QtComponentsCalendarWidgetTitle::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(Qt::white);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}

void QtComponentsCalendarWidgetTitle::init()
{

    QList<QPushButton*> listBtn = findChildren<QPushButton*>();
    QList<QPushButton*>::const_iterator iter = listBtn.constBegin();
    for (; iter != listBtn.constEnd(); ++iter)
    {
        (*iter)->setFixedSize(16, 16);
    }

    QHBoxLayout* hb = new QHBoxLayout;
    hb->setContentsMargins(12, 2, 12, 2);
    hb->setSpacing(4);
    hb->addWidget(_pLastYear);
    hb->addWidget(_pLastMonth);
    hb->addStretch();
    hb->addWidget(_pText);
    hb->addStretch();
    hb->addWidget(_pNextMonth);
    hb->addWidget(_pNextYear);

    setLayout(hb);

    connect(_pLastMonth, SIGNAL(clicked()), _pCalendar, SLOT(showPreviousMonth()));
    connect(_pLastYear, SIGNAL(clicked()), _pCalendar, SLOT(showPreviousYear()));
    connect(_pNextMonth, SIGNAL(clicked()), _pCalendar, SLOT(showNextMonth()));
    connect(_pNextYear, SIGNAL(clicked()), _pCalendar, SLOT(showNextYear()));
    connect(_pCalendar, SIGNAL(clicked(const QDate&)), SLOT(setDateText(const QDate&)));
}


QtComponentsCalendarWidgetStyle::QtComponentsCalendarWidgetStyle(QtComponentsCalendarWidget* parent)
    : _pCalendar(parent)
{
    Q_ASSERT(parent);
    setParent(parent);
}

QtComponentsCalendarWidgetStyle::~QtComponentsCalendarWidgetStyle()
{

}

void QtComponentsCalendarWidgetStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
{
    if (element == PE_FrameFocusRect)
    {
        return;
    }
    QProxyStyle::drawPrimitive(element, option, painter, widget);
}
