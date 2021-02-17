//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple1
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- QT Includes ----*/
#include <QDebug>
#include <QApplication>
#include <QPushButton>


int main(int p_argc, char* p_argv[])
{
	//Create the QApplication to manage the GUI
	QApplication app(p_argc, p_argv);

	//Create a button
	QPushButton button("First button");

	//Show the button
	button.show();

	//Start application / start the events loop
	//The GUI is not displayed if the exec() method is not called
	app.exec();

	return 0;
} 
