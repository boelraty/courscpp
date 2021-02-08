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
	//Typedef to define a image type (refer to exercice 1 and replace unsigned char with signed short)
	typedef itk::Image<signed short, 2> ShortImageType;

	//Create the GDCM image IO
	itk::GDCMImageIO::Pointer gdcmImageIO = itk::GDCMImageIO::New();

	//Create the reader to read an image
	itk::ImageFileReader<ShortImageType>::Pointer reader = itk::ImageFileReader<ShortImageType>::New();
	reader->SetFileName("/home/vsimoes/Documents/Formations/Donnees/CoursISEN/Data/ImageDICOM");
	reader->SetImageIO(gdcmImageIO);
	reader->Update();

	//Write dimensions and spacing
	qDebug() << "Dimensions X :" << reader->GetOutput()->GetLargestPossibleRegion().GetSize()[0];
	qDebug() << "Dimensions Y :" << reader->GetOutput()->GetLargestPossibleRegion().GetSize()[1];
	qDebug() << "Spacing X :" << reader->GetOutput()->GetSpacing()[0];
	qDebug() << "Spacing Y :" << reader->GetOutput()->GetSpacing()[1];

	//Check information from the GDCM ImageIO
	char * patientname = new char;
	char * patientbirthdate = new char;
	char * patientid = new char;
	char * studydate = new char;
	std::string modality;

	//Get DICOM data
	gdcmImageIO->GetPatientName(patientname);
	gdcmImageIO->GetPatientDOB(patientbirthdate);
	gdcmImageIO->GetPatientID(patientid);
	gdcmImageIO->GetStudyDate(studydate);
	gdcmImageIO->GetValueFromTag(std::string("0008|0060"), modality);

	qDebug() << "Patient name :" << patientname;
	qDebug() << "Patient birthdate :" << patientbirthdate;
	qDebug() << "Patient id :" << patientid;
	qDebug() << "Study date :" << studydate;
	qDebug() << "Modality :" << modality.c_str();

    itk::ImageFileWriter<ShortImageType>::Pointer writer = itk::ImageFileWriter<ShortImageType>::New();
    writer->SetInput(reader->GetOutput());
    writer->SetFileName("image.tiff");
    writer->Write();

	//Delete allocated pointers
	delete [] patientname;
	delete [] patientbirthdate;
	delete [] patientid;
	delete [] studydate;
	return 0;
} 
