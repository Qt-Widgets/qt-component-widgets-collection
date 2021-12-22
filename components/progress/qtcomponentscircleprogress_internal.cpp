#include "qtcomponentscircleprogress_internal.h"

QtComponentsCircleProgressDelegate::QtComponentsCircleProgressDelegate(QtComponentsCircleProgress *parent)
    : _progress(parent)
    , _offset(0)
    , _angle(0)
    , _len(50)
{
    Q_ASSERT(parent);
}

QtComponentsCircleProgressDelegate::~QtComponentsCircleProgressDelegate()
{

}
