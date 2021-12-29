#include "qtcomponentsalert_internal.h"
#include "qtcomponentsalert.h"
#include "components/lib/qtcomponentstools.h"

#include <QPainter>
#include <QEvent>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QPauseAnimation>

QtComponentsAlertStyle::QtComponentsAlertStyle(QtComponentsAlert* parent)
    : QWidget(parent)
    , _alert(parent)
{
    Q_ASSERT(parent);
    parent->installEventFilter(this);
}

QtComponentsAlertStyle::~QtComponentsAlertStyle()
{

}


void QtComponentsAlertStyle::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);
    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    
    drawBackdrop(painter);

    drawIcon(painter);

    drawText(painter);

}

bool QtComponentsAlertStyle::eventFilter(QObject * obj, QEvent * event)
{
    const QEvent::Type type = event->type();

    if (QEvent::Resize == type || QEvent::Move == type)
    {
        setGeometry(_alert->rect());
    }
    
    return QWidget::eventFilter(obj, event);
}

void QtComponentsAlertStyle::drawBackdrop(QPainter& painter)
{
    painter.save();
    painter.setPen(Qt::NoPen);
    painter.setBrush(_alert->backdropColor());
    painter.drawRoundedRect(rect(), 6, 6);
    painter.restore();
}

void QtComponentsAlertStyle::drawIcon(QPainter& painter)
{
    painter.save();

    int center = rect().center().x();
    center = center - QtComponentsTools::inst().fontMetrics(_alert->text()).width() / 2 - 20;
    painter.drawPixmap(center, rect().y() + _alert->pixmap().height() / 2 + 1, _alert->pixmap());

    painter.restore();
}

void QtComponentsAlertStyle::drawText(QPainter& painter)
{
    painter.save();

    QPen pen(_alert->textColor());
    painter.setPen(pen);

    if (Components::NoStyle == _alert->alertStyle())
    {
        painter.drawText(rect(), _alert->alertTextFlag(), _alert->text());
    }
    else
    {
        painter.drawText(rect(), _alert->alertTextFlag(), _alert->text() + "\n" + _alert->description());
    }
    
    painter.restore();
}

QtComponentsAlertDelegate::QtComponentsAlertDelegate(QtComponentsAlert* parent)
    : QObject(parent)
{
    _propertyAnimation = new QSequentialAnimationGroup(this);

    QGraphicsOpacityEffect *pOpacity = new QGraphicsOpacityEffect(this);
    pOpacity->setOpacity(1);
    parent->setGraphicsEffect(pOpacity);

    QPropertyAnimation* inPropertyAnimation = new QPropertyAnimation(pOpacity, "opacity");
    inPropertyAnimation->setDuration(500);
    inPropertyAnimation->setStartValue(0);
    inPropertyAnimation->setEndValue(1);

    QPropertyAnimation* outPropertyAnimation = new QPropertyAnimation(pOpacity, "opacity");
    outPropertyAnimation->setDuration(500);
    outPropertyAnimation->setStartValue(1);
    outPropertyAnimation->setEndValue(0);

    _propertyAnimation->addAnimation(inPropertyAnimation);
    _propertyAnimation->addPause(3000);
    _propertyAnimation->addAnimation(outPropertyAnimation);

    _propertyAnimation->start();
}

QtComponentsAlertDelegate::~QtComponentsAlertDelegate()
{

}
