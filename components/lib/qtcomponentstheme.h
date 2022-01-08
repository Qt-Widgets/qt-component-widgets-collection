#ifndef __QTCOMPONENTSTHEME_H__
#define __QTCOMPONENTSTHEME_H__

#include <QObject>
#include <QPair>
#include <QSharedPointer>

namespace Components
{
    enum AlertTextFlag
    {
        AlertLeft = Qt::AlignLeft,
        AlertRight = Qt::AlignRight,
        AlertCenter = Qt::AlignCenter
    };

    enum AlertStyle
    {
        NoStyle,
        Details
    };

    enum AlertMsgType
    {
        Success,
        Warning,
        Info,
        Error
    };

    enum Color
    {
        green50,
        green100,
        grey50,
        grey100,
        yellow50,
        yellow100,
        red50,
        red100,
        errorColor,
        successColor,
        lineColor,
        defTextColor,
        pointTextColor,
        successPointTextColor,
    };

    enum Variant
    {
        VarBase,
        VarOutline,
        VarDashed,
        VarText
    };

    enum ExpendMode
    {
        SingleClick,
        DoubleClick,
        NoClick
    };

    enum UserRoleModel
    {
        ExpandRole = Qt::UserRole + 1,

    };

    enum MouseState
    {
        DefState,
        HoverState,
        PressedState
    };

    enum TableHeaderType
    {
        hID,
        hCheckBox,
        hText,
        hSort,
        hSearch
    };
    typedef QPair<TableHeaderType, QString> _TableHeaderPair;

    enum TableModelType
    {
        Checked = Qt::Checked,
        UnChecked = Qt::Unchecked,
        ID = 0xF,
        Freeze,
        Text,
        PointText,
        SuccessPointText,
        ErrorPointText,
        ColorText,
        InitBtn,
        UpdateBtn,
        Search,
        Warn,
        BanRun
    };
    typedef QPair<TableModelType, QString> _TableModelPair;

    typedef struct TagTableHeaderItem
    {
        Components::TableHeaderType type;
        int                         width;
        QString                     text;
    }_TableHeaderItem;


}

class QColor;
class QtComponentsPrivate;

class QtComponents : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponents)
    Q_DECLARE_PRIVATE(QtComponents)

public:

    explicit QtComponents(QObject* parent = NULL);
    ~QtComponents();

    QColor getColor(const QString& key)const;

    void setColor(const QString& key, const QColor& color);
    void setColor(const QString& key, Components::Color color);

protected:

    const QSharedPointer<QtComponentsPrivate>   d_ptr;
};




#endif  //__QTCOMPONENTSTHEME_H__