#ifndef PREVIEWWINDOW_H
#define PREVIEWWINDOW_H

#include <QDialog>
#include <QPixmap>
#include <QGraphicsScene>
#include <QThread>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>

namespace Ui {
class PreviewWindow;
}

class PreviewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PreviewWindow(QWidget *parent = 0);
    ~PreviewWindow();

private:
    Ui::PreviewWindow *ui;
    int fps;
    std::vector<QImage> imageList;
    QPixmap pixImage;
    QGraphicsPixmapItem pixMap;
    QThread workerThread;
    QGraphicsView theView;
    QGraphicsScene *theScene;
    QTimer timer;
    int counter;

public slots:
    void previewSlot(int value, std::vector<QImage> _imageList);
    void timerSlot();
};

#endif // PREVIEWWINDOW_H
