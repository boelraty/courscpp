//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple6
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/
#include <itkBinaryThresholdImageFilter.h>
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkGDCMImageIO.h>

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


		//Create the GDCM image IO
		itk::GDCMImageIO::Pointer gdcmImageIO = itk::GDCMImageIO::New();

		//Create the reader to read an image
		itk::ImageFileReader<ShortImageType>::Pointer reader = itk::ImageFileReader<ShortImageType>::New();
		reader->SetFileName("D:/Owncloud/CoursISEN/Data");
		reader->SetImageIO(gdcmImageIO);
		reader->Update();

		//Create filter to apply threshold on image
		itk::BinaryThresholdImageFilter<ShortImageType, UCharImageType>::Pointer thresholder =
			itk::BinaryThresholdImageFilter<ShortImageType, UCharImageType>::New();
		//Use reader->GetOutput() as input of thresholder
                        


		//Write the binary image
        itk::ImageFileWriter<UCharImageType>::Pointer writer = itk::ImageFileWriter<UCharImageType>::New();
		//Refer to ex 3 and use output of thresholder
		
		
	}
	catch(itk::ExceptionObject & ex)
	{
		std::cout << ex.what();
	}
	return 0;
} 
