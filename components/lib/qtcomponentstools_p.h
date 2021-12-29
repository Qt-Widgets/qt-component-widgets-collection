#ifndef __QTCOMPONENTSTOOLS_P_H__
#define __QTCOMPONENTSTOOLS_P_H__

#include <QtGlobal>

class QtComponents;
class QtComponentsTools;

class QtComponentsToolsPrivate
{
    Q_DISABLE_COPY(QtComponentsToolsPrivate)
    Q_DECLARE_PUBLIC(QtComponentsTools)

public:

    QtComponentsToolsPrivate(QtComponentsTools* q);
    virtual ~QtComponentsToolsPrivate();

    QtComponentsTools*const     q_ptr;
    QtComponents*               _components;
};



#endif  //__QTCOMPONENTSTOOLS_P_H__