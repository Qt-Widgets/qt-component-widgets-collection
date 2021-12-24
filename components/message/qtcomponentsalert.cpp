#include "qtcomponentsalert.h"
#include "qtcomponentsalert_p.h"
#include "qtcomponentsalert_internal.h"


QtComponentsAlert::QtComponentsAlert(QWidget* parent /*= NULL*/)
    : QWidget(parent)
    , d_ptr(new QtComponentsAlertPrivate(this))
{
    d_func()->init();
}

QtComponentsAlert::QtComponentsAlert(QtComponentsAlertPrivate& d, QWidget* parent)
    : QWidget(parent)
    , d_ptr(&d)
{
    d_func()->init();
}

QtComponentsAlert::~QtComponentsAlert()
{

}

void QtComponentsAlert::setAlertStyle(const Components::AlertStyle style)
{
    Q_D(QtComponentsAlert);
    d->_alertStyle = style;
}

Components::AlertStyle QtComponentsAlert::alertStyle() const
{
    Q_D(const QtComponentsAlert);
    return d->_alertStyle;
}

void QtComponentsAlert::setAlertTextFlag(const Components::AlertTextFlag flag)
{
    Q_D(QtComponentsAlert);
    d->_alertFlag = flag;
}

Components::AlertTextFlag QtComponentsAlert::alertTextFlag() const
{
    Q_D(const QtComponentsAlert);
    return d->_alertFlag;
}

void QtComponentsAlert::setAlertMsgType(const Components::AlertMsgType type)
{
    Q_D(QtComponentsAlert);
    d->_alertType = type;
}

Components::AlertMsgType QtComponentsAlert::alertMsgType() const
{
    Q_D(const QtComponentsAlert);
    return d->_alertType;
}

void QtComponentsAlert::setText(const QString& text)
{
    Q_D(QtComponentsAlert);
    d->_text = text;
}

QString QtComponentsAlert::text() const
{
    Q_D(const QtComponentsAlert);
    return d->_text;
}

void QtComponentsAlert::setDescription(const QString& text)
{
    Q_D(QtComponentsAlert);
    d->_description = text;
}

QString QtComponentsAlert::description() const
{
    Q_D(const QtComponentsAlert);
    return d->_description;
}

void QtComponentsAlert::setCloseText(const QString& text)
{
    Q_D(QtComponentsAlert);
    d->_closeText = text;
}

QString QtComponentsAlert::closeText() const
{
    Q_D(const QtComponentsAlert);
    return d->_closeText;
}

QtComponentsAlertPrivate::QtComponentsAlertPrivate(QtComponentsAlert* q)
    : q_ptr(q)
{
    Q_ASSERT(q);
}


QtComponentsAlertPrivate::~QtComponentsAlertPrivate()
{

}


void QtComponentsAlertPrivate::init()
{
    Q_Q(QtComponentsAlert);
}