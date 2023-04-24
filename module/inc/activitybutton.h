#ifndef COMP_BUTTON_H
#define COMP_BUTTON_H

#include <QWidget>
#include <QLabel>

class ActivityButton : public QWidget
{
    Q_OBJECT
private:
    QPixmap def;
    QPixmap act;
    QLabel *label;
    bool active;
    int id;

public:
    ActivityButton(QWidget *parent, const QString &def, const QString &act, int id = 0);
    int getId();
    void setActive();
    void setDefault();
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    ~ActivityButton();
signals:
    void clicked(int id);
};
#endif // COMP_BUTTON_H