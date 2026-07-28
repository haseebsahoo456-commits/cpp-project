#include <iostream>
#include <iomanip>
#include <string>

using namespace std;






void registerCustomer(string &customerName, string &customerID, string &customerType, string &paymentMethod);

void displayMenu();

void displayList(string items[] , double prices[] , int size);

double addToCart(string items[] , double prices[] , int size, double &salesTax);

double calculateSalesTax(int itemNo, double itemTotal );

double calculateMemberDiscount(double total, string customerType);

double calculateBillDiscount(double total);

double calculateCardCharges(double amount, string paymentMethod);

int calculateLoyaltyPoints(double totalBill);

void displayBill(string customerName, string customerType, string paymentMethod, double cartBill, double salesTax, 
                 double memberDiscount, double billDiscount, double cardCharges, int generatedPoints, double totalBill);
                 
void displayCustomerDetails(string customerName , string customerID , string customerType , string paymentMethod);






int main (){
	string customerName, customerID, customerType, paymentMethod;
    
    string items[8] ={"Rice 1 KG", "Sugar 1 KG", "Cooking Oil 1 Litre", "Milk Pack", "Tea Pack", "Flour 5 KG", "Eggs Dozen",
                      "Detergent" };

    double prices[8] = {350, 180, 580, 220, 450, 950, 320, 600 };
    
    registerCustomer(customerName, customerID, customerType, paymentMethod) ;
    
    int choice;
    
    double cartBill, memberDiscount, billDiscount, cardCharges , subtotal, totalBill ;
    double salesTax = 0 ;
    int generatedPoints ;
    
    do{
    	displayMenu();
        cin >> choice;
        
    if(choice == 1)
	{
		displayList(items , prices , 8);
	}
	else if(choice == 2)
	{
		cartBill += addToCart(items , prices , 8, salesTax);
	}
	else if(choice == 3)
	{
        memberDiscount = calculateMemberDiscount( cartBill, customerType );
        
        billDiscount = calculateBillDiscount( cartBill );
        
        subtotal = cartBill + salesTax - memberDiscount - billDiscount;
        
		cardCharges = calculateCardCharges( cartBill, paymentMethod );
		
		totalBill = subtotal + cardCharges;
		
		generatedPoints = calculateLoyaltyPoints(totalBill);
		
		displayBill(customerName, customerType, paymentMethod, cartBill, salesTax, memberDiscount, billDiscount, 
		            cardCharges, generatedPoints, totalBill);
		
	}
	else if(choice == 4)
	{
		displayCustomerDetails(customerName , customerID , customerType , paymentMethod);
	}
	else if(choice == 5)
	{
		cout << "\n\t\t\t\t            >>>Program Exited Successfully<<<" << endl;
		cout << "\n\n========================================================================================================================";
	}
	else{
		cout << "\n\t\t\t\t        >>>Invalid Choice. Please Try Again<<<" << endl ;
	}
	
}while(choice != 5);
    
    
}






void registerCustomer(string &customerName, string &customerID, string &customerType, string &paymentMethod)
{
	int op , option ;
	
    cout << "================================================ CUSTOMER REGISTRATION ================================================\n" << endl ;
		
    cout << "\n\tEnter Customer Name: ";
    cin >> customerName ;

    cout << "\tEnter Customer ID: ";
    cin >> customerID ;
    
    do{  
    cout << "\n\tCustomer Type :" << endl;
    cout << "\t1. Regular Customer " << endl;
    cout << "\t2. Member Customer " << endl;
    cout << "\n\t\tEnter Choice : " ;
    cin >> op ;
    if(op==1)
	        {
    	    customerType = "Regular Customer";
	        } 
	else if(op==2)
	        {
		    customerType = "Member Customer";
	        }
	else
	        {
		    cout << "\n\t\t\t\t        >>>Invalid Choice. Please Try Again<<<" << endl ;
	        cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
	        }
    }while(op != 1  &&  op != 2);
    
    do{  
    cout << "\n\tPayment Method :" << endl;
    cout << "\t1. Cash " << endl;
    cout << "\t2. Card " << endl;
    cout << "\n\t\tEnter Choice : " ;
    cin >> option ;
    if(option == 1)
	        {
    	    paymentMethod = "Cash";
	        } 
	else if(option == 2)
	        {
		    paymentMethod = "Card";
	        }
	else
	        {
		    cout << "\n\t\t\t\t        >>>Invalid Choice. Please Try Again<<<" << endl ;
	        cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
	        }
    }while(option != 1  &&  option != 2);
    
    cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
    cout << "\n\t\t\t\t\t>>>Customer Registered Successfully<<<\n";
    
}


void displayMenu()
{
    cout << "\n\n====================================================== MAIN MENU ======================================================\n" << endl ;

    cout << "\n\t1. View Grocery Items " << endl ;
    cout << "\t2. Add Items to Cart " << endl ;
    cout << "\t3. Calculate Bill " << endl ;
    cout << "\t4. View Customer Details " << endl ;
    cout << "\t5. Exit " << endl ;

    cout << "\n\t\tEnter Your Choice: ";
}


void displayList(string items[] , double prices[] , int size)
{
    cout << "\n\n===================================================== GROCERY LIST =====================================================\n" << endl ;
    
    for(int i = 0; i < size; i++)
    {
        cout << "\n\t" << i + 1 << ". " << items[i] << " - Rs. " << prices[i] << endl;
    }
}


double addToCart(string items[] , double prices[] , int size, double &salesTax)
{
    int itemNo, quantity;
    char choice;

    double total = 0;
	
	cout << "\n\n===================================================== ADD TO CART =====================================================\n" << endl ;
        
        for(int i = 0; i < size; i++)
    {
        cout << "\n\t" << i + 1 << ". " << items[i] << " - Rs. " << prices[i] << endl;
    }
    
    double itemEight = 0, itemElse = 0 , sectionTax = 0 ;
    double foodTax , nonFoodTax ;
    
    do
    {
    cout << "\n\t\tEnter Item Number: ";
    cin >> itemNo;

    cout << "\t\tEnter Quantity: ";
    cin >> quantity;

    if(itemNo >= 1 && itemNo <= size)
    {
    	double itemTotal;
    	
    itemTotal = prices[itemNo - 1] * quantity;
    
    salesTax += calculateSalesTax(itemNo, itemTotal);
    
    total += itemTotal;

    cout << "\n\t\t\t\t\t               >>>Items Added Successfully<<<\n";
    cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
    }
    else
    {
		cout << "\n\t\t\t\t   >>>Invalid Item Number. Please Try Again<<<" << endl ;
		cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
    }

        cout << "\n\t\tDo you want to add more? (y/n): ";
        cin >> choice;

    } while(choice == 'y' || choice == 'Y');

    return total;
}


double calculateSalesTax(int itemNo, double itemTotal )
{
	
    if(itemNo >= 1 && itemNo <= 7){
        return itemTotal * 0.05;
    }
    else if(itemNo == 8){
        return itemTotal * 0.10;
    }
    return 0;
}


double calculateMemberDiscount(double total, string customerType)
{
    if (customerType == "Regular Customer")
	{
        return 0;
    }
    return total * 0.07;
}


double calculateBillDiscount(double total)
{
    if (total >= 5000 && total <= 10000){
        return total * 0.05;
    }
    else if (total > 10000)
	{
        return total * 0.10;
	}
    return 0;
}


double calculateCardCharges(double amount, string paymentMethod)
{
    if(paymentMethod == "Card"){
        return amount * 0.02;
    }
    return 0;
}

int calculateLoyaltyPoints(double totalBill)
{
    return totalBill / 100;
}


void displayBill(string customerName, string customerType, string paymentMethod, double cartBill, double salesTax, 
                 double memberDiscount, double billDiscount, double cardCharges, int generatedPoints, double totalBill)
{
    int existingPoints, totalPoints, choice;
    double payableAmount;

    cout << "\n\n================================================ GROCERY MART BILL ================================================\n" << endl ;

    cout << "\tCustomer Name: " << customerName << endl;
    cout << "\tCustomer Type: " << customerType << endl;
    cout << "\tPayment Method: " << paymentMethod << endl;

    cout << "\n\tGross Bill: Rs. " << cartBill << endl;
    cout << "\tSales Tax: Rs. " << salesTax << endl;
    cout << "\tMembership Discount: Rs. " << memberDiscount << endl;
    cout << "\tBill Discount: Rs. " << billDiscount << endl;
    cout << "\tCard Charges: Rs. " << cardCharges << endl;
    cout << "\tGenerated Loyalty Points: " << generatedPoints << endl;

    cout << "\n\tEnter Your Existing Loyalty Points (Enter 0 if you're a new user): ";
    cin >> existingPoints;

    totalPoints = existingPoints + generatedPoints;

    cout << "\n\tLoyalty Points after Purchase: " << totalPoints << endl;

    cout << "\tPress 1 to redeem your loyalty points, Press 2 to continue: ";
    cin >> choice;

    if (choice == 1)
    {
        payableAmount =  totalBill - totalPoints;   
    }
    else
	{
		payableAmount =  totalBill;
    }

    cout << "\n\t----------------------------------------------------------------------------------------------------"<<endl;
    cout << "\tTotal Payable Amount: Rs. " << payableAmount << endl;
    cout << "\tThank You For Shopping :)" << endl;
    cout << "========================================================================================================================";
}


void displayCustomerDetails(string customerName , string customerID , string customerType , string paymentMethod)
{
    cout << "\n\n=================================================== CUSTOMER DETAILS ===================================================" << endl;

    cout << "\n\tCustomer Name: " << customerName << endl;
	
	cout << "\tcustomer ID: "<< customerID << endl;

    cout << "\tPayment Method: " << paymentMethod << endl;

    cout << "\tCustomer Type:  " << customerType << endl;

    cout << "\n\n========================================================================================================================";
}
