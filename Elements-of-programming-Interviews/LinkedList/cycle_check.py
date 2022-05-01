class Node:
	def __init__(self, value=0, next=None):
		self.value = value
		self.next = next

class LinkedList:
	def __init__(self, value=0):
		self.head = Node(value, None)

	def add_node(self, value):
		new_node = Node(value)
		current_node = self.head
		while current_node.next:
			current_node = current_node.next

		current_node.next = new_node

	def display(self):
		temp = self.head
		while temp:
			print(temp.value, '->', end=' ')
		print('NULL')

	def is_cyclic(self):
		slow_pointer = fast_pointer = self.head
		current_node = self.head
		meeting_pointer = None
		while slow_pointer.next and fast_pointer.next.next:
			if fast_pointer == slow_pointer:
				meeting_pointer = slow_pointer
				break
		else:
			return None

		while current_node and meeting_pointer:
			if current_node = meeting_pointer:
				return current_node
			current_node = current_node.next
			meeting_pointer = meeting_pointer.next


def main():
	a = LinkedList(1)
	a.add_node(2)
	a.add_node(3)
	a.add_node(4)
	a.add_node(5)
	a.add_node(6)
	current_node = a.head
	prev_node = current_node
	while current_node.next:
		prev_node = current_node
		current_node = current_node.next
	current_node.next = prev_node
	# a.display()
	print(prev_node.value)
	print(a.is_cyclic())

if __name__ == '__main__':
	main()