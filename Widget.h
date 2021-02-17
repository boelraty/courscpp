#pragma once

/*---- QT Includes ----*/
#include <QWidget>
#include <QPushButton>
#include <QSlider>


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
		/*!	\brief	DestructoR
		*///-----------------------------------------------------------------------------------------------------------------
		~Widget();

	private slots :


	//Signals could be declared here
	//signals :

	private:
		QPushButton* m_button;
		QSlider* m_slider;

		Widget( const Widget & );					//! Purposely not implemented
		Widget & operator=(const Widget & );		//! Purposely not implemented
		
};

