#ifndef CCONFIGURATIONMANAGER_H
#define CCONFIGURATIONMANAGER_H

#include <configuration.h>
#include <QDateTime>

////////////////////////////////////////////////////////////
//
//singleton
//class CConfiguratuinManager
//

class CConfigurationManager
{
public:
    //static functions
    static void init(QString const& path = "configurations");
    static CConfigurationManager* getInstance();

public:
    //
    bool add(CConfiguration const& config);
//    bool update(CConfiguration const& config);
    bool update(CConfiguration const&  oldConfig,CConfiguration const& newConfig);
    bool remove(QString const& name);
    CConfiguration getConfig(QString const& name);
    QStringList getNames()const;

private:
    //constructor
    CConfigurationManager();

    //destructor
    ~CConfigurationManager();

private:
    //static functions
    static bool save(CConfiguration const& configuration);
    static CConfiguration load(QString const& filePath);


private:
    //static fields
    static CConfigurationManager* m_instance;
    static QString m_path;

private:
    //instance fields

    //cache
    //<configName,QPair<modificationDateTime,Config>>
    QHash<QString,QPair<QDateTime,CConfiguration>> m_configHash;
};

#endif // CCONFIGURATIONMANAGER_H
