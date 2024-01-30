class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_position(self, data, position):
        if position == 0:
            self.prepend(data)
            return
        new_node = Node(data)
        current = self.head
        for _ in range(position - 1):
            if current is None:
                print("Invalid position. List size is smaller.")
                return
            current = current.next
        new_node.next = current.next
        current.next = new_node

    def delete(self, key):
        current = self.head
        if current and current.data == key:
            self.head = current.next
            return
        prev = None
        while current and current.data != key:
            prev = current
            current = current.next
        if current is None:
            print(f"Node with data {key} not found.")
            return
        prev.next = current.next

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

# Menu-Driven Program
linked_list = LinkedList()

while True:
    print("\nLinked List Operations:")
    print("1. Append Node")
    print("2. Prepend Node")
    print("3. Insert at Position")
    print("4. Delete Node")
    print("5. Print List")
    print("6. Exit")

    choice = int(input("Enter your choice (1-6): "))

    if choice == 1:
        data = input("Enter data to append: ")
        linked_list.append(data)
    elif choice == 2:
        data = input("Enter data to prepend: ")
        linked_list.prepend(data)
    elif choice == 3:
        data = input("Enter data to insert: ")
        position = int(input("Enter position: "))
        linked_list.insert_at_position(data, position)
    elif choice == 4:
        key = input("Enter data to delete: ")
        linked_list.delete(key)
    elif choice == 5:
        linked_list.print_list()
    elif choice == 6:
        print("Exiting the program.")
        break
    else:
        print("Invalid choice. Please enter a number between 1 and 6.")
