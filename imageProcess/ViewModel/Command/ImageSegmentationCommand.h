#pragma once
#include <string>
#include "../../Common/Command.h"

class ViewModel;
class ImageSegmentationCommand: public Command
{
private:
    // Command负责发送指令给ViewModel
    // ViewModel类似于控制器Controller的作用
    ViewModel* viewModel;
    int threshold;
public:
    ImageSegmentationCommand(ViewModel* view_model);
    ~ImageSegmentationCommand();
    void setParameter(std::any params);
    void exec();
};