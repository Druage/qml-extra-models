#include "database.h"

#include <QSqlDatabase>
#include <QDebugStateSaver>

Database::Database(QObject *parent)
    : QObject( parent ),
      mDriverType( QStringLiteral( "QSQLITE" ) ),
      mPort( INT_MIN ),
      mNumericalPrecisionPolicy( NumericalPrecisionPolicy::Default )
{

}

QString Database::password() const
{
    return mPassword;
}

QString Database::userName() const
{
    return mUserName;
}

QString Database::connectionOptions() const
{
    return mConnectionOptions;
}

QString Database::databaseName() const
{
    return mDatabaseName;
}

QString Database::driverType() const
{
    return mDriverType;
}

QString Database::hostName() const
{
    return mHostName;
}

QString Database::connectionName() const
{
    return mConnectionName;
}

int Database::port() const
{
    return mPort;
}

Database::NumericalPrecisionPolicy Database::numericalPrecisionPolicy() const
{
    return mNumericalPrecisionPolicy;
}

void Database::setPassword(const QString password) {
    mPassword = password;
}

void Database::setUserName(const QString userName) {
    mUserName = userName;
}

void Database::setConnectionOptions(const QString options) {
    mConnectionOptions = options;
}

void Database::setDatabaseName(const QString name) {
    mDatabaseName = name;
}

void Database::setDriverType(const QString type) {
    mDriverType = type;
}

void Database::setHostName(const QString name) {
    mHostName = name;
}

void Database::setConnectionName(const QString name) {
    mConnectionName = name;
}

void Database::setPort(const int port) {
    mPort = port;
}

void Database::setNumericalPrecisionPolicy(const Database::NumericalPrecisionPolicy policy) {
    mNumericalPrecisionPolicy = policy;
}

bool Database::isDriverAvailable(const QString name) {
    return QSqlDatabase::isDriverAvailable( name );
}

QDebug operator <<(QDebug d, const Database &db) {
    QDebugStateSaver saver( d );
    Q_UNUSED( saver );
    d << "Database(";
    d << "\n  userName: " << db.userName()
      << "\n  password: " << db.password()
      << "\n  databaseName: " << db.databaseName()
      << "\n  driverType: " << db.driverType()
      << "\n  hostName:" << db.hostName()
      << "\n  port:" << ( db.port() == INT_MIN ? QStringLiteral( "undefined" ) : QString::number( static_cast<int>( db.port() ) ) )
      << "\n  numericalPrecisionPolicy:" << static_cast<int>( db.numericalPrecisionPolicy() )
      << "\n  connectionOptions: " << db.connectionOptions()
      << "\n  policy: " << static_cast<int>( db.numericalPrecisionPolicy() )
      << "\n)";
    return d;
}
