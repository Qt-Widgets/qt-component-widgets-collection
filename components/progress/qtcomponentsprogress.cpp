#include "qtcomponentsprogress.h"
#include "qtcomponentsprogress_p.h"
#include "qtcomponentsprogress_internal.h"

#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>

QtComponentsProgress::QtComponentsProgress(QWidget* parent)
    : QProgressBar(parent)
    , d_ptr(new QtComponentsProgressPrivate(this))
{
    d_func()->init();
}

QtComponentsProgress::~QtComponentsProgress()
{

}

void QtComponentsProgress::setInputColor(const QColor &color)
{
    Q_D(QtComponentsProgress);
    d->_inputColor = color;
}

QColor QtComponentsProgress::inputColor() const
{
    Q_D(const QtComponentsProgress);
    return d->_inputColor;
}

void QtComponentsProgress::setFrontColor(const QColor &color)
{
    Q_D(QtComponentsProgress);
    d->_frontColor = color;
}

QColor QtComponentsProgress::frontColor() const
{
    Q_D(const QtComponentsProgress);
    return d->_frontColor;
}

void QtComponentsProgress::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);
    Q_D(QtComponentsProgress);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(inputColor());
    painter.setBrush(brush);
    painter.setPen(Qt::NoPen);

    QPainterPath path;
    path.addRoundedRect(0, height()/2-3, width(), 6, 3, 3);
    painter.setClipPath(path);

    painter.drawRect(0, 0, width(), height());

    if (isEnabled())
    {
        brush.setColor(frontColor());
        painter.setBrush(brush);

        qDebug()<<d->_delegate->offset();
        painter.drawRect(d->_delegate->offset()*width()*2-width(), 0, width(), height());

    }
}



QtComponentsProgressPrivate::QtComponentsProgressPrivate(QtComponentsProgress *q)
    : q_ptr(q)
{

}

QtComponentsProgressPrivate::~QtComponentsProgressPrivate()
{

}

void QtComponentsProgressPrivate::init()
{
    Q_Q(QtComponentsProgress);
    _delegate = new QtComponentsProgressDelegate(q);
    _inputColor = QColor("#E0E0E0");
    _frontColor = QColor("#00BCD4");

    QPropertyAnimation *animation;

    animation = new QPropertyAnimation(q);
    animation->setPropertyName("offset");
    animation->setTargetObject(_delegate);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setDuration(1000);

    animation->setLoopCount(-1);

    animation->start();
}
