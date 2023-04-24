#ifndef PLUGIN_THEME_H
#define PLUGIN_THEME_H

#include <QObject>

class IPluginTheme: public QObject
{
    Q_OBJECT
public:
    explicit IPluginTheme(QObject *parent = nullptr): QObject(parent) {}
    virtual ~IPluginTheme() {}
    virtual QString id() = 0;
    virtual QString name() = 0;
    virtual QString version() = 0;
    virtual QJsonObject theme() = 0;
};

#define IPluginTheme_iid "com.ahriknow.plugin-theme"

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(IPluginTheme, IPluginTheme_iid)
QT_END_NAMESPACE
#endif // PLUGIN_THEME_H
