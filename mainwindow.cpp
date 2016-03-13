
#include "mainwindow_p.h"



//--------------------------------------------------------------------------------------------------
//	FUNCTION: MainWindow
//--------------------------------------------------------------------------------------------------
MainWindow::MainWindow() : QMainWindow(), d_ptr(new MainWindowPrivate(this))
{
	Q_D(MainWindow);

	this->setStatusBar(d->statusBar);

	this->setCentralWidget(d->testCaseTreeView);
	this->setWindowIcon(QIcon(":images/logo"));

	this->addDockWidget(Qt::LeftDockWidgetArea, d->executableDock);
	this->addDockWidget(Qt::BottomDockWidgetArea, d->consoleDock);
	this->addDockWidget(Qt::BottomDockWidgetArea, d->failureDock);

	this->setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);

	// restore settings
	d->loadSettings();
}

//--------------------------------------------------------------------------------------------------
//	FUNCTION: ~MainWindow
//--------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{

}

//--------------------------------------------------------------------------------------------------
//	FUNCTION: closeEvent
//--------------------------------------------------------------------------------------------------
void MainWindow::closeEvent(QCloseEvent* event)
{
	Q_D(MainWindow);
	d->saveSettings();
	QMainWindow::closeEvent(event);
}

//--------------------------------------------------------------------------------------------------
//	FUNCTION: changeEvent
//--------------------------------------------------------------------------------------------------
void MainWindow::changeEvent(QEvent *e)
{
	QMainWindow::changeEvent(e);
}

