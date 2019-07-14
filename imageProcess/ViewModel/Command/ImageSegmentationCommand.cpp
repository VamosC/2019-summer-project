#include "ImageSegmentationCommand.h"
#include "../ViewModel.h"
#include <any>
#include <string>
#include <QDebug>

ImageSegmentationCommand::ImageSegmentationCommand(ViewModel* view_model) : viewModel(view_model)
{
    // nothing
}

ImageSegmentationCommand::~ImageSegmentationCommand()
{
    // nothing
}

void ImageSegmentationCommand::exec()
{
    viewModel->imageSegmentation(threshold);
}

void ImageSegmentationCommand::setParameter(std::any params)
{
    threshold= *std::any_cast<int>(&params);
}