//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple2
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


	//Set a new text to the button
	button.setText("New text for button");

	//Set new width and height
	button.setFixedWidth(400);
	button.setFixedHeight(200);

	//Set a tool tip text
	button.setToolTip("This is a button");

	//Set a new font to the text
	button.setFont(QFont("Courier", 20, QFont::Bold));

	// ...

	//Show the button
	button.show();

	//Start application / start the events loop
	//The GUI is not displayed if the exec() method is not called
	app.exec();

	return 0;
}
