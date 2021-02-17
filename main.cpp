//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple9
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- VTK Includes ----*/
#include <vtkActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSTLReader.h>
#include <vtkSmartPointer.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
    // Read SCAPULA STL file
    //vtkSmartPointer<vtkSTLReader> reader1 = //...

	// Create mapper for the scapula
    //vtkSmartPointer<vtkPolyDataMapper> mapper1 = //...

	// Create actor related to previous mapper
    //vtkSmartPointer<vtkActor> actor1 = //...

    // Read HUMERUS STL file


    // Create mapper for the humerus

	// Create actor related to previous mapper

	//Create renderer
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

	// Set background color
	renderer->SetBackground(0.5, 0, 1);

	// Create render window
	vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	// Associate the renderer to the window
	renderWindow->AddRenderer(renderer);

	// Create window interactor
	vtkSmartPointer<vtkRenderWindowInteractor> interactorWindow = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	interactorWindow->SetRenderWindow(renderWindow);

	// Add actors to renderer


	// Start rendering
	renderWindow->Render();

	// Start interactor
	interactorWindow->Start();

	return 0;
}
