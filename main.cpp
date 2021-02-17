//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple4
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- Internal Includes ----*/
#include "Widget.h"

/*---- QT Includes ----*/
#include <QDebug>
#include <QApplication>

int main(int p_argc, char* p_argv[])
{
	//Create the QApplication to manage the GUI
	QApplication app(p_argc, p_argv);

	//Create our own widget
	Widget mywidget;
	mywidget.show();

	//Start application / start the events loop
	//The GUI is not displayed if the exec() method is not called
	app.exec();

	return 0;
}
