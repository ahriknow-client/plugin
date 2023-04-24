#ifndef PLUGIN_FUNCTION_H
#define PLUGIN_FUNCTION_H

#include <QObject>

class IPluginFunction: public QObject
{
    Q_OBJECT
public:
    explicit IPluginFunction(QObject *parent = nullptr): QObject(parent) {}
    virtual ~IPluginFunction() {}
    virtual QString init() = 0;
    virtual QJsonObject theme() = 0;
    virtual QWidget *btnActivity() = 0;
};

#define IPluginFunction_iid "com.ahriknow.plugin-func"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IPluginFunction, IPluginFunction_iid)
QT_END_NAMESPACE
#endif // PLUGIN_FUNCTION_H
