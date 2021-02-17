//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple7
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- VTK Includes ----*/
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkCubeSource.h>
#include <vtkSphereSource.h>
#include <vtkBooleanOperationPolyDataFilter.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
	// Create a cube
	vtkSmartPointer<vtkSphereSource> sphereObject = vtkSmartPointer<vtkSphereSource>::New();
	sphereObject->SetCenter(40, 0, 0);
    sphereObject->SetRadius(50);
    sphereObject->SetPhiResolution(50);
    sphereObject->SetThetaResolution(50);
	sphereObject->Update();

	// Create a cube
	vtkSmartPointer<vtkSphereSource> sphereObject2 = vtkSmartPointer<vtkSphereSource>::New();
	sphereObject2->SetCenter(0, 0, 0);
    sphereObject2->SetRadius(45);
    sphereObject2->SetPhiResolution(50);
    sphereObject2->SetThetaResolution(50);
	sphereObject2->Update();

    vtkSmartPointer<vtkBooleanOperationPolyDataFilter> booleanFilter = vtkSmartPointer<vtkBooleanOperationPolyDataFilter>::New();
    booleanFilter->SetInputData(0, sphereObject->GetOutput());
    booleanFilter->SetInputData(1, sphereObject2->GetOutput());
    booleanFilter->SetOperationToDifference();//Difference, Intersection
    booleanFilter->Update();

	// Create mapper for the sphere
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputData(booleanFilter->GetOutput());

	// Create actor related to previous mapper
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetColor(1, 0, 0);


	// Create renderer
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

	// Set background color
	renderer->SetBackground(1, 1, 1);

	// Create render window
	vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	// Associate the renderer to the window
	renderWindow->AddRenderer(renderer);

	// Create window interactor
	vtkSmartPointer<vtkRenderWindowInteractor> interactorWindow = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	interactorWindow->SetRenderWindow(renderWindow);

	// Add actor to renderer
	renderer->AddActor(actor);

	// Start rendering
	renderWindow->Render();

	// Start interactor
	interactorWindow->Start();

	return 0;
}
