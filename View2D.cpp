//-------------------------------------------------------------------------------------------------------------------
/*!	\brief 	Implementation of class View2D
*	\file	View2D.cpp
*///-----------------------------------------------------------------------------------------------------------------

#include "View2D.h"

/*---- Internal Includes ----*/
#include "ApplicationData.h"

/*---- VTK Includes ----*/
#include <vtkActor2D.h>
#include <vtkRenderWindow.h>
#include <QDebug>

//-----------------------------------------------------------------------------------------------------------------
View2D::View2D(QWidget * p_parent)
: QWidget(p_parent), m_renderer(vtkSmartPointer<vtkRenderer>::New()), m_viewer(vtkSmartPointer<vtkImageViewer>::New())
//-----------------------------------------------------------------------------------------------------------------
{
	m_ui.setupUi(this);
}

//-----------------------------------------------------------------------------------------------------------------
View2D::~View2D()
//-----------------------------------------------------------------------------------------------------------------
{
	//Not necessary to delete children View2D, Qt will do it automatically
}

//-----------------------------------------------------------------------------------------------------------------
void View2D::initData()
//-----------------------------------------------------------------------------------------------------------------
{
	//Add renderer
	//m_ui.view->GetRenderWindow()->AddRenderer(m_renderer);

	//Set input to viewer
	//m_viewer->SetInputData(ApplicationData::getInstance()->getRawVTKData());

	//Add actor to the renderer
	//m_renderer->AddActor2D(m_viewer->GetActor2D());

	//Set Z Slice and update view
	//m_viewer->SetZSlice(0);

	//Init slider
	//m_ui.slider->setRange(0, 
	//m_ui.slider->setValue(0);

	//Connect slider to 2D view
	//QObject::connect(
	//Connect slider to LCD number
	//QObject::connect(

	//Update color
	double range[2];
	ApplicationData::getInstance()->getRawVTKData()->GetScalarRange(range);

	m_viewer->SetColorWindow(range[1] - range[0] );
	m_viewer->SetColorLevel( (range[1]+range[0])/2 );
}

//-----------------------------------------------------------------------------------------------------------------
void View2D::slotUpdateSlice(const int p_value)
//-----------------------------------------------------------------------------------------------------------------
{
	qDebug() << "Update to slice:" << p_value;

	//m_viewer->SetZSlice(p_value);
	m_ui.view->update();

	//Necessary to avoid clicking on the view to update the view
	m_ui.view->GetRenderWindow()->GetInteractor()->Render();
}

