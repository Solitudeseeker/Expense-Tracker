#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
class Expense{
    public:
    int amount;
    char category;
    string description;
    Expense(int amt, char C, string D){
        amount = amt;
        category = C;
        description = D;
    }
    string CCategory(char C){
        switch(C){
            case 'F':
                return "Food";
            case 'T':
                return "Transportation";
            case 'E':
                return "Education";
            case 'S':
                return "Shopping";
            default:
                return "Other";
        }
    }
};
void displayExpense(vector<Expense> expenses){
    for(int i=0; i<expenses.size(); i++){
        cout<<"Expense "<<i+1<<": "<<endl;
        cout<<"Amount: "<<expenses[i].amount<<endl;
        cout<<"Category: "<<expenses[i].CCategory(expenses[i].category)<<endl;
        cout<<"Description: "<<expenses[i].description<<endl;
    }
}
int calculateTotal(vector<Expense> expenses){
    int total=0;
    for(int i=0; i<expenses.size(); i++){
        total+=expenses[i].amount;
    }
    return total;
}
int categoryTotal(vector<Expense> expenses, char C){
    int total=0;
    for(int i=0; i<expenses.size(); i++){
        if(expenses[i].category == C || tolower(expenses[i].category) == tolower(C)){
            total+=expenses[i].amount;
        }
    }
    return total;
}
void searchExpense(vector<Expense> expenses, string desc){
    for(int i=0; i<expenses.size(); i++){
        if(expenses[i].description.find(desc) != string::npos){
            cout<<"Expense "<<i+1<<" matches the search description."<<endl;
            cout<<"Amount: "<<expenses[i].amount<<endl;
            cout<<"Category: "<<expenses[i].CCategory(expenses[i].category)<<endl;
            cout<<"Description: "<<expenses[i].description<<endl;
        }
    }
}
int HighestExpense(vector<Expense> expenses){
    int highest=0;
    int highestIndex=0;
    for(int i=0; i<expenses.size(); i++){
        if(expenses[i].amount > highest){
            highest = expenses[i].amount;
            highestIndex = i;
        }
    }
    return highestIndex;
}
int main(){
    int A;
    char choose;
    string desc;
    char another;
    string SearchDesc;
    vector<Expense> expenses;
    do{    
        cout<<"Enter the amount: ";
        cin>>A;
        cout<<"The amount is: "<<A<<endl;
        cout<<"Enter the category from the following options: F (Food), T (Transportation), E (Education), S (Shopping): ";
        cin>>choose;
        cout<<"Enter the description: ";
        cin.ignore();
        getline(cin, desc);
        Expense obj(A, choose, desc);
        cout<<"Description: "<<desc<<endl;
        cout<<"Do you want to enter another expense? (Y/N):";
        expenses.push_back(obj);
        cin>>another;
        while(another != 'Y' && another != 'y' && another != 'N' && another != 'n'){
            cout<<"Invalid input. Please enter Y or N."<<endl;
            cin>>another;
        }
        if(another== 'N' || another == 'n'){
            cout<<"Thankyou for using the expense tracker!"<<endl;
        }else{
            cout<<"Adding another expense..."<<endl;
        }
    }while(another == 'Y' || another == 'y');
    cout<<endl;
    cout<<endl;
    displayExpense(expenses);
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"Total amount spent: "<<calculateTotal(expenses)<<endl;
    cout<<"Food expenses: "<<categoryTotal(expenses, 'F')<<endl;
    cout<<"Transportation expenses: "<<categoryTotal(expenses, 'T')<<endl;
    cout<<"Shopping expenses: "<<categoryTotal(expenses, 'S')<<endl;
    cout<<"Education expenses: "<<categoryTotal(expenses, 'E')<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;
    int highestIndex = HighestExpense(expenses);
    cout<<"Highest expense amount: "<<expenses[highestIndex].amount<<endl;
    cout<<"Category: "<<expenses[highestIndex].CCategory(expenses[highestIndex].category)<<endl;
    cout<<"Description: "<<expenses[highestIndex].description<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"----------------------------------------"<<endl;
    cout<<"Enter some description to search for: ";
    cin.ignore();
    getline(cin, SearchDesc);
    searchExpense(expenses, SearchDesc);
    cout<<"----------------------------------------"<<endl;
    return 0;
}   