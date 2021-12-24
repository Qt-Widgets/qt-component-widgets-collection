#include "qtcomponentscalendar_internal.h"

#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QPalette>
#include <QColor>
#include <QStyleOption>
#include <QPainter>
#include <QDebug>

QtComponentsCalendarWidgetTitle::QtComponentsCalendarWidgetTitle(QtComponentsCalendarWidget *parent)
    : _pCalendar(parent)
    , _LastMonth(new QPushButton(this))
    , _LastYear(new QPushButton(this))
    , _NextMonth(new QPushButton(this))
    , _NextYear(new QPushButton(this))
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
    hb->addWidget(_LastYear);
    hb->addWidget(_LastMonth);
    hb->addStretch();
    hb->addWidget(_pText);
    hb->addStretch();
    hb->addWidget(_NextMonth);
    hb->addWidget(_NextYear);

    setLayout(hb);

    connect(_LastMonth, SIGNAL(clicked()), _pCalendar, SLOT(showPreviousMonth()));
    connect(_LastYear, SIGNAL(clicked()), _pCalendar, SLOT(showPreviousYear()));
    connect(_NextMonth, SIGNAL(clicked()), _pCalendar, SLOT(showNextMonth()));
    connect(_NextYear, SIGNAL(clicked()), _pCalendar, SLOT(showNextYear()));
    connect(_pCalendar, SIGNAL(clicked(const QDate&)), SLOT(setDateText(const QDate&)));

    setDateText(QDate::currentDate());
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

QtComponentsCalendarWidgetWeek::QtComponentsCalendarWidgetWeek(QtComponentsCalendarWidget* parent)
    : QWidget(parent)
    , _calendar(parent)
{
    Q_ASSERT(parent);
    init();
}

QtComponentsCalendarWidgetWeek::~QtComponentsCalendarWidgetWeek()
{

}

void QtComponentsCalendarWidgetWeek::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);

    const int h = parentWidget()->width();
    const qreal splt = h / 7;

    QStringList weekList;
    
    weekList
        << QString::fromLocal8Bit("日") << QString::fromLocal8Bit("一") 
        << QString::fromLocal8Bit("二") << QString::fromLocal8Bit("三")
        << QString::fromLocal8Bit("四") << QString::fromLocal8Bit("五")
        << QString::fromLocal8Bit("六");

    QPainter painter(this);

    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::white);
    painter.drawRect(rect());
    painter.restore();
    QFont font;
    font.setPixelSize(12);
    painter.setFont(font);
    painter.setPen(QPen(QColor("#60627F")));
    for (int col = 0; col < 7; ++col)
    {
        const QRect rect(col * splt, 0, splt, height());
        painter.drawText(rect, Qt::AlignCenter, weekList[col]);
    }
    painter.save();
    painter.setPen(QPen(QColor("#EBEEF5")));
    painter.drawLine(rect().bottomLeft(), rect().bottomRight());
    painter.restore();
}

void QtComponentsCalendarWidgetWeek::init()
{
    setMinimumHeight(30);
}
