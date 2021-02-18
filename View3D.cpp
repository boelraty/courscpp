//-------------------------------------------------------------------------------------------------------------------
/*!	\brief 	Implementation of class View3D
*	\file	View3D.cpp
*///-----------------------------------------------------------------------------------------------------------------

#include "View3D.h"

/*---- Internal Includes ----*/
#include "ApplicationData.h"

/*---- VTK Includes ----*/
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>

#include <QDebug>

//-----------------------------------------------------------------------------------------------------------------
View3D::View3D(QWidget * p_parent)
: QVTKWidget(p_parent), m_renderer(vtkSmartPointer<vtkRenderer>::New())
//-----------------------------------------------------------------------------------------------------------------
{
}

//-----------------------------------------------------------------------------------------------------------------
View3D::~View3D()
//-----------------------------------------------------------------------------------------------------------------
{
	//Not necessary to delete children View3D, Qt will do it automatically
}

//-----------------------------------------------------------------------------------------------------------------
void View3D::initData()
//-----------------------------------------------------------------------------------------------------------------
{
	//Add renderer
    this->GetRenderWindow()->AddRenderer(m_renderer);

	//Set background color
	m_renderer->SetBackground(1, 1, 1);

	//Render
	m_renderer->Render();
	update();

	//Create mapper for scapula
	//Use ScalarVisibilityOff() on mapper

	//Create actor for scapula


	//Create mapper for humerus
	//Use ScalarVisibilityOff() on mapper

	//Create actor for humerus


	//Add actors
}
