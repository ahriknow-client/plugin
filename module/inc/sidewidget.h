#ifndef COMP_SIDEWIDGET_H
#define COMP_SIDEWIDGET_H

#include <QWidget>

class SideWidget : public QWidget
{
    Q_OBJECT
private:
public:
    SideWidget(QWidget *parent, int id = 0);
    int oid;
    ~SideWidget();
};
#endif // COMP_SIDEWIDGET_H