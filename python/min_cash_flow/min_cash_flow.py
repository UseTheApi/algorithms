"""
Minimize Cash Flow among a given set of friends who have borrowed money from each other
Given a number of friends who have to give or take some amount of money from one another.
Design an algorithm by which the total cash flow among all the friends is minimized.
"""


class Person(object):
    """
    Class represents vertices of a graph
    """
    def __init__(self, p_name):
        self.name = p_name
        self.debit = 0
        self.credit = 0

    def __str__(self):
        person_str = str(self.name) + ' credit: ' + str(self.credit) + ' debit: ' + str(self.debit)
        return person_str

    def balance(self):
        credit_copy = self.credit
        self.credit = self.credit - self.debit if self.credit > self.debit else 0
        self.debit = self.debit - credit_copy if self.credit < self.debit else 0

    def balanced(self):
        return self.credit == 0 and self.debit == 0


class Graph(object):
    def __init__(self):
        self.vertices = list()
        self.edges = list()

    def add_vertex(self, vertex_name):
        person = Person(vertex_name)
        self.vertices.append(person)
        return person

    def get_vertex(self, vertex_name):
        persons = [person for person in self.vertices if person.name == vertex_name]
        try:
            return persons[0]
        except IndexError:
            return None

    def add_edge(self, name1, name2, amount):
        person1 = self.get_vertex(name1)
        person2 = self.get_vertex(name2)
        if not person1 or not person2:
            return
        self.edges.append((person1, person2, amount))
        person1.credit += amount
        person2.debit += amount
        person1.balance()
        person2.balance()

    def __str__(self):
        return str([(edge[0].name, edge[1].name, edge[2]) for edge in self.edges])

    def min_vertex(self):
        min_vertex = self.vertices[0]
        for i in range(1, len(self.vertices)):
            min_vertex = self.vertices[i] if self.vertices[i].credit > min_vertex.credit else min_vertex
        return min_vertex

    def max_vertex(self):
        max_vertex = self.vertices[0]
        for i in range(1, len(self.vertices)):
            max_vertex = self.vertices[i] if self.vertices[i].debit > max_vertex.debit else max_vertex
        return max_vertex


def minimize_cash_flow(graph):
    result_transactions = list()
    while graph.vertices:
        person_with_max_credit = graph.min_vertex()
        person_with_max_debit = graph.max_vertex()
        if person_with_max_debit.debit >= person_with_max_credit.credit:
            person_with_max_debit.debit -= person_with_max_credit.credit
            result_transactions.append((person_with_max_credit.name, person_with_max_debit.name, person_with_max_credit.credit))
            person_with_max_credit.credit = 0
        else:
            person_with_max_credit.credit -= person_with_max_debit.debit
            result_transactions.append((person_with_max_credit.name, person_with_max_debit.name, person_with_max_debit.debit))
            person_with_max_debit.debit = 0
        if person_with_max_debit.balanced():
            graph.vertices.remove(person_with_max_debit)
        if person_with_max_credit.balanced():
            graph.vertices.remove(person_with_max_credit)
    return result_transactions


if __name__ == "__main__":
    group = Graph()
    # Persons names
    p1 = 'p1'
    p2 = 'p2'
    p3 = 'p3'
    p4 = 'p4'

    # Adding persons to the graph
    p_v1 = group.add_vertex(p1)
    p_v2 = group.add_vertex(p2)
    p_v3 = group.add_vertex(p3)
    p_v4 = group.add_vertex(p4)

    # Collecting all transactions
    group.add_edge(p1, p2, 3)
    group.add_edge(p1, p3, 2)
    group.add_edge(p2, p4, 2)
    group.add_edge(p3, p2, 1)
    group.add_edge(p3, p4, 4)

    # Balanced persons
    print("Balanced persons", end='\n\n')
    print(p_v1)
    print(p_v2)
    print(p_v3)
    print(p_v4, end='\n\n')

    # Print Out a whole group
    print("Print Out a whole group")
    print(group, end='\n\n')

    # Minimizing transactions
    transactions = minimize_cash_flow(group)

    # All persons get balanced out
    print("All persons get balanced out")
    print(p_v1)
    print(p_v2)
    print(p_v3)
    print(p_v4, end='\n\n')

    # Result Transactions
    print("Result Transactions")
    print(transactions)
