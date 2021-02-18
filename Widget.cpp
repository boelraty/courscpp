//-------------------------------------------------------------------------------------------------------------------
/*!	\brief 	Implementation of class Widget
*	\file	Widget.cpp
*///-----------------------------------------------------------------------------------------------------------------

#include "Widget.h"

/*---- Internal Includes ----*/
#include "ApplicationData.h"
#include "View2D.h"
#include "View3D.h"

/*---- QT Includes ----*/
#include <QFileDialog>
#include <QHBoxLayout>

//-----------------------------------------------------------------------------------------------------------------
Widget::Widget(QWidget * p_parent) : QWidget(p_parent)
//-----------------------------------------------------------------------------------------------------------------
{
	m_ui.setupUi(this);
	
	//Hide view

	//Connect signals and slots for Load button
}

//-----------------------------------------------------------------------------------------------------------------
Widget::~Widget()
//-----------------------------------------------------------------------------------------------------------------
{
}


//-----------------------------------------------------------------------------------------------------------------
void Widget::slotSelectDir()
//-----------------------------------------------------------------------------------------------------------------
{
	const QString dirPath = QFileDialog::getExistingDirectory(this, "Select a directory", "");


	if(dirPath != "")
	{
		//Load directory
		ApplicationData::getInstance()->loadDirectory(dirPath);

		//Connect signals and slots for Segment button

		//m_ui.view2D->initData();

		//Show view2D and view3D
		//m_ui.view2D->show();
		//m_ui.view3D->show();
	}
}

//-----------------------------------------------------------------------------------------------------------------
void Widget::slotSegmentData()
//-----------------------------------------------------------------------------------------------------------------
{
	//Disconnect segment button

	//Segment data

	//Init view3D
}
