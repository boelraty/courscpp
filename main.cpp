//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple3
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/
#include <itkImage.h>
#include <itkImageRegionConstIterator.h>
#include <itkImageRegionIterator.h>
#include <itkImageFileWriter.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
	//Typedef to define a image type
	typedef itk::Image<unsigned char, 2> UCharImageType;

	//Create image
	UCharImageType::Pointer image = UCharImageType::New();

	//Define starting point (0, 0)
	UCharImageType::IndexType startIndex;
	startIndex[0] = 0;
	startIndex[1] = 0;

	//Define image size
	UCharImageType::SizeType size;
	size[0] = 512;
	size[1] = 512;

	//Define image region
	UCharImageType::RegionType region;
	region.SetIndex(startIndex);
	region.SetSize(size);

	//Set the region to the image
	image->SetRegions(region);

	//Set image origin (where it starts in a 2D/3D referentiel)
	UCharImageType::PointType origin;
	origin[0] = 0;
	origin[1] = 0;
	image->SetOrigin(origin);

	//Set image spacing
	UCharImageType::SpacingType spacing;
	spacing[0] = 0.5;
	spacing[1] = 0.5;
	image->SetSpacing(spacing);

	//Allocate the image in memory
	image->Allocate();
	image->FillBuffer(0);


	//START EXERCICE 2

	//Create const iterator for the iteration on the entire image
	itk::ImageRegionConstIterator<UCharImageType> globalIterator(image, image->GetLargestPossibleRegion());

	// Initialize iterator to beginning
	globalIterator.GoToBegin();

	//Iterate over the entire image to count the number of pixels
	int nbPixels = 0;

	while (! globalIterator.IsAtEnd())
	{
		//To print the pixel value
		//qDebug() << globalIterator.Get();

		//Increment number of pixels
		++nbPixels;

		//Increment iterator
		++globalIterator;
	}

	qDebug() << "Number of pixels (512, 512) =" << nbPixels;

	//Create a region for iterate over a part of the image
	UCharImageType::RegionType regionForIteration;

	//Define starting pixel for iteration
	UCharImageType::IndexType startingPixel;
	startingPixel[0] = 50;
	startingPixel[1] = 100;

	//Define size of region for iteration
	UCharImageType::SizeType regionSize;
	regionSize[0] = 100;
	regionSize[1] = 200;

	regionForIteration.SetIndex(startingPixel);
	regionForIteration.SetSize(regionSize);

	//Create non const iterator for fill the image with the square
	itk::ImageRegionIterator<UCharImageType> localIterator(image, regionForIteration);
	localIterator.GoToBegin();

	nbPixels = 0;

	while(!localIterator.IsAtEnd())
	{
		//Set a value to the pixel
		localIterator.Set(static_cast<unsigned char>(255));

		//Increment number of set pixels
		++nbPixels;

		//Increment iterator
		++localIterator;
	}

	qDebug() << "Number of pixels set:" << nbPixels;

	//Access to a specific pixel
	UCharImageType::IndexType pixelIndex1;
	pixelIndex1[0] = 60;
	pixelIndex1[1] = 150;

	UCharImageType::IndexType pixelIndex2;
	pixelIndex2[0] = 200;
	pixelIndex2[1] = 150;

	qDebug() << "Pixel(60, 150) =" << image->GetPixel(pixelIndex1);
	qDebug() << "Pixel(200, 150) =" << image->GetPixel(pixelIndex2);

	//In order to catch possible error
	try
	{
		//Create the filter to write the image
		itk::ImageFileWriter<UCharImageType>::Pointer writer = itk::ImageFileWriter<UCharImageType>::New();
        writer->SetFileName("toto.png");
		writer->SetInput(image);
		writer->Write();
		//writer->Update();
		qDebug() << "Writing done";
	}
	catch(itk::ExceptionObject & ex)
	{
		std::cout << ex.what();
	}


	return 0;
} 
