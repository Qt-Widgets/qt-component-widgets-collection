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
    Q_PROPERTY(QColor color READ backdropColor WRITE setBackdropColor)
    Q_PROPERTY(QColor color READ textColor WRITE setTextColor)
    Q_PROPERTY(QSize size READ iconSize WRITE setIconSize)
    Q_PROPERTY(QPixmap pixmap READ pixmap WRITE setPixmap)

public:

    static void Success(QWidget* parent, const QString& text, const QString& description = QString());
    static void Warning(QWidget* parent, const QString& text, const QString& description = QString());
    static void Info(QWidget* parent, const QString& text, const QString& description = QString());
    static void Error(QWidget* parent, const QString& text, const QString& description = QString());


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

    void setBackdropColor(const QColor& color);
    QColor backdropColor()const;

    void setTextColor(const QColor& color);
    QColor textColor()const;

    void setIconSize(const QSize& size);
    QSize iconSize()const;

    void setPixmap(const QPixmap& pixmap);
    QPixmap pixmap()const;

    void from2Center(QWidget* parent);

protected:

    QtComponentsAlert(QtComponentsAlertPrivate& d, QWidget* parent);
    const QSharedPointer<QtComponentsAlertPrivate> d_ptr;

    virtual bool event(QEvent* event);
    virtual void paintEvent(QPaintEvent * event);

};
#if 0
class QtComponentsAlertSuccess : public QtComponentsAlert
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsAlertSuccess)
    
public:

    explicit QtComponentsAlertSuccess(QWidget* parent, const QString& text, const QString& description = QString());

};


class QtComponentsAlertWarning : public QtComponentsAlert
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsAlertWarning)

public:

    explicit QtComponentsAlertWarning(QWidget* parent, const QString& text, const QString& description = QString());

};

class QtComponentsAlertInfo : public QtComponentsAlert
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsAlertInfo)

public:

    explicit QtComponentsAlertInfo(QWidget* parent, const QString& text, const QString& description = QString());
};

class QtComponentsAlertError : public QtComponentsAlert
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsAlertError)

public:

    explicit QtComponentsAlertError(QWidget* parent, const QString& text, const QString& description = QString());
};
#endif
#endif //QTCOMPONENTSALERT_H