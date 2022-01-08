#include "qtcomponentsalert.h"
#include "qtcomponentsalert_p.h"
#include "qtcomponentsalert_internal.h"
#include "components/lib/qtcomponentstools.h"

#include "log_util.h"

#include <QEvent>

void QtComponentsAlert::Success(QWidget* parent, const QString& text, const QString& description /*= QString()*/)
{
    QtComponentsAlert* alert = new QtComponentsAlert(parent);
    if (!description.isEmpty())
    {
        alert->setAlertStyle(Components::Details);
    }
    alert->setText(text);
    alert->setDescription(description);
    alert->setBackdropColor(QtComponentsTools::inst().getColor("success"));
    alert->setTextColor(QtComponentsTools::inst().getColor("successtext"));
    alert->setAlertMsgType(Components::Success);
    alert->setPixmap(QtComponentsTools::inst().pixmap(QString("alert"), QString("success"), alert->iconSize()));
    alert->from2Center(parent);
    alert->show();
    LOG_DBG << text.toLocal8Bit().data() << description.toLocal8Bit().data();
}

void QtComponentsAlert::Warning(QWidget* parent, const QString& text, const QString& description /*= QString()*/)
{
    QtComponentsAlert* alert = new QtComponentsAlert(parent);
    if (!description.isEmpty())
    {
        alert->setAlertStyle(Components::Details);
    }
    alert->setText(text);
    alert->setDescription(description);
    alert->setBackdropColor(QtComponentsTools::inst().getColor("warning"));
    alert->setTextColor(QtComponentsTools::inst().getColor("warningtext"));
    alert->setAlertMsgType(Components::Warning);
    alert->setPixmap(QtComponentsTools::inst().pixmap(QString("alert"), QString("warning"), alert->iconSize()));
    alert->from2Center(parent);
    alert->show();
    LOG_WRN << text.toLocal8Bit().data() << description.toLocal8Bit().data();
}

void QtComponentsAlert::Info(QWidget* parent, const QString& text, const QString& description /*= QString()*/)
{
    QtComponentsAlert* alert = new QtComponentsAlert(parent);
    if (!description.isEmpty())
    {
        alert->setAlertStyle(Components::Details);
    }
    alert->setText(text);
    alert->setDescription(description);
    alert->setBackdropColor(QtComponentsTools::inst().getColor("info"));
    alert->setTextColor(QtComponentsTools::inst().getColor("infotext"));
    alert->setAlertMsgType(Components::Info);
    alert->setPixmap(QtComponentsTools::inst().pixmap(QString("alert"), QString("info"), alert->iconSize()));
    alert->from2Center(parent);
    alert->show();
    LOG_INF << text.toLocal8Bit().data() << description.toLocal8Bit().data();
}

void QtComponentsAlert::Error(QWidget* parent, const QString& text, const QString& description /*= QString()*/)
{
    QtComponentsAlert* alert = new QtComponentsAlert(parent);
    if (!description.isEmpty())
    {
        alert->setAlertStyle(Components::Details);
    }
    alert->setText(text);
    alert->setDescription(description);
    alert->setBackdropColor(QtComponentsTools::inst().getColor("error"));
    alert->setTextColor(QtComponentsTools::inst().getColor("errortext"));
    alert->setAlertMsgType(Components::Error);
    alert->setPixmap(QtComponentsTools::inst().pixmap(QString("alert"), QString("error"), alert->iconSize()));
    alert->from2Center(parent);
    alert->show();
    LOG_ERR << text.toLocal8Bit().data() << description.toLocal8Bit().data();
}

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


void QtComponentsAlert::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);
}

QtComponentsAlert::~QtComponentsAlert()
{

}

bool QtComponentsAlert::event(QEvent* event)
{
    Q_D(QtComponentsAlert);

    switch (event->type())
    {
    case QEvent::ParentChange:
    {
        QWidget* widget;
        if (widget == parentWidget())
        {
            d->_pStyle->setParent(widget);
        }
        break;
    }
    default:
        break;
    }
    return QWidget::event(event);
}

void QtComponentsAlert::setAlertStyle(const Components::AlertStyle style)
{
    Q_D(QtComponentsAlert);
    if (Components::NoStyle == style)
    {
        setMinimumHeight(30);
        d->_iconSize = QSize(15, 15);
    }
    else
    {
        setMinimumHeight(60);
        d->_iconSize = QSize(30, 30);
    }
    d->_alertStyle = style;
    update();
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

void QtComponentsAlert::setBackdropColor(const QColor& color)
{
    Q_D(QtComponentsAlert);
    d->_backdropColor = color;
}

QColor QtComponentsAlert::backdropColor() const
{
    Q_D(const QtComponentsAlert);
    return d->_backdropColor;
}

void QtComponentsAlert::setTextColor(const QColor& color)
{
    Q_D(QtComponentsAlert);
    d->_textColor = color;
}

QColor QtComponentsAlert::textColor() const
{
    Q_D(const QtComponentsAlert);
    return d->_textColor;
}

void QtComponentsAlert::setIconSize(const QSize& size)
{
    Q_D(QtComponentsAlert);
    d->_iconSize = size;
}

QSize QtComponentsAlert::iconSize() const
{
    Q_D(const QtComponentsAlert);
    return d->_iconSize;
}

void QtComponentsAlert::setPixmap(const QPixmap& pixmap)
{
    Q_D(QtComponentsAlert);
    d->_icon = pixmap;
}

QPixmap QtComponentsAlert::pixmap() const
{
    Q_D(const QtComponentsAlert);
    return d->_icon;
}

void QtComponentsAlert::from2Center(QWidget* parent)
{
    Q_ASSERT(parent);

    QSize textSize = QtComponentsTools::inst().fontMetrics(text());
    resize(textSize.width() + 80, height());
    move(parent->width() / 2 - width() / 2, 30);
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
    q->resize(300, 30);
    q->setAttribute(Qt::WA_TranslucentBackground);
    q->setWindowFlags(Qt::FramelessWindowHint);
   
    _pStyle = new QtComponentsAlertStyle(q);
    _pDelegate = new QtComponentsAlertDelegate(q);
    _iconSize = QSize(15, 15);
    _icon = QtComponentsTools::inst().pixmap(QString("alert"), QString("success"), _iconSize);
    _backdropColor = QtComponentsTools::inst().getColor("success");
    _textColor = QtComponentsTools::inst().getColor("successtext");
    _alertFlag = Components::AlertCenter;
    _alertType = Components::Success;
    _alertStyle = Components::NoStyle;
    _text = QString::fromLocal8Bit("成功提示的文案");
    _description = QString::fromLocal8Bit("文字说明文字说明文字说明");
    _closeText = QString::fromLocal8Bit("知道了");

}
#if 0
QtComponentsAlertSuccess::QtComponentsAlertSuccess(QWidget* parent, const QString& text, const QString& description)
    : QtComponentsAlert(parent)
{
    if (!description.isEmpty())
    {
        setAlertStyle(Components::Details);
    }
    setText(text);
    setDescription(description);
    setBackdropColor(QtComponentsTools::inst().getColor("success"));
    setTextColor(QtComponentsTools::inst().getColor("successtext"));
    setAlertMsgType(Components::Success);
    setPixmap(QtComponentsTools::inst().pixmap("alert", "success", iconSize()));
    //from2Center(parent);
}

QtComponentsAlertWarning::QtComponentsAlertWarning(QWidget* parent, const QString& text, const QString& description)
    : QtComponentsAlert(parent)
{
    if (!description.isEmpty())
    {
        setAlertStyle(Components::Details);
    }
    setText(text);
    setDescription(description);
    setBackdropColor(QtComponentsTools::inst().getColor("warning"));
    setTextColor(QtComponentsTools::inst().getColor("warningtext"));
    setAlertMsgType(Components::Warning);
    setPixmap(QtComponentsTools::inst().pixmap("alert", "warning", iconSize()));
    from2Center(parent);
}

QtComponentsAlertInfo::QtComponentsAlertInfo(QWidget* parent, const QString& text, const QString& description /*= QString()*/)
    : QtComponentsAlert(parent)
{
    if (!description.isEmpty())
    {
        setAlertStyle(Components::Details);
    }
    setText(text);
    setDescription(description);
    setBackdropColor(QtComponentsTools::inst().getColor("info"));
    setTextColor(QtComponentsTools::inst().getColor("infotext"));
    setAlertMsgType(Components::Info);
    setPixmap(QtComponentsTools::inst().pixmap("alert", "info", iconSize()));
    show();
}

QtComponentsAlertError::QtComponentsAlertError(QWidget* parent, const QString& text, const QString& description /*= QString()*/)
    : QtComponentsAlert(parent)
{
    if (!description.isEmpty())
    {
        setAlertStyle(Components::Details);
    }
    setText(text);
    setDescription(description);
    setBackdropColor(QtComponentsTools::inst().getColor("error"));
    setTextColor(QtComponentsTools::inst().getColor("errortext"));
    setAlertMsgType(Components::Error);
    setPixmap(QtComponentsTools::inst().pixmap("alert", "error", iconSize()));
    from2Center(parent);
    show();
}
#endif