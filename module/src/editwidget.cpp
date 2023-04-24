#include "editwidget.h"

EditWidget::EditWidget(QWidget *parent, int id) : QTabWidget(parent)
{
    this->id = id;
    this->title = "";
}

EditWidget::EditWidget(QWidget *parent, QString title, int id) : QTabWidget(parent)
{
    this->id = id;
    this->title = title;
}

int EditWidget::getId()
{
    return this->id;
}

QString EditWidget::getTitle()
{
    return this->title;
}

void EditWidget::setTitle(QString title)
{
    this->title = title;
}

EditWidget::~EditWidget()
{
}
