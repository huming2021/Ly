
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
        LyPoint3d  operator* (T r);    
        LyPoint3d  operator/ (T r);

        // friend LyPoint3d<T> operator* (T r, const LyPoint3d<T>& a)
        // {
        //     return LyPoint3d<T>(r * a.X, r * a.Y, r*a.Z);
        // }

        void Set(T a, T b, T c);
        ~LyPoint3d() {}
    };
}