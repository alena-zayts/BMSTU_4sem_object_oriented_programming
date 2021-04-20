#include "main.hpp"
#include <vector>

void test_constructors()
{
    cout << "Constructors" << endl;

    try
    {
        cout << "<Default list0>" << endl;
        List<int> list0;
        cout << list0 << endl;

        cout << "<Copy from list0>" << endl;
        List<int> list1(list0);
        cout << list1 << endl;
        list1 = list0;
        cout << list1 << endl;

        cout << "<Move list0>" << endl;////
        List<int> list2(move(list0));
        list2 = move(list2);
        cout << list2 << endl;

        cout << "<With initializer list of double>" << endl;
        List<double> list3({3, 0.1, 0.2, 0.4});
        cout << list3 << endl;

        cout << "<From array>" << endl;
        int arr[] = {1, 2, 3, 4, 5};
        List<int> list4(arr, 4);
        cout << list4 << endl;

        std::vector<int> vect{10, 20, 30};
        List<int> list5(vect.begin(), vect.end());
        cout << "<With 2 iterators (from vector)>" << endl;
        cout << list5 << endl;

        cout << "<=list1>" << endl;
        list0 = list1;
        cout << list0 << endl;

        cout << "<=initializer_list>" << endl;
        list0 = {1, 2, 3};
        cout << list0 << endl;

        cout << "<=iterator>" << endl;
        list0 = list1.begin();
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
    cout << endl;
    cout << endl;
    cout << "Elements addition" << endl;

    try
    {
        //List<int> list0({2, 10, 11});
        //List<int> list2;

        List<int> list1({2, 10, 11});
        cout << "list1" << endl;
        cout << list1 << endl;

        cout << "<add/+(data)>" << endl;
        cout << "list1 = list1.add(1)" << endl;
        list1 = list1.add(1);
        cout << list1 << endl;
        cout << "list1 = list1 + 1" << endl;
        list1 = list1 + 1;
        cout << list1 << endl;

        cout << "<append/+=(data)>" << endl;
        cout << "list1.append(11)" << endl;
        list1.append(11);
        cout << list1 << endl;
        cout << "list1 += 22" << endl;
        list1 += 22;
        cout << list1 << endl;

        cout << "<addlist/+(list)>" << endl;
        cout << "list1" << endl;
        cout << list1 << endl;
        List<int> list2({1, 2, 3});
        cout << "list2" << endl;
        cout << list2 << endl;

        cout << "list1 = list1+list2" << endl;
        list1 = list1 + list2;
        cout << list1 << endl;

        cout << "list1 = list1.addlist(list1)" << endl;
        list1 = list1 + list1;
        cout << list1 << endl;

        cout << "<addlist(begin, end)>" << endl;
        cout << "list1 = list1.addlist(list1.begin(), list1.end());" << endl;
        ListIter<int> iter0(list1.begin());
        ListIter<int> iter1(list1.end());
        list1 = list1.addlist(iter0, iter1);
        cout << list1 << endl;

        cout << "<extend/+=(list)>" << endl;
        cout << "list2.extend(list2)" << endl;
        list2.extend(list2);
        cout << list2 << endl;

        cout << "list2+=list1" << endl;
        list2 += list1;
        cout << list2 << endl;

        cout << endl;
        cout << "Push" << endl;
        cout << "Before" << endl;
        list1 = {1, 2, 3};
        list2 = {9, 8, 7};
        int a[] = {-1, -2};
        int len = 2;
        cout << list1 << endl;
        cout << "pushHead(10)" << endl;
        list1.pushHead(10);
        cout << list1 << endl;
        cout << "with array pushHead(-1, -2)" << endl;
        list1.pushHead(a, len);
        cout << list1 << endl;
        cout << "with iterator pushHead(9, 8, 7)" << endl;
        list1.pushHead(list2.begin(), list2.end());
        cout << list1 << endl;
        cout << "pushTail(10)" << endl;
        list1.pushTail(10);
        cout << list1 << endl;
        cout << "with array pushTail(-1, -2)" << endl;
        list1.pushTail(a, len);
        cout << list1 << endl;
        cout << "with iterator pushTail(9, 8, 7)" << endl;
        list1.pushTail(list2.begin(), list2.end());
        cout << list1 << endl;
        cout << "pushIter(10, 2)" << endl;
        ListIter<int> iter(list1.begin());
        iter++;
        iter++;
        list1.pushIter(10, iter);
        cout << list1 << endl;
        cout << "with array pushIter(-1, -2) to 3" << endl;
        list1.pushIter(a, len, iter);
        cout << list1 << endl;
        cout << "with iterator pushIter(9, 8, 7) to 5" << endl;
        list1.pushIter(list2.begin(), list2.end(), iter);
        cout << list1 << endl;

    }
    catch (ListErrorBase &error)
    {
        cout << error.what() << endl;
    }
}

void test_removal()
{
    cout << endl;
    cout << endl;
    cout << "Elements removal" << endl;

    try
    {
        List<int> list0({5, 1, 2, 3, 4, 5, 10, 932, 1});
        cout << "before" << endl;
        cout << list0 << endl;

        cout << "<popHead()>" << endl;
        list0.popHead();
        cout << "first pop" << endl;
        cout << list0 << endl;

        list0.popHead();
        cout << "second pop" << endl;
        cout << list0 << endl;

        cout << "<popTail()>" << endl;

        list0.popTail();
        cout << "first pop" << endl;
        cout << list0 << endl;

        list0.popTail();
        cout << "second pop" << endl;
        cout << list0 << endl;


        cout << "<popIter(iter)>" << endl;
        cout << "popIter 0++, ++1" << endl;
        ListIter<int> iter1(list0.begin());
        iter1++;
        iter1++;
        list0.popIter(iter1);
        cout << list0 << endl;

        cout << "<remove(1, 3)>" << endl;
        ListIter<int> iter_beg(list0.begin());
        ListIter<int> iter_end(list0.begin());
        iter_beg++;
        iter_end++;
        iter_end++;
        iter_end++;
        list0.remove(iter_beg, iter_end);
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
