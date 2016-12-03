#ifndef CONFIGURATION_H
#define CONFIGURATION_H



// Forward declaration
#include <QString>
#include <QVariant>


//////////////////////////////////////////////////////////////////////////
//
// Class CConfiguration
//
class CConfiguration
{
public:
	//
	// Static functions
	//
	// Load configuration from file
	static CConfiguration loadConfigFromFile(QString const& sPath);
	// Get file format
	static QString getFileFormat();

public:
    // Default constructor
    CConfiguration();
    // Init Constructor
    CConfiguration(QString const& sName, QString const& sType, int nVersion);
    // Destructor
    ~CConfiguration();

    //
    // Interface
    //
    // Get/Set config descriptors
    void setName(QString const& sName);
    QString getName() const;
    void setType(QString const& sType);
    QString getType() const;
    void setVersion(int nVersion);
    int getVersion() const;
	bool isValid() const;

    // Get/Set config parameters
    void setParameter(QString const& sKey, const QVariant& value);
	QVariant getParameter(QString const& sKey) const;

    int getParamCount() const;
    bool isEmpty() const;
    bool isContained(QString const& sKey) const;
    // Clear all parameters
    void clearParameters();
    // Clear config
    void reset();

    // Load configuration from xml file
    void load(QString const& sPath);
    // Save configuration into xml file
    void save(QString const& sPath) const;

private:
	// Static const keys for config description
	static QString const sConfigDescription;
	static QString const sConfigParameters;
	static QString const sConfigName;
	static QString const sConfigType;
	static QString const sConfigVersion;

private:
    //
    // content
    //

    // Config description
    QString							m_sName;
    QString							m_sType;
    int								m_nVersion;

    // Config parameters
	QVariantHash					m_mapParam;
};
//////////////////////////////////////////////////////////////////////////


#endif // CONFIGURATION_H












