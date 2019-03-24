#include "MenuBar.hpp"
#include <Loader.hpp>

void MenuBar::load(QString filename)
{
    filename.remove(0, 8);
    Loader().load(filename.toStdString());
}
