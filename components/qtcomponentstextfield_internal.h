#ifndef QTCOMPONENTSTEXTFIELD_INTERNAL_H
#define QTCOMPONENTSTEXTFIELD_INTERNAL_H

#include <QStateMachine>
#include <QtWidgets/QWidget>

#include "qtcomponentstextfield.h"

class QPropertyAnimation;
class QtComponentsTextFieldLabel;

class QtComponentsTextFieldStateMachine : public QStateMachine
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsTextFieldStateMachine)

    Q_PROPERTY(qreal progress READ progress WRITE setProgress)

public:

    explicit QtComponentsTextFieldStateMachine(QtComponentsTextField* parent);
    ~QtComponentsTextFieldStateMachine();

    inline void setProgress(qreal progress);
    inline qreal progress()const;

private:

    QtComponentsTextField*const     m_textField;
    QtComponentsTextFieldLabel*     m_label;
    QState*const                    m_frontState;
    QState*const                    m_inputState;
    QPropertyAnimation*             m_frontAnimation;
    QPropertyAnimation*             m_inputAnimation;
    qreal                           m_progress;
};


class QtComponentsTextFieldLabel : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsTextFieldLabel)

public:

    explicit QtComponentsTextFieldLabel(QtComponentsTextField* parent = 0);
    ~QtComponentsTextFieldLabel();

private:

    QtComponentsTextField*const     m_textField;
};


#endif // QTCOMPONENTSTEXTFIELD_INTERNAL_H
