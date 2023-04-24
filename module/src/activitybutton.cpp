#include "activitybutton.h"

#include <QLabel>
#include <QGridLayout>
#include <QVariant>
#include <QDebug>

ActivityButton::ActivityButton(QWidget *parent, const QString &def, const QString &act, int id)
    : QWidget(parent)
{
    this->id = id;
    this->active = false;
    QGridLayout *layout = new QGridLayout();
    this->setLayout(layout);

    this->label = new QLabel(this);
    this->label->setProperty("class", QVariant("button"));

    QPixmap defOrigin(def);
    QPixmap actOrigin(act);
    this->def = defOrigin.scaled(this->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->act = actOrigin.scaled(this->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    this->setDefault();
    this->setFixedSize(50, 50);
    layout->addWidget(this->label);
}

int ActivityButton::getId()
{
    return this->id;
}

void ActivityButton::setActive()
{
    this->active = true;
    this->label->setPixmap(this->act);
}

void ActivityButton::setDefault()
{
    this->active = false;
    this->label->setPixmap(this->def);
}

void ActivityButton::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->setCursor(Qt::PointingHandCursor);
    this->label->setPixmap(this->act);
}

void ActivityButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->setCursor(Qt::ArrowCursor);
    if (!this->active)
        this->label->setPixmap(this->def);
}

void ActivityButton::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    if (this->active)
    {
        emit this->clicked(-1);
    }
    else
    {
        emit this->clicked(this->id);
    }
}

ActivityButton::~ActivityButton()
{
}
