#pragma once


/*---- ITK Includes ----*/
#include <itkImage.h>

/*---- QT Includes ----*/
#include <QList>
#include <QString>

/*---- VTK Includes ----*/
#include <vtkImageData.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>

//Define image type
typedef itk::Image<signed short, 2> ShortImageType;
typedef itk::Image<unsigned char, 2> UCharImageType;


//-------------------------------------------------------------------------------------------------------------------
/*!	\class	ApplicationData
*	\brief	Stored the application data using SingletonPattern
*
*	\note	Copy constructor and assignment operator are purposely not implemented.
*	
*	\file	ApplicationData.h
*///-----------------------------------------------------------------------------------------------------------------
class ApplicationData
{
	public:
		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Get instance: if NULL create it	
		*///-----------------------------------------------------------------------------------------------------------------
		static ApplicationData * getInstance()
		{
			//Create instance
			if (!m_instance)
				m_instance = new ApplicationData();
			return m_instance;
		}

		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Kill the instance if already created	
		*///-----------------------------------------------------------------------------------------------------------------
		static void kill()
		{
			//Delete instance
			if (m_instance)
			{
				delete m_instance;
				m_instance = 0;
			}
		}

		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Method to load a directory
		*///-----------------------------------------------------------------------------------------------------------------
		void loadDirectory(const QString & p_dirPath);

		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Method to segment the data
		*///-----------------------------------------------------------------------------------------------------------------
		void segmentData();

		//! Getters
		//...
        vtkSmartPointer<vtkImageData> getRawVTKData() { return m_rawVTKData; }
		vtkPolyData * getScapula() { return m_scapula; }
		vtkPolyData * getHumerus() { return m_humerus; }

	private:
		static ApplicationData *m_instance;
		
		QString m_dirPath;								//! The path to the current processed directory
		double m_spacingX, m_spacingY, m_spacingZ;		//! The spacing for the loaded scan
		int m_dimensionX, m_dimensionY, m_dimensionZ;	//! The dimensions of the loaded scan

		//! Store the raw images
		QList<ShortImageType::Pointer> m_rawImages;		

		//! The raw data in VTK format
        vtkSmartPointer<vtkImageData> m_rawVTKData;

		vtkPolyData * m_scapula, * m_humerus;

		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Method to segment the data depending on lower and higher threshold
		*///-----------------------------------------------------------------------------------------------------------------
		vtkPolyData * segmentData(const int p_lowerThreshold, const int p_upperThreshold) const;

		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Constructor
		*///-----------------------------------------------------------------------------------------------------------------
		ApplicationData();

		//-------------------------------------------------------------------------------------------------------------------
		/*!	\brief	Destructor
		*///-----------------------------------------------------------------------------------------------------------------
		~ApplicationData();
		
		ApplicationData( const ApplicationData & );					//! Purposely not implemented
		ApplicationData & operator=(const ApplicationData & );		//! Purposely not implemented
		
};
