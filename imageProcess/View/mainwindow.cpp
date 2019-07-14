#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Notification/UpdateNotification.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    updateNotification(std::make_shared<UpdateNotification>(this))
{
    ui->setupUi(this);
    scene = new QGraphicsScene;//图像显示
    graphView = this->findChild<QGraphicsView*>("image1");
}

MainWindow::~MainWindow()
{
    delete scene;
    delete ui;
}

void MainWindow::update()
{
    scene->clear();
    scene->addPixmap(QPixmap::fromImage(*qImage));//.scaled(graphView->size(),Qt::KeepAspectRatio)
    graphView->setScene(scene);
    graphView->show();
}

void MainWindow::setOpenFileCommand(std::shared_ptr<Command> openFileCommand)
{
    this->openFileCommand = openFileCommand;
}

void MainWindow::setSaveFileCommand(std::shared_ptr<Command> saveFileCommand)
{
    this->saveFileCommand = saveFileCommand;
}

void MainWindow::setAverBlurCommand(std::shared_ptr<Command> averBlurCommand)
{
    this->averBlurCommand = averBlurCommand;
}

void MainWindow::setMidBlurCommand(std::shared_ptr<Command> midBlurCommand)
{
    this->midBlurCommand = midBlurCommand;
}

void MainWindow::setGaussBlurCommand(std::shared_ptr<Command> gaussBlurCommand)
{
    this->gaussBlurCommand = gaussBlurCommand;
}

void MainWindow::setBilaterBlurCommand(std::shared_ptr<Command> bilaterBlurCommand)
{
    this->bilaterBlurCommand = bilaterBlurCommand;
}

void MainWindow::setLightContrastCommand(std::shared_ptr<Command> lightContrastCommand)
{
    lightDialog.setLightContrastCommand(lightContrastCommand);
}


void MainWindow::setTmpLightContrastCommand(std::shared_ptr<Command> tmpLightContrastCommand)
{
    lightDialog.setTmpLightContrastCommand(tmpLightContrastCommand);
}


void MainWindow::setToGrayCommand(std::shared_ptr<Command> toGrayCommand)
{
    this->toGrayCommand = toGrayCommand;
}

void MainWindow::setToBinaryCommand(std::shared_ptr<Command> toBinaryCommand)
{
    this->toBinaryCommand = toBinaryCommand;
}

void MainWindow::setDetectEdgeCommand(std::shared_ptr<Command> detectEdgeCommand)
{
    this->detectEdgeCommand = detectEdgeCommand;
}

void MainWindow::setGrayEqualizeHistCommand(std::shared_ptr<Command> grayEqualizeHistCommand)
{
    this->grayEqualizeHistCommand=grayEqualizeHistCommand;
}

void MainWindow::setColorEqualizeHistCommand(std::shared_ptr<Command> colorEqualizeHistCommand)
{
    this->colorEqualizeHistCommand=colorEqualizeHistCommand;
}

void MainWindow::setLaplaceCommand(std::shared_ptr<Command> laplaceCommand)
{
    this->laplaceCommand=laplaceCommand;
}

void MainWindow::setLogEnhanceCommand(std::shared_ptr<Command> logEnhanceCommand)
{
    this->logEnhanceCommand=logEnhanceCommand;
}

void MainWindow::setGammaCorrectCommand(std::shared_ptr<Command> gammaCorrectCommand)
{
    this->gammaCorrectCommand=gammaCorrectCommand;
}

void MainWindow::setAddGaussNoiseCommand(std::shared_ptr<Command> addGaussNoiseCommand){
    this->addGaussNoiseCommand=addGaussNoiseCommand;
}

void MainWindow::setAddSaltNoiseCommand(std::shared_ptr<Command> addSaltNoiseCommand){
    this->addSaltNoiseCommand=addSaltNoiseCommand;
}

void MainWindow::setImageSegmentationCommand(std::shared_ptr<Command> imageSegmentationCommand){
    this->imageSegmentationCommand=imageSegmentationCommand;
}

void MainWindow::setImageEnlargeCommand(std::shared_ptr<Command> imageEnlargeCommand){
    this->imageEnlargeCommand=imageEnlargeCommand;
}

void MainWindow::setImageReductCommand(std::shared_ptr<Command> imageReductCommand){
    this->imageReductCommand=imageReductCommand;
}

void MainWindow::setTrainModelCommand(std::shared_ptr<Command> trainModelCommand){
    this->trainEigenModelCommand=trainModelCommand;
}

void MainWindow::setDetectFacesCommand(std::shared_ptr<Command> detectFacesCommand)
{
    this->detectFacesCommand=detectFacesCommand;
}

void MainWindow::setAnnotateFacesCommand(std::shared_ptr<Command> annotateFacesCommand)
{
    this->annotateFacesCommand=annotateFacesCommand;
}

void MainWindow::setBeautifyFacesCommand(std::shared_ptr<Command> beautifyFacesCommand)
{
    this->beautifyFacesCommand=beautifyFacesCommand;
}
void MainWindow::setGenerateHeadshotsCommand(std::shared_ptr<Command> generateHeadshotsCommand)
{
    this->generateHeadshotsCommand=generateHeadshotsCommand;
}

void MainWindow::setQImage(std::shared_ptr<QImage> qImage)
{
    this->qImage = qImage;
}

void MainWindow::on_actionopen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this);
    if(fileName.isEmpty())
    {
        return;
    }
    else
    {
        openFileCommand->setParameter(fileName.toStdString());
        openFileCommand->exec();
    }
}

std::shared_ptr<Notification> MainWindow::getNotification()
{
    return updateNotification;
}

void MainWindow::on_actionsave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if(fileName.isEmpty())
    {
        return;
    }
    else
    {
        saveFileCommand->setParameter(fileName.toStdString());
        saveFileCommand->exec();
    }
}

void MainWindow::on_actionToGray_triggered()
{
    toGrayCommand->exec();
}

void MainWindow::on_actionToBinary_triggered()
{
    int threshold=100;
    toBinaryCommand->setParameter(threshold);
    toBinaryCommand->exec();
}

void MainWindow::on_actionlight_triggered()
{
    lightDialog.show();
}

void MainWindow::on_actionDetectEdge_triggered()
{
    int threshold=30;
    detectEdgeCommand->setParameter(threshold);
    detectEdgeCommand->exec();
}

void MainWindow::on_actionGrayEqualizeHist_triggered()
{
    grayEqualizeHistCommand->exec();
}

void MainWindow::on_actionColorEqualizeHist_triggered()
{
    colorEqualizeHistCommand->exec();
}

void MainWindow::on_actionLaplace_triggered()
{
    laplaceCommand->exec();
}

void MainWindow::on_actionLogEnhance_triggered()
{
    logEnhanceCommand->exec();
}


void MainWindow::on_actionGamma_triggered()
{
    float fGamma=0.4f;
    gammaCorrectCommand->setParameter(fGamma);
    gammaCorrectCommand->exec();
}

void MainWindow::on_actionGaussNoise_triggered()
{
    addGaussNoiseCommand->exec();
}

void MainWindow::on_actionSalt_triggered()
{
    int n=5000;
    addSaltNoiseCommand->setParameter(n);
    addSaltNoiseCommand->exec();
}

void MainWindow::on_actionImageSegmentation_triggered()
{
    int threshold=50;
    imageSegmentationCommand->setParameter(threshold);
    imageSegmentationCommand->exec();
}

void MainWindow::on_actionjizhilvbo_triggered()
{
    averBlurCommand->exec();
}

void MainWindow::on_actionzhongzhillvbo_triggered()
{
    midBlurCommand->exec();
}

void MainWindow::on_actiongaosilvbo_triggered()
{
    gaussBlurCommand->exec();
}

void MainWindow::on_actionshuangbianlvbo_triggered()
{
    bilaterBlurCommand->exec();
}

void MainWindow::on_actionEnlarge_triggered()
{
    imageEnlargeCommand->exec();
}

void MainWindow::on_actionReduct_triggered()
{
    imageReductCommand->exec();
}

void MainWindow::on_actionTrainEigenModel_triggered()
{
    QString datapath = QFileDialog::getExistingDirectory();
    if(datapath.isEmpty())
    {
        return;
    }
    else
    {
        trainEigenModelCommand->setParameter(datapath.toStdString());
        trainEigenModelCommand->exec();
    }
}


void MainWindow::on_actionDetectFaces_triggered()
{

}

void MainWindow::on_actionAnnotateFaces_triggered(){

}

void MainWindow::on_actionBeautifyFaces_triggered(){

}

void MainWindow::on_actionGenerateHeadshots_triggered(){

}
