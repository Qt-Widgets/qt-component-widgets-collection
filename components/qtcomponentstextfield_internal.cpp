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

    transition = new QEventTransition(parent, QEvent::FocusIn);
    transition->setTargetState(m_frontState);
    m_frontState->addTransition(transition);

    animation = new QPropertyAnimation(this, "progress", this);
    animation->setEasingCurve(QEasingCurve::InCubic);
    animation->setDuration(310);
    transition->addAnimation(animation);

    transition = new QEventTransition(parent, QEvent::FocusOut);
    transition->setTargetState(m_inputState);
    m_inputState->addTransition(transition);

    animation = new QPropertyAnimation(this, "progress", this);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    animation->setDuration(310);
    transition->addAnimation(animation);

    m_frontState->assignProperty(this, "progress", 0);
    m_inputState->assignProperty(this, "progress", 1);

    on_Update_Properties();

    connect(m_textField, SIGNAL(textChanged(QString)), this, SLOT(on_Update_Properties()));

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

void QtComponentsTextFieldStateMachine::on_Update_Properties()
{

    const int m = m_textField->textMargins().top();

    if (m_textField->text().isEmpty()) {
        m_frontState->assignProperty(m_label, "offset", QPointF(0, 26));
    } else {
        m_frontState->assignProperty(m_label, "offset", QPointF(0, 0-m));
    }

    m_inputState->assignProperty(m_label, "offset", QPointF(0, 0-m));
    m_inputState->assignProperty(m_label, "color", m_textField->inputColor());
    m_frontState->assignProperty(m_label, "color", m_textField->frontColor());

    if (0 != m_label->offset().y() && !m_textField->text().isEmpty()) {
        m_label->setOffset(QPointF(0, 0-m));
    } else if (!m_textField->hasFocus() && m_label->offset().y() <= 0 && m_textField->text().isEmpty()) {
        m_label->setOffset(QPointF(0, 26));
    }


    m_textField->update();
}
