//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple1
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/


/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
	//Typedef to define a image type
	typedef itk::Image<unsigned char, 2> UCharImageType;

	//Create image


	//Define starting point (0, 0)
        UCharImageType::IndexType startIndex;

	//Define image size
        UCharImageType::SizeType size;

        //Define image region

	//Set the region to the image
	image->SetRegions(region);

	//Set image origin (where it starts in a 2D/3D referentiel)
	UCharImageType::PointType origin;


	//Set image spacing
	UCharImageType::SpacingType spacing;


	//Allocate the image in memory

	//Check image
        qDebug() << "Dimension X:" << image->GetLargestPossibleRegion().GetSize()[0];
        //....
	return 0;
} 
