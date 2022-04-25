"""

Given a linked list, construct an in-place reversing algorithm

1 -> 2 -> 3 -> NULL
output: 3 -> 2 -> 1 -> NULL



"""

class Node:
	def __init__(self, value):
		self.val = value
		self.next = None


class LinkedList:
	def __init__(self, value):
		self.head = Node(value)
		self.tail = self.head


	def addNode(self, value):
		temp = Node(value)
		self.tail.next = temp
		self.tail = self.tail.next

	def reverse(self):
		currentNode = self.head
		previousNode = None
		nextNode = None
		while currentNode:
			nextNode = currentNode.next
			currentNode.next = previousNode
			previousNode = currentNode
			currentNode = nextNode
		self.head = previousNode

	def display(self):
		temp = self.head
		while temp:
			print(temp.val, '->', end=' ')
			temp = temp.next
		print('NULL')

def main():
	a = LinkedList(1)
	a.addNode(2)
	a.addNode(3)
	a.display()
	a.reverse()
	a.display()

if __name__ == '__main__':
	main()


