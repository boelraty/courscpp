#ifndef Widget_H
#define Widget_H

/*---- QT Includes ----*/
#include <QPushButton>
#include <QSlider>
#include <QWidget>


//-------------------------------------------------------------------------------------------------------------------
/*!	\class	Widget
*	\brief	Widget
*
*	\note	Copy constructor and assignment operator are purposely not implemented.
*	
*	\file	Widget.h
*///-----------------------------------------------------------------------------------------------------------------
class Widget : public QWidget
{
	Q_OBJECT
	public:
		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Constructor	
		*///-----------------------------------------------------------------------------------------------------------------
		Widget(QWidget * p_parent = NULL);

		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Destructor	
		*///-----------------------------------------------------------------------------------------------------------------
		~Widget();

	private slots :
		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Slot to be connected with the click on the button
		*///-----------------------------------------------------------------------------------------------------------------
		void slotButtonClicked();

		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Slot to be connected with the slider
		*///-----------------------------------------------------------------------------------------------------------------
		void slotSliderMoved(int p_newValue);

	//Signals could be declared here
	//signals :

	private:
		QPushButton * m_button;
		QSlider * m_slider;

		Widget( const Widget & );					//! Purposely not implemented
		Widget & operator=(const Widget & );		//! Purposely not implemented
		
};

#endif // Widget_H
