//-------------------------------------------------------------------------------------------------------------------
/*!	\brief 	Implementation of class Widget
*	\file	Widget.cpp
*///-----------------------------------------------------------------------------------------------------------------

#include "Widget.h"

/*---- QT Includes ----*/
#include <QDebug>

//-----------------------------------------------------------------------------------------------------------------
//Initialization list => used to initialize all class members
Widget::Widget(QWidget * p_parent) : QWidget(p_parent), m_button(NULL), m_slider(NULL)
//-----------------------------------------------------------------------------------------------------------------
{
	//Create button inside current widget
	m_button = new QPushButton("Button", this);
	m_button->move(100, 100);
	m_button->show();

	//Create slider inside current widget
	m_slider = new QSlider(this);
	m_slider->setOrientation(Qt::Horizontal);
	m_slider->setRange(0, 200);
	m_slider->move(200, 100);
	m_slider->show();

	//Connect signals to slots
	connect(m_button, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
	connect(m_slider, SIGNAL(valueChanged(int)), this, SLOT(slotSliderMoved(int)));

}

//-----------------------------------------------------------------------------------------------------------------
Widget::~Widget()
//-----------------------------------------------------------------------------------------------------------------
{
	//Not necessary to delete children widget, Qt will do it automatically
}

//-----------------------------------------------------------------------------------------------------------------
void Widget::slotButtonClicked()
//-----------------------------------------------------------------------------------------------------------------
{
	qDebug() << "Button clicked";
}

//-----------------------------------------------------------------------------------------------------------------
void Widget::slotSliderMoved(int p_newValue)
//-----------------------------------------------------------------------------------------------------------------
{
	qDebug() << p_newValue;
}
