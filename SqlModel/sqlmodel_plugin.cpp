#include "sqlmodel_plugin.h"

#include "sqlmodel.h"
#include "sqlcolumn.h"
#include "sqlthreadedmodel.h"

#include <qqml.h>

void SqlModelPlugin::registerTypes( const char *uri )
{
    qmlRegisterType<SqlModel>( uri, 1, 0, "SqlModel" );
    qmlRegisterType<SqlColumn>( uri, 1, 0, "SqlColumn" );
    qmlRegisterType<SqlThreadedModel>( uri, 1, 0, "SqlThreadedModel" );
    qmlRegisterType<Database>();

    qRegisterMetaType<SqlModel::FilterType>( "SqlModel::FilterType" );

}

