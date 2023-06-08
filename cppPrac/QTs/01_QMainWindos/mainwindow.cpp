#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 重置窗口大小
    resize(600, 600);
    setWindowTitle("01");

    // 菜单栏最多只能有一个(menuBar()已经把对象创建在了对象树上)
    QMenuBar* bar = menuBar();
    // QMenuBar* bar = new QMenuBar(this);  //  用这个也不报错
    setMenuBar(bar);

    // 创建菜单
    QMenu* file_menu = bar->addMenu("文件");
    QMenu* edit_menu = bar->addMenu("编辑");

    // 在menu中增加内容
    QAction* fm_ac1 = file_menu->addAction("新建");
    // 添加分隔线
    file_menu->addSeparator();
    QAction* fm_ac2 = file_menu->addAction("打开");

    edit_menu->addAction("选择");
    edit_menu->addSeparator();
    edit_menu->addAction("转到");

    // 工具栏，可以有多个
    QToolBar* tool_bar = new QToolBar(this);
    // 设置停靠在左边
    addToolBar(Qt::LeftToolBarArea, tool_bar);

    // 设置只允许左右停靠
    tool_bar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea | Qt::TopToolBarArea);

    // 设置浮动
    tool_bar->setFloatable(false);

    // 设置移动(总开关)，默认为true，改为false之后工具栏就无法再动了
    tool_bar->setMovable(true);

    // 在toolbar中增加内容
    tool_bar->addAction(fm_ac1);
    tool_bar->addSeparator();
    tool_bar->addAction(fm_ac2);
    tool_bar->addSeparator();
    tool_bar->addAction("矩形");

    // 在toolbar中增加按钮控件
    QPushButton* btn = new QPushButton("hh", this);
    tool_bar->addWidget(btn);

    // 状态栏（最多有一个）
    QStatusBar* st_bar = statusBar();

    // 把状态栏放到窗口中
    setStatusBar(st_bar);

    // 放标签控件
    // 左侧提示的位置
    QLabel* label = new QLabel("Message", this);
    st_bar->addWidget(label);

    // 右侧提示的位置
    QLabel* label2 = new QLabel("right Message", this);
    st_bar->addPermanentWidget(label2);

    // 铆接部件（浮动窗口），可以有多个
    QDockWidget* dock = new QDockWidget("Dock", this);
    addDockWidget(Qt::BottomDockWidgetArea, dock);

    // dock停靠位置设置成上下
    dock->setAllowedAreas(Qt::BottomDockWidgetArea | Qt::TopDockWidgetArea);

    // 设置中心部件，只能有一个
    QTextEdit* edit = new QTextEdit(this);
    setCentralWidget(edit);

}

MainWindow::~MainWindow()
{
}

