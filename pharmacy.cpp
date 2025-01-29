
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10

using namespace std;


class MedType	
{
public:

    void order();
    void delete_item(); 
    void update_order(); 
	void order_list(); 
	void summarry(); 
	void quit();  
	MedType();

};

 MedType::MedType ()
{

}		


struct node 
{
	int receiptNo;
	string Cus_Name;
	string date;
	int med_quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double med_amt[10];
    string Med_Name[10]={"Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet",
	"Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double tot_order;

	node *prev;
	node *next;
	node *link; 

}*q, *temp;				


node *starting_point = NULL;
node *head_point = NULL;
node *lasting_point = NULL;

int main()	
{

	system("COLOR 2F");		
	MedType medicine;
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t\t    Pharmacy Management System \n";
		cout<<"\t\t####################################################\n\n";
		cout<<"\t\t####################################################\n";
		cout<<"\t\t\t1. Take new Medicine order \t\t\n";
		cout<<"\t\t\t2. Delete latest Medicine order\t\t\n";
		cout<<"\t\t\t3. Modify Order List \t\t\t\n";
		cout<<"\t\t\t4. Print the Reciept and Make Payment \t\n";
		cout<<"\t\t\t5. Daily Summary of total Sale \t\t \n";
		cout<<"\t\t\t6. Exit\t\t\t\t\t\n";
		cout<<"\t\t####################################################\n";
		cout<<"Enter choice: ";

		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				medicine.order();	
				break;
			}	
		
		
		case 2:
			{
				medicine.delete_item();
				system("PAUSE");
				break;
			}	
			
		case 3:
			{
				medicine.update_order();	
				system("PAUSE");
				break;
			}	

		case 4:
			{
				medicine.order_list();	
				system("PAUSE");
				break;
			}	
		case 5:
			{
				medicine.summarry();	
				system("PAUSE");
				break;
			}	
        case 6:
			{
				medicine.quit();	
				goto a;
				break;
			}	

		
		default:
			{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}
		}
	}while(menu!=6);
	a:
	cout<<"thank you"<<endl;
	system ("PAUSE");
	return 0;
}


void MedType::order()		
{
	system("cls");
	int i;
    int options, med_quantity, med_price,None;

	cout <<"\nAdd Order Details\n";
	cout <<"########################################################################## \n\n";

	node *temp;
	temp=new node;

				cout <<"##########################################################################\n";
				cout<<"DRUGS ID"<<"\tDRUGS TYPE"<<"   \t\tDRUGS NAME"<<"           DRUGS PRICE(RM)"<<endl;
				cout <<"##########################################################################\n";
                cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Probiotics"<<"			RM 2.00"<<endl;
                cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamin C(500mg)"<<"		RM 3.00"<<endl;
                cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Acid Free C(500mg)"<<"		RM 1.00"<<endl;
                cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Women'S Multivate"<<"		RM 4.00"<<endl;
                cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Marino Tablet"<<"	 	RM 1.00"<<endl;
                cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    Maxi Cal Tablet"<<" 		RM 5.00"<<endl;
                cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Amino Zinc Tablet"<<"		RM 7.00"<<endl;
                cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Burnex"<<"			RM 4.00"<<endl;//1353fn
                cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Fabuloss 5"<<"			RM 3.00"<<endl;
                cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Royal Propollen"<<"		RM 5.00"<<endl;
                cout<<" "<<endl;
    
	temp = new node;
	cout << "Type Order no: ";
    cin >> temp->receiptNo;
	cout<< "Enter Customer Name: ";
	cin>> temp->Cus_Name;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection : "<<endl;
		cin>> temp->menu2[i];
        cout<< "Medicine Name: " <<temp->Med_Name[temp->menu2[i]-1]<<endl;
        cout << "How many medicine do you want: ";
        cin >> temp->med_quantity[i];
        temp->med_amt[i] = temp->med_quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay is: " << temp->med_amt[i]<<" RM"<<endl;
        system("PAUSE");
                      
	}
	cout<<"##########################################################################"<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"##########################################################################"<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"##########################################################################"<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(starting_point!=NULL)
	{
		temp->next=starting_point;
	}
	starting_point=temp;
	system("cls");
}
}


void MedType::order_list()		
{
	int i, num, num2;	
	bool found;			
	system("cls");
	node *temp;

	temp=starting_point;
	found = false;
	
	cout<<" Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"##########################################################################"<<endl;
	cout <<"\t\tHere is the Order list\n"; 
	cout<<"##########################################################################"<<endl;


	if(temp == NULL) 
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->receiptNo==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	
        {
		cout <<"Reciept Number : "<<temp->receiptNo;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->Cus_Name<<endl;
				
		cout<<"Order Date : "<<temp->date<<endl;
				
		cout<<"##########################################################################"<<endl;
			
		cout << "##########################################################################" << endl;
		cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "##########################################################################" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type <<"  \t\t";
			cout<<temp->Med_Name[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->med_quantity[i] <<"\t\t";
			cout<< temp->med_amt[i]<<" RM"<<endl;
			cout<<"##########################################################################"<<endl;
		}
		
		temp->tot_order = temp->med_amt[0]+temp->med_amt[1]+temp->med_amt[2]+temp->med_amt[3]+temp->med_amt[4]+temp->med_amt[5]+temp->med_amt[6]+temp->med_amt[7]
						+temp->med_amt[8]+temp->med_amt[9];
		cout<<"Total Bill is : "<<temp->tot_order;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;

		cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n##########################################################################\n";
		}


}
}	


void MedType::delete_item()	
{
	system("cls");
	int i, num, count;
    cout<<"Enter the data you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(starting_point == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(starting_point->receiptNo == num)
		{
			q = starting_point;
			starting_point = starting_point->next;
			count--;
			if(starting_point == NULL)
			lasting_point = NULL;
			delete q;
			cout<<"The Reciept is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = starting_point;
			q = starting_point->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->receiptNo != num) 
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(lasting_point == q) 
				lasting_point = temp;
				delete q;
				cout<<"The Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
			}
		} 
}	



void MedType::update_order()		
{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = starting_point;
 cout<<"Enter Receipt Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->receiptNo==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Change  Order Number: ";
    cin >> temp->receiptNo;
	cout<< "Change Customer Name: ";
	cin>> temp->Cus_Name;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "Please enter your selection to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "Change Medicine Name: " <<temp->Med_Name[temp->menu2[i]-1]<<endl;
        cout << "How many New medicine do you want: ";
        cin >> temp->med_quantity[i];
        temp->med_amt[i] = temp->med_quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->med_amt[i]<<" RM"<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");
	
	}

 cout<<"RECORD MODIFIED....!"<<endl;
 }
 else 
 {
 	if(temp != NULL && temp->receiptNo != sid)
 	{
 	cout<<"Invalid Reciept Number...!"<<endl;
    }
 }
}
}
}		



void MedType::summarry()		
{
	int i,num;
	system("cls");
	node *temp ;

	temp=starting_point;


	if(temp == NULL) 
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"##########################################################################"<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"##########################################################################"<<endl;

		while(temp!=NULL)
		{
		
				cout <<"Reciept Number : "<<temp->receiptNo;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->Cus_Name<<endl;
				
				cout<<"Order Date : "<<temp->date<<endl;
				
				cout<<"*****************************************************************************"<<endl;
			
				cout << "##########################################################################" << endl;
				cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "#######++##################++################++###############++##########" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout << temp->type <<"  \t\t";
				cout<<temp->Med_Name[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->med_quantity[i] <<"\t\t";
				cout<< temp->med_amt[i]<<" RM"<<endl;
				cout<<"*****************************************************************************"<<endl;
			}
			
			temp->tot_order = temp->med_amt[0]+temp->med_amt[1]+temp->med_amt[2]+temp->med_amt[3]+temp->med_amt[4]+temp->med_amt[5]+temp->med_amt[6]+temp->med_amt[7]
			+temp->med_amt[8]+temp->med_amt[9];
			cout<<"Total Bill is : "<<temp->tot_order;
		
			cout <<"\n";
			cout <<"\n";
			cout <<"\n******************************************************************************\n";
				
			temp=temp->next;
		}
	}
}		
void MedType::quit() 
{
	cout<<"\nYou choose to exit.\n"<<endl;
}	


