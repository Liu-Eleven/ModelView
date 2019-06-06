#include "widget.h"
#include "pieview.h"
#include <QStandardItemModel>
#include <QTableView>
#include <QSplitter>
#include <QSqlQuery>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(900 , 600);
    chartModel = new QStandardItemModel;

    chartModel->setColumnCount(2);
    chartModel->setHeaderData(0, Qt::Horizontal, QString("品牌"));
    chartModel->setHeaderData(1, Qt::Horizontal, QString("销售数量"));

    QWidget *page = new QWidget(this);
    QSplitter *splitter = new QSplitter(page);
    splitter->resize(900, 320);
    splitter->move(0, 80);


    QTableView *table = new QTableView;
    PieView *pieChart = new PieView;
    splitter->addWidget(table);
    splitter->addWidget(pieChart);


    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 2);

    table->setModel(chartModel);
    pieChart->setModel(chartModel);
    connect(chartModel , SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)) , pieChart , SLOT(dataChanged(QModelIndex,QModelIndex)));


    QItemSelectionModel *selectionModel = new QItemSelectionModel(chartModel);
    table->setSelectionModel(selectionModel);
    pieChart->setSelectionModel(selectionModel);


    btn = new QPushButton(this);
    btn->setText("ok");
    btn->setGeometry(0 , 530 , 120 , 30);

    connect(btn , SIGNAL(clicked(bool)) ,this , SLOT(onClick()));



}

Widget::~Widget()
{

}

void Widget::onClick()
{
    QSqlQuery query;
    query.exec(QString("select name,sell from brand where type='%1'")
               .arg("电视"));

    chartModel->removeRows(0, chartModel->rowCount(QModelIndex()), QModelIndex());
//qDebug()<<query.value(0).toString();
    int row = 0;

    while(row<5) {
        int r = qrand() % 256;
        int g = qrand() % 256;
        int b = qrand() % 256;

        chartModel->insertRows(row, 1, QModelIndex());

        chartModel->setData(chartModel->index(row, 0, QModelIndex()),
                            "卧槽");
        chartModel->setData(chartModel->index(row, 1, QModelIndex()),
                            30);
        chartModel->setData(chartModel->index(row, 0, QModelIndex()),
                            QColor(r, g, b), Qt::DecorationRole);
        row++;
    }
}
