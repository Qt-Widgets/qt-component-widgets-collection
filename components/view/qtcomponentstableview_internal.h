#ifndef __QTCOMPONENTSTABLEVIEW_INTERNAL_H__
#define __QTCOMPONENTSTABLEVIEW_INTERNAL_H__

#include <QHeaderView>
#include <QStyledItemDelegate>

#include "components/lib/qtcomponentstheme.h"

class QtComponentsTableView;

class QtComponentsHeaderView : public QHeaderView
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsHeaderView)

    Q_PROPERTY(Qt::CheckState state READ isChecked WRITE setCheckable)

public:

    explicit QtComponentsHeaderView(QtComponentsTableView* view, Qt::Orientation orientation = Qt::Horizontal, QWidget *parent = NULL);
    ~QtComponentsHeaderView();

    
    Qt::CheckState isChecked()const;

public slots:

    void setCheckable(Qt::CheckState state);
    
Q_SIGNALS:

    void sectionCheckable(Qt::CheckState);

protected:

    virtual void paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const;

    virtual void mousePressEvent(QMouseEvent *event);

private:

    void drawHeaderCheckBox(QPainter *painter, const QRect &rect, int logicalIndex) const;

    void drawHeaderText(QPainter *painter, const QRect &rect, int logicalIndex) const;

    void drawHeaderSort(QPainter *painter, const QRect &rect, int logicalIndex) const;

    void drawHeaderSearch(QPainter *painter, const QRect &rect) const;

    void drawCutLine(QPainter *painter, const QRect &rect) const;

private:

    Qt::CheckState                              _state;
    QtComponentsTableView*const                 _view;
};


class QtComponentsTableModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsTableModel)

public:

    explicit QtComponentsTableModel(QtComponentsTableView* view, QObject* parent = NULL);
    ~QtComponentsTableModel();

    void resetModel();

    void insertRow(QVector<Components::_TableModelPair>& rows);

    void removeRow(int row);

    void clearModel();

Q_SIGNALS:

    void sectionCheckable(Qt::CheckState);

protected:

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    virtual bool     setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role);

    virtual int      rowCount(const QModelIndex &parent) const;

    virtual int      columnCount(const QModelIndex &parent) const;

    virtual QVariant data(const QModelIndex &index, int role) const;

    virtual bool     setData(const QModelIndex &index, const QVariant &value, int role);

    virtual bool     removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

    virtual bool     insertRows(int row, int count, const QModelIndex &parent = QModelIndex());

    virtual Qt::ItemFlags flags(const QModelIndex &index) const;

private:

    QtComponentsTableView*const                 _view;
};




class QtComponentsTableDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsTableDelegate)

public:

    explicit QtComponentsTableDelegate(QtComponentsTableView* view, QObject* parent = NULL);
    ~QtComponentsTableDelegate();

Q_SIGNALS:

    void initClicked(const QString&);
    void updateClicked(const QString&);
    void clicked(const QModelIndex&);

protected:

    virtual QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    virtual void setEditorData(QWidget* editor, const QModelIndex& index) const;

    virtual void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const;

    virtual void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    virtual QSize sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const;

    virtual bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:

    void drawDefText(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void drawPointText(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void drawSuccessPointText(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void drawErrorPointText(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void drawWarnIcon(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void drawBanRunIcon(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void drawColorText(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void drawInitButton(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

    void drawUpdateButton(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;

private:

    QtComponentsTableView*const                 _view;
};



#endif  //__QTCOMPONENTSTABLEVIEW_INTERNAL_H__