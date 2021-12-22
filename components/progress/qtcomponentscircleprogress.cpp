#include "qtcomponentscircleprogress.h"
#include "qtcomponentscircleprogress_p.h"
#include "qtcomponentscircleprogress_internal.h"


#include <QPainter>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>

QtComponentsCircleProgress::QtComponentsCircleProgress(QWidget *parent)
    : QProgressBar(parent)
    , d_ptr(new QtComponentsCircleProgressPrivate(this))
{
    d_func()->init();
}

QtComponentsCircleProgress::~QtComponentsCircleProgress()
{

}

void QtComponentsCircleProgress::setInputColor(const QColor &color)
{
    Q_D(QtComponentsCircleProgress);
    d->_inputColor = color;
}

QColor QtComponentsCircleProgress::inputColor() const
{
    Q_D(const QtComponentsCircleProgress);
    return d->_inputColor;
}

void QtComponentsCircleProgress::setFrontColor(const QColor &color)
{
    Q_D(QtComponentsCircleProgress);
    d->_frontColor = color;
}

QColor QtComponentsCircleProgress::frontColor() const
{
    Q_D(const QtComponentsCircleProgress);
    return d->_frontColor;
}


void QtComponentsCircleProgress::setSize(const int size)
{
    Q_D(QtComponentsCircleProgress);
    d->_size = size;
    update();
    updateGeometry();
}

int QtComponentsCircleProgress::size() const
{
    Q_D(const QtComponentsCircleProgress);
    return d->_size;
}

QSize QtComponentsCircleProgress::sizeHint() const
{
    Q_D(const QtComponentsCircleProgress);
    const qreal s = d->_size + 6.25 + 8;
    return QSize(s, s);
}

void QtComponentsCircleProgress::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    Q_D(QtComponentsCircleProgress);

    const qreal penWidth = 6.25;

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    if(!isEnabled())
    {
        QPen pen;
        pen.setCapStyle(Qt::RoundCap);
        pen.setWidthF(penWidth);
        pen.setColor(frontColor());
        painter.setPen(pen);
        painter.drawLine(rect().center() - QPointF(20, 20), rect().center() + QPointF(20, 20));
        painter.drawLine(rect().center() + QPointF(20, -20), rect().center() - QPointF(20, -20));
        return;
    }

    if(0 == maximum())
    {
        painter.translate(width()/2, height()/2);
        painter.rotate(d->_delegate->angle());
    }

    QPen pen;
    pen.setCapStyle(Qt::RoundCap);
    pen.setWidthF(penWidth);
    pen.setColor(inputColor());

    if(0 == maximum())
    {
        QVector<qreal> pattern;
        pattern << d->_delegate->len() * d->_size / 50 << 30 * d->_size / 50;

        pen.setDashOffset(d->_delegate->offset() * d->_size / 50);
        pen.setDashPattern(pattern);

        painter.setPen(pen);

        painter.drawEllipse(QPoint(0, 0), d->_size / 2, d->_size / 2);
    }
    else
    {
        painter.setPen(pen);

        const qreal x = (width()-d->_size) / 2;
        const qreal y = (height()-d->_size) / 2;

        const qreal a = 360 * (value()-minimum()) / (maximum()-minimum());

        QPainterPath path;
        path.arcMoveTo(x, y, d->_size, d->_size, 0);
        path.arcTo(x, y, d->_size, d->_size, 0, a);

        painter.drawPath(path);
    }

}

QtComponentsCircleProgress::QtComponentsCircleProgress(QtComponentsCircleProgressPrivate &d, QWidget *parent)
    : QProgressBar(parent)
    , d_ptr(&d)
{
    d_func()->init();
}

QtComponentsCircleProgressPrivate::QtComponentsCircleProgressPrivate(QtComponentsCircleProgress *q)
    : q_ptr(q)
{
    Q_ASSERT(q);
}

QtComponentsCircleProgressPrivate::~QtComponentsCircleProgressPrivate()
{

}

void QtComponentsCircleProgressPrivate::init()
{
    Q_Q(QtComponentsCircleProgress);
    _delegate = new QtComponentsCircleProgressDelegate(q);
    _inputColor = QColor("#00BCD4");
    _frontColor = QColor("#E0E0E0");
    _size = 64;

    q->setMaximum(0);

    q->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding,
                                 QSizePolicy::MinimumExpanding));

    QParallelAnimationGroup *group = new QParallelAnimationGroup(q);
    group->setLoopCount(-1);

    QPropertyAnimation *animation;

    animation = new QPropertyAnimation(q);
    animation->setPropertyName("len");
    animation->setTargetObject(_delegate);
    animation->setEasingCurve(QEasingCurve::InOutQuad);
    animation->setStartValue(0.1);
    animation->setKeyValueAt(0.15, 0.2);
    animation->setKeyValueAt(0.6, 20);
    animation->setKeyValueAt(0.7, 20);
    animation->setEndValue(20);
    animation->setDuration(2050);

    group->addAnimation(animation);

    animation = new QPropertyAnimation(q);
    animation->setPropertyName("offset");
    animation->setTargetObject(_delegate);
    animation->setEasingCurve(QEasingCurve::InOutSine);
    animation->setStartValue(0);
    animation->setKeyValueAt(0.15, 0);
    animation->setKeyValueAt(0.6, -7);
    animation->setKeyValueAt(0.7, -7);
    animation->setEndValue(-25);
    animation->setDuration(2050);

    group->addAnimation(animation);

    animation = new QPropertyAnimation(q);
    animation->setPropertyName("angle");
    animation->setTargetObject(_delegate);
    animation->setStartValue(0);
    animation->setEndValue(719);
    animation->setDuration(2050);

    group->addAnimation(animation);

    group->start();
}
