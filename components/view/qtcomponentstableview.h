#ifndef __QTCOMPONENTSTABLEVIEW_H__
#define __QTCOMPONENTSTABLEVIEW_H__

#include <QTableView>

#include "components/lib/qtcomponentstheme.h"

class QtComponentsTableData;
class QtComponentsTableViewPrivate;

class QtComponentsTableView : public QTableView
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsTableView)
    Q_DECLARE_PRIVATE(QtComponentsTableView)

public:

    explicit QtComponentsTableView(QWidget* parent = NULL);
    ~QtComponentsTableView();

    void setHeaderLabel(int logicalIndex, Components::_TableHeaderPair label);
    void setHeaderLabels(QList<Components::_TableHeaderItem>& labels);

    QVector<Components::_TableHeaderPair> headerLabels()const;
    Components::_TableHeaderPair headerLabel(int logicalIndex)const;

    QtComponentsTableData* modelData()const;
    Components::_TableModelPair modelData(int row, int col)const;

    void resetModel();

    void insertRow(QVector<Components::_TableModelPair>& rows);

    void removeRow(int row);

    void clearModel();

protected:

    QtComponentsTableView(QtComponentsTableViewPrivate& d, QWidget* parent = NULL);
    const QSharedPointer<QtComponentsTableViewPrivate>      d_ptr;

};


class QtComponentsTableData : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsTableData)

public:

    QtComponentsTableData(QtComponentsTableView* view);
    ~QtComponentsTableData();

    QVector<Components::_TableHeaderPair>           _labels;
    QVector<QVector<Components::_TableModelPair> >  _modelData;

    int checkedSize()const;

    QVector<QVector<Components::_TableModelPair> > checkeds()const;

    void delChecked();

public slots:

    void onSectionCheckable(Qt::CheckState state);

private:

    QtComponentsTableView*const             _view;
};



#endif  //__QTCOMPONENTSTABLEVIEW_H__