


#include "chatdialogs.h"
#include <QtGui\QAction>
#include <QtGui\QFormLayout>
#include <QtGui\QVBoxLayout>
#include <QtGui\QHBoxLayout>
#include <QtGui\QRegExpValidator>
#include <QtCore\QRegExp>
#include <Qt\qapplication.h>
#include <QtNetwork\QHostInfo>



CTurnOnServerWidget::CTurnOnServerWidget(QWidget *parent)
    : QDialog(parent)
{
    setupUi();
}


CTurnOnServerWidget::~CTurnOnServerWidget()
{

}


void CTurnOnServerWidget::setupUi()
{
    setWindowTitle(tr("Server settings"));

    // Name imput
    m_pServerName = new QLineEdit(this);
    QRegExpValidator* pValidator = new QRegExpValidator(this);
    pValidator->setRegExp(QRegExp("[A-Za-z0-9_]*"));
    m_pServerName->setValidator(pValidator);
	m_pServerName->setText(LOCAL_HOST_NAME);
    QObject::connect(m_pServerName, SIGNAL(textChanged(const QString&)), this, SLOT(onError()));

	// Server port imput
	m_pServerPort = new QLineEdit(this);
	QIntValidator* pIntValidator = new QIntValidator(0, 65535, this);
	m_pServerPort->setValidator(pIntValidator);
	m_pServerPort->setText(QString::number(DEFAULT_PORT_FOR_MESSAGE));
	QObject::connect(m_pServerPort, SIGNAL(textChanged(const QString&)), this, SLOT(onError()));

    // Error messeg
    m_pError = new QLabel(this);
	QFont oFont;
	oFont.setPixelSize(11);
	QPalette oPalatte;
	oPalatte.setColor(QPalette::WindowText, Qt::red);
	m_pError->setFont(oFont);
	m_pError->setPalette(oPalatte);

    // Buttons
    m_pBtnAccept = new QPushButton(tr("Accept"), this);
    QObject::connect(m_pBtnAccept, SIGNAL(clicked(bool)), this, SLOT(accept()));
    m_pBtnCencel = new QPushButton(tr("Cencel"), this);
    QObject::connect(m_pBtnCencel, SIGNAL(clicked(bool)), this, SLOT(reject()));

    // Horizontal Line
    QFrame* pHLine = new QFrame(this);
    pHLine->setFrameStyle(QFrame::HLine | QFrame::Sunken);

    // Middle layout
    QFormLayout* pMiddleLayout = new QFormLayout;
    pMiddleLayout->setSpacing(5);
    pMiddleLayout->setFormAlignment(Qt::AlignLeft);
    pMiddleLayout->addRow(tr("Server name:"), m_pServerName);
	pMiddleLayout->addRow(tr("Server port:"), m_pServerPort);
    pMiddleLayout->addRow(QString(), m_pError);

    // Buttom layout
    QHBoxLayout* pButtomLayout = new QHBoxLayout;
    pButtomLayout->addStretch(1);
    pButtomLayout->addWidget(m_pBtnAccept);
    pButtomLayout->addWidget(m_pBtnCencel);

    // Main layout
    QVBoxLayout* pMainLayout = new QVBoxLayout;
    pMainLayout->setContentsMargins(10, 20, 10, 10);
    pMainLayout->addLayout(pMiddleLayout);
    pMainLayout->addWidget(pHLine);
    pMainLayout->addLayout(pButtomLayout);
    setLayout(pMainLayout);
    setFixedSize(sizeHint().width() + 70, sizeHint().height());
}


void CTurnOnServerWidget::setServerName(QString const& sName)
{
	m_pServerName->setText(sName);
}


QString CTurnOnServerWidget::getServerName() const
{
	return m_pServerName->text();
}


void CTurnOnServerWidget::setServerPort(quint16 nPort)
{
	m_pServerPort->setText(QString::number(nPort));
}


void CTurnOnServerWidget::setPortEditable(bool bVal)
{
	m_pServerPort->setEnabled(bVal);
}


quint16 CTurnOnServerWidget::getServerPort() const
{
	return m_pServerPort->text().toInt();
}


void CTurnOnServerWidget::onError()
{
	m_pError->clear();
	m_pBtnAccept->setEnabled(true);

    if (m_pServerName->text().size() < 4)
    {
        if (m_pServerName->text().isEmpty())
            m_pError->setText(tr("Error: The server name is empty!"));
        else
            m_pError->setText(tr("Error: The server name is short!"));
        m_pBtnAccept->setEnabled(false);
    }
	
	if (m_pServerPort->text().isEmpty())
	{
		m_pError->setText(tr("Error: The server port is empty!"));
		m_pBtnAccept->setEnabled(false);
	}
}








CConnectToServerWidget::CConnectToServerWidget(QWidget* parent)
	: QDialog(parent)
{
    setupUi();
}


CConnectToServerWidget::~CConnectToServerWidget()
{

}


void CConnectToServerWidget::setupUi()
{
    setWindowTitle(tr("Connect to server"));

    // Host address label
    m_pRbtnHostName = new QRadioButton(tr("Host Name:"), this);
    m_pRbtnHostName->setChecked(true);
    QObject::connect(m_pRbtnHostName, SIGNAL(toggled(bool)), this, SLOT(onChecked()));
	QObject::connect(m_pRbtnHostName, SIGNAL(toggled(bool)), this, SLOT(onError()));
    m_pRbtnIpAddress = new QRadioButton(tr("IP address:"), this);
    QObject::connect(m_pRbtnIpAddress, SIGNAL(toggled(bool)), this, SLOT(onChecked()));
	QObject::connect(m_pRbtnIpAddress, SIGNAL(toggled(bool)), this, SLOT(onError()));

    // Imputs
    m_pHostName = new QLineEdit(this);
    QObject::connect(m_pHostName, SIGNAL(textChanged(QString const&)), this, SLOT(onError()));

    m_pIpAddress = new QLineEdit(this);
    QRegExpValidator* pValidator = new QRegExpValidator(this);
    pValidator->setRegExp(QRegExp("(\\d{1,3}\\.){3}\\d{1,3}"));
    m_pIpAddress->setValidator(pValidator);
    m_pIpAddress->setEnabled(false);
    QObject::connect(m_pIpAddress, SIGNAL(textChanged(QString const&)), this, SLOT(onError()));
	
	m_pServerPort = new QLineEdit(this);
	QIntValidator* pIntValidator = new QIntValidator(0, 65535, this);
	m_pServerPort->setValidator(pIntValidator);
	m_pServerPort->setText(QString::number(DEFAULT_PORT_FOR_MESSAGE));
	QObject::connect(m_pServerPort, SIGNAL(textChanged(QString const&)), this, SLOT(onError()));

    // Error label
    m_pError = new QLabel(this);
	QFont oFont;
    oFont.setPixelSize(11);
    QPalette oPalatte;
    oPalatte.setColor(QPalette::WindowText, Qt::red);
    m_pError->setFont(oFont);
    m_pError->setPalette(oPalatte);

    // Horizontal line
    QFrame* pHLine = new QFrame;
    pHLine->setFrameStyle(QFrame::HLine | QFrame::Sunken);

    // Buttons
    m_pbBtnConnect = new QPushButton(tr("Connect"), this);
    m_pbBtnConnect->setEnabled(false);
    QObject::connect(m_pbBtnConnect, SIGNAL(clicked(bool)), this, SLOT(accept()));
    m_pbBtnCencel = new QPushButton(tr("Cencel"), this);
    QObject::connect(m_pbBtnCencel, SIGNAL(clicked(bool)), this, SLOT(reject()));

    // Middle layout
    QFormLayout* pMiddleLayout = new QFormLayout;
    pMiddleLayout->setSpacing(10);
    pMiddleLayout->setMargin(5);
    pMiddleLayout->addRow(m_pRbtnHostName, m_pHostName);
    pMiddleLayout->addRow(m_pRbtnIpAddress, m_pIpAddress);
	pMiddleLayout->addRow("Server port:", m_pServerPort);

    // Buttom layout
    QHBoxLayout* pButtomLayout = new QHBoxLayout;
    pButtomLayout->addStretch(1);
    pButtomLayout->addWidget(m_pbBtnConnect);
    pButtomLayout->addWidget(m_pbBtnCencel);

    // Main layout
    QVBoxLayout* pMainLayout = new QVBoxLayout;
    pMainLayout->setContentsMargins(10, 20, 10, 10);
    pMainLayout->addLayout(pMiddleLayout);
    pMainLayout->addWidget(m_pError, 1, Qt::AlignCenter);
    pMainLayout->addStretch(1);
    pMainLayout->addWidget(pHLine);
    pMainLayout->addLayout(pButtomLayout);

    setLayout(pMainLayout);
    setFixedSize(sizeHint().width() + 50, sizeHint().height());
}


void CConnectToServerWidget::onChecked()
{
    m_pHostName->setEnabled(m_pRbtnHostName->isChecked());
    m_pIpAddress->setEnabled(!m_pRbtnHostName->isChecked());
}


void CConnectToServerWidget::onError()
{
    m_pError->clear();
    m_pbBtnConnect->setEnabled(true);
   
    if (m_pRbtnHostName->isChecked())
    {
		if (m_pHostName->text().isEmpty())
		{
			m_pError->setText("Error: The host name is empty!");
			m_pbBtnConnect->setEnabled(false);
		}
        else if (m_pHostName->text().size() < 4)
		{
			m_pError->setText("Error: The host name is short!");
			m_pbBtnConnect->setEnabled(false);

		}
    }
    else
    {
		if (!QRegExp("(\\d{1,3}\\.){3}\\d{1,3}").exactMatch(m_pIpAddress->text()))
		{
			m_pError->setText("Error: Invalid Ip address!");
			m_pbBtnConnect->setEnabled(false);
		}
    }

    if (m_pServerPort->text().isEmpty())
    {
		m_pError->setText("Error: The server port is empty!");
        m_pbBtnConnect->setEnabled(false);
    }
}


QString CConnectToServerWidget::getServerHost() const
{
	if (m_pRbtnHostName->isChecked())
		return m_pHostName->text();
    return m_pIpAddress->text();
}


quint16 CConnectToServerWidget::getServerPort() const
{
	return m_pServerPort->text().toInt();
}





CLookUpWidget::CLookUpWidget(QWidget* parent)
	: QWidget(parent)
{
	// label
	m_pLabel = new QLabel(tr("Host name/address:"), this);

	// imput host name
	m_pHostName = new QLineEdit(this);
	QObject::connect(m_pHostName, SIGNAL(returnPressed()), this, SLOT(onSearch()));
	m_pLabel->setBuddy(m_pLabel);

	// button
	m_pBtnSearch = new QToolButton(this);
	m_pBtnSearch->setIcon(QIcon("resources/search.ico"));
	QObject::connect(m_pBtnSearch, SIGNAL(clicked(bool)), this, SLOT(onSearch()));

	// results
	m_pResult = new QPlainTextEdit(this);
	m_pResult->setReadOnly(true);

	// top layout
	QHBoxLayout* pTopLayout = new QHBoxLayout;
	pTopLayout->addWidget(m_pLabel);
	pTopLayout->addWidget(m_pHostName);
	pTopLayout->addWidget(m_pBtnSearch);


	// Main layout
	QVBoxLayout* pMainLayout = new QVBoxLayout;
	pMainLayout->addLayout(pTopLayout);
	pMainLayout->addWidget(m_pResult);

	setLayout(pMainLayout);
	setWindowTitle(tr("Look Up"));
	resize(sizeHint().width() + 100, sizeHint().height());

	QObject::connect(this, SIGNAL(destroyed()), this, SLOT(deleteLater()));
}


void CLookUpWidget::onSearch()
{
	QString sHostName = m_pHostName->text().trimmed();
	m_pHostName->setText(sHostName);
	QApplication::setOverrideCursor(Qt::WaitCursor);
	QHostInfo oInfo = QHostInfo::fromName(sHostName);
	QApplication::restoreOverrideCursor();
	QList<QHostAddress> aAddresses = oInfo.addresses();
	m_pResult->clear();
	if (aAddresses.isEmpty())
	{
		m_pResult->setPlainText("Not founded");
		return;
	}

	bool bVal = true;
	for (int i = 0; i < aAddresses.size(); ++i)
	{
		QString sAddress = aAddresses[i].toString();
		if (oInfo.hostName() == sHostName)
		{
			bVal = false;
			break;
		}
	}
	if (bVal && aAddresses.size() == 1)
		m_pResult->appendPlainText(QString("Host Name: %1").arg(oInfo.hostName()));
	else
	{

		for (int i = 0; i < aAddresses.size(); ++i)
		{
			QString sAddress = aAddresses[i].toString();
			if (aAddresses[i].protocol() == QAbstractSocket::NetworkLayerProtocol::IPv4Protocol)
				m_pResult->appendPlainText(QString("IPv4: %1").arg(sAddress));
			else if (aAddresses[i].protocol() == QAbstractSocket::NetworkLayerProtocol::IPv6Protocol)
				m_pResult->appendPlainText(QString("IPv6: %1").arg(sAddress));
			else
				m_pResult->appendPlainText(sAddress);
		}
	}
}




class CServerItem : public QStandardItem
{
public:
	SServerInfo getInfo() const
	{
		return m_Info;
	}

	void setInfo(SServerInfo const& info)
	{
		m_Info = info;
	}

private:
	SServerInfo m_Info;
};



CServerListWidget::CServerListWidget(QWidget* parent)
	: QListView(parent),
	  m_pModel(nullptr)
{
	m_pModel = new QStandardItemModel(this);
	setModel(m_pModel);

	setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
	QObject::connect(this, SIGNAL(customContextMenuRequested(QPoint const&)), this, SLOT(onContextMenu(QPoint const&)));

	setSelectionMode(QAbstractItemView::SelectionMode::ContiguousSelection);
}


void CServerListWidget::addItem(SServerInfo const& oInfo)
{
	CServerItem* pItem = new CServerItem;
	pItem->setCheckable(true);
	pItem->setCheckState(Qt::CheckState::Checked);
	pItem->setText(oInfo.sServerName);
	pItem->setInfo(oInfo);
	m_pModel->appendRow(pItem);
}


QList<SServerInfo> CServerListWidget::getServersInfo() const
{
	QList<SServerInfo> aInfo;
	for (int i = 0; i < m_pModel->rowCount(); ++i)
	{
		CServerItem* pItem = dynamic_cast<CServerItem*>(m_pModel->item(i));
		Q_ASSERT(pItem);
		aInfo.append(pItem->getInfo());
	}
	return aInfo;
}


QStringList CServerListWidget::getActiveServersName() const
{
	QStringList aServers;
	for (int i = 0; i < m_pModel->rowCount(); ++i)
	{
		CServerItem* pItem = dynamic_cast<CServerItem*>(m_pModel->item(i));
		Q_ASSERT(pItem);
		if (pItem->checkState() == Qt::CheckState::Checked)
			aServers.append(pItem->getInfo().sServerName);
	}
	return aServers;
}


void CServerListWidget::clear()
{
	m_pModel->clear();
}


void CServerListWidget::onContextMenu(QPoint const& pos)
{
	QModelIndex index = indexAt(pos);
	if (index.isValid())
	{
		m_pActConnecto = new QAction(tr("Connect"), this);
		m_pActConnecto->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key::Key_C));
		m_pActConnecto->setIcon(QIcon(":/mos/resources/connecttoserver.ico"));
		QObject::connect(m_pActConnecto, SIGNAL(triggered(bool)), this, SLOT(onConnectTo()));

		m_pActDisconnect = new QAction(tr("Disconnect"), this);
		m_pActDisconnect->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key::Key_D));
		//m_pActDisconnect->setIcon(QIcon(":/mos/resources/.ico"));								//TODO
		QObject::connect(m_pActDisconnect, SIGNAL(triggered(bool)), this, SLOT(onDisconnectFrom()));

		m_pActDelete = new QAction(tr("Delete"), this);
		m_pActDelete->setShortcut(QKeySequence(Qt::Key_Delete));
		//m_pActDelete->setIcon(QIcon(":/mos/resources/.ico"));									//TODO
		QObject::connect(m_pActDelete, SIGNAL(triggered(bool)), this, SLOT(onDelete()));

		m_pActAbout = new QAction(tr("About client"), this);
		m_pActAbout->setShortcut(QKeySequence(Qt::Key_F3));
		m_pActAbout->setIcon(QIcon(":/mos/resources/about.ico"));
		QObject::connect(m_pActAbout, SIGNAL(triggered(bool)), this, SLOT(onAbout()));

		QMenu contextMenu;
		contextMenu.addAction(m_pActConnecto);
		contextMenu.addAction(m_pActDisconnect);
		contextMenu.addAction(m_pActDelete);
		contextMenu.addAction(m_pActAbout);
		contextMenu.exec(mapToGlobal(pos));
	}

}


void CServerListWidget::onConnectTo()
{
	QModelIndexList aSelection = selectedIndexes();
	for (int i = 0; i < aSelection.size(); ++i)
	{
		CServerItem* pItem = dynamic_cast<CServerItem*>(m_pModel->item(aSelection[i].row()));
		Q_ASSERT(pItem);
		pItem->setCheckState(Qt::CheckState::Checked);
		emit sigConnectTo(pItem->getInfo());
	}
}


void CServerListWidget::onDisconnectFrom()
{
	QModelIndexList aSelection = selectedIndexes();
	for (int i = 0; i < aSelection.size(); ++i)
	{
		CServerItem* pItem = dynamic_cast<CServerItem*>(m_pModel->item(aSelection[i].row()));
		Q_ASSERT(pItem);
		pItem->setCheckState(Qt::CheckState::Unchecked);
		emit sigDisconnectFrom(pItem->getInfo());
	}
}


void CServerListWidget::onDelete()
{
	onDisconnectFrom();
	QModelIndexList aSelection = selectedIndexes();
	for (int i = 0; i < aSelection.size(); ++i)
		m_pModel->removeRow(aSelection[i].row());
}


void CServerListWidget::onAbout()
{
	QModelIndex index = currentIndex();
	if (index.isValid())
	{
		// TO do
	}
}