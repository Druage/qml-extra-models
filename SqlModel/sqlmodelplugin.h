#ifndef SQLMODELPLUGIN_H
#define SQLMODELPLUGIN_H

#include <QQuickItem>

class SqlModelPlugin : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(SqlModelPlugin)

public:
    SqlModelPlugin(QQuickItem *parent = 0);
    ~SqlModelPlugin();
};

#endif // SQLMODELPLUGIN_H
