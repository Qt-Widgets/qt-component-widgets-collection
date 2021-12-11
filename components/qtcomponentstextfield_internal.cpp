#include "qtcomponentstextfield_internal.h"

#include <QEventTransition>

QtComponentsTextFieldStateMachine::QtComponentsTextFieldStateMachine(QtComponentsTextField* parent)
    : QStateMachine(parent)
    , m_textField(parent)
    , m_label(new QtComponentsTextFieldLabel(parent))
    , m_frontState(new QState)
    , m_inputState(new QState)
    , m_frontAnimation(0)
    , m_inputAnimation(0)
    , m_progress(0.0)
{
    Q_ASSERT(parent);
    addState(m_frontState);
    addState(m_inputState);
    setInitialState(m_frontState);

    QEventTransition *transition;
    QPropertyAnimation *animation;
}

inline void QtComponentsTextFieldStateMachine::setProgress(qreal progress)
{
    m_progress = progress;
    m_textField->update();
}

qreal QtComponentsTextFieldStateMachine::progress() const
{
    return m_progress;
}
