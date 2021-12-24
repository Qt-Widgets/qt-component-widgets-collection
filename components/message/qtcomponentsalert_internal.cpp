#include "qtcomponentsalert_internal.h"

QtComponentsAlertStyle::QtComponentsAlertStyle(QtComponentsAlert* parent)
    : _alert(parent)
{
    Q_ASSERT(parent);
}

QtComponentsAlertStyle::~QtComponentsAlertStyle()
{

}


void QtComponentsAlertStyle::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);
}
