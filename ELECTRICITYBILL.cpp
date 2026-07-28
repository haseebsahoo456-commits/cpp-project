#include <iostream>
#include <string>
#include <iomanip>

using namespace std;






void registerCustomer(string &customerName , int &customerId , string &customerType , int &meterOption);

void displayMenu();

double calcEctricityCharges(int unitsConsumed , double slabRates[]);

double calcGST(double amount);

double calcIncomeTax(double amount , string customerType);

double calcElectricityDuty(double consumptionCharges);

double calcMeterRent(int meterOption);

double calcFixedCharges(int unitsConsumed);

void displayFinalBill(string customerName , int customerId , string customerType , int unitsConsumed , 
                      double consumptionCharges , double ElectricityDuty ,double MeterRent , double FixedCharges , 
					  double GST , double IncomeTax , double TotalBill );
					  
double calcNewConnectionCharges(char connectionChoice , bool &properConnection , string customerType , int meterOption ,
                                double &additionalCharges );

void displayNewConnection(string customerName , string customerType ,  int customerId , char connectionChoice , 
                          double additionalCharges , double NewConnecCharges , bool properConnection );
                          
void displayCustomerDetails(string customerName , int customerId , string customerType , int meterOption);






int main(){
    string customerName , customerType;
    int customerId , meterOption , choice ;	
    
    double slabRates[8] = { 12.21 , 14.53 , 31.51 , 38.41 , 41.62 , 43.04 , 44.18 , 49.10};
    
    registerCustomer(customerName , customerId , customerType , meterOption);
    
do{    	
    displayMenu();	
    cin >> choice;
    cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
    
    if( choice == 1 )
	{
            int unitsConsumed;

            cout << "\n\t\tEnter Units Consumed: ";
            cin >> unitsConsumed;

            double consumptionCharges , GST , IncomeTax , ElectricityDuty , MeterRent , FixedCharges , SubTotal , TotalBill ;
            
			consumptionCharges = calcEctricityCharges(unitsConsumed , slabRates);
            ElectricityDuty    = calcElectricityDuty(consumptionCharges);
            MeterRent          = calcMeterRent(meterOption);
            FixedCharges       = calcFixedCharges(unitsConsumed);
            
        SubTotal = consumptionCharges + ElectricityDuty + FixedCharges + MeterRent + 35 ;
        
		    GST       = calcGST(SubTotal);
            IncomeTax = calcIncomeTax(SubTotal , customerType);
            
        TotalBill = SubTotal + GST + IncomeTax;
        
        displayFinalBill(customerName , customerId , customerType , unitsConsumed ,consumptionCharges , ElectricityDuty , 
		                 MeterRent , FixedCharges , GST , IncomeTax , TotalBill );    
	}
	else if( choice == 2 )
	{
		char connectionChoice;
		bool properConnection = false;
	    double additionalCharges ;
	    double NewConnecCharges = calcNewConnectionCharges(connectionChoice , properConnection , customerType , meterOption ,
                                  additionalCharges );

        displayNewConnection(customerName , customerType ,  customerId , connectionChoice , additionalCharges , 
		                     NewConnecCharges ,properConnection );
	
	}
	else if(choice == 3)
	{
		displayCustomerDetails(customerName , customerId , customerType , meterOption);
	}
	else if(choice == 4)
	{
		cout << "\n\t\t\t\t            >>>Program Exited Successfully<<<" << endl;
		    cout << "\n\n========================================================================================================================";
	}
	else{
		cout << "\n\t\t\t\t        >>>Invalid Choice. Please Try Again<<<" << endl ;
	}
}while(choice != 4);
	return 0;
    
}






void registerCustomer(string &customerName, int &customerId, string &customerType, int &meterOption)
{	
    int customerChoice;
    
	cout << "================================================ CUSTOMER REGISTRATION ================================================" << endl ;

    cout << "\n\tEnter Customer Name: ";
    cin >> customerName ;

    cout << "\tEnter Customer ID: ";
    cin >> customerId;

    

    cout << "\n\tSelect Customer Type" << endl ;
    cout << "\t1. Household" << endl ;
    cout << "\t2. Commercial" << endl ;
    cout << "\n\t\tEnter Choice: ";
    cin >> customerChoice;
    cout << "\t----------------------------------------------------------------------------------------------------"<<endl;

    if (customerChoice == 1)
    {
        customerType = "Household";
    }
    else
    {
        customerType = "Commercial";
    }

    cout << "\n\tMeter Option" << endl ;
    cout << "\t1. First Meter" << endl ;
    cout << "\t2. Second Meter" << endl ;
    cout << "\n\t\tEnter Choice: ";
    cin >> meterOption;
    cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
    cout << "\n\t\t\t\t\t>>>Customer Registered Successfully<<<\n";
	
}


void displayMenu()
{
    cout << "\n\n=================================================== LESCO MAIN MENU ===================================================" << endl ;

    cout << "\n\t1. Calculate Monthly Electricity Bill" << endl ;
    cout << "\t2. Apply for New Electricity Connection" << endl ;
    cout << "\t3. View Customer Details" << endl ;
    cout << "\t4. Exit Program" << endl ;

    cout << "\n\t\tEnter Your Choice: ";
}


double calcEctricityCharges(int unitsConsumed , double slabRates[])
{
    double charges = 0;

    if (unitsConsumed <= 100)
    {
        charges = unitsConsumed * slabRates[0];
    }
    else if (unitsConsumed <= 200)
    {
        charges = (100 * slabRates[0]) +  
			      ((unitsConsumed - 100) * slabRates[1]);
    }
    else if (unitsConsumed <= 300)
    {
        charges = (100 * slabRates[0]) + 
			      (100 * slabRates[1]) + 
			      ((unitsConsumed - 200) * slabRates[2]);
    }
    else if (unitsConsumed <= 400)
    {
        charges = (100 * slabRates[0]) +
                  (100 * slabRates[1]) +
                  (100 * slabRates[2]) +
                  ((unitsConsumed - 300) * slabRates[3]);
    }
    else if (unitsConsumed <= 500)
    {
        charges = (100 * slabRates[0]) +
                  (100 * slabRates[1]) +
                  (100 * slabRates[2]) +
                  (100 * slabRates[3]) +
                  ((unitsConsumed - 400) * slabRates[4]);
    }
    else if (unitsConsumed <= 600)
    {
        charges = (100 * slabRates[0]) +
                  (100 * slabRates[1]) +
                  (100 * slabRates[2]) +
                  (100 * slabRates[3]) +
                  (100 * slabRates[4]) +
                  ((unitsConsumed - 500) * slabRates[5]);
    }
    else if (unitsConsumed <= 700)
    {
        charges = (100 * slabRates[0]) +
                  (100 * slabRates[1]) +
                  (100 * slabRates[2]) +
                  (100 * slabRates[3]) +
                  (100 * slabRates[4]) +
                  (100 * slabRates[5]) +
                  ((unitsConsumed - 600) * slabRates[6]);
    }
    else
    {
        charges = (100 * slabRates[0]) +
                  (100 * slabRates[1]) +
                  (100 * slabRates[2]) +
                  (100 * slabRates[3]) +
                  (100 * slabRates[4]) +
                  (100 * slabRates[5]) +
                  (100 * slabRates[6]) +
                  ((unitsConsumed - 700) * slabRates[7]);
    }

    return charges;
}


double calcGST(double amount)
{
    return amount * 0.18;
}

double calcIncomeTax(double amount , string customerType)
{
    if (customerType == "Household")
    {
        return amount * 0.10;
    }
    else
    {
        return amount * 0.15;
    }
}


double calcElectricityDuty(double consumptionCharges)
{
    return consumptionCharges * 0.015;
}


double calcMeterRent(int meterOption)
{
	if(meterOption==1){
		return 250;
	}
	else {
		return 250*2;
	}
}


double calcFixedCharges(int unitsConsumed)
{
    if (unitsConsumed >= 301 && unitsConsumed <= 400)
    {
        return 200;
    }
    else if (unitsConsumed >= 401 && unitsConsumed <= 500)
    {
        return 400;
    }
    else if (unitsConsumed >= 501 && unitsConsumed <= 600)
    {
        return 600;
    }
    else if (unitsConsumed >= 601 && unitsConsumed <= 700)
    {
        return 800;
    }
    else if (unitsConsumed > 700)
    {
        return 1000;
    }
    else
    {
        return 0;
    }
}


void displayFinalBill(string customerName , int customerId , string customerType , int unitsConsumed , 
                      double consumptionCharges , double ElectricityDuty ,double MeterRent , double FixedCharges , 
					  double GST , double IncomeTax , double TotalBill )
{
    cout << fixed << setprecision(2);

    cout << "\n\n================================================ LESCO ELECTRICITY BILL ================================================" << endl;

    cout << "\n\tCustomer Name: " << customerName << endl;

    cout << "\tCustomer ID: " << customerId << endl;

    cout << "\tCustomer Type: " << customerType << endl;

    cout << "\tUnits Consumed: " << unitsConsumed << endl;

    cout << "\n\tElectricity Consumption Charges: Rs. " << consumptionCharges << endl;

    cout << "\tElectricity Duty: Rs. " << ElectricityDuty << endl;

    cout << "\tFixed Charges: Rs. " << FixedCharges << endl;

    cout << "\tMeter Rent: Rs."<< MeterRent << endl;

    cout << "\tTV Fee: Rs. 35.00" << endl;

    cout << "\tGST: Rs. " << GST << endl;

    cout << "\tIncome Tax: Rs. " << IncomeTax << endl;

    cout << "\n\tTotal Payable Bill: Rs. " << TotalBill << endl;

    cout << "\n========================================================================================================================\n";
}


double calcNewConnectionCharges(char connectionChoice , bool &properConnection , string customerType , int meterOption ,
                                double &additionalCharges )
{
    cout << "\n\tDo you want a proper new connection? (Y/N): ";
    cin >> connectionChoice;

    if (connectionChoice == 'Y' || connectionChoice == 'y')
    {
        properConnection = true;
    }
	
	double meterCost    = 14000 ,
           cableCost    = 4000 ,
           securityCost = 3500 ;
    double totalCharges;

    if (customerType == "Household")
	{
        if (meterOption == 1)
        {
            additionalCharges = 2500;
        }
        else
        {
            additionalCharges = 5000;
        }
    }
    else
    {
        if (meterOption == 1)
        {
            additionalCharges = 35000;
        }
        else
        {
            additionalCharges = 70000;
        }
    }
    
    totalCharges = meterCost + cableCost + securityCost + additionalCharges;

    if (properConnection == true)
    {
        totalCharges = totalCharges + 250000;
    }

    return totalCharges;
}


void displayNewConnection(string customerName , string customerType ,  int customerId , char connectionChoice , 
                          double additionalCharges , double NewConnecCharges , bool properConnection )
{
	 cout << "\n\n================================================ NEW CONNECTION DETAILS ================================================" << endl ;

            cout << "\n\tCustomer Name: " << customerName << endl;
            
            cout << "\tCustomer ID: " << customerId << endl;    
			    
            cout << "\tCustomer Type: " << customerType << endl;

            cout << "\n\tMeter Cost    = 14000" << endl;
            
            cout << "\tCable Cost    = 4000" << endl;
            
            cout << "\tSecurity Deposit = 3500" << endl;
            
            cout << "\tAdditional Charges = " << additionalCharges <<endl;
            
            if( properConnection == true )
            {
            	cout << "\tProper Connectin Charges = 250000" << endl;
			}
            cout << "\n\tTotal New Connection Charges: Rs. " << fixed << setprecision(2) << NewConnecCharges << endl;

    cout << "\n\n========================================================================================================================\n";
}


void displayCustomerDetails(string customerName , int customerId , string customerType , int meterOption)
{
    cout << "\n\n=================================================== CUSTOMER DETAILS ===================================================" << endl;

    cout << "\n\tCustomer Name: " << customerName << endl;

    cout << "\tCustomer ID: " << customerId << endl;

    cout << "\tCustomer Type: " << customerType << endl;

    if (meterOption == 1)
    {
        cout << "\tMeter Option: First Meter" << endl;
    }
    else
    {
        cout << "\tMeter Option: Second Meter" << endl;
    }

    cout << "\n\n========================================================================================================================";
}

