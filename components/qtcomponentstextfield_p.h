#ifndef QTCOMPONENTSTEXTFIELD_P_H
#define QTCOMPONENTSTEXTFIELD_P_H


#include <QtGlobal>
#include <QColor>

class QtComponentsTextField;
class QtComponentsTextFieldLabel;
class QtComponentsTextFieldStateMachine;

class QtComponentsTextFieldPrivate
{
    Q_DISABLE_COPY(QtComponentsTextFieldPrivate)
    Q_DECLARE_PUBLIC(QtComponentsTextField)

public:

    QtComponentsTextFieldPrivate(QtComponentsTextField* q);
    virtual ~QtComponentsTextFieldPrivate();

    void init();

    QtComponentsTextField*const         q_ptr;
    QtComponentsTextFieldLabel*         label;
    QtComponentsTextFieldStateMachine*  stateMachine;
    QColor                              inputColor;
    QColor                              frontColor;
    QString                             labelText;
};




#endif // QTCOMPONENTSTEXTFIELD_P_H
