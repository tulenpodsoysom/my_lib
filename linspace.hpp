#include <vector>

class discrete_linspace : public std::vector<double>
{
    double l_bound, r_bound;
public: 
    using std::vector<double>::operator[];

    discrete_linspace() {}
    void create_bound_dependent(double l, double r, size_t divisions) 
    { 
        this->resize(divisions); 
        for (size_t i = 0; i < this->size(); i++)
        {
            (*this)[i] = l + (r-l) * i / (double)divisions; 
        }
        l_bound = l;
        r_bound = r;
    }
    void create_width_dependent(double l,double width, size_t divisions)
    {
        this->resize(divisions);
        for (size_t i = 0; i < this->size(); i++)
        {
            (*this)[i] = l + width * i / (double)divisions; 
        }
        l_bound = l;
        r_bound = l + width;
    }
    double left_bound() {return l_bound;}
    double right_bound() {return r_bound;}
};

