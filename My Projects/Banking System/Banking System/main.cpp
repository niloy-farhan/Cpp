//
//  main.cpp
//  Banking System
//
//  Created by Niloy Farhan on 26/2/24.
//

#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;

int main(int argc, const char * argv[]) {
    
    bool quit = false;
    
    
    while(!quit) {
        
        unsigned int options;
        
        cout<< "\n\n\n       SELECT ONE OPTION BELOW" <<endl;
        cout<<"       1 Open an Account \n";
        cout<<"       2 Balance Enquiry \n";
        cout<<"       3 Deposit \n";
        cout<<"       4 Withdraw \n";
        cout<<"       5 Close an Account \n";
        cout<<"       6 Show All Accounts \n";
        cout<<"       7 Quit \n";
        cout<<"\nEnter Your Choice: " ;
        std::cin>>options;
        
        switch (options) {
            case 1:
                cout<< " Open an Account";
                break;
            case 2:
                cout<< " Balance Enquiry";
                break;
            case 3:
                cout<< " Deposit";
                break;
            case 4:
                cout<< " Withdraw";
                break;
            case 5:
                cout<< " Close an Account";
                break;
            case 6:
                cout<< " Show All Accounts";
                break;
            case 7:
                quit = true;
            default:
                cout<<" Invalid Selection: (" <<options <<")" <<endl;
        }
    }
    
    return 0;
}
