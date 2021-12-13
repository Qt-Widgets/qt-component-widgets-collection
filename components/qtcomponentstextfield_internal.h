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

public slots:

    void on_Update_Properties();

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

    Q_PROPERTY(qreal scale READ scale WRITE setScale)
    Q_PROPERTY(QPointF offSet READ offset WRITE setOffset)
    Q_PROPERTY(QColor color READ color WRITE setColor)

public:

    explicit QtComponentsTextFieldLabel(QtComponentsTextField* parent = 0);
    ~QtComponentsTextFieldLabel();

    inline void setScale(qreal scale);
    inline qreal scale() const;

    inline void setOffset(const QPointF &pos);
    inline QPointF offset() const;

    inline void setColor(const QColor &color);
    inline QColor color() const;

private:

    QtComponentsTextField*const     m_textField;
    qreal                      m_scale;
    qreal                      m_posX;
    qreal                      m_posY;
    QColor                     m_color;
};


#endif // QTCOMPONENTSTEXTFIELD_INTERNAL_H
