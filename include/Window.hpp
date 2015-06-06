#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "starlight.hpp"

class Window
{
    public:
        Window(t_uint const w, t_uint const h);
        Window(Window const & ref);
        virtual ~Window();

        unsigned int getWidth() const;
        unsigned int getHeight() const;

        void setWidth(t_uint const val);
        void setHeight(t_uint const val);

    protected:
    private:
        t_uint  _width;
        t_uint  _height;
        float   _resolution;
};

std::ostream &  operator<<(std::ostream & o, const Window & win);

#endif // WINDOW_HPP
