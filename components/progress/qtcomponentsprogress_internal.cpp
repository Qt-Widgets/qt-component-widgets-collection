#include "qtcomponentsprogress_internal.h"


QtComponentsProgressDelegate::QtComponentsProgressDelegate(QtComponentsProgress *parent)
    : QObject(parent)
    , _pProgress(parent)
    , _offset(0.0)
{
    Q_ASSERT(parent);
}

QtComponentsProgressDelegate::~QtComponentsProgressDelegate()
{

}
