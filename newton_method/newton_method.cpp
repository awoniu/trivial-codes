#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include <iomanip>
#include <functional>
template<class T>
inline const T SQR(const T a) {return a*a;}

template<typename M, typename V>
V lms(M& a, V& b)  //retrun x
{

    M a_tr = a.transpose();
    M a_in = (a_tr*a).inverse()*a_tr;
    V x = a_in*b;
    return x;
}

//void usrfun(Vec_I_DP &x, Vec_O_DP &fvec, Mat_O_DP &fjac)
template<typename M, typename V>
class NewTonM{
public:
    typedef std::function<bool(const V& x, M& jac, V& v)> UsrFunc;
    static V newton(V &init_v, int ntrial, double tolx, double tolf, UsrFunc func)
    {
        M jac;
        V func_v;
        V x = init_v;
        for(int i=0; i<ntrial; i++)
        {
            //std::cout << x << std::endl;
            func(x, jac, func_v);
            func_v = -1*func_v;
            //for(int i=0; i<func_v.size();i++) func_v[i] = -1*func_v[i];
            V theta_x = lms<M,V>(jac, func_v);
            x = x+theta_x;
        }
        //std::cout << x << std::endl;
        return x;
    }
};

// Driver for routine mnewt
bool usrfun(const Eigen::Vector4d &x, Eigen::Matrix4d &fjac, Eigen::Vector4d &fvec)
{
        int i;
        int n=x.size();
        fjac(0,0) = -2.0*x[0];
        fjac(0,1) = -2.0*x[1];
        fjac(0,2) = -2.0*x[2];
        fjac(0,3) = 1.0;
        for (i=0;i<n;i++) fjac(1,i) = 2.0*x[i];
        fjac(2,0) = 1.0;
        fjac(2,1) = -1.0;
        fjac(2,2) = 0.0;
        fjac(2,3) = 0.0;
        fjac(3,0) = 0.0;
        fjac(3,1) = 1.0;
        fjac(3,2) = -1.0;
        fjac(3,3) = 0.0;
        fvec[0] = -SQR(x[0])-SQR(x[1])-SQR(x[2])+x[3];
        fvec[1] = SQR(x[0])+SQR(x[1])+SQR(x[2])+SQR(x[3])-1.0;
        fvec[2] = x[0]-x[1];
        fvec[3] = x[1]-x[2];
}


int main()
{
    Eigen::Matrix4d a(4,4); a << 1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16 ;
    Eigen::Vector4d b;      b << 1,1,1,1;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    auto rr = lms(a,b);

    const int NTRIAL=5,N=4;
    const double TOLX=1.0e-6,TOLF=1.0e-6;
    Eigen::Vector4d x;

    std::cout << std::fixed << std::setprecision(6);
    for (int kk=0;kk<2;kk++) {
        for (int k=0;k<3;k++) {
        double xx=0.2001*k*(2*kk-1);
        std::cout << "Starting vector number " << (k+1) << std::endl << std::endl;
        for (int i=0;i<4;i++) {
            x[i]=xx+0.2*(i+1);
            std::cout << std::setw(7) << "x[" << i << "] = ";
            std::cout << std::setw(12) << x[i] << std::endl;
        }
        std::cout << std::endl;
        for (int j=0;j<NTRIAL;j++) {
            std::function<bool(const Eigen::Vector4d &x, Eigen::Matrix4d &fjac, Eigen::Vector4d &fvec)> f = usrfun;
            x = NewTonM<Eigen::Matrix4d, Eigen::Vector4d>::newton
            (x, 5, TOLX, TOLF, f);
            Eigen::Vector4d fvec;
            Eigen::Matrix4d fjac;
            usrfun(x,fjac,fvec);
            std::cout << std::setw(5) << "i" << std::setw(12) << "x[i]";
            std::cout << std::setw(14) << "f" << std::endl;
            for (int i=0;i<N;i++) {
            std::cout << std::setw(5) << i << std::setw(14) << x[i];
            std::cout << std::setw(15) << fvec[i] << std::endl;
            }
            //std::cout << std::endl << "press RETURN to continue..." << std::endl;
            //std::cin.get();
        }
        }
    }


    std::cout << x << std::endl;
    return 0;
}