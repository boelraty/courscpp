//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple5
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/
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
		//Typedef to define a image type (refer to exercice 1 and replace unsigned char with signed short)
		typedef itk::Image<short, 2> ShortImageType;

		//Create the GDCM image IO
		itk::GDCMImageIO::Pointer gdcmImageIO = itk::GDCMImageIO::New();

		//Create the reader to read an image
		itk::ImageFileReader<ShortImageType>::Pointer reader = itk::ImageFileReader<ShortImageType>::New();
		reader->SetFileName("D:/Owncloud/CoursISEN/Data/ImageDICOM");
		reader->SetImageIO(gdcmImageIO);
		reader->Update();

		//Write dimensions and spacing
		qDebug() << "Dimensions X :" << reader->GetOutput()->GetLargestPossibleRegion().GetSize()[0];
		qDebug() << "Dimensions Y :" << reader->GetOutput()->GetLargestPossibleRegion().GetSize()[1];
		qDebug() << "Spacing X :" << reader->GetOutput()->GetSpacing()[0];
		qDebug() << "Spacing Y :" << reader->GetOutput()->GetSpacing()[1];

		//Check information from the GDCM ImageIO
		std::string patientName, dob, studyDate, modality;

		//Get DICOM data
		gdcmImageIO->GetValueFromTag(std::string("0010|0010"), patientName);
		gdcmImageIO->GetValueFromTag(std::string("0010|0030"), dob);
		gdcmImageIO->GetValueFromTag(std::string("0010|0010"), patientName);
		gdcmImageIO->GetValueFromTag(std::string("0008|0020"), studyDate);
		gdcmImageIO->GetValueFromTag(std::string("0008|0060"), modality);

		qDebug() << "Patient name :" << patientName.c_str();
		qDebug() << "Patient birthdate :" << dob.c_str();
		qDebug() << "Patient birthdate :" << studyDate.c_str();
		qDebug() << "Modality :" << modality.c_str();

		itk::ImageFileWriter<ShortImageType>::Pointer writer = itk::ImageFileWriter<ShortImageType>::New();
		writer->SetInput(reader->GetOutput());
		writer->SetFileName("D:/image.tiff");
		writer->Write();

	}
	catch (itk::ExceptionObject& ex)
	{
		qDebug() << ex.what();
	}
	return 0;
} 
