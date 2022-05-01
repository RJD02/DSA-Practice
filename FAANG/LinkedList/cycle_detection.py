class Node:
	def __init__(self, value=0, next=None):
		self.value = value
		self.next = next

	def display(self):
		print(self.value)

class LinkedList:
	def __init__(self, value):
		self.head = Node(value, None)

	def is_cyclic(self):
		slow_pointer = fast_pointer = self.head
		while slow_pointer.next and fast_pointer.next.next:
			if slow_pointer == fast_pointer:
				return slow_pointer
			slow_pointer = slow_pointer.next
			fast_pointer = fast_pointer.next.next