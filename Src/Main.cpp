#include "WindowMain.h"

#if _MSC_VER && _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

int main(int argc, char* argv[])
{
#if _MSC_VER && _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

#if _DEBUG
    qputenv("QT_SCALE_FACTOR", "1");
#endif

    QApplication a(argc, argv);
    QGuiApplication::setAttribute(Qt::AA_DontCreateNativeWidgetSiblings);
    QGuiApplication::setFont(QFont(QFontDatabase().families()[219], 9));
    WindowMain w;
    w.show();
    return a.exec();
}
