#ifndef __QTCOMPONENTSTABLEVIEW_P_H__
#define __QTCOMPONENTSTABLEVIEW_P_H__

#include <QtGlobal>

class QtComponentsTableView;
class QtComponentsHeaderView;
class QtComponentsTableDelegate;
class QtComponentsTableData;
class QtComponentsTableModel;


class QtComponentsTableViewPrivate
{
    Q_DISABLE_COPY(QtComponentsTableViewPrivate)
    Q_DECLARE_PUBLIC(QtComponentsTableView)

public:

    QtComponentsTableViewPrivate(QtComponentsTableView* q);
    virtual ~QtComponentsTableViewPrivate();

    void init();


    QtComponentsTableView*const         q_ptr;
    QtComponentsHeaderView*             _headerView;
    QtComponentsTableData*              _modelData;
    QtComponentsTableDelegate*          _delegate;
    QtComponentsTableModel*             _model;
};

#endif  //__QTCOMPONENTSTABLEVIEW_P_H__