//-------------------------------------------------------------------------------------------------------------------
/*!	\brief	Exemple1
*	\file	main.cpp
*///-----------------------------------------------------------------------------------------------------------------

/*---- ITK Includes ----*/
#include <itkImage.h>

/*---- QT Includes ----*/
#include <qdebug.h>


int main(int p_argc, char* p_argv[])
{
	//Typedef to define a image type
	typedef itk::Image<unsigned char, 2> UCharImageType;

	//Create image
	UCharImageType::Pointer image = UCharImageType::New();

	//Define image size
	UCharImageType::SizeType size;
	size[0] = 512;
	size[1] = 512;

	//Define image region
	UCharImageType::RegionType region;
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

	//Check image
	qDebug() << "Dimension X:" << image->GetLargestPossibleRegion().GetSize()[0];
	qDebug() << "Dimension Y:" << image->GetLargestPossibleRegion().GetSize()[1];
	qDebug() << "Spacing X:" << image->GetSpacing()[0];
	qDebug() << "Spacing Y:" << image->GetSpacing()[1];
	qDebug() << "Origin X:" << image->GetOrigin()[0];
	qDebug() << "Origin Y:" << image->GetOrigin()[1];

	return 0;
} 
