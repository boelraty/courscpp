//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple3
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- QT Includes ----*/
#include <QDebug>
#include <QApplication>
#include <QPushButton>
#include <QWidget>


int main(int p_argc, char* p_argv[])
{
	//Create the QApplication to manage the GUI
	QApplication app(p_argc, p_argv);

	//Create main widget
	QWidget mainWidget;
	mainWidget.setFixedSize(500, 500);

	//Create a button and give the containing widget as a pointer
	QPushButton button("First button", &mainWidget);

	//Set new width and height
	button.setFixedSize(100, 50);

	// Move the button inside the main widget
	button.move(200, 200);

	//Show the main widget
	mainWidget.show();

	//Start application / start the events loop
	//The GUI is not displayed if the exec() method is not called
	app.exec();

	return 0;
}
