

#include "configuration.h"

#include <QFile>
#include <QByteArray>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>



QString const CConfiguration::sConfigDescription = QString("configDescription");
QString const CConfiguration::sConfigParameters = QString("configParameters");
QString const CConfiguration::sConfigName = QString("configName");
QString const CConfiguration::sConfigType = QString("configType");
QString const CConfiguration::sConfigVersion = QString("configVersion");


CConfiguration::CConfiguration()
    : m_sName(),
      m_sType(),
      m_nVersion(0.0),
      m_mapParam()
{

}


CConfiguration::CConfiguration(QString const& sName, QString const& sType, int nVersion)
    : m_sName(sName),
      m_sType(sType),
      m_nVersion(nVersion),
      m_mapParam()
{

}


CConfiguration::~CConfiguration()
{

}


CConfiguration CConfiguration::loadConfigFromFile(QString const & sPath)
{
	CConfiguration oConfig;
	oConfig.load(sPath);
	return oConfig;
}

QString CConfiguration::getFileFormat()
{
	return QString(".json");
}


void CConfiguration::setName(QString const& sName)
{
    m_sName = sName;
}


QString CConfiguration::getName() const
{
    return m_sName;
}


void CConfiguration::setType(QString const& sType)
{
    m_sType = sType;
}


QString CConfiguration::getType() const
{
    return m_sType;
}


void CConfiguration::setVersion(int nVersion)
{
    m_nVersion = nVersion;
}


int CConfiguration::getVersion() const
{
    return m_nVersion;
}

bool CConfiguration::isValid() const
{
	return !(m_sName.isEmpty() || m_sType.isEmpty() || m_nVersion <= 0);
}


void CConfiguration::setParameter(QString const& sKey, QVariant const& value)
{
    m_mapParam[sKey] = value;
}


QVariant CConfiguration::getParameter(QString const& sKey) const
{
    auto it = m_mapParam.find(sKey);
    if (it != m_mapParam.end())
        return it.value();
    return QString();
}


int CConfiguration::getParamCount() const
{
    return m_mapParam.count();
}


bool CConfiguration::isEmpty() const
{
    return m_mapParam.isEmpty();
}


bool CConfiguration::isContained(QString const& sKey) const
{
    if (m_mapParam.find(sKey) != m_mapParam.end())
        return true;
    return false;
}


void CConfiguration::reset()
{
    m_sName.clear();
    m_sType.clear();
    m_nVersion = 0.0;
    m_mapParam.clear();
}


void CConfiguration::clearParameters()
{
    m_mapParam.clear();
}


void CConfiguration::load(QString const& sPath)
{
	reset();
	QString fileFullPath = sPath + m_sName + getFileFormat();
	QFile configFile(fileFullPath);
    // Open file only for reading
    if (configFile.open(QFile::ReadOnly | QFile::Text))
    {
		QJsonDocument const jsonDoc = QJsonDocument::fromJson(configFile.readAll());
		configFile.close();
		
		if (!jsonDoc.isEmpty() && jsonDoc.isObject())
		{
			QJsonObject rootObject = jsonDoc.object();
			if (rootObject.value(sConfigDescription).isObject())
			{	// Read config descriptors
				QJsonObject descObject = rootObject.value(sConfigDescription).toObject();
				m_sName = descObject.value(sConfigName).toString();
				m_sType = descObject.value(sConfigType).toString();
				m_nVersion = descObject.value(sConfigVersion).toInt();

				if (rootObject.value(sConfigParameters).isObject())
				{	// Read config parameters
					QJsonObject paramObject = rootObject.value(sConfigParameters).toObject();
					m_mapParam = paramObject.toVariantHash();
				}
			}
		}

    }
}


void CConfiguration::save(QString const& sPath) const
{
	QString fileFullPath = sPath + m_sName + getFileFormat();
    QFile configFile(fileFullPath);
    // Open file only for writing
    if (configFile.open(QFile::WriteOnly | QFile::Text))
    {
		QJsonObject rootObject;
		// Write config descriptors
		QJsonObject descObject;
		descObject[sConfigName] = m_sName;
		descObject[sConfigType] = m_sType;
		descObject[sConfigVersion] = m_nVersion;
		rootObject[sConfigDescription] = descObject;
		
		// Write config parameters
		QJsonObject paramObject = QJsonObject::fromVariantHash(m_mapParam);
		rootObject[sConfigParameters] = paramObject;

		// Save data
		QJsonDocument jsonDoc(rootObject);
		QByteArray data = jsonDoc.toJson(QJsonDocument::Indented);
		configFile.write(data);
        configFile.close();
    }
}



































