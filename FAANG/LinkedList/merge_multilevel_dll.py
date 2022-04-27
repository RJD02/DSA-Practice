class Node:
	def __init__(self, value=0, next=None, prev=None, child=None):
		self.value = value
		self.next = next
		self.child = child
		self.prev = prev

class LinkedList:
	def __init__(self, value=0, next=None, prev=None, child=None):
		self.head = Node(value, next, prev, child)

	def add_node(self, value=0):
		new_node = Node(value)
		current_node = self.head
		while current_node.next:
			current_node = current_node.next
		new_node.prev = current_node
		current_node.next = new_node

	def add_child(self, child_list, pos):
		current_node = self.head
		while pos and current_node.next:
			pos -= 1
			current_node = current_node.next
		current_node.child = child_list

	def display(self):
		current_node = self.head
		while current_node:
			print(current_node.value, '->', end=' ')
			current_node = current_node.next
		print('NULL')

	def merge(self):
		current_node = self.head
		while current_node.next:
			print(current_node.value)
			if current_node.child:
				child_node = current_node.child.head
				while child_node.next:
					child_node = child_node.next
				child_node.next = current_node.next
				current_node.next.prev = child_node
				current_node.next = current_node.child.head
				current_node.child.head.prev = current_node
				current_node.child = None
			# print(current_node.next.value)
			current_node = current_node.next
			self.display()

# def merge(head):
# 	current_node = head
# 	print(current_node.next.next.value)
# 	while current_node:
		
# 	return head

def main():
	a = LinkedList(1)
	a.add_node(2)
	a.add_node(3)
	a.add_node(4)
	a.add_node(5)
	a.add_node(6)
	# a.display()

	b = LinkedList(7)
	b.add_node(8)
	b.add_node(9)

	c = LinkedList(10)
	c.add_node(11)
	d = LinkedList(12)
	d.add_node(13)
	# b.display()

	a.add_child(b, 1)
	b.add_child(c, 1)
	a.add_child(d, 4)
	a.display()
	a.merge()
	a.display()


	
	
	

if __name__ == '__main__':
	main()