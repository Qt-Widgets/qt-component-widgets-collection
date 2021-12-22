#include "qtcomponentscalendar_internal.h".h"

#include <QHBoxLayout>

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


void QtComponentsCalendarWidgetTitle::init()
{
    QHBoxLayout* hb = new QHBoxLayout;
    hb->setContentsMargins(12, 0, 12, 0);
    hb->setSpacing(4);
    hb->addWidget(_pLastYear);
    hb->addWidget(_pLastMonth);
    hb->addStretch();
    hb->addWidget(_pText);
    hb->addStretch();
    hb->addWidget(_pNextMonth);
    hb->addWidget(_pNextYear);
    setLayout(hb);

    connect(_pLastMonth,SIGNAL(clicked()),_pCalendar,SLOT(showPreviousMonth()));
    connect(_pLastYear,SIGNAL(clicked()),_pCalendar,SLOT(showPreviousYear()));
    connect(_pNextMonth,SIGNAL(clicked()),_pCalendar,SLOT(showNextMonth()));
    connect(_pNextYear,SIGNAL(clicked()),_pCalendar,SLOT(showNextYear()));
}
