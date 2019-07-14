#include <iostream>

#include "0516072_Link_List.h"

using namespace std;

int main()
{
    /////////////////////////////////////////////////////////////////////////
    //////////////////////////// basic score: 70 ////////////////////////////
    /////////////////////////////////////////////////////////////////////////
    // test default constructor
    Link_List linkList1;

    // test copy constructor
    Link_List linkList2(linkList1);

    // test getSize()
    cout << linkList2.getSize() << endl;
    cout << "(5, ANSWER_1): 0" << endl
         << endl;

    // test insert_node(value), delete_node(), operator<<, operator>>

    Link_List linkList3;
    cout << "Enter a integer: "; // use 0 here
    cin >> linkList3;
    cout << "               " << linkList3 << endl;
    cout << "(5, ANSWER_2): 0" << endl
         << endl;

    linkList3.insert_node(11);
    linkList3.insert_node(12);
    linkList3.insert_node(13);
    linkList3.insert_node(14);
    linkList3.insert_node(15);
    cout << "               " << linkList3.insert_node(16) << endl;
    cout << "(5, ANSWER_3): 1" << endl
         << endl;
    cout << "               " << linkList3 << endl;
    cout << "(5, ANSWER_4): 0 11 12 13 14 15 16" << endl
         << endl;

    cout << "               " << linkList3.delete_node() << endl;
    cout << "(5, ANSWER_5): 1" << endl
         << endl;
    cout << "               " << linkList3 << endl;
    cout << "(5, ANSWER_6): 0 11 12 13 14 15" << endl
         << endl;

    // test assignment operator, equality operator, insert_node(index, value), delete_node(index)
    Link_List linkList4 = linkList3;
    cout << "               " << linkList4 << endl;
    cout << "(5, ANSWER_7): 0 11 12 13 14 15" << endl
         << endl;

    cout << "               " << linkList4.insert_node(3, 17) << endl;
    cout << "(5, ANSWER_8): 1" << endl
         << endl;
    cout << "               " << linkList4 << endl;
    cout << "(5, ANSWER_9): 0 11 12 17 13 14 15" << endl
         << endl;

    cout << "                " << linkList4.delete_node(4) << endl;
    cout << "(5, ANSWER_10): 1" << endl
         << endl;
    cout << "                " << (linkList4 == linkList3) << endl;
    cout << "(5, ANSWER_11): 0" << endl
         << endl;
    cout << "                " << linkList4 << endl;
    cout << "(5, ANSWER_12): 0 11 12 17 14 15" << endl
         << endl;

    // test subscript operator []
    const Link_List linkList5 = linkList4;
    cout << "                " << linkList4[1] << endl;
    cout << "(5, ANSWER_13): 11" << endl
         << endl;
    cout << "                " << linkList5[1] << endl;
    cout << "(5, ANSWER_14): 11" << endl
         << endl;

    /////////////////////////////////////////////////////////////////////////
    ////////////////////////// advanced score: 30 ///////////////////////////
    /////////////////////////////////////////////////////////////////////////

    Link_List linkList6;
    linkList6.insert_node(0, 20);
    linkList6.insert_node(0, 21);
    linkList6.delete_node();
    linkList6.delete_node(0);
    cout << "                 " << linkList6.delete_node(0) << endl;
    cout << "(10, ANSWER_15): 0" << endl
         << endl;

    Link_List linkList7;
    linkList7.insert_node(100);
    linkList7.insert_node(31);
    linkList7.insert_node(32);
    linkList7[0] = 30;
    cout << "                 " << linkList7[0] << endl;
    cout << "(10, ANSWER_16): 30" << endl
         << endl;

    Link_List linkList8;
    linkList8.insert_node(41);
    linkList8.insert_node(44);
    linkList8.insert_node(45);
    linkList8.insert_node(1, 43);
    linkList8.insert_node(1, 42);
    linkList8.delete_node(4);
    Link_List temp(linkList8);
    cout << "                 " << temp << endl;
    cout << "(10, ANSWER_17): 41 42 43 44" << endl
         << endl;


    return 0;
}
