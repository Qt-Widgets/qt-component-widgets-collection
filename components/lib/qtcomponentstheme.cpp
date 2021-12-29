#include "qtcomponentstheme.h"
#include "qtcomponentstheme_p.h"



QtComponentsPrivate::QtComponentsPrivate(QtComponents* q)
    : q_ptr(q)
{
    Q_ASSERT(q);
}

QtComponentsPrivate::~QtComponentsPrivate()
{

}

QtComponents::QtComponents(QObject* parent /*= NULL*/)
    : QObject(parent)
    , d_ptr(new QtComponentsPrivate(this))
{
    setColor("success", Components::green50);
    setColor("successtext", Components::green100);
    setColor("info", Components::grey50);
    setColor("infotext", Components::grey100);
    setColor("warning", Components::yellow50);
    setColor("warningtext", Components::yellow100);
    setColor("error", Components::red50);
    setColor("errortext", Components::red100);
}

QtComponents::~QtComponents()
{

}

QColor QtComponents::getColor(const QString& key) const
{
    Q_D(const QtComponents);
    if (!d->colors.contains(key))
    {
        return QColor();
    }
    return d->colors.value(key);
}

void QtComponents::setColor(const QString& key, const QColor& color)
{
    Q_D(QtComponents);
    d->colors.insert(key, color);
}

void QtComponents::setColor(const QString& key, Components::Color color)
{
    Q_D(QtComponents);
    static const QColor palette[] = 
    {
        QColor("#F0F9EB"), QColor("#67C23A"), QColor("#F4F4F5"), QColor("#909399"),
        QColor("#FDF6EC"), QColor("#E6A23C"), QColor("#FEF0F0"), QColor("#F56C6C")
    };
    d->colors.insert(key, palette[color]);
}
