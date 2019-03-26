#include "MenuBar.hpp"

#include <Loader.hpp>

void MenuBar::load(QString filename)
{
    filename.remove(0, 8);
    Loader().load(filename.toStdString());
    last_filename = filename;
    emit filename_changed();
    emit refresh_after_load();
}

QString MenuBar::get_filename() const noexcept
{
    return last_filename;
}
