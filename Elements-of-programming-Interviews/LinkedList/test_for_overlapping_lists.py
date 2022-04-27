class Node:
	def __init__(self, value=0, next=None):
		self.value = value
		self.next = next

class LinkedList:
	def __init__(self, value=0):
		self.head = Node(value)

	def add_node(self, value=0):
		current_node = self.head
		new_node = Node(value)
		while current_node.next:
			current_node = current_node.next
		current_node.next = new_node

	def display(self):
		current_node = self.head
		while current_node:
			print(current_node.value, '->', end=' ')
			current_node = current_node.next
		print()


def check_for_overlapping_list(a, b):
	head1 = a.head
	head2 = b.head
	current_node1 = head1
	current_node2 = head2
	res = []
	while current_node1:
		current_node2 = head2
		while current_node2.next:
			if current_node1.value == current_node2.value:
				res.append(current_node2.value)
			current_node2 = current_node2.next
		current_node1 = current_node1.next
	return res

def check_for_overlapping_list2(a, b):
	res = []
	head1 = a.head
	head2 = b.head
	while head1.next:
		res.append(head1.value)
		head1 = head1.next
	res = set(res)
	ret = []
	while head2.next:
		if head2.value in res:
			ret.append(head2.value)
		head2 = head2.next

	return ret



def main():
	a = LinkedList(1)
	a.add_node(2)
	a.add_node(3)
	a.add_node(4)
	a.add_node(5)
	a.add_node(6)
	b = LinkedList(6)
	b.add_node(7)
	b.add_node(8)
	b.add_node(9)
	print(check_for_overlapping_list(a, b))
	print(check_for_overlapping_list2(a, b))

if __name__ == '__main__':
	main()
