//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple4
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/
#include <itkImage.h>
#include <itkImageRegionConstIterator.h>
#include <itkImageFileReader.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
	//Typedef to define a image type
	typedef itk::Image<unsigned char, 2> UCharImageType;

	//Create the reader to read an image
	itk::ImageFileReader<UCharImageType>::Pointer reader = itk::ImageFileReader<UCharImageType>::New();
	reader->SetFileName("/home/vsimoes/image.png");
	reader->Update();

	//Write dimensions and spacing
	qDebug() << "Dimensions X :" << reader->GetOutput()->GetLargestPossibleRegion().GetSize()[0];
	qDebug() << "Dimensions Y :" << reader->GetOutput()->GetLargestPossibleRegion().GetSize()[1];
	qDebug() << "Spacing X :" << reader->GetOutput()->GetSpacing()[0];
	qDebug() << "Spacing Y :" << reader->GetOutput()->GetSpacing()[1];

	//Create an iterator to check if the image contains the rectangle
	itk::ImageRegionConstIterator<UCharImageType> iterator(reader->GetOutput(), reader->GetOutput()->GetLargestPossibleRegion());
	
	//Initialize iterator to begin (GoToBegin())
	iterator.GoToBegin();

	int nbPixels = 0;

	while(!iterator.IsAtEnd())
	{
		//Check if pixel = 255
		if(iterator.Get() == static_cast<unsigned char>(255))
			++nbPixels;

		//Increment iterator
		++iterator;
	}

	qDebug() << "Nb pixels equal to 255 :" << nbPixels;

	return 0;
} 
