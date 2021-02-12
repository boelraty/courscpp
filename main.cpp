//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple7
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkConnectedComponentImageFilter.h>
#include <itkRelabelComponentImageFilter.h>
#include <itkImageFileWriter.h>
#include <itkRescaleIntensityImageFilter.h>

/*---- QT Includes ----*/
#include <QDebug>

/*---- STL Includes ----*/
#include <string>


int main(int p_argc, char* p_argv[])
{
	//Typedef to define a image type
	typedef itk::Image<unsigned char, 2> UCharImageType;

	typedef itk::Image<int, 2> IntImageType;

	//Create the reader to read an image
	itk::ImageFileReader<UCharImageType>::Pointer reader = itk::ImageFileReader<UCharImageType>::New();
	reader->SetFileName("D:/image_seuillee.png");
	reader->Update();

	//Labelize the image
	itk::ConnectedComponentImageFilter<UCharImageType, IntImageType>::Pointer labeler =
			itk::ConnectedComponentImageFilter<UCharImageType, IntImageType>::New();
	labeler->SetInput(reader->GetOutput());
	labeler->Update();

	//Relabelize the image to get info about the group of found pixels
	itk::RelabelComponentImageFilter<IntImageType, UCharImageType>::Pointer relabeler =
			itk::RelabelComponentImageFilter<IntImageType, UCharImageType>::New();
	relabeler->SetInput(labeler->GetOutput());
	relabeler->SetMinimumObjectSize(100);
	relabeler->Update();

    itk::ImageFileWriter<UCharImageType>::Pointer writer2 = itk::ImageFileWriter<UCharImageType>::New();
    writer2->SetInput(relabeler->GetOutput());
    writer2->SetFileName("D:/output.png");
    writer2->Update();


	qDebug() << "Number of found objects :" << relabeler->GetNumberOfObjects();
	for (int i = 0 ; i < relabeler->GetNumberOfObjects() ; ++i)
		qDebug() << "Area of objects " << i << ":" << relabeler->GetSizeOfObjectInPhysicalUnits(i);

	//Rescale the image to see colors on labelized output
	itk::RescaleIntensityImageFilter<UCharImageType, UCharImageType>::Pointer rescaler =
			itk::RescaleIntensityImageFilter<UCharImageType, UCharImageType>::New();
	rescaler->SetInput(relabeler->GetOutput());
	rescaler->Update();

	//Write the binary image
	itk::ImageFileWriter<UCharImageType>::Pointer writer = itk::ImageFileWriter<UCharImageType>::New();
	writer->SetFileName("D:/labelizedimage.png");
	writer->SetInput(rescaler->GetOutput());
	writer->Update();

	return 0;
} 
