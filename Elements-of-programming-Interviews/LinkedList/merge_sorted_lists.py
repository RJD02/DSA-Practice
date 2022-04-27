class Node:
	def __init__(self, value):
		self.value = value
		self.next = None

class LinkedList:
	def __init__(self, value):
		self.head = Node(value)

	def add_node(self, value):
		current_node = self.head
		new_node = Node(value)
		while current_node.next:
			current_node = current_node.next
		current_node.next = new_node

	def merge(self, l):
		l1 = self.head
		l2 = l.head
		if l1.value <= l2.value:
			current_node = l1
			l1 = l1.next
		else:
			current_node = l2
			l2 = l2.next
		print('Current Node =', current_node.value)
		while l1 and l2:
			if l1.value <= l2.value:
				current_node.next = l1
				l1 = l1.next
			elif l1.value > l2.value:
				current_node.next = l2
				l2 = l2.next
			current_node = current_node.next
		current_node.next = l1 or l2

	def display(self):
		temp = self.head
		while temp:
			print(temp.value, '->', end=' ')
			temp = temp.next
		print('Null')


def main():
	l1 = LinkedList(2)
	l1.add_node(5)
	l1.add_node(7)
	
	l2 = LinkedList(3)
	l2.add_node(11)
	l1.merge(l2)
	l1.display()

if __name__ == '__main__':
	main()