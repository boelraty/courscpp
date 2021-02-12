//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple6
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkBinaryThresholdImageFilter.h>
#include <itkImageFileWriter.h>

/*---- QT Includes ----*/
#include <qdebug.h>

/*---- STL Includes ----*/
#include <string>


int main(int p_argc, char* p_argv[])
{
	try
	{
		//Typedef to define a image type
		typedef itk::Image<signed short, 2> ShortImageType;
		typedef itk::Image<unsigned char, 2> UCharImageType;

		//Create the reader to read an image
		itk::ImageFileReader<ShortImageType>::Pointer reader = itk::ImageFileReader<ShortImageType>::New();
		reader->SetFileName("/home/vsimoes/Documents/Formations/Donnees/CoursISEN/Data/ImageDICOM");
		reader->Update();

		//Create filter to apply threshold on image
		itk::BinaryThresholdImageFilter<ShortImageType, UCharImageType>::Pointer thresholder =
				itk::BinaryThresholdImageFilter<ShortImageType, UCharImageType>::New();
		thresholder->SetInput(reader->GetOutput());
		thresholder->SetLowerThreshold(160);
		//thresholder->SetUpperThreshold(1000);
		thresholder->SetInsideValue(255);
		thresholder->SetOutsideValue(0);
		thresholder->Update();

		//Write the binary image
		itk::ImageFileWriter<UCharImageType>::Pointer writer = itk::ImageFileWriter<UCharImageType>::New();
		writer->SetFileName("/home/vsimoes/binaryimage.png");
		writer->SetInput(thresholder->GetOutput());
		writer->Update();
	}
	catch(itk::ExceptionObject & ex)
	{
		std::cout << ex.what();
	}
	return 0;
} 
