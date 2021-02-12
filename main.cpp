//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple1
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- VTK Includes ----*/
#include <vtkSphereSource.h>
#include <vtkSmartPointer.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
	// Create a sphere
	vtkSmartPointer<vtkSphereSource> sphereObject = vtkSmartPointer<vtkSphereSource>::New();
	sphereObject->SetCenter(20, 30, 40);
	sphereObject->SetRadius(50);
	sphereObject->SetPhiResolution(10);
	sphereObject->SetThetaResolution(10);
	sphereObject->Update();

	// Get bounds of resulting polydata
	double * bounds = new double[6];
	sphereObject->GetOutput()->GetBounds(bounds);
	qDebug() << "Bounds:" << bounds[0] << ";" << bounds[1] << ";" << bounds[2] << ";" << bounds[3] << ";" << bounds[4] << ";" << bounds[5];

	delete [] bounds;

	return 0;
} 
