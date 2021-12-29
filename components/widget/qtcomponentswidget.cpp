#include "qtcomponentswidget.h"
#include "qtcomponentswidget_p.h"
#include "qtcomponentswidget_internal.h"

#include <QHBoxLayout>
#include <QEvent>
#include <QPushButton>


QtComponentsWidget::QtComponentsWidget(QWidget *parent)
    : QWidget(parent)
    , d_ptr(new QtComponentsWidgetPrivate(this))
{
    d_func()->init();
}

void QtComponentsWidget::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);
}

bool QtComponentsWidget::event(QEvent* event)
{
    Q_D(QtComponentsWidget);
    QEvent::Type type = event->type();
    switch (type)
    {
    case QEvent::ParentChange:
    {
        QWidget* widget;
        if (widget == parentWidget())
        {
            d->_center->setParent(widget);
        }
        break;
    }
    default:
        break;
    }
    return QWidget::event(event);
}


QtComponentsWidget::~QtComponentsWidget()
{

}

QtComponentsWidget::QtComponentsWidget(QtComponentsWidgetPrivate &d, QWidget *parent)
    : QWidget(parent)
    , d_ptr(&d)
{
    d_func()->init();
}

QtComponentsWidgetPrivate::QtComponentsWidgetPrivate(QtComponentsWidget *q)
    : q_ptr(q)
{
    Q_ASSERT(q);
}

QtComponentsWidgetPrivate::~QtComponentsWidgetPrivate()
{

}

void QtComponentsWidgetPrivate::init()
{
    Q_Q(QtComponentsWidget);

    q->setAttribute(Qt::WA_TranslucentBackground);
    q->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    _effect = new QtComponentsWidgetShadowEffect(q);

    _center = new QtComponentsCenterWidget(_effect);

}
