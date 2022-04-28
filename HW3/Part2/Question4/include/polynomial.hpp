//polynomial.hpp
#include <polynomial.h>
#include <cstdlib>

void Polynomial::NewTerm(const double &in_coef, const int &in_exp){
    Term new_term(in_coef, in_exp);
    term_list.InsertBack(new_term);
    terms++;
}

const Polynomial& Polynomial::operator=(const Polynomial &b){
    terms               = b.terms;
    max_exp             = b.max_exp;
    input_at_least_once = b.input_at_least_once;
    term_list           = b.term_list;
    std::cout<<"> Operator=() of Polynomial is called."<<std::endl;

    return *this;
}

Polynomial Polynomial::operator+(const Polynomial &b){
    if(terms == 0 && b.terms == 0){
        throw std::runtime_error(std::string("Warning: all the input Polynomial of operator+() are empty."));
    }

    Polynomial c(0, "temp_result");
    CircularHeaderList<Term>::Iterator aPos = term_list.Begin();
    CircularHeaderList<Term>::Iterator bPos = b.term_list.Begin();

    //Reset c to remove 0 term because of the default constructor.
    if(c.terms > 0){
        c.DeleteAll();
    }

    //Begin the algorithm
    while((aPos!=term_list.End()) && (bPos!=b.term_list.End())){
        if((*aPos).exp == (*bPos).exp){
            double t = (*aPos).coef + (*bPos).coef;
            c.NewTerm(t, (*aPos).exp);
            aPos++;
            bPos++;
        }else if((*aPos).exp < (*bPos).exp){
            c.NewTerm((*bPos).coef, (*bPos).exp);
            bPos++;
        }else{
            c.NewTerm((*aPos).coef, (*aPos).exp);
            aPos++;
        }
    }

    for(CircularHeaderList<Term>::Iterator i=aPos; i != term_list.End(); i++){
        c.NewTerm((*i).coef, (*i).exp);
    }

    for(CircularHeaderList<Term>::Iterator i=bPos; i != b.term_list.End(); i++){
        c.NewTerm((*i).coef, (*i).exp);
    }

    try {c.FindLeadExp();}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    return c;
}

Polynomial Polynomial::operator-(const Polynomial &b){
    if(terms == 0 && b.terms == 0){
        throw std::runtime_error(std::string("Warning: all the input Polynomial of operator+() are empty."));
    }

    Polynomial c(0, "temp_result");
    Polynomial inverse_b(0, "temp_neg_b_result");

    for(CircularHeaderList<Term>::Iterator i=b.term_list.Begin(); i != b.term_list.End(); i++){
        inverse_b.NewTerm(((*i).coef)*(-1), (*i).exp);
    }

    //Reset c to remove 0 term because of the default constructor.
    if(c.terms > 0){
        c.DeleteAll();
    }

    //Begin the algorithm
    c = (*this)+inverse_b;

    return c;
}

void Polynomial::FindLeadExp(){
    int tmp;

    if(terms == 0){
        throw std::runtime_error(std::string("Warning: Not available. The Polynomial is empty."));
        //exit(0);
    }

    for(CircularHeaderList<Term>::Iterator i=term_list.Begin(); i != term_list.End(); i++){
        if(i==term_list.Begin()){
            tmp = (*i).exp;
        }else{
            if(tmp < (*i).exp){
                tmp = (*i).exp;
            }
        }
    }

    max_exp = tmp;
}

bool Polynomial::SortFunction(const Term &a, const Term &b){
    return (a.exp > b.exp);
}

Polynomial Polynomial::operator*(const Polynomial &b){
    if(terms == 0 && b.terms == 0){
        throw std::runtime_error(std::string("Warning: all the input Polynomial of Mult() are empty."));
    }

    int count_i = 0;
    Polynomial c(0, "temp_result");
    std::unordered_map<int, int> map_exp2pos; //to record the exp stored in which position in c

    //Reset c to remove 0 term because of the default constructor.
    if(c.terms > 0){
        c.DeleteAll();
    }

    for(CircularHeaderList<Term>::Iterator i=term_list.Begin(); i != term_list.End(); i++){
        for(CircularHeaderList<Term>::Iterator j=b.term_list.Begin(); j != b.term_list.End(); j++){
            int    exp_result   = (*i).exp  + (*j).exp;
            double  coef_result = (*i).coef * (*j).coef;

            if(map_exp2pos.find(exp_result) == map_exp2pos.end()){//not found
                map_exp2pos[exp_result] = c.terms;
                c.NewTerm(coef_result, exp_result);
            }else{
                c.term_list.Get(map_exp2pos[exp_result]+1)->data.coef += coef_result;
            }
        }
    }

    //Do the sorting
    Term *term_array = new Term[c.terms];
    for(CircularHeaderList<Term>::Iterator i=c.term_list.Begin(); i != c.term_list.End(); i++){
        term_array[count_i] = *i;
        count_i++;
    }

    std::sort(term_array, term_array+c.terms, c.SortFunction);

    count_i = 0;
    for(CircularHeaderList<Term>::Iterator i=c.term_list.Begin(); i != c.term_list.End(); i++){
        *i = term_array[count_i];
        count_i++;
    }

    try {c.FindLeadExp();}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    delete [] term_array;
    term_array = NULL;

    return c;
}

double Polynomial::Evaluate(double x) const {
    if(terms == 0){
        throw std::runtime_error(std::string("Warning: Not available. The Polynomial is empty."));
    }

    double tmp_sum = 0;
    for(CircularHeaderList<Term>::Iterator i=term_list.Begin(); i != term_list.End(); i++){
        int pow_term = (*i).exp;
        tmp_sum += (*i).coef*pow(x, (double)pow_term);
    }

    return tmp_sum;
}

