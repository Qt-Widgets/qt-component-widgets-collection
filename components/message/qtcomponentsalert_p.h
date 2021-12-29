#ifndef QTCOMPONENTSALERT_P_H
#define QTCOMPONENTSALERT_P_H

#include <QtGlobal>


#include "components/lib/qtcomponentstheme.h"

class QtComponentsAlert;
class QtComponentsAlertStyle;
class QtComponentsAlertDelegate;


class QtComponentsAlertPrivate
{
    Q_DISABLE_COPY(QtComponentsAlertPrivate)
    Q_DECLARE_PUBLIC(QtComponentsAlert)
    
public:

    void init();
    
    QtComponentsAlertPrivate(QtComponentsAlert* q);
    virtual ~QtComponentsAlertPrivate();

    QtComponentsAlert*const                 q_ptr;
    QtComponentsAlertStyle*                 _pStyle;
    QtComponentsAlertDelegate*              _pDelegate;
    Components::AlertStyle                  _alertStyle;
    Components::AlertTextFlag               _alertFlag;
    Components::AlertMsgType                _alertType;
    QString                                 _text;
    QString                                 _description;
    QString                                 _closeText;
    QColor                                  _textColor;
    QColor                                  _backdropColor;
    QSize                                   _iconSize;
    QPixmap                                 _icon;
};


#endif //QTCOMPONENTSALERT_P_H