#include<iostream>
#include<iostream>
#include<algorithm>
using namespace std;

class MyRelation
{
	int *set1;
	int *set2;
	int **matrix;
	int row;
	int col;
	
	public:
    MyRelation();
    MyRelation(int ,int);
    void input_relation();
    void input_set(int,int);
	
	
};                                                  //class ends

MyRelation :: MyRelation ()            // default constructor
    {
        row=col=0;
    }


MyRelation :: MyRelation(int r,int c)               // parametrised constructor
{
    row=r;
    col=c;

    set1=new int [r];
    set2 =new int [c];

    matrix =new int * [r];

    for(int i=0;i<r;i++)
    {
        matrix[i]=new int [c];
    }
}

void MyRelation :: input_relation()                       //enter relation
{   
    cout<<"\nEnter the relation in form of matrix : \n";
    cout<<"\n\nMATRIX  SIZE "<<row<<"X"<<col<<"......which means "<<row*col<<"elements\n";
    int k=1;
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			{
                cout<<k<<". ("<<set1[i]<<","<< set2[j] <<")   : ";
                cin>>matrix[i][j];
                cout<<"\n";
                k++;
            }
}

void MyRelation :: input_set(int size1,int size2=0)
{
	if(size2==0)
	{
		cout<<"\nEnter set :-\n";
		for(int i=0;i<size1;i++)
			cin>>set1[i]; 
			
		for(int i=0;i<size1;i++)
			set2[i]=set1[i];

            sort(set1,set1+size1);
	}
	else
	{
		cout<<"\n->Enter 1st set :-\n";
		for(int i=0;i<size1;i++)
			cin>>set1[i];
		
		cout<<"\n->Enter 2nd set :-\n";
		for(int i=0;i<size2;i++)
			cin>>set2[i];

            sort(set1,set1+size1);
            sort(set2,set2+size2);
	}
}



int main()
{
	
	cout<<"\nWould you like to work on a single set or 2 sets ? <Press 1 for single and 2 for double>";
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				cout<<"\nEnter no of elements : ";
				int size;
				cin>>size;
				MyRelation r1(size,size);
				r1.input_set(size);
				r1.input_relation();
				//r1.print_relation();
			}
			break;
		case 2:
			{
				int size1,size2;
				cout<<"\nEnter no of elements for set 1 : ";
				cin>>size1;
				cout<<"\nEnter no of elements for set 2 : ";
				cin>>size2;
				MyRelation r1(size1,size2);
				r1.input_set(size1,size2);
				r1.input_relation();
				//r1.print_relation();
			}
			break;
		default:
			cout<<"invalid choice!!";


			break;
	}
	return 0;
}



















