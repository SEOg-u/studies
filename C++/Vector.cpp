#include <iostream>
using namespace std;

class CVector
{
private:
  double _x, _y, _z;
public:
  CVector(double x, double y, double z);
  void print() const;
  CVector operator + (CVector& v);
  CVector operator - ();
  // CVector operator * (CVector& v);
  // CVector operator / (CVector& v);
};

CVector::CVector(double x, double y, double z) :_x(x), _y(y), _z(z) {}

void CVector::print() const
{
  std::cout << "[x : " << _x << ", y : " << _y << ", z : " << _z << " ]" << std::endl;
}

// +
CVector CVector::operator + (CVector& t)
{
  CVector result(_x + t._x, _y + t._y, _z + t._z);

  return result;
}
// -
CVector CVector::operator - ()
{
  CVector result(-_x, -_y, -_z);

  return result;
}

int main() {
  CVector v0 {0, 1, 2};
  CVector v1 {1, 2, 3};

  cout << "v0 : ";
  v0.print();
  cout << "v1 : ";
  v1.print();

  const CVector v2 = v0 + v1;
  cout << "v2 : ";
  v2.print();

  const CVector v3 = -v1;
  cout << "v3 : ";
  v3.print();

  return 0;
}
