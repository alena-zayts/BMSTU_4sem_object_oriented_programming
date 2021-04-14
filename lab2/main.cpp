#include "main.hpp"
#include <vector>

void test_constructors()
{
    cout << "Constructors" << endl;

    try
    {
        List<int> list0;
        cout << "<Default constructor>" << endl;
        cout << list0 << endl;

        List<int> list1({2, 10, 11});
        cout << "<Constructor with initializer list>" << endl;
        cout << list1 << endl;

        List<int> list2(list1);
        cout << "<Copy from another list constructor>" << endl;
        cout << list2 << endl;

        List<double> list3({3, 0.1, 0.2, 0.4});
        cout << "<Constructor with initializer list of double>" << endl;
        cout << list3 << endl;

        std::vector<int> vect{10, 20, 30};
        List<int> list4(vect.begin(), vect.end());
        cout << "<Copy from vecctor (using iterators)>" << endl;
        cout << list4 << endl;

        int arr[] = {1, 2, 3, 4, 5};
        List<int> list5(arr, 4);
        cout << "<Copy from list>" << endl;
        cout << list5 << endl;


        list0 = list1;
        cout << "<Copying constructor>" << endl;
        cout << list0 << endl;
        cout << endl;
    }
    // обработка ошибки
    catch (ListErrorBase &error)
    {
        cout << error.what() << endl;
    }
}

void test_addition()
{
    cout << "Elements addition" << endl;

    try
    {
        List<int> list0;
        List<int> list1;
        List<int> list2;

        cout << "<append(data)>" << endl;
        cout << "before" << endl;
        cout << list0 << endl;

        list0.append(11);
        cout << "first append" << endl;
        cout << list0 << endl;

        list0.append(12);
        cout << "second append" << endl;
        cout << list0 << endl;

        cout << "<insert(data, iter)>" << endl;
        cout << "before" << endl;
        cout << list1 << endl;

        ListIter<int> iter0(list1.begin());
        list1.insert(11, iter0);
        cout << "first insert beg" << endl;
        cout << list1 << endl;

        ListIter<int> iter1(list1.begin());
        list1.insert(12, iter1);
        cout << "second insert beg" << endl;
        cout << list1 << endl;

        ListIter<int> iter2(list1.end());
        list1.insert(13, iter2);
        cout << "first insert end" << endl;
        cout << list1 << endl;
        list1.insert(14, iter2);
        cout << "second insert end" << endl;
        cout << list1 << endl;

        cout << "<extend(list)>" << endl;

        cout << "before" << endl;
        cout << list2 << endl;

        list2.extend(list2);
        cout << "extend self" << endl;
        cout << list2 << endl;

        list2.extend(list0);
        cout << "extend very first" << endl;
        cout << list2 << endl;

        list2.extend(list2);
        cout << "extend self" << endl;
        cout << list2 << endl;

        list2.extend(list1);
        cout << "extend second" << endl;
        cout << list2 << endl;
        cout << endl;
    }
    catch (ListErrorBase &error)
    {
        cout << error.what() << endl;
    }
}

void test_removal()
{
    cout << "Elements removal" << endl;

    try
    {
        List<int> list0({5, 1, 2, 3, 4, 5});

        cout << "<remove(iter)>" << endl;
        ListIter<int> iter0(list0.begin());
        cout << list0 << endl;

        list0.remove(iter0);
        cout << "before" << endl;
        cout << list0 << endl;

        ListIter<int> iter1(list0.begin());
        iter1++;
        ++iter1;
        list0.remove(iter1);
        cout << "remove 0++, ++1" << endl;
        cout << list0 << endl;

        cout << "<pop()>" << endl;

        list0.pop();
        cout << "first pop" << endl;
        cout << list0 << endl;

        list0.pop();
        cout << "second pop" << endl;
        cout << list0 << endl;

        list0.pop();
        cout << "third pop" << endl;
        cout << list0 << endl;

        cout << "<clear()>" << endl;

        list0.clear();
        cout << list0 << endl;
        cout << endl;
    }
    catch (ListErrorBase &error)
    {
        cout << error.what() << endl;
    }
}

void test_other()
{
    try
    {
        List<int> list0({3, 1, 2, 3});
        List<int> list1({2, 1, 2});

        cout << "<getLen()>" << endl;
        cout << list0 << endl;
        cout << list0.getLen() << endl;
        cout << list1 << endl;
        cout << list1.getLen() << endl;

        cout << "<operators>" << endl;
        if (list0 != list1)
        {
            cout << "list2 not equal list1" << endl;
        }
        if (not list0.isEqual(list1))
        {
            cout << "list2 not equal list1" << endl;
        }
        cout << "list0+=list1" << endl;
        list0 += list1;
        cout << list0 << endl;
        cout << "list0+=15" << endl;
        list0 += 15;
        cout << list0 << endl;
        cout << endl;
    }
    catch (ListErrorBase &error)
    {
        cout << error.what() << endl;
    }
}

int main()
{
    cout << "TEST" << endl;
    test_constructors();
    test_addition();
    test_removal();
    test_other();

    return 0;
}
