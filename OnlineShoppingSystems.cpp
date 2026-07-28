#include <iostream>
#include <iomanip>
#include <string>

using namespace std;







void registerUser(string &name , string &email , string &city , string &customerType);

void displayMenu();

void displayProducts(string products[] , double prices[] , int size);

double addToCart(string products[] , double prices[] , int size);

double calculateGST(double total);

double calculateDeliveryCharges(string city);

double calculateCustomerDiscount(double total, string customerType);

double calculateOrderDiscount(double total);

double paymentMethod(double total);

void displayCheckoutBill(string name, string city, string customerType, double cartBill, double gst, double delivery, 
                         double customerDiscount, double orderDiscount, double paymentCharges, double finalAmount);
                         
void displayCustomerDetails(string name , string city , string customerType , string email);







using namespace std;

int main(){

    string products[8] = {"T-Shirt", "Jeans", "Shoes", "Watch", "Handbag", "Headphones", "Mobile Cover", "Perfume"};

    double prices[8] = {1200, 3500, 5000, 2500, 4200, 3000, 700, 2800};

    string name, email, city, customerType;
    


    registerUser(name , email , city , customerType);
    
    int MainChoice ;
    double cartBill, gst, delivery, customerDiscount, orderDiscount, subtotal, paymentCharges, finalAmount ;
    
do{    
    displayMenu();
    cin >> MainChoice;
    
    if(MainChoice == 1){
    	displayProducts(products , prices , 8);
	}
    else if(MainChoice == 2){
        cartBill +=	addToCart(products , prices , 8);
	}
	else if(MainChoice == 3){
		gst = calculateGST(cartBill);
		delivery = calculateDeliveryCharges(city);
		customerDiscount = calculateCustomerDiscount(cartBill, customerType);
		orderDiscount = calculateOrderDiscount(cartBill);
		
		subtotal = cartBill + gst + delivery - customerDiscount - orderDiscount;
		
		paymentCharges = paymentMethod(subtotal);
		
		finalAmount = subtotal + paymentCharges;
		
		displayCheckoutBill(name, city, customerType, cartBill, gst, delivery, customerDiscount, orderDiscount, 
		                    paymentCharges, finalAmount);
	}
	else if(MainChoice == 4){
		displayCustomerDetails(name , city , customerType , email);	
	}
	else if(MainChoice == 5)
	{
		cout << "\n\t\t\t\t            >>>Program Exited Successfully<<<" << endl;
		    cout << "\n\n========================================================================================================================";
	}
	else{
		cout << "\n\t\t\t\t        >>>Invalid Choice. Please Try Again<<<" << endl ;
	}
	
}while(MainChoice != 5);


}










void registerUser(string &name , string &email , string &city , string &customerType)
{
	int op;
	
    cout << "================================================ CUSTOMER REGISTRATION ================================================\n" << endl ;

    cout << "\n\tEnter User Name: ";
    cin >> name ;

    cout << "\tEnter Email: ";
    cin >> email ;

    cout << "\tEnter City: ";
    cin >> city ;


    do{  
    cout << "\n\tCustomer Type :" << endl;
    cout << "\t1. New Customer " << endl;
    cout << "\t2. Returning Customer " << endl;
    cout << "\n\t\tEnter Choice : " ;
    cin >> op ;
    if(op==1)
	        {
    	    customerType = "New Customer";
	        } 
	else if(op==2)
	        {
		    customerType = "Returning Customer";
	        }
	else
	        {
		    cout << "\n\t\t\t\t        >>>Invalid Choice. Please Try Again<<<" << endl ;
	        cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
	        }
    }while(op != 1  &&  op != 2);

    cout << "\t----------------------------------------------------------------------------------------------------"<<endl;
    cout << "\n\t\t\t\t\t>>>Customer Registered Successfully<<<\n";

}



void displayMenu()
{
    cout << "\n\n====================================================== MAIN MENU ======================================================\n" << endl ;

    cout << "\n\t1. View Products " << endl ;
    cout << "\t2. Add Product to Cart " << endl ;
    cout << "\t3. Calculate Checkout Bill " << endl ;
    cout << "\t4. View User Details " << endl ;
    cout << "\t5. Exit " << endl ;

    cout << "\n\t\tEnter Your Choice: ";
}



void displayProducts(string products[] , double prices[] , int size)
{
    cout << "\n\n===================================================== PRODUCT LIST =====================================================\n" << endl ;
    
    for(int i = 0; i < size; i++)
    {
        cout << "\n\t" << i + 1 << ". " << products[i] << " - Rs. " << prices[i] << endl;
    }
}



double addToCart(string products[] , double prices[] , int size)
{
    int itemNo, quantity;
    char choice;

    double total = 0;
	
	cout << "\n\n===================================================== ADD TO CART =====================================================\n" << endl ;
        
        for(int i = 0; i < size; i++)
    {
        cout << "\n\t" << i + 1 << ". " << products[i] << " - Rs. " << prices[i] << endl;
    }

    do
    {
    cout << "\n\t\tEnter Item Number: ";
    cin >> itemNo;

    cout << "\t\tEnter Quantity: ";
    cin >> quantity;

    if(itemNo >= 1 && itemNo <= size)
    {
        total += prices[itemNo - 1] * quantity;

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



double calculateGST(double total)
{
    return total * 0.17;
}



double calculateDeliveryCharges(string city)
{
    if (city == "Lahore" || city == "lahore" || city == "Karachi" || city == "karachi" || city == "Islamabad" 
	                     || city == "islamabad")
    {
        return 250;
    }

    return 500;
}



double calculateCustomerDiscount(double total, string customerType)
{
    if (customerType == "New Customer")
        return total * 0.05;

    return total * 0.10;
}



double calculateOrderDiscount(double total)
{
    if (total >= 5000 && total <= 10000){
        return total * 0.05;
    }
    else if (total > 10000){
        return total * 0.12;
	}
    else{
    return 0;
	}
}



double paymentMethod(double total)
{
	int opt;
	cout << "\n\n================================================ SELECT PAYMENT METHOD ================================================\n" << endl ;
	cout << "\n\tPayment Method: " << endl;
    cout << "\t1. Cash on Delivery" << endl;
    cout << "\t2. Debit/Credit Card" << endl ;
    cout << "\t\tEnter Choice: ";
    cin >> opt;
    if(opt == 1){
    	return 0;
	}
	else{
		return total*0.025;
	}
}



void displayCheckoutBill(string name, string city, string customerType, double cartBill, double gst, double delivery, 
                         double customerDiscount, double orderDiscount, double paymentCharges, double finalAmount)
{
    cout << fixed << setprecision(2);

    cout << "\n\n================================================= ONLINE SHOPPING BILL =================================================\n" << endl ;
    
    cout << "\tUser Name: " << name << endl;
    cout << "\tCity: " << city << endl;

    cout << "\tCustomer Type: " << customerType << endl;
    

    cout << "\n\tProduct Total: Rs. " << cartBill << endl;
    cout << "\tGST: Rs. " << gst << endl;
    cout << "\tDelivery Charges: Rs. " << delivery << endl;
    cout << "\tCustomer Discount: Rs. " << customerDiscount << endl;
    cout << "\tOrder Discount: Rs. " << orderDiscount << endl;
    cout << "\tPayment Charges: Rs. " << paymentCharges << endl;

    cout << "\n\t----------------------------------------------------------------------------------------------------"<<endl;
    cout << "\tFinal Payable Amount: Rs. "<< finalAmount << endl;

    cout << "\n\tThank You for Shopping :)" << endl;
    cout << "========================================================================================================================";
}



void displayCustomerDetails(string name , string city , string customerType , string email)
{
    cout << "\n\n=================================================== CUSTOMER DETAILS ===================================================" << endl;

    cout << "\n\tCustomer Name: " << name << endl;
	
	cout << "\tEmail: "<< email << endl;

    cout << "\tCity: " << city << endl;

    cout << "\tCustomer Type:  " << customerType << endl;

    cout << "\n\n========================================================================================================================";
}
