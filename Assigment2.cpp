#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

const int SIZE = 50;
int loadArrays(string[] /*code*/, int[] /*qoh*/); //Prototype
int findHighest(int qoh[], int noProducts);
void showInventory(string[] /*code*/, int[] /*qoh*/, int /*noProducts*/);
int addProduct(string[] /*code*/, int[] /*qoh*/, int /*noProducts*/);
int removeProduct(string[] /*code*/, int[] /*qoh*/, int /*noProducts*/);

int main()
{
	
	string code[SIZE];
	int qoh[SIZE];
	int noProducts;
	cout << "Initial array load:\n\n" << endl;
	noProducts = loadArrays(code, qoh);
	showInventory(code, qoh, noProducts);
	cout << "A product added:\n\n" << endl;
	noProducts = addProduct(code, qoh, noProducts);
	showInventory(code, qoh, noProducts);
	cout << "Attempted to add same product:\n\n" << endl;
	noProducts = addProduct(code, qoh, noProducts);
	showInventory(code, qoh, noProducts);
	cout << "Product deleted:\n\n" << endl;
	noProducts = removeProduct(code, qoh, noProducts);
	showInventory(code, qoh, noProducts);
	cout << "Attempted to delete same product load\n\n" << endl;
	noProducts = removeProduct(code, qoh, noProducts);
	showInventory(code, qoh, noProducts);
	cout << "Program ended successfully" << endl;
	system("type inventory.dat");
	

	system("pause");

}

int loadArrays(string code[], int qoh[])
{
	int noProducts;

	ifstream fin("inventory.dat");
	for (noProducts = 0; noProducts <SIZE ; noProducts++)
	{
		

		if (fin.eof())
			break;

		getline(fin, code[noProducts]); //Reads String
		fin >> qoh[noProducts];		//Reads Numbers
		fin.ignore(80, '\n');		//Gets ride of enter	

		


	}
	return noProducts;
}
void showInventory(string code[], int qoh[], int noProducts)
{
	cout << setw(20) << left << "Product Code" << left << setw(8) << "Quantity" << endl << endl;
	int highest = findHighest(qoh, noProducts);


	for (int index = 0; index < noProducts; index++)
	{
		cout << setw(20) << left << code[index] << setw(8) << right << qoh[index];
		if (highest == index)
			cout << " *** most ***";
		cout << endl;
	}

	cout << endl<< "No Products=" << noProducts << endl;
	
}
int addProduct(string code[], int qoh[], int noProducts)

{

	return noProducts;

}
int removeProduct(string code[], int qoh[], int noProducts)
{
	return noProducts;
}
int findHighest(int qoh[], int noProducts)
{
	int pos = 0;
	
	for (int index = 1; index < noProducts; index++)
	{

		if (qoh[pos] < qoh[index])
			pos = index;
	}
	return pos;
}
