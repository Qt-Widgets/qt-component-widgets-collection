#include "qtcomponentswidget.h"
#include "qtcomponentswidget_internal.h"

#include <QStyleOption>
#include <QEvent>
#include <QPainter>
#include <QGraphicsDropShadowEffect>


QtComponentsWidgetShadowEffect::QtComponentsWidgetShadowEffect(QtComponentsWidget* parent)
    : QWidget(parent)
    , _parent(parent)
    , _offset(0)
    , _proColor("#00BCD4")
{
    Q_ASSERT(parent);

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(8);
    effect->setColor(QColor(0, 0, 0, 80));
    effect->setOffset(QPointF(0,0));
    setGraphicsEffect(effect);

    parent->installEventFilter(this);
}

QtComponentsWidgetShadowEffect::~QtComponentsWidgetShadowEffect()
{

}

bool QtComponentsWidgetShadowEffect::eventFilter(QObject * obj, QEvent * event)
{
    const QEvent::Type type = event->type();

    if (QEvent::Resize == type || QEvent::Move == type)
    {
        setGeometry(_parent->rect().adjusted(8, 8, -8, -8));
    }

    return QWidget::eventFilter(obj, event);
}

void QtComponentsWidgetShadowEffect::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(rect(), QColor("#FFFFFF"));
    
    if (_offset > 0)
    {
        const qreal split = width() * _offset * 0.01;
        painter.setPen(_proColor);
        const QPointF endPointF = QPointF(split, height() - 1);
        painter.drawLine(rect().bottomLeft(), endPointF);
    }
}

QtComponentsCenterWidget::QtComponentsCenterWidget(QtComponentsWidgetShadowEffect* parent)
    : QWidget(parent)
    , _parent(parent)
{
    Q_ASSERT(parent);

    parent->installEventFilter(this);
}

QtComponentsCenterWidget::~QtComponentsCenterWidget()
{

}

bool QtComponentsCenterWidget::eventFilter(QObject * obj, QEvent * event)
{
    const QEvent::Type type = event->type();

    if (QEvent::Resize == type || QEvent::Move == type)
    {
        setGeometry(_parent->rect());
    }

    return QWidget::eventFilter(obj, event);
}

void QtComponentsCenterWidget::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);
}
