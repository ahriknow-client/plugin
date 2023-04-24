#ifndef PLUGIN_MODULE_H
#define PLUGIN_MODULE_H

#include "../module/inc/activitybutton.h"
#include "../module/inc/sidewidget.h"
#include "../module/inc/editwidget.h"

#include <QObject>
#include <QJsonObject>

class IPluginModule: public QObject
{
    Q_OBJECT
public:
    explicit IPluginModule(QObject *parent = nullptr): QObject(parent) {}
    virtual ~IPluginModule() {}
    virtual QString id() = 0;
    virtual QString name() = 0;
    virtual QString version() = 0;
    virtual ActivityButton *createActivityButton(QWidget *parent, int id) = 0;
    virtual SideWidget *addSideWidget(QWidget *parent, int id) = 0;
    virtual bool removeWidgetFromEdit(int id) = 0;
    virtual bool channelReceive(QString fromId, QJsonObject data) = 0;
signals:
    void addWidgetToEdit(EditWidget *widget);
    void channelSend(QString toId, QJsonObject data);
};

#define IPluginModule_iid "com.ahriknow.plugin-module"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IPluginModule, IPluginModule_iid)
QT_END_NAMESPACE
#endif // PLUGIN_MODULE_H
