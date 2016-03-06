//Thobani Mabaso (212535063)

#include<iostream>
#include<string>

using namespace std;

class Fraction {
private:
	int num;                       //Numerator
	int den;                       //Denominator
	int gcf(int a, int b);         //Greatest common factor 
	int lcm(int a, int b);         //Lowwest common factor
	void print();                  //Convert a fraction to standard form
public:
	void set(int n, int d){
		num = n;
		den = d;
		print();
	}
	int get_num(){ return num; }
	int get_den(){ return den; }
	Fraction add(Fraction other);
	Fraction sub(Fraction other);
	Fraction mult(Fraction other);
	Fraction div(Fraction other);
};

int main(){
	Fraction frac1, frac2, frac3, frac4, frac5, frac6;

	frac1.set(3, 4);
	frac2.set(4, 8);

	frac3 = frac1.add(frac2);
	frac4 = frac1.sub(frac2);
	frac5 = frac1.mult(frac2);
	frac6 = frac1.div(frac2);

	cout << "3/4 + 4/8 = ";
	cout << frac3.get_num() << "/" << frac3.get_den()
		<< endl;
	cout << "3/4 - 4/8 = ";
	cout << frac4.get_num() << "/" << frac4.get_den()
		<< endl;
	cout << "3/4 * 4/8 = ";
	cout << frac5.get_num() << "/" << frac5.get_den()
		<< endl;
	cout << "3/4 / 4/8 = ";
	cout << frac6.get_num() << "/" << frac6.get_den()
		<< endl << endl;

	system("pause");
	return 0;
}

//Fractiion Class Functions

void Fraction::print(){
	if (den == 0 || num == 0){
		num = 0;
		den = 1;
	} // For a cases involving zero

	if (den < 0){
		num *= -1;
		den *= -1;
	} //when a negative sing is involve, put negative sign in numerator only

	int n = gcf(num, den);   // Factor out GCF from numerator and denominator
	num = num / n;
	den = den / n;
}

// Greatest common factor
int Fraction::gcf(int a, int b) {
	if (b == 0)
		return abs(a);
	else
		return gcf(b, a%b);
}
// Lowest Common Denominator
//
int Fraction::lcm(int a, int b){
	int n = gcf(a, b);
	return a / n * b;
}
Fraction Fraction::add(Fraction other) {
	Fraction fract;
	int lcd = lcm(den, other.den);
	int quot1 = lcd / den;
	int quot2 = lcd / other.den;
	fract.set(num * quot1 + other.num * quot2, lcd);
	return fract;
}

Fraction Fraction::sub(Fraction other) {
	Fraction fract;
	int lcd = lcm(den, other.den);
	int quot1 = lcd / den;
	int quot2 = lcd / other.den;
	fract.set(num * quot1 - other.num * quot2, lcd);
	return fract;
}

Fraction Fraction::div(Fraction other) {
	Fraction fract;
	int lcd = lcm(den, other.den);
	int quot1 = lcd / den;
	int quot2 = lcd / other.den;
	fract.set(num * quot1 / other.num * quot2, lcd);
	return fract;
}

Fraction Fraction::mult(Fraction other) {
	Fraction fract;
	fract.set(num * other.num, den * other.den);
	return fract;
}