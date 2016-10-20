#include "configurationmanager.h"

#include <QDateTime>
#include <QDir>
#include <QHash>


//static fields
CConfigurationManager* CConfigurationManager::m_instance = nullptr;
QString CConfigurationManager::m_path;

CConfigurationManager::CConfigurationManager(){}
 
bool CConfigurationManager::add(CConfiguration const& config)
{
    if(!m_configHash.contains(config.getName()) && CConfigurationManager::save(config))
    {
        QDateTime lastModification = QFileInfo(m_path + "/" + config.getName() + ".json").lastModified();
        m_configHash.insert(config.getName(),QPair<QDateTime,CConfiguration>(lastModification,CConfiguration(config)));
	// Save fikle here?
        return true;
    }
    return false;
}

bool CConfigurationManager::update(CConfiguration const& oldConfig,CConfiguration const& newConfig)
{
    //????
    //user can call remove and add
    remove(oldConfig.getName());
    return add(newConfig);
}

bool CConfigurationManager::remove(QString const& name)
{
    m_configHash.remove(name);
    QFile configFile(m_path+"/"+name+".json");
    if(configFile.exists())
        return configFile.remove();
     return false;
}

CConfiguration CConfigurationManager::getConfig(QString const& name)
{
    QDateTime lastModification = QFileInfo(m_path + "/" + name + ".json").lastModified();
    if(!m_configHash.contains(name) || !(lastModification == m_configHash.value(name).first))
    {
        CConfiguration config = load(name);
        lastModification = QFileInfo(m_path + "/" + config.getName()).lastModified();
        m_configHash.insert(config.getName(),QPair<QDateTime,CConfiguration>(lastModification,config));
    }
    return CConfiguration((m_configHash.value(name)).second);
}

QStringList CConfigurationManager::getNames()const
{
    return QDir(m_path).entryList(QStringList() << "*.json");
}

void CConfigurationManager::init(QString const& path)
{
    if(m_path == path)
        return;
    m_path = path;
    if(m_instance)
        m_instance->m_configHash.clear();
}


CConfigurationManager* CConfigurationManager::getInstance()
{
    if (!m_instance)
        m_instance = new CConfigurationManager();
    return m_instance;
}


bool CConfigurationManager::save(CConfiguration const& configuration)
{
    if(!QDir(m_path).exists())
        if(!QDir().mkdir(m_path))
           return false;
    // Pass only path?
    configuration.save(m_path+"/"+configuration.getName()+".json");
    return true;
}

CConfiguration CConfigurationManager::load(QString const& filePath)
{
    if(!QFile(filePath).exists()) // full path ?
        return CConfiguration();
    return CConfiguration::loadConfigFromFile(filePath);
}

