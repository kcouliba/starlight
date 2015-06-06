#include "../include/Window.hpp"

Window::Window(t_uint const w, t_uint const h)
    : _width(w), _height(h), _resolution(w / h)
{
    std::cout << "Window set : " << this->getWidth() << " wide"
        << " and " << this->getHeight() << "height"
        << std::endl;
    return ;
}

Window::Window(Window const & ref)
{
    *this = ref;
    return ;
}

Window::~Window()
{
    std::cout << "Window destroyed." << std::endl;
    return ;
}

void        Window::setWidth(t_uint val)
{
    this->_width = val;
}

void        Window::setHeight(t_uint val)
{
    this->_height = val;
}

t_uint      Window::getWidth(void) const
{
    return (this->_width);
}

t_uint      Window::getHeight(void) const
{
    return (this->_height);
}

std::ostream &  operator<<(std::ostream & o, Window const & win)
{
    o << "This window is " << win.getWidth() << " wide"
        << " and " << win.getHeight() << " height.";
    return (o);
}
