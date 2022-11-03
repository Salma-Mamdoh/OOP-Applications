#include <bits/stdc++.h>
#include <functional>

using namespace std;

class Function
{   
public:
    virtual double evaluationAt(double num) = 0;
};

class SimpleFunction :public Function
{
private:
    function <double(double)> fun;
public:
    double evaluationAt(double num)
    {
        return fun(num);
    }
    SimpleFunction(function <double(double)> fun)
    {
        this->fun = fun;
    }
};
class DerivativeFunction : public Function
{
private:
    function <double(double)> fun;
    double deltax;
public:
    DerivativeFunction(function <double(double)> fun , double deltax)
    {
        this -> fun = fun;
        this -> deltax = deltax;
    }
    double evaluationAt(double num)
    {
        double result = (fun(num + deltax) - fun(num-deltax))/(2*deltax);
        return result;
    }
};

class CompositionFunction : public Function
{
private:
    function <double(double)> f;
    function <double(double)> G;
public:
    CompositionFunction(function <double(double)> f,function <double(double)> G)
    {
        this -> f = f;
        this -> G = G;
    }
    double evaluationAt(double num)
    {
        return f(G(num));
    }
};

double cube (double n) {
    return n * n * n;
}
double second (double d) {
    return d * d - 5 * d - 4;
}
double fun (double d) {
    return d * d - 3 * d - 4;
}


int main()
{
SimpleFunction f1([](double n) -> double {return n * n;});
 cout << f1.evaluationAt(5) << endl;
 DerivativeFunction f2 (second, 5); 
 cout << f2.evaluationAt(5) << endl;
 
 CompositionFunction f3 (fun, cube);
 cout << f3.evaluationAt(5) << endl;
 return 0;

}