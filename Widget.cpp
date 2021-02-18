//-------------------------------------------------------------------------------------------------------------------
/*!	\brief 	Implementation of class Widget
*	\file	Widget.cpp
*///-----------------------------------------------------------------------------------------------------------------

#include "Widget.h"

/*---- VTK Includes ----*/
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>

//-----------------------------------------------------------------------------------------------------------------
Widget::Widget(QWidget * p_parent) : QVTKWidget(p_parent), m_renderer(vtkSmartPointer<vtkRenderer>::New())
//-----------------------------------------------------------------------------------------------------------------
{
	//Create data : a sphere
	vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
	sphere->SetCenter(0, 0, 0);
	sphere->SetRadius(100);
	sphere->Update();

	//Create mapper
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(sphere->GetOutput());

	//Create actor
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	//Add renderer
	this->GetRenderWindow()->AddRenderer(m_renderer);

	//Add actor to renderer
	m_renderer->AddActor(actor);

	//Render
	//m_renderer->Render();
	
}

//-----------------------------------------------------------------------------------------------------------------
Widget::~Widget()
//-----------------------------------------------------------------------------------------------------------------
{
	//Not necessary to delete children widget, Qt will do it automatically
}
