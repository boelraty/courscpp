//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple12
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- VTK Includes ----*/
#include <vtkActor.h>
#include <vtkPointData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkUnsignedCharArray.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
	// Create vtkImageData
	vtkSmartPointer<vtkImageData> data = //...

	// Fill the image data
	vtkSmartPointer<vtkUnsignedCharArray> scalars = //...

	for (int i = 0 ; i < 100 ; ++i)
	{
		for(int j = 0 ; j < 100 ; ++j)
		{
			for(int k = 0 ; k < 100 ; ++k)
			{
				//Fill scalars
				if (k > 40 && k < 60 && j > 30 && j < 70 && i > 20 && i < 80)
					scalars->SetValue(k + j * 100 + i * 100 * 100, 1);
				else scalars->SetValue(k + j * 100 + i * 100 * 100, 0);
			}
		}
	}
	data->GetPointData()->SetScalars(scalars);

	//Create mesh related to image data
	vtkSmartPointer<vtkMarchingCubes> marchingcubes = //...

	qDebug() << "Before decimater:" << marchingcubes->GetOutput()->GetNumberOfPoints();
	
	vtkSmartPointer<vtkDecimatePro> decimater = //...

	qDebug() << "After decimater: " << decimater->GetOutput()->GetNumberOfPoints();

	// Create mapper for the sphere
	vtkSmartPointer<vtkPolyDataMapper> mapper = //...

	// Create actor related to previous mapper
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	actor->GetProperty()->SetColor(0.87, 0.83, 0.69);

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
