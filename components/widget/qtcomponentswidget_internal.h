#ifndef QTCOMPONENTSWIDGET_INTERNAL_H
#define QTCOMPONENTSWIDGET_INTERNAL_H

#include <QWidget>

class QtComponentsWidget;


class QtComponentsWidgetShadowEffect : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsWidgetShadowEffect)

    Q_PROPERTY(qreal offset READ offset WRITE setOffset)
    Q_PROPERTY(QColor color READ progressColor WRITE setProgressColor)

public:

    QtComponentsWidgetShadowEffect(QtComponentsWidget* parent);
    ~QtComponentsWidgetShadowEffect();

    inline void setOffset(const qreal offset);
    inline qreal offset()const;

    inline void setProgressColor(const QColor& color);
    inline QColor progressColor()const;

protected:

    virtual bool eventFilter(QObject * obj, QEvent * event);
    virtual void paintEvent(QPaintEvent * event);

private:

    QtComponentsWidget*const         _parent;
    qreal                            _offset;
    QColor                           _proColor;
};

inline void QtComponentsWidgetShadowEffect::setProgressColor(const QColor& color)
{
    _proColor = color;
}

inline QColor QtComponentsWidgetShadowEffect::progressColor()const
{
    return _proColor;
}

inline void QtComponentsWidgetShadowEffect::setOffset(const qreal offset)
{
    _offset = offset;
}

inline qreal QtComponentsWidgetShadowEffect::offset()const
{
    return _offset;
}

class QtComponentsCenterWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsCenterWidget)

public:

    QtComponentsCenterWidget(QtComponentsWidget* parent);
    ~QtComponentsCenterWidget();

protected:

    virtual bool eventFilter(QObject * obj, QEvent * event);
    virtual void paintEvent(QPaintEvent * event);

private:

    QtComponentsWidget*const            _parent;

};



#endif // QTCOMPONENTSWIDGET_INTERNAL_H
