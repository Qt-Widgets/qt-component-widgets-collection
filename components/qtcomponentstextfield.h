#ifndef QTCOMPONENTSTEXTFIELD_H
#define QTCOMPONENTSTEXTFIELD_H

#include <QtWidgets/QLineEdit>
#include <QColor>

class QtComponentsTextFieldPrivate;

class QtComponentsTextField : public QLineEdit
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsTextField)
    Q_DECLARE_PRIVATE(QtComponentsTextField)

    Q_PROPERTY(QColor frontColor READ frontColor WRITE setFrontColor)
    Q_PROPERTY(QColor inputColor READ inputColor WRITE setInputColor)

public:
    explicit QtComponentsTextField(QWidget* parent = 0);
    ~QtComponentsTextField();

    void setFrontColor(const QColor& color);
    QColor frontColor()const;

    void setInputColor(const QColor& color);
    QColor inputColor()const;

protected:
    QtComponentsTextField(QtComponentsTextFieldPrivate& d, QWidget *parent = 0);
    const QSharedPointer<QtComponentsTextFieldPrivate>    d_ptr;


    virtual void paintEvent(QPaintEvent * event);
    virtual bool event(QEvent * event);


};

#endif // QTCOMPONENTSTEXTFIELD_H
