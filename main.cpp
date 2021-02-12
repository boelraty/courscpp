//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple8
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkBinaryBallStructuringElement.h>
#include <itkBinaryDilateImageFilter.h>
#include <itkBinaryErodeImageFilter.h>
#include <itkGrayscaleFillholeImageFilter.h>
#include <itkImageFileWriter.h>

/*---- QT Includes ----*/
#include <QDebug>

/*---- STL Includes ----*/
#include <string>


int main(int p_argc, char* p_argv[])
{
	//Typedef to define a image type
	typedef itk::Image<unsigned char, 2> UCharImageType;

	//Create the reader to read an image
	itk::ImageFileReader<UCharImageType>::Pointer reader = itk::ImageFileReader<UCharImageType>::New();
	reader->SetFileName("/home/vsimoes/binaryimage.png");
	reader->Update();

	//Typedef to define a StructuringElement type
	typedef itk::BinaryBallStructuringElement <unsigned char, 2> StructuringElementType;

    //Create structuring element
	StructuringElementType structuringElement;
	structuringElement.SetRadius( 1 );
	structuringElement.CreateStructuringElement();

	//Typedef to define a DilateFilter type
	typedef itk::BinaryDilateImageFilter <	UCharImageType, UCharImageType, StructuringElementType> DilateFilterType;

	//Typedef to define a ErodeFilter type
	typedef itk::BinaryErodeImageFilter <	UCharImageType, UCharImageType, StructuringElementType> ErodeFilterType;

	//Erode image
	ErodeFilterType::Pointer eroder = ErodeFilterType::New();

	//Dilate image
	DilateFilterType::Pointer eroder = DilateFilterType::New();


	//Typedef to define a FillFilter Type
	typedef itk::GrayscaleFillholeImageFilter < UCharImageType, UCharImageType > FillFilterType;

	//Fill holes in image


	//Write the binary image

	return 0;
} 
