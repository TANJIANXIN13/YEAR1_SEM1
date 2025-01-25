// Name: TAN JIAN XIN A24CS0303
// Name: SIVARAJ A/L SIVAKUAR A24CS0194

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
double calprice(int);

int main()
{
	int modelchoice, variantchoice, regionchoice, paintchoice, price;
	string model, variant, region, paint;
	char answer;
	
	do
	{
		cout << "Proton Car Loan Calculator" << endl << endl;
		do
		{
			cout << "Model [1-X50, 2-Exora, 3-Persona]: ";
			cin >> modelchoice;
			if (modelchoice == 1)
				model = "X50";
			else if (modelchoice == 2)
				model = "Exora";
			else if (modelchoice == 3)
				model = "Persona";
			else 
				cout << "Invalid. Please try again." << endl;
		} while ((modelchoice < 1) || (modelchoice > 3));
	
		do
		{
			cout << "Variants [1-1.6L Standard CVT, 2-1.6L Premium CVT]: ";
			cin >> variantchoice;
			if (variantchoice == 1)
				variant = "1.6L Standard CVT";
			else if (variantchoice == 2)
				variant = "1.6L Premium CVT";
			else 
				cout << "Invalid. Please try again." << endl;
		} while ((variantchoice < 1) || (variantchoice > 2));
	
		do
		{
			cout << "Region [1-Peninsular Malaysia, 2-East Malaysia]: ";
			cin >> regionchoice;
			if (regionchoice == 1)
				region = "Peninsular Malaysia";
			else if (regionchoice == 2)
				region = "East Malaysia";
			else 
				cout << "Invalid. Please try again." << endl;
		} while ((regionchoice < 1) || (regionchoice > 2));
	
		do
		{
			cout << "Paint type [1-Metallic, 2-Solid]: ";
			cin >> paintchoice;
			if (paintchoice == 1)
				paint = "Metallic";
			else if (paintchoice == 2)
				paint = "Solid";
			else 
				cout << "Invalid. Please try again." << endl;
		} while ((paintchoice < 1) || (paintchoice > 2));
	
		if ((modelchoice == 1) && (variantchoice == 1))
		{
			price = 86300;
			if (regionchoice == 2)
				price = price + 2000;
		}
		else if ((modelchoice == 1) && (variantchoice == 2))
		{
			price = 101800;
			if (regionchoice == 2)
				price = price + 2000;
		}
		else if ((modelchoice == 2) && (variantchoice == 1))
		{
			price = 59800;
			if (regionchoice == 2)
				price = price + 2000;
		}
		else if ((modelchoice == 2) && (variantchoice == 2))
		{
			price = 69800;
			if (regionchoice == 2)
				price = price + 2000;
		}
		else if ((modelchoice == 3) && (variantchoice == 1))
		{
			price = 47800;
			if (regionchoice == 2)
				price = price + 2000;
		}
		else if ((modelchoice == 3) && (variantchoice == 2))
		{
			price = 58300;	
			if (regionchoice == 2)
				price = price + 2000;
		}
		
		cout << endl;
		cout << "Car Info" << endl;
		cout << "Model: " << model << endl;
		cout << "Variant: " << variant << endl;
		cout << "Region: " << region << endl;
		cout << "Paint Type: " << paint << endl;
		cout << "Price (MYR): RM" << price << endl;
		
		calprice(price);
		
		cout << endl;
		cout << "Do you want to enter other data? [Y or N]: ";
		cin >> answer;
	} while ((answer == 'Y') || (answer == 'y'));
	
	cout << endl;
	cout << "Thank you :)" << endl;
	
	return 0;
}

double calprice(int price)
{
	double rate, downpay, interest, monthly, loan;
	int years, totalmonth;
	
	cout << endl;
	
	do
	{
		cout << "How many percentage for down payment (%): ";
		cin >> rate;
		if ((rate <= 0) || (rate >= 100))
			cout << "Invalid. Please try again." << endl;
	} while ((rate <= 0) || (rate >= 100));
	
	downpay = (rate / 100) * price;
	cout << "Down Payment (MYR): RM" << downpay << endl;
	
	do
	{
		cout << "Interest Rate (%): ";
		cin >> interest;
		if ((interest <= 0) || (interest >= 100))
			cout << "Invalid. Please try again." << endl;
	} while ((interest <= 0) || (interest >= 100));
	
	do
	{
		cout << "Repayment period (in years): ";
		cin >> years;
		if (years < 1)
			cout << "Invalid. Please try again." << endl;
	} while (years <= 0);
	
	interest = ((interest / 100) * years) + 1;
	loan = price - downpay;
	totalmonth = years * 12;
	monthly = (loan * interest) / totalmonth;
	
	cout << fixed << setprecision(2);
	cout << "MONTHLY INSTALLMENT (MYR): " << monthly << endl;
}
