#include "qtcomponentstableview.h"
#include "qtcomponentstableview_p.h"
#include "qtcomponentstableview_internal.h"
#include "components/lib/qtcomponentstools.h"

#include <QPainter>
#include <QObject>

QtComponentsTableView::QtComponentsTableView(QWidget* parent)
    : QTableView(parent)
    , d_ptr(new QtComponentsTableViewPrivate(this))
{
    d_func()->init();
}

QtComponentsTableView::QtComponentsTableView(QtComponentsTableViewPrivate& d, QWidget* parent)
    : QTableView(parent)
    , d_ptr(&d)
{
    d_func()->init();
}

QtComponentsTableView::~QtComponentsTableView()
{

}

void QtComponentsTableView::setHeaderLabels(QList<Components::_TableHeaderItem>& labels)
{
    Q_D(QtComponentsTableView);
    for (int col = 0; col < labels.size(); ++col)
    {
        d->_modelData->_labels.push_back(qMakePair(labels[col].type, labels[col].text));
    }
    d->_headerView->setResizeMode(QHeaderView::Stretch);
    for (int col = 0; col < labels.size(); ++col)
    {
        if (0 == labels[col].width)
        {
            d->_headerView->setResizeMode(col,QHeaderView::Stretch);
        }
        else
        {
            d->_headerView->setResizeMode(col, QHeaderView::Fixed);
            setColumnWidth(col, labels[col].width);
        }
    }
}

QVector<Components::_TableHeaderPair> QtComponentsTableView::headerLabels() const
{
    Q_D(const QtComponentsTableView);
    return d->_modelData->_labels;
}

Components::_TableHeaderPair QtComponentsTableView::headerLabel(int logicalIndex) const
{
    Q_D(const QtComponentsTableView);
    return d->_modelData->_labels[logicalIndex];
}

QtComponentsTableData* QtComponentsTableView::modelData() const
{
    Q_D(const QtComponentsTableView);
    return d->_modelData;
}

Components::_TableModelPair QtComponentsTableView::modelData(int row, int col) const
{
    Q_D(const QtComponentsTableView);
    return d->_modelData->_modelData[row][col];
}

void QtComponentsTableView::resetModel()
{
    Q_D(QtComponentsTableView);
    d->_model->resetModel();
}

void QtComponentsTableView::insertRow(QVector<Components::_TableModelPair>& rows)
{
    Q_D(QtComponentsTableView);
    d->_model->insertRow(rows);
}

void QtComponentsTableView::removeRow(int row)
{
    Q_D(QtComponentsTableView);
    d->_model->removeRow(row);
}

void QtComponentsTableView::clearModel()
{
    Q_D(QtComponentsTableView);
    d->_model->clearModel();
}

void QtComponentsTableView::setHeaderLabel(int logicalIndex, Components::_TableHeaderPair label)
{
    Q_D(QtComponentsTableView);
    d->_modelData->_labels[logicalIndex] = label;
    d->_headerView->viewport()->update();
}

void QtComponentsTableViewPrivate::init()
{
    Q_Q(QtComponentsTableView);

    _modelData = new QtComponentsTableData(q);

    _headerView = new QtComponentsHeaderView(q);

    _headerView->setFixedHeight(30);

    _headerView->setResizeMode(QHeaderView::Stretch);

    _model = new QtComponentsTableModel(q);

    _delegate = new QtComponentsTableDelegate(q);

    q->setHorizontalHeader(_headerView);

    q->verticalHeader()->hide();

    q->setModel(_model);

    q->setItemDelegate(_delegate);

    q->setSelectionBehavior(QAbstractItemView::SelectRows);

    q->setWordWrap(false);

    q->setShowGrid(false);

    q->setFocusPolicy(Qt::NoFocus);

    QObject::connect(_headerView, SIGNAL(sectionCheckable(Qt::CheckState)), _modelData, SLOT(onSectionCheckable(Qt::CheckState)));
    QObject::connect(_model, SIGNAL(sectionCheckable(Qt::CheckState)), _headerView, SLOT(setCheckable(Qt::CheckState)));

}

QtComponentsTableViewPrivate::QtComponentsTableViewPrivate(QtComponentsTableView* q)
    : q_ptr(q)
{
    Q_ASSERT(q);
}

QtComponentsTableViewPrivate::~QtComponentsTableViewPrivate()
{
    
}

QtComponentsTableData::QtComponentsTableData(QtComponentsTableView* view)
    : _view(view)
{
    Q_ASSERT(view);
}

QtComponentsTableData::~QtComponentsTableData()
{

}

int QtComponentsTableData::checkedSize() const
{
    int size = 0;
    for (int row = 0; row < _modelData.size(); ++row)
    {
        for (int col = 0; col < _modelData[row].size(); ++col)
        {
            if (Components::Checked == _modelData[row][col].first)
            {
                size++;
                break;
            }
        }
    }
    return size;
}

QVector<QVector<Components::_TableModelPair> > QtComponentsTableData::checkeds() const
{
    QVector<QVector<Components::_TableModelPair> > items;
    QVector<QVector<Components::_TableModelPair> >::const_iterator rowIter = _modelData.begin();
    QVector<Components::_TableModelPair>::const_iterator colIter;
    for (; rowIter != _modelData.end(); ++rowIter)
    {
        for (colIter = rowIter->begin(); colIter != rowIter->end(); ++colIter)
        {
            if (Components::Checked == colIter->first)
            {
                items.push_back(*rowIter);
                break;
            }
        }
    }
    return items;
}

void QtComponentsTableData::delChecked()
{
    QVector<QVector<Components::_TableModelPair> >::iterator rowIter = _modelData.begin();
    QVector<Components::_TableModelPair>::iterator colIter;
    for (; rowIter != _modelData.end(); ++rowIter)
    {
        for (colIter = rowIter->begin(); colIter != rowIter->end(); ++colIter)
        {
            if (Components::Checked == colIter->first)
            {
                _modelData.erase(rowIter--);
                break;
            }
        }
    }
    QtComponentsHeaderView* header = qobject_cast<QtComponentsHeaderView*>(_view->horizontalHeader());
    header->setCheckable(Qt::Unchecked);
    _view->resetModel();
}

void QtComponentsTableData::onSectionCheckable(Qt::CheckState state)
{
    for (int row = 0; row < _modelData.size(); ++row)
    {
        for (int col = 0; col < _modelData[row].size(); ++col)
        {
            if (Components::Checked == _modelData[row][col].first ||
                Components::UnChecked == _modelData[row][col].first)
            {
                _modelData[row][col].first = static_cast<Components::TableModelType>(state);
                break;
            }
        }
    }
    _view->resetModel();
}
