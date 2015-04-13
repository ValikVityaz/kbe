/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#include "extendedtabwidget.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QTabBar>
#include <QMdiSubWindow>


ExtendedTabWidget::ExtendedTabWidget(QWidget *parent) :
    QTabWidget(parent)
{
    QTabBar* tb = new QTabBar(this);
    tb->setSelectionBehaviorOnRemove(QTabBar::SelectPreviousTab);
    setTabBar(tb);
    setMovable(true);
    setTabPosition(QTabWidget::North);
    setTabShape(QTabWidget::Rounded);
    setTabsClosable(true);
    setIconSize(QSize(32, 32));

    connect(this, SIGNAL(tabCloseRequested(int)), this, SLOT(close(int)));
}

ExtendedTabWidget::~ExtendedTabWidget()
{

}

bool ExtendedTabWidget::eventFilter(QObject* watched, QEvent* event)
{
    QWidget* subWindow = qobject_cast<QWidget*>(watched);
    if(!subWindow)
        return QTabWidget::eventFilter(watched, event);

    switch (event->type())
    {
        case QEvent::WindowTitleChange:
        case QEvent::ModifiedChange:
                setTabText(indexOf(subWindow), tabTextFor(subWindow));
            break;
/*        case QEvent::WindowIconChange:
                setTabIcon(indexOf(subWindow), subWindow->windowIcon());
            break;*/
        default:
            break;
    }

    return QTabWidget::eventFilter(watched, event);
}

QString ExtendedTabWidget::tabTextFor(QWidget* subWindow)
{
    if (!subWindow)
        return QString();

    QString title = subWindow->windowTitle();
    title.replace('\\', '/');

    int n = title.lastIndexOf('/');
    if (n != -1)
        title = title.mid(n + 1);

//    if (subWindow->isWindowModified())
//        title += " [*]";

    return title.isEmpty() ? tr("(Untitled)") : title;
}

bool ExtendedTabWidget::closeWindow(QWidget* wnd)
{
    Q_ASSERT_X(wnd,
               "bool ExtendedTabWidget::close(int index)",
               "Can't get window");

    if(emit tabBeforeClose(wnd))
    {
        wnd->close();
        removeTab(indexOf(wnd));
        delete wnd;
        tabsUpdate();
        return true;
    }

    return false;
}

QList<QWidget*> ExtendedTabWidget::subWindowList() const
{
    QList<QWidget*> res;
    int cnt = count();
    for(int i =0; i < cnt; ++i)
        res.push_back(widget(i));

    return res;
}

void ExtendedTabWidget::closeOtherDocuments()
{
    QWidget* currentWindow = currentWidget();
    QList<QWidget*> list = subWindowList();
    QList<QWidget*>::const_iterator it = list.begin();

    for(; it != list.end(); it++)
        if (*it != currentWindow)
            if (!(*it)->close())
                return;
}

void ExtendedTabWidget::closeAllDocuments()
{
    QWidget* w = widget(0);
    while(w)
    {
        if(!closeWindow(w))
            return;
        w = widget(0);
    }
    tabsUpdate();
}

void ExtendedTabWidget::close(int index)
{
    if (index == -1)
        index = currentIndex();

    closeWindow(widget(index));
}

int ExtendedTabWidget::addSubWindow(EditorInterface* window)
{
    QWidget *widget = window->widget();
    Q_ASSERT(widget != 0);

    int curr = currentIndex();
    int index = QTabWidget::insertTab(curr + 1, widget, window->icon(), tabTextFor(widget));
    widget->installEventFilter(this);
    widget->setAttribute(Qt::WA_DeleteOnClose, true);
    setCurrentWidget(widget);
    tabsUpdate();
    return index;
}

/*
void ExtendedTabWidget::addMenu(QMdiSubWindow* wnd)
{
    QMenu* menu = wnd->systemMenu();
    menu->addAction(MainWindow::getInstance()->ui->actionClose_Others);
    menu->addAction(MainWindow::getInstance()->ui->actionClose_All);
}
*/
