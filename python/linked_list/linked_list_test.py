
import unittest
from linked_list import LinkedList


class LinkedListTest(unittest.TestCase):
    def test_InsertLinkedList(self):
        linked_list = LinkedList()
        num_of_elements = 5
        for i in range(num_of_elements):
            linked_list.insert(i)
        self.assertEquals(linked_list.size, num_of_elements)
        cur_el = 0
        for i in range(num_of_elements-1, 1, -1):
            self.assertEquals(cur_el, linked_list[i].data)
            cur_el += 1

    def test_AppendLinkedList(self):
        linked_list = LinkedList()
        num_of_elements = 5
        for i in range(num_of_elements):
            linked_list.append(i)
        self.assertEquals(linked_list.size, num_of_elements)
        for i in range(num_of_elements):
            self.assertEquals(i, linked_list[i].data)

    def test_ReverseLinkedList(self):
        linked_list = LinkedList()
        reversed_man_list = LinkedList()
        num_of_elements = 5
        for i in range(num_of_elements):
            linked_list.append(i)

        self.assertEquals(linked_list.size, num_of_elements)

        for i in range(num_of_elements-1, -1, -1):
            reversed_man_list.append(i)

        linked_list.reverse()

        for index, item in enumerate(linked_list):
            self.assertEquals(item.data, reversed_man_list[index].data)

    def test_AddLinkedList(self):
        first = LinkedList()
        other = LinkedList()
        compare_list = LinkedList()
        num_of_elements = 5
        for i in range(num_of_elements):
            first.append(i)
            other.append(i)
            compare_list.append(i+i)

        self.assertEquals(first.size, num_of_elements)
        self.assertEquals(other.size, num_of_elements)

        res = first + other

        for index, item in enumerate(res):
            self.assertEquals(item.data, compare_list[index].data)

    def test_AddDecimalLinkedList_SameLength_NoCarry(self):
        first = LinkedList()
        second = LinkedList()
        compare_list = LinkedList()

        num_of_elements = 4
        for i in range(num_of_elements):
            first.append(i)
            second.append(i)
            compare_list.append(i+i)

        print(first)
        print(second)
        print(compare_list)

        res = first.add_as_decimal(second)

        for index, item in enumerate(res):
            self.assertEquals(item.data, compare_list[index].data)

    def test_AddDecimalLinkedList_FirstLonger_Carry(self):
        first = LinkedList()
        second = LinkedList()
        compare_list = LinkedList()

        first.from_list([1, 2, 4, 9])
        second.from_list([8, 5, 0])
        compare_list.from_list([2, 0, 9, 9])

        res = first.add_as_decimal(second)

        for index, item in enumerate(res):
            self.assertEquals(item.data, compare_list[index].data)

    def test_AddDecimalLinkedList_SecondLonger_Carry(self):
        first = LinkedList()
        second = LinkedList()
        compare_list = LinkedList()

        first.from_list([8, 5, 0])
        second.from_list([1, 2, 4, 9])
        compare_list.from_list([2, 0, 9, 9])

        res = first.add_as_decimal(second)

        for index, item in enumerate(res):
            self.assertEquals(item.data, compare_list[index].data)

    def test_AddDecimalLinkedList_SameLength_Carry(self):
        first = LinkedList()
        second = LinkedList()
        compare_list = LinkedList()

        first.from_list([8, 7, 8, 5])
        second.from_list([2, 2, 1, 6])
        compare_list.from_list([1, 1, 0, 0, 1])

        res = first.add_as_decimal(second)

        for index, item in enumerate(res):
            self.assertEquals(item.data, compare_list[index].data)

