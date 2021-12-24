#ifndef QTCOMPONENTSALERT_H
#define QTCOMPONENTSALERT_H

#include <QWidget>

#include "components/lib/qtcomponentstheme.h"

class QtComponentsAlertPrivate;

class QtComponentsAlert : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsAlert)
    Q_DECLARE_PRIVATE(QtComponentsAlert)

    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(QString text READ description WRITE setDescription)
    Q_PROPERTY(QString text READ closeText WRITE setCloseText)

public:

    explicit QtComponentsAlert(QWidget* parent = NULL);
    ~QtComponentsAlert();

    void setAlertStyle(const Components::AlertStyle style);
    Components::AlertStyle alertStyle()const;

    void setAlertTextFlag(const Components::AlertTextFlag flag);
    Components::AlertTextFlag alertTextFlag()const;

    void setAlertMsgType(const Components::AlertMsgType type);
    Components::AlertMsgType alertMsgType()const;

    void setText(const QString& text);
    QString text()const;

    void setDescription(const QString& text);
    QString description()const;

    void setCloseText(const QString& text);
    QString closeText()const;

protected:

    QtComponentsAlert(QtComponentsAlertPrivate& d, QWidget* parent);
    const QSharedPointer<QtComponentsAlertPrivate> d_ptr;

};


#endif //QTCOMPONENTSALERT_H