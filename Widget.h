#ifndef Widget_H
#define Widget_H


/*---- VTK Includes ----*/
#include <QVTKWidget.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>

//-------------------------------------------------------------------------------------------------------------------
/*!	\class	Widget
*	\brief	Widget
*
*	\note	Copy constructor and assignment operator are purposely not implemented.
*	
*	\file	Widget.h
*///-----------------------------------------------------------------------------------------------------------------
class Widget : public QVTKWidget
{
	public:
		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Constructor	
		*///-----------------------------------------------------------------------------------------------------------------
		Widget(QWidget * p_parent = NULL);

		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Destructor	
		*///-----------------------------------------------------------------------------------------------------------------
		~Widget();
		
	private:
		vtkSmartPointer<vtkRenderer> m_renderer;

		Widget( const Widget & );					//! Purposely not implemented
		Widget & operator=(const Widget & );		//! Purposely not implemented
		
};

#endif // Widget_H
