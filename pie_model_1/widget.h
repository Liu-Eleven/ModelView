#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>

class QStandardItemModel;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void onClick();
private:

    QStandardItemModel *chartModel;
    QPushButton *btn;
};

#endif // WIDGET_H
