#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
    cout << "Binary Search Tree!" << endl;

    Bst t;
    int opt, value;
    do{
        cout<<"1-insert"<<endl;
        cout<<"2-remove"<<endl;
        cout<<"3-search"<<endl;
        cout<<"4-in-order"<<endl;
        cout<<"5-pre-order"<<endl;
        cout<<"6-post-order"<<endl;
        cout<<"9-exit"<<endl;
        cout<<"select:";
        cin>>opt;
        switch(opt){
        case 1:
            cout<<"Insert:";
            cin>>value;
            t.insert(t.rootPtr, value);
            break;
        case 2:
            cout<<"Remove:";
            cin>>value;
            t.remove(t.rootPtr, value);
            break;
        case 3:
            cout<<"Search:";
            cin>>value;
            if(t.search(t.rootPtr, value)==true)
                cout<<"Number found!"<<endl;
            else
                cout<<"Number not found!"<<endl;
            break;
        case 4:
            cout<<"In-order:"<<endl;
            t.inorder(t.rootPtr);
            cout<<endl;
            break;
        case 5:
            cout<<"Pre-order:"<<endl;
            t.preorder(t.rootPtr);
            cout<<endl;
            break;
        case 6:
            cout<<"Post-order:"<<endl;
            t.postorder(t.rootPtr);
            cout<<endl;
            break;
        case 9:
            cout<<"end..."<<endl;
            break;
        default:
            cout<<"invalid option"<<endl;
            break;
        }

    }while(opt != 9);
    return 0;
}
