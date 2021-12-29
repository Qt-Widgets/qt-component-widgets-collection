#ifndef __QTCOMPONENTSTHEME_P_H__
#define __QTCOMPONENTSTHEME_P_H__

#include <QtGlobal>
#include <QHash>
#include <QColor>

class QtComponents;

class QtComponentsPrivate
{
    Q_DISABLE_COPY(QtComponentsPrivate)
    Q_DECLARE_PUBLIC(QtComponents)

public:

    QtComponentsPrivate(QtComponents* q);
    virtual ~QtComponentsPrivate();

    QtComponents*const          q_ptr;
    QHash<QString, QColor>      colors;

};



#endif  //__QTCOMPONENTSTHEME_P_H__