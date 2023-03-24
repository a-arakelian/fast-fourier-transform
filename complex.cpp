#pragma once
#include <cmath>
#include <iostream>


class Complex
{
protected:
	//   Internal presentation - real and imaginary parts
	double m_re;
	double m_im;

public:
	//   Constructors
	Complex(): m_re(0.), m_im(0.) {}
	Complex(double re, double im): m_re(re), m_im(im) {}
	Complex(double val): m_re(val), m_im(0.) {}

	//   Assignment
	Complex& operator= (const double val)
	{
		m_re = val;
		m_im = 0.;
		return *this;
	}

	//   Basic operations - taking parts
	double re() const { return m_re; }
	double im() const { return m_im; }

    operator double() const { return m_re; }

	//   Conjugate number
	Complex conjugate() const
	{
		return Complex(m_re, -m_im);
	}

	//   Norm   
	double norm() const
	{
		return m_re * m_re + m_im * m_im;
	}

	//   Arithmetic operations
	Complex operator+ (const Complex& other) const
	{
		return Complex(m_re + other.m_re, m_im + other.m_im);
	}

	Complex operator- (const Complex& other) const
	{
		return Complex(m_re - other.m_re, m_im - other.m_im);
	}

	Complex operator* (const Complex& other) const
	{
		return Complex(m_re * other.m_re - m_im * other.m_im,
			m_re * other.m_im + m_im * other.m_re);
	}

	Complex operator/ (const Complex& other) const
	{
		const double denominator = other.m_re * other.m_re + other.m_im * other.m_im;
		return Complex((m_re * other.m_re + m_im * other.m_im) / denominator,
			(m_im * other.m_re - m_re * other.m_im) / denominator);
	}

	Complex& operator+= (const Complex& other)
	{
		m_re += other.m_re;
		m_im += other.m_im;
		return *this;
	}

	Complex& operator-= (const Complex& other)
	{
		m_re -= other.m_re;
		m_im -= other.m_im;
		return *this;
	}

	Complex& operator*= (const Complex& other)
	{
		const double temp = m_re;
		m_re = m_re * other.m_re - m_im * other.m_im;
		m_im = m_im * other.m_re + temp * other.m_im;
		return *this;
	}

	Complex& operator/= (const Complex& other)
	{
		const double denominator = other.m_re * other.m_re + other.m_im * other.m_im;
		const double temp = m_re;
		m_re = (m_re * other.m_re + m_im * other.m_im) / denominator;
		m_im = (m_im * other.m_re - temp * other.m_im) / denominator;
		return *this;
	}

	Complex& operator++ ()
	{
		++m_re;
		return *this;
	}

	Complex operator++ (int)
	{
		Complex temp(*this);
		++m_re;
		return temp;
	}

	Complex& operator-- ()
	{
		--m_re;
		return *this;
	}

	Complex operator-- (int)
	{
		Complex temp(*this);
		--m_re;
		return temp;
	}

	Complex operator+ (const double val) const
	{
		return Complex(m_re + val, m_im);
	}

	Complex operator- (const double val) const
	{
		return Complex(m_re - val, m_im);
	}

	Complex operator* (const double val) const
	{
		return Complex(m_re * val, m_im * val);
	}

	Complex operator/ (const double val) const
	{
		return Complex(m_re / val, m_im / val);
	}

	Complex& operator+= (const double val)
	{
		m_re += val;
		return *this;
	}

	Complex& operator-= (const double val)
	{
		m_re -= val;
		return *this;
	}

	Complex& operator*= (const double val)
	{
		m_re *= val;
		m_im *= val;
		return *this;
	}

	Complex& operator/= (const double val)
	{
		m_re /= val;
		m_im /= val;
		return *this;
	}

	friend Complex operator+ (const double left, const Complex& right)
	{
		return Complex(left + right.m_re, right.m_im);
	}

	friend Complex operator- (const double left, const Complex& right)
	{
		return Complex(left - right.m_re, -right.m_im);
	}

	friend Complex operator* (const double left, const Complex& right)
	{
		return Complex(left * right.m_re, left * right.m_im);
	}

	friend Complex operator/ (const double left, const Complex& right)
	{
		const double denominator = right.m_re * right.m_re + right.m_im * right.m_im;
		return Complex(left * right.m_re / denominator,
			-left * right.m_im / denominator);
	}

	//   Boolean operators
	bool operator== (const Complex &other) const
	{
		return m_re == other.m_re && m_im == other.m_im;
	}

	bool operator!= (const Complex &other) const
	{
		return m_re != other.m_re || m_im != other.m_im;
	}

	bool operator== (const double val) const
	{
		return m_re == val && m_im == 0.;
	}

	bool operator!= (const double val) const
	{
		return m_re != val || m_im != 0.;
	}

	friend bool operator== (const double left, const Complex& right)
	{
		return left == right.m_re && right.m_im == 0.;
	}

	friend bool operator!= (const double left, const Complex& right)
	{
		return left != right.m_re || right.m_im != 0.;
	}
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	double r = c.re();
    double i = c.im();
	double x = std::round(r * std::pow(10, 2)) / std::pow(10, 2);
	double y = std::round(i * std::pow(10, 2)) / std::pow(10, 2);
    os << x << " + " << y << "i";
    return os;
}


double cexp(double x) { return std::exp(x); }
Complex cexp(Complex x) {
    double re = x.re();
    double im = x.im();
    Complex exp_x(std::cos(im), std::sin(im));
    return exp_x *= std::exp(re);
}


