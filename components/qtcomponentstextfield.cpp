#include "qtcomponentstextfield.h"
#include "qtcomponentstextfield_p.h"
#include "qtcomponentstextfield_internal.h"

#include <QCoreApplication>

QtComponentsTextFieldPrivate::QtComponentsTextFieldPrivate(QtComponentsTextField *q)
    : q_ptr(q)
{

}

QtComponentsTextFieldPrivate::~QtComponentsTextFieldPrivate()
{

}

void QtComponentsTextFieldPrivate::init()
{
    Q_Q(QtComponentsTextField);

    stateMachine = new QtComponentsTextFieldStateMachine(q);
    label = 0;

    inputColor = QColor("#E0E0E0");
    frontColor = QColor("#00BCD4");

    q->setFrame(false);
    q->setAttribute(Qt::WA_Hover);
    q->setMouseTracking(true);
    q->setTextMargins(0, 2, 0, 4);
    q->setFont(QFont("Roboto", 11, QFont::Normal));

    stateMachine->start();
    QCoreApplication::processEvents();
}

QtComponentsTextField::QtComponentsTextField(QWidget *parent)
    : QLineEdit(parent)
    , d_ptr(new QtComponentsTextFieldPrivate(this))
{
    d_func()->init();
}

QtComponentsTextField::~QtComponentsTextField()
{

}

void QtComponentsTextField::setFrontColor(const QColor &color)
{
    Q_D(QtComponentsTextField);
    d->frontColor = color;
}

QColor QtComponentsTextField::frontColor() const
{
    Q_D(const QtComponentsTextField);
    return d->frontColor;
}

void QtComponentsTextField::setInputColor(const QColor &color)
{
    Q_D(QtComponentsTextField);
    d->inputColor = color;
}

QColor QtComponentsTextField::inputColor() const
{
    Q_D(const QtComponentsTextField);
    return d->inputColor;
}

QtComponentsTextField::QtComponentsTextField(QtComponentsTextFieldPrivate &d, QWidget *parent)
    : QLineEdit(parent)
    , d_ptr(&d)
{
    d_func()->init();
}

void QtComponentsTextField::paintEvent(QPaintEvent *event)
{
    QLineEdit::paintEvent(event);

    Q_D(QtComponentsTextField);

    QPainter painter(this);

    const qreal progress = d->stateMachine->progress();

    if(text().isEmpty() && progress < 1)
    {
        painter.setOpacity(1 - progress);
        painter.fillRect(rect(), parentWidget()->palette().color(backgroundRole()));
    }

    QPen pen;
    pen.setWidth(1);
    pen.setColor(frontColor());

    if (!isEnabled())
    {
        pen.setStyle(Qt::DashLine);
    }

    painter.setPen(pen);
    painter.setOpacity(1);
    painter.drawLine(QLineF(2.5, y, wd, y));

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(inputColor());

    if (progress > 0)
    {
        painter.setPen(Qt::NoPen);
        painter.setBrush(brush);
        const int w = (1 - progress)*static_cast<qreal>(wd / 2);
        painter.drawRect(w + 2.5, height() - 2, wd - w * 2, 2);
    }

}
