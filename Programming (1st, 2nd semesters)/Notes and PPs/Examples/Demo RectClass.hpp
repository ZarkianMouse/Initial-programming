#ifndef RECTCLASS_HPP_INCLUDED
#define RECTCLASS_HPP_INCLUDED

// Rectangle class declaration.

class Rectangle {
  private:
    double width;
    double length;
  public:
    void setWidth(double);
    void setLength(double);
    double getWidth() const;
    double getLength() const;
    double getArea() const;
};

#endif // RECTCLASS_HPP_INCLUDED
