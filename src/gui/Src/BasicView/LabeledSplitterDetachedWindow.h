#ifndef LABELEDSPLITTERDETACHEDWINDOW_H
#define LABELEDSPLITTERDETACHEDWINDOW_H

#include <QMainWindow>
#include <QSplitterHandle>

class LabeledSplitter;

class LabeledSplitterHandle : public QSplitterHandle
{
    Q_OBJECT
public:
    LabeledSplitterHandle(Qt::Orientation o, LabeledSplitter* parent);
protected slots:
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void contextMenuEvent(QContextMenuEvent* event) override;
    void detachSlot();
    void collapseSlot();
protected:
    int getIndex();
    int charHeight;
    int originalSize;
    int originalIndex;
    void setupContextMenu();
    LabeledSplitter* getParent() const;
    QMenu* mMenu;
    QAction* mExpandCollapseAction;
};

class LabeledSplitterDetachedWindow : public QMainWindow
{
    Q_OBJECT

public:
    LabeledSplitterDetachedWindow(QWidget* parent = 0, LabeledSplitter* splitterwidget = 0);
    ~LabeledSplitterDetachedWindow(void);
    int index;

protected:
    LabeledSplitter* m_SplitterWidget;

    void closeEvent(QCloseEvent* event);

signals:
    void OnClose(LabeledSplitterDetachedWindow* widget);
};


#endif //LABELEDSPLITTERDETACHEDWINDOW_H
