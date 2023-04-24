#ifndef COMP_EDITWIDGET_H
#define COMP_EDITWIDGET_H

#include <QTabWidget>

class EditWidget : public QTabWidget
{
    Q_OBJECT
private:
    int id;
    QString title;
public:
    EditWidget(QWidget *parent, int id = 0);
    EditWidget(QWidget *parent, QString title, int id = 0);
    int getId();
    QString getTitle();
    void setTitle(QString title);
    ~EditWidget();
};
#endif // COMP_EDITWIDGET_H