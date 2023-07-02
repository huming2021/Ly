
#include<stdio.h>
#include <iostream>
#include <math.h>

namespace Ly
{
    template<class T> class LyPoint3d
    {
    public:
        T X, Y, Z;
        LyPoint3d();
        LyPoint3d(T a);
        LyPoint3d(T a, T b, T c);
        LyPoint3d(const LyPoint3d& s);
        LyPoint3d& operator= (const LyPoint3d<T>& s);
        LyPoint3d  operator+ (const LyPoint3d<T>& a);
        LyPoint3d  operator- (const LyPoint3d<T>& a);

        friend LyPoint3d<T> operator* (const LyPoint3d<T>& a, T r)
        {
            return LyPoint3d<T>(r * a.X, r * a.Y, r*a.Z);
        }
        friend LyPoint3d<T> operator* (T r, const LyPoint3d<T>& a)
        {
            return LyPoint3d<T>(r * a.X, r * a.Y, r*a.Z);
        }
        friend LyPoint3d<T> operator/ (const LyPoint3d<T>& a, T r)
        {
            return LyPoint3d<T>(a.X / r, a.Y / r, a.Z/r);
        }

        void Set(T a, T b, T c);
        ~LyPoint3d() {}
    };
}

namespace Ly
{
    template<class T> LyPoint3d<T>::LyPoint3d()
    {
        X = Y = Z = 0;
    }
    template<class T> LyPoint3d<T>::LyPoint3d(T a)
    {
        X = Y = Z = a;
    }
    template<class T> LyPoint3d<T>::LyPoint3d(T a, T b, T c)
    {
        X = a;
        Y = b;
        Z = c;
    }
    template<class T> LyPoint3d<T>::LyPoint3d(const LyPoint3d& s)
    {
        X = s.X;
        Y = s.Y;
        Z = s.Z;
    }
    template<class T> LyPoint3d<T>& LyPoint3d<T>::operator= (const LyPoint3d<T>& s)
    {
        if (this != &s)  //判断是否给同一个对象赋值
        {
            this->X = s.X;
            this->Y = s.Y;
            this->Z = s.Z;
        }
        return *this;       //返回当前对象
    }
    template<class T> LyPoint3d<T> LyPoint3d<T>::operator+ (const LyPoint3d<T>& a)
    {
        T x = this->X + a.X;
        T y = this->Y + a.Y;
        T z = this->Z + a.Z;
        return LyPoint3d(x, y, z);
    }
    template<class T> LyPoint3d<T> LyPoint3d<T>::operator- (const LyPoint3d<T>& a)
    {
        T x = this->X - a.X;
        T y = this->Y - a.Y;
        T z = this->Z - a.Z;
        return LyPoint3d(x, y, z);
    }
    template<class T> void LyPoint3d<T>::Set(T a, T b, T c)
    {
        this->X = a;
        this->Y = b;
        this->Z = c;
    }
}

namespace Ly
{
    template<class T> T dis(LyPoint3d<T>& a, LyPoint3d<T>& b)
    {
        T dx = a.X - b.X;
        T dy = a.Y - b.Y;
        T dz = a.Z - b.Z;
        return sqrt(dx*dx + dy*dy + dz*dz);
    }
}

namespace Ly
{
    template<size_t D, class T> class LyVec
    {
    public:
        T v[D];
        LyVec()
        {
            for(size_t i = 0; i < D; i++){v[i] = 0;}
        }
        LyVec(T a)
        {
            for(size_t i = 0; i < D; i++){v[i] = a;}
        }
        size_t GetNum()
        {
            return D;
        }
        ~LyVec()
        {

        }
    };
}

int main()
{
    Ly::LyPoint3d<double> a(1.0, 2.0, 3.0);
    Ly::LyPoint3d<float> b(1.0f, 2.0f, 3.0f);
    Ly::LyPoint3d<int> c(1, 2, 3);
    Ly::LyPoint3d<double> e(a);
    Ly::LyPoint3d<double> f = a;
    Ly::LyPoint3d<double> d = 0.5*a + 2.0*e + f/3.0;
    std::cout << d.X << " " << d.Y << " " << d.Z << std::endl;

    typedef Ly::LyPoint3d<double> point;
    point P0(1.0, 2.3, 3.4);
    point P1(2.3, 3.5, 4.7);
    std::cout << dis(P0, P0) << std::endl;
    std::cout << dis(P0, P1) << std::endl;

    Ly::LyVec<2, double> A(1.0);
    typedef Ly::LyVec<3, int> vec;
    vec B;
    std::cout << A.GetNum() << std::endl;
    std::cout << A.v[0] << " " << A.v[1] << " " << std::endl;
}
