//Point2d.h
#ifndef CHAOS_GEOMETRY_INCLUDE_CONCEPTION2D_H
#define CHAOS_GEOMETRY_INCLUDE_CONCEPTION2D_H

namespace chaos {

namespace geo {

template<typename T>
class Conception2d {
public:
  ~Conception2d() { }
  Conception2d() : a(0), b(0), c(1) { }

  Conception2d(const Conception2d& p)
    : a(p.x()), b(p.y()), c(p.z()) { }

  Conception2d(const T t1, const T t2)
    : a(t1), b(t2), c(1) { }

  Conception2d(const T t1, const T t2, const T t3)
    : a(t1), b(t2), c(t3) { }

public:
  Conception2d<T>& operator=(const Conception2d<T>& p){

    if(this == &p)return *this;

    this->a = p.x();
    this->b = p.y();
    this->c = p.z();
    return *this;
  }

  inline T x() const { return a; }
  inline T& x() { return a; }

  inline T y() const { return b; }
  inline T& y() { return b; }

  inline T z() const { return c; }
  inline T& z() { return c; }

private:
  T a;
  T b;
  T c;
};

typedef Conception2d<int>    Point2i;
typedef Conception2d<float>    Point2f;
typedef Conception2d<double>    point2d;

//typedef Conception2d<int>    Line2i;
typedef Conception2d<float>   Line2f;
//typedef Conception2d<double>    Line2d;

}  //namespace geo

}  //namespace chaos

#endif