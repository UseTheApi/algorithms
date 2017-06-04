
"""
Problem: Write a function that will sum 2 linked lists as decimal numbers
"""

class Node(object):
    """
    class represents data node of a linked list
    """
    def __init__(self, init_data):
        self.data = init_data
        self.next = None

    def __str__(self):
        return str(self.data)

    def __add__(self, other):
        return self.data + other.data

    def __sub__(self, other):
        return self.data - other.data


class LinkedList(object):
    """
    class represents a linked list DS
    """
    def __init__(self, init_data=None):
        self.head = Node(init_data) if init_data else None
        self.size = 1 if init_data else 0

    def __str__(self):
        s = ''
        tmp = self.head
        while tmp:
            s += str(tmp.data) + ' '
            tmp = tmp.next
        return s

    def insert(self, key):
        """
        This method inserts a given key into the beginning of the list
        :param key: data to be inserted into a linked list
        :type key: any iterable
        """
        new_node = Node(key)
        self.size += 1
        if not self.head:
            self.head = new_node
            return
        tmp = self.head
        new_node.next = tmp
        self.head = new_node

    def append(self, key):
        """
        This method appends a given key into the end of the list
        :param key: data to be appended to a linked list
        :type key: any iterable
        """
        new_node = Node(key)
        self.size += 1
        if not self.head:
            self.head = new_node
            return

        tmp = self.head
        while tmp.next:
            tmp = tmp.next
        tmp.next = new_node

    def from_list(self, items):
        """
        This method takes all values from a given list and appends them into self
        :param items: items to append
        :type items: list
        """
        if not self.head:
            self.head = Node(items[0])
            self.size += 1
            items.remove(items[0])
        for i in items:
            self.append(i)


    def reverse(self):
        """
        This method reverses the list and returns new reversed list
        return: self
        """
        cur = self.head
        prev = cur.next
        new_next = None

        while cur.next:
            cur.next = new_next
            new_next = cur
            cur = prev
            prev = prev.next
        cur.next = new_next
        self.head = cur
        return self

    def __add__(self, other):
        """
        Classical summing of linked lists, where all items sum up
        with each other in certain order
        :param other: other linked list
        :type other: LinkedList
        """
        result_list = [first+second for (first, second) in zip(self, other)]
        sum_linked_list = LinkedList()
        for item in result_list:
            sum_linked_list.append(item)
        return sum_linked_list

    def __iter__(self):
        cur = self.head
        while cur:
            yield cur
            cur = cur.next

    def __getitem__(self, item):
        i = 0
        tmp = self.head
        while i < item:
            tmp = tmp.next
            i += 1
        return tmp

    def add_as_decimal(self, other):
        """
        This method sums up 2 given linked lists as they were decimal numbers
        :param other: other linked list
        :type other: LinkedList
        :return: sum of 2 linked lists
        :rtype: LinkedList
        """
        self.reverse()  # reversing first list
        other.reverse()  # reversing second list
        result_list = LinkedList()
        first_longer = self.size > other.size
        carry = 0  # initializing carry for sum
        i = 0

        while i < min(self.size, other.size):
            cur_sum = self[i] + other[i] + carry
            # calculating current carry
            carry = cur_sum // 10
            # appending cur_sum to new list
            result_list.append(cur_sum % 10)
            i += 1

        # taking care of length differences
        while i < self.size if first_longer else i < other.size:
            cur_sum = self[i].data if first_longer else other[i].data
            cur_sum += carry
            carry = cur_sum // 10
            result_list.append(cur_sum % 10)
            i += 1

        # if carry still remains just adding it to list
        if carry:
            result_list.append(carry)

        # reversing lists back
        self.reverse()
        other.reverse()
        # reversing result list back and returning
        return result_list.reverse()

