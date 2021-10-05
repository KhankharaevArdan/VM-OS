#include "complex.h"
#include <fstream>
#include <string>
#include <iomanip>

const double ACCURACY = 0.00001;

void test_complex ();
int test_checker (const ComplexNumber &number3, const ComplexNumber &test_result);
int test_checker_double (double number1_abs, double test_result_double);

int main ()
{
    test_complex ();
    return 0;
}

void test_complex ()
{
    ComplexNumber number1;
    ComplexNumber number2;
    ComplexNumber number3;
    ComplexNumber test_result;
    double test_result_double;
    std::string input_name = "input.txt";
    std::string output_name = "output.txt";
    std::fstream fin;
    std::fstream fout;
    fin.open (input_name, std::fstream::in);
    fout.open (output_name, std::fstream::out | std::fstream::app);

    if (!fin.is_open ())
    {
        std::cout << input_name << "open error" << std::endl;
    }
    else
    {
        std::cout << input_name << " opened" << std::endl;
    }

    if (!fout.is_open ())
    {
        std::cout << output_name << "open error" << std::endl;
    }
    else
    {
        std::cout << output_name << " opened" << std::endl;
    }

    int test_number = 0;
    while (!fin.eof())
    {
        test_number++;
        fin >> number1;
        fin >> number2;
        fin >> test_result;
        number3 = number1;
        if (test_checker (number3, test_result) == 0)
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl = compl' result: " << number3 << std::endl;
        }
        fin >> test_result;
        number3 = number1 + number2;
        if (test_checker (number3, test_result) == 0)
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl + compl' result: " << number3 << std::endl;
        }
        fin >> test_result;
        number3 = number1 - number2;
        if (test_checker (number3, test_result) == 0)
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl - compl' result: " << number3 << std::endl;
        }
        fin >> test_result;
        number3 = number1 * number2;
        if (test_checker (number3, test_result) == 0)
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl * compl' result: " << number3 << std::endl;
        }
        fin >> test_result;
        number3 = number1 / number2;
        if (test_checker (number3, test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl / compl' result: " << number3 << std::endl;
        }
        fin >> test_result_double;
        if (test_checker_double (number1.abs (), test_result_double) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    method 'abs' result: " << number1.abs () << std::endl;
        }
        fin >> test_result_double;
        if (test_checker_double (number1.Re (), test_result_double) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    method 'Re' result: " << number1.Re () << std::endl;
        }
        fin >> test_result_double;
        if (test_checker_double (number1.Im (), test_result_double) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    method 'Im' result: " << number1.Im () << std::endl;
        }
        fin >> test_result_double;
        if (test_checker_double (number1.arg (), test_result_double) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    method 'arg' result: " << number1.arg () << std::endl;
        }
        fin >> test_result;
        if (test_checker (number1.complex_pow (4), test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    method 'complex_pow' result: " << number1.complex_pow (4) << std::endl;
        }
        fin >> test_result;
        number3 = number1 + number2.re;
        if (test_checker (number3, test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl + double' result: " << number3 << std::endl;
        }
        fin >> test_result;
        number3 = number1 * number2.re;
        if (test_checker (number3, test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl * double' result: " << number3 << std::endl;
        }
        fin >> test_result;
        number3 = number2.re + number1;
        if (test_checker (number3, test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    operator 'double + compl' result: " << number3 << std::endl;
        }
        fin >> test_result;
        number3 = number2.re * number1;
        if (test_checker (number3, test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    operator 'double * compl' result: " << number3 << std::endl;
        }
        fin >> test_result;
        number3 = number1;
        number1 += number2;
        if (test_checker (number1, test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl += compl' result: " << number1 << std::endl;
        }
        fin >> test_result;
        number1 = number3;
        number1 *= number2;
        if (test_checker (number1, test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl *= compl' result: " << number1 << std::endl;
        }
        fin >> test_result;
        number1 = number3;
        number1 += number2.re;
        if (test_checker (number1, test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl += double' result: " << number1 << std::endl;
        }
        fin >> test_result;
        number1 = number3;
        number1 *= number2.re;
        if (test_checker (number1, test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    operator 'compl *= double' result: " << number1 << std::endl;
        }
        fin >> test_result;
        number1 = -number3;
        if (test_checker (number1, test_result) == 0)    
        {
            fout << "NO " << "test № " << test_number << "    operator ' -compl' result: " << number1 << std::endl;
        }
    }
    fout.close();
    fin.close();
}

int test_checker (const ComplexNumber &number3, const ComplexNumber &test_result)
{
    if (sqrt ((number3.re - test_result.re) * (number3.re - test_result.re) + (number3.im - test_result.im) * (number3.im - test_result.im)) < ACCURACY)
        return 1;
    else 
        return 0;
}

int test_checker_double (double number1_abs, double test_result_double)
{
    if (abs(number1_abs - test_result_double) < ACCURACY)
        return 1;
    else 
        return 0;
}