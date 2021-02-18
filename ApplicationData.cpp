//-------------------------------------------------------------------------------------------------------------------
/*!	\brief 	Implementation of class ApplicationData
*	\file	ApplicationData.cpp
*///-----------------------------------------------------------------------------------------------------------------

#include "ApplicationData.h"

/*---- ITK Includes ----*/

/*---- QT Includes ----*/
#include <QDebug>
#include <QDir>
#include <QFileInfo>
#include <QStringList>

/*---- VTK Includes ----*/
#include <vtkImageFlip.h>
#include <vtkPointData.h>
#include <vtkShortArray.h>
#include <vtkUnsignedCharArray.h>

//Initialize static variable
ApplicationData * ApplicationData::m_instance = 0;

//-----------------------------------------------------------------------------------------------------------------
ApplicationData::ApplicationData() :
		m_scapula(vtkPolyData::New()), m_humerus(vtkPolyData::New())
//-----------------------------------------------------------------------------------------------------------------
{
}

//-----------------------------------------------------------------------------------------------------------------
ApplicationData::~ApplicationData()
//-----------------------------------------------------------------------------------------------------------------
{
	m_scapula->Delete();
	m_humerus->Delete();
}

//-----------------------------------------------------------------------------------------------------------------
void ApplicationData::loadDirectory(const QString & p_dirPath)
//-----------------------------------------------------------------------------------------------------------------
{
    //Save path
	m_dirPath = p_dirPath;

	//List files in a directory
	QDir dir(p_dirPath);

	//Create the list of string to store files path
	QStringList filesList;

	//Set the appropriate filter (we only want Files) and sorting procedure (by name).
	dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Readable);
	dir.setSorting(QDir::Name);

	//List all files
	const QFileInfoList list = dir.entryInfoList();

	for (int i = 0 ; i < list.size() ; ++i)
	{
		//Check if it is a readable file
		if ( (list[i].isFile()) && (list[i].isReadable()) )
			filesList.push_back(list[i].absoluteFilePath());
	}

	qDebug() << filesList.size();
	qDebug() << filesList;
        //filesList contains all the files found in the directory

	//Read Dicom Image
	double positionZ = 0.;
	for(int i = 0 ; i < filesList.size() ; ++i)
	{
		//try to read the ITK file and save the image - Ex4 et Ex5 ITK
                //try
                //{
			qDebug() << "Reading image " << i << "with path:" << filesList[i];

                        //reader->SetFileName(filesList[i].toStdString().c_str())

			//For the first two images, we get the image position (0020, 0032).
			//From the difference, we compute the spacingZ
//			if(i <= 1)
//			{
//				std::string currentPosition;
//				gdcmImageIO->GetValueFromTag(std::string("0020|0032"), currentPosition);
//				const double currentPositionZ = QString(currentPosition.c_str()).trimmed().split("\\").last().toDouble();
//				qDebug() << QString(currentPosition.c_str()) << positionZ;
//				if(i == 1)
//				{
//					m_spacingZ = currentPositionZ - positionZ;
//				}
//				else positionZ = currentPositionZ;
//			}

                //}
                //catch error in case we try to read a non dicom file

	}

        //Get dimensionX/Y
        //...

        //Get spacing X/Y
        //...

        //Get dimensionZ
        //...

	//Build the vtkImageData containing the raw volume - Ex12 VTK
        //m_rawVTKData = vtkSmartPointer<vtkImageData>::New();
        //m_rawVTKData->SetDimensions(m_dimensionX, m_dimensionY, m_dimensionZ);
		//m_rawVTKData->SetExtent(
		//m_rawVTKData->SetSpacing(
		//...

	//Create scalars to fill the vtkImageData
	vtkSmartPointer<vtkShortArray> scalars = vtkSmartPointer<vtkShortArray>::New();
        //SetNumberOfValues(...);

	int offset  = 0;
	//Iterate over all images and fill the scalars
 	for(int z = 0 ; z < m_rawImages.size() ; ++z)
	{
		//Create const ITK iterator on each image
		//In the while, set the value of each pixel to the scalars using offset
		//Ex3 - ITK
	}
	
//	m_rawData->GetPointData()->SetScalars(scalars);


        //Flip image along Y to respect difference of referentiel between ITK/VTK display
    vtkSmartPointer<vtkImageFlip> flipper = vtkSmartPointer<vtkImageFlip>::New();
//	flipper->SetFilteredAxis(1);
//	flipper->SetInputData(m_rawVTKData);
//	flipper->Update();

	//m_rawVTKData = flipper->GetOutput();
}

//-----------------------------------------------------------------------------------------------------------------
void ApplicationData::segmentData()
//-----------------------------------------------------------------------------------------------------------------
{
        //Segment from 1 to 2 for Scapula
	m_scapula->Delete();
	m_scapula = segmentData(2, 2);

	//Segment from 0 to 1 for Humerus
	m_humerus->Delete();
	m_humerus = segmentData(1, 1);
}

//-----------------------------------------------------------------------------------------------------------------
vtkPolyData * ApplicationData::segmentData(const int p_lowerThreshold, const int p_upperThreshold) const
//-----------------------------------------------------------------------------------------------------------------
{
	QList<UCharImageType::Pointer> binaryImages;

	//Apply threshold on each raw images
//Same as ITKReader with itk::BinaryThresholdImageFilter
//See Exo6 ITK
	for(int z = 0 ; z < m_rawImages.size() ; ++z)
	{
		
		//Create thresholder and save outpout in binaryImages
	}


	//Build Image Data for input of marching cubes
	//Cf 

        //Create scalars to fill the vtkImageData

	int offset  = 0;
	//Iterate over all images and fill the scalars
	//For loop on binary images


        //Apply the marching cubes
//vtkMarchingCubes
//See Exo12 VTK

		//Return resulting mesh after copy
		vtkPolyData * mesh = vtkPolyData::New();
		//mesh->DeepCopy(marchingcubes->GetOutput());

        return mesh;
}
