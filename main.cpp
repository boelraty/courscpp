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
	reader->SetFileName("/home/vsimoes/binaryimage.png");
	reader->Update();
	
	
	//Labelize the image
	itk::ConnectedComponentImageFilter<UCharImageType, IntImageType>::Pointer labeler =
			itk::ConnectedComponentImageFilter<UCharImageType, IntImageType>::New();
	//Set input = outout of reader

	
	//Relabelize the image to get info about the group of found pixels
//	itk::RelabelComponentImageFilter<IntImageType, UCharImageType>::Pointer relabeler =
//		itk::RelabelComponentImageFilter<IntImageType, UCharImageType>::New();


//	qDebug() << "Number of found objects :" << relabeler->GetNumberOfObjects();
//	for (int i = 0 ; i < relabeler->GetNumberOfObjects() ; ++i)
//		qDebug() << "Area of objects " << i << ":" << relabeler->GetSizeOfObjectInPhysicalUnits(i);

	//Rescale the image to see colors on labelized output
//    itk::RescaleIntensityImageFilter<UCharImageType, UCharImageType>::Pointer rescaler =
//    ...

	//Write the binary image
//	itk::RescaleIntensityImageFilter<UCharImageType, UCharImageType>::Pointer rescaler =
//		itk::RescaleIntensityImageFilter<UCharImageType, UCharImageType>::New();
//  //...

	return 0;
} 
