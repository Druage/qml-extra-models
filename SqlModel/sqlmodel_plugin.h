#ifndef SQLMODEL_PLUGIN_H
#define SQLMODEL_PLUGIN_H

#include <QQmlExtensionPlugin>

class SqlModelPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void registerTypes( const char *uri ) override;
};

#endif // SQLMODEL_PLUGIN_H
