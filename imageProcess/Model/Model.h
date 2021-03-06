#pragma once
#include "../ViewModel/ViewModel.h"
#include "../Common/myImage.h"
#include "../Common/ImageList.h"
#include "../Common/Notification.h"
#include "../Utility/utility.h"
#include <string>
#include <QProgressDialog>

class Model
{
private:
    std::shared_ptr<ImageList> imageList;
    std::shared_ptr<Notification> notification;
    std::shared_ptr<Notification> tmpNotification;
public:
    Model();
    ~Model();
    bool imageGuided(float& eps);
    bool imageDefog();
    bool openImage(const std::string &file_name);
    bool saveImage(const std::string &file_name);
    bool changeImageLightContrast(int light, int contrast);
    bool changeTmpImageLightContrast(int light, int contrast);
    bool display();
    bool undo();
    bool averBlur();
    bool midBlur();
    bool gaussBlur();
    bool bilaterBlur();
    bool toGray();
    bool toBinary(int& threshold);
    bool detectEdge(int& threshold);
    bool grayEqualizeHist();
    bool colorEqualizeHist();
    bool laplace();
    bool logEnhance();
    bool gammaCorrect(float& fGamma);
    bool addGaussNoise();
    bool addSaltNoise(int& n);
    bool imageSegmentation(int& threshold);
    bool imageEnlarge();
    bool imageReduct();
    bool trainModel(const std::string &dataPath);
    bool detectFaces(const std::string &modelPath);
    bool annotateFaces(const std::string &modelPath);
    bool beautifyFaces();
    bool generateHeadshots(const std::string &outputPath);
    std::shared_ptr<ImageList> getImageList();
    void setUpdateNotification(std::shared_ptr<Notification> notification);
    void setUpdateTmpNotification(std::shared_ptr<Notification> notification);
};
